#include <ros/ros.h>
#include <std_msgs/Header.h>
#include <sensor_msgs/Range.h>
#include <sensor_msgs/LaserScan.h>
#include <map_msgs/ProjectedMap.h>
#include <nav_msgs/OccupancyGrid.h>
#include <nav_msgs/Odometry.h>
#include <nav_msgs/Path.h>
#include <tf/transform_listener.h>
#include <tf/transform_broadcaster.h>
#include <geometry_msgs/Pose.h>
#include <geometry_msgs/PoseStamped.h>
#include <unistd.h>
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <time.h>
#include <queue>
#include <vector>
#include <math.h>
#include "region_growing.h"
#include "filter.h"
#include "cal_vel.h"


#define PI 3.14159
#define BEAM_THRESH 0.1
#define BEAMS 1081
#define MAX_RANGE 5
#define SOLUTION 0.05
#define map_x 200
#define map_y 200
#define G_origin 1969120
#define G_width 1984

/********************************话题订阅回调函数声明*****************************************/
/*************************************************************************************/
void data_substract(const sensor_msgs::LaserScan& msg);
void cpy_map(const nav_msgs::OccupancyGrid& msg);

/********************************普通函数声明*****************************************/
/*************************************************************************************/
void data_substract(const sensor_msgs::LaserScan& msg);
void rbtPose(const nav_msgs::Odometry& rvtPs);
void cal_centroid(std::queue<int> group_x,std::queue<int> group_y,int *centroid);
void pthread_publish(void);
std::queue<int> beam_substract(float *minuend,float * subtrahend,int n );//激光束对应的beam作差,如果超过阈值,则认为有动态物体.
void map_update(int **map,float *beams, std::queue<int> mark_beam,float AglRbt_m);//地图更新函数,根据mark_beam来跟新动态物体的位置
void deal_Gmap(void);

time_t tm;
nav_msgs::OccupancyGrid Gmap;
bool deal_flag=false;
float scan_data[11][1081]={{0}};      //一共保存11帧数据,每组数据有1081个beams.
static int frames=0;            //静态数据
nav_msgs::OccupancyGrid Map_Msg;//栅格地图消息
geometry_msgs::Pose RobotCenter;//地图中心,应该定义为机器人的中心
int map[map_x][map_y];          //地图数组
float AngleIncrement;           //激光雷达的增角
float AglRbt;                   //机器人的角度姿态
std::list<Point_custom> LastMAP;//由于存储上一帧地图的有效点
//x,y卡尔曼滤波的参数
struct kal_param x_pos_param(0,0,1,2,0,0,0,0);
struct kal_param y_pos_param(0,0,1,2,0,0,0,0);
struct kal_param x_vel_param(0,0,1,2,0,0,0,0);
struct kal_param y_vel_param(0,0,1,2,0,0,0,0);

int main(int argc, char *argv[])
{
    ros::init(argc,argv,"dynamic_detection");
    ros::NodeHandle nh;
    geometry_msgs::PointStamped laser_point;
    geometry_msgs::PointStamped Gmap_point;

    tf::TransformBroadcaster br;
    tf::Transform trans_br;
    tf::StampedTransform transform;


    ROS_INFO("***********START*************");


    ros::Publisher pub_map=nh.advertise<nav_msgs::OccupancyGrid>("/substracted",1);  //publish the local map of dynamics
    ros::Publisher pub_Gmap=nh.advertise<nav_msgs::OccupancyGrid>("/Gmap_tpc",1);  //publish the local map of dynamics
    ros::Subscriber sub=nh.subscribe("/base_scan",1,&data_substract);                                  //subscribe the laser data
    ros::Subscriber sub_cpy=nh.subscribe("/map",1,&cpy_map);                                  //subscribe the laser data
    tf::TransformListener listener(ros::Duration(10));
    ros::Rate rate(10);

    laser_point.header.frame_id = "/substracted";
    laser_point.header.stamp = ros::Time();
    laser_point.point.z = 0;

    while(ros::ok())
    {
        try{
        listener.waitForTransform("/map","/base_laser_link",ros::Time(0),ros::Duration(10.0));
        listener.lookupTransform("/map","/base_laser_link",ros::Time(0),transform);
        } catch (tf::TransformException ex){
            ROS_ERROR("%s",ex.what());
        }
        //将局部地图更新进大地图
        //因为局部地图不是完全固定在机器人上,而是像窗口一样的平移.所以物体的实际坐标是
        //"在局部地图中的坐标 简单的加上 局部地图的世界坐标"
        if(deal_flag)
        {
            Gmap.data.assign(G_width*G_width,0);
            Gmap.data[G_origin+8*G_width+8]=100;
            for(int i=0; i<map_x; i++)
               for(int j=0; j<map_y; j++)
               {
                   if(map[i][j]==100)
                   {
                        //laser_point.point.x = -1.05*(i-100);
                        //laser_point.point.y = 0.05*(j-100);
                        laser_point.point.x = (i-100);
                        laser_point.point.y = (j-100);
                        //listener.transformPoint("/map",laser_point,Gmap_point);  //坐标转换
                        //int xx=(int) (Gmap_point.point.x + 20*transform.getOrigin().x());
                        //int yy=(int) (Gmap_point.point.y + 20*transform.getOrigin().y());
                        int xx = j -100 + 20*transform.getOrigin().x(); //因为局部地图的问题,所以在这里的J值才是局部地图的x值.
                        int yy = i -100 + 20*transform.getOrigin().y();

                        //int xx=(int) (20*Gmap_point.point.x);
                        //int yy=(int) (20*Gmap_point.point.y);
                        Gmap.data[G_origin + (yy+8) * G_width + xx+8]=100;//这里的xx与yy都加8,是为了修正,似乎地图数组的中心与地图坐标原点的中心各差了8个像素单位
                        //Gmap.data[G_origin + (int)(xx * G_width) + (int)(yy)]=100;
                        //ROS_INFO("(%d,%d)---->(%d,%d)",0,0,(int) (xx),(int) ( yy));
                   }

               }
        }

        //跟新地图的基本信息
        AglRbt = tf::getYaw( transform.getRotation() );//change the quaternion to Eular angle. use the angle to correct the pose of robot
        RobotCenter.position.x=transform.getOrigin().x()-5;//
        RobotCenter.position.y=transform.getOrigin().y()-5;
        Map_Msg.info.width=map_x;
        Map_Msg.info.height=map_y;
        Map_Msg.info.resolution=SOLUTION;
        Map_Msg.info.origin=RobotCenter;
        pub_map.publish(Map_Msg);
        pub_Gmap.publish(Gmap);

        //局部地图的tf坐标系
        //trans_br.setOrigin(tf::Vector3(RobotCenter.position.x+5, RobotCenter.position.y+5 ,0));
        //tf::Quaternion quaternion_br=tf::createQuaternionFromRPY(0,0,0);
        //trans_br.setRotation(quaternion_br.normalize());
        //br.sendTransform(tf::StampedTransform(trans_br, ros::Time::now(),"/map","/substracted"));

        ROS_INFO("PUBLISH...");
        ros::spinOnce();
        rate.sleep();
    }

    return 0;
}

void cpy_map(const nav_msgs::OccupancyGrid& msg)
{
    Gmap = msg;
    ROS_INFO("copied!");
    deal_flag = true;
}
void deal_Gmap(void)
{

}
//在回调函数中建立地图,回调函数0.1s执行一次
void data_substract(const sensor_msgs::LaserScan& msg)
{
    std::queue<int> mark_beam;
    //tm=time(NULL);
    AngleIncrement=msg.angle_increment;
    //ROS_INFO("TIME: %ld",tm);
    for(int j=0;j<BEAMS;j++)
    {
        scan_data[frames][j] = msg.ranges[j];
    }
    //激光束作差,与1秒前的数据帧作差
    if(frames==10) { mark_beam = beam_substract(scan_data[10],scan_data[0],BEAMS);}
    else mark_beam = beam_substract(scan_data[frames],scan_data[frames+1],BEAMS);

    for(int i=0; i<map_x*map_y; i++)// clear the whole map, start calculate the next frame of map
    {
        *( (int*)map+i )=0;
    }

    if(!mark_beam.empty())
    {
        /*调用地图更新函数*/
        map_update((int **)map,*(scan_data+frames),(std::queue<int>)mark_beam,AglRbt);
    }

    std::vector<signed char> VMap(*map,*map+(map_x*map_y));//将数组地图转化为向量,用以发布消息的赋值.
    Map_Msg.data=VMap;//用二维数组更新地图

    frames++;
    if(frames>10) {frames=0;}
}


/******************************普通函数************************************/
//两帧激光束之间作差函数,
std::queue<int> beam_substract(float *minuend,float * subtrahend,int n )
{
    std::queue<int> marked_beam;

    float result;
    for(int i=0;i<n;i++)
    {
      result = minuend[i]-subtrahend[i];
      if(result>BEAM_THRESH || result<-BEAM_THRESH )//要求运动物体运动一秒的距离大于临界值
      {
          marked_beam.push(i);
          //ROS_INFO("beam: %d",i);
      }
    }
    return marked_beam;
}

//地图更新函数
/*@des 地图更新函数,只是将所有的拟动态物体标示出来.并未加以区分,应该用区域增长法将各动态物体区分开来
 * @map 地图指针,@beam 激光帧, @mark_beam 被标记激光的队列,@AglRbt_m
 **/
void map_update(int **map,float *beams, std::queue<int> mark_beam,float AglRbt_m)
{
    int x_grid;
    int y_grid;
    double theta=0;
    float range=0;
    std::queue<Point_custom> region_ctr;
    std::queue<int> x_group;
    std::queue<int> y_group;
    //int x_last=0,y_last=0;
    ROS_INFO("interval: %ld",time(NULL)-tm);
    tm=time(NULL);

    while(!mark_beam.empty())
    {
        theta= 2.35562 + AglRbt_m + AngleIncrement*mark_beam.front();//此处的2.355 (3*PI/4)为地图与机器人坐标的矫正值

        range=beams[mark_beam.front()];//0.3是调整参数,调整激光折算到栅格地图不匹配的问题
        mark_beam.pop();
        if(range > MAX_RANGE-0.2) continue;//雷达边界附近的激光舍去

        x_grid = ( range*cos(theta) / SOLUTION) ;//变动激光击中的点的x坐标,以地图中心为原点
        y_grid = -(range*sin(theta) / SOLUTION);//变动激光击中的点的y坐标,以地图中心为原点        //将所有的击中点标记到地图之中,以提供给Search_region()函数搜索
        *((int *)map +(map_x*map_y/2+map_y/2)+ (x_grid-1)*map_y + y_grid)=20;
    }

    region_ctr = Search_region(map,map_x,map_y);

    std::list<Point_custom> region_efficient;//复制一份重心地图
    //清空整个地图,用搜索到中心来重画地图
    //for(int i=0;i<map_x*map_y;i++)
    //    *((int *)map+i)=0;
/*
    while(!region_ctr.empty())
    {
        Point_custom ctr_p = region_ctr.front();
        Point_custom mt_p = point_match(LastMAP,ctr_p);

        //in 0.2s, the robot have to move more more than 5cm at least in x_direction or y_dir
        //these points is efficient dyanmic_point
        if((ctr_p.x != mt_p.x) || (ctr_p.y!=mt_p.y))
        {
            *((int *)map + (ctr_p.x)*map_y + ctr_p.y)=100;  //这里的region_ctr.front().x是以地图的角落为原点的

            ctr_p.y_vel = (ctr_p.y - mt_p.y);
            ctr_p.x_vel = (ctr_p.x - mt_p.x);
            if(ctr_p.x_vel != ctr_p.x)
            {
                ctr_p.x_vel = kalman_filter(&x_vel_param, ctr_p.x_vel,0);
            }
            if(ctr_p.y_vel != ctr_p.y)
            {
                ctr_p.y_vel = kalman_filter(&y_vel_param, ctr_p.y_vel,0);
                ROS_INFO("(%d,%d): %f, %f",ctr_p.x, ctr_p.y, ctr_p.x_vel, ctr_p.y_vel);
            }

            region_efficient.push_front(ctr_p);
        }

        region_ctr.pop();
    }
*/
    //将重心输出到地图局部地图上
    while(!region_ctr.empty())
    {
        Point_custom ctr_p = region_ctr.front();
        *((int *)map + (ctr_p.x)*map_y + ctr_p.y)=100;  //这里的region_ctr.front().x是以地图的角落为原点的
        region_efficient.push_front(ctr_p);

        region_ctr.pop();
    }

    LastMAP=region_efficient;
    region_efficient.clear();
}

/*@des 计算质心函数
 * @group_x x坐标队列
 * @centroid 一个二维数组,作为分别包含质点的x坐标和y坐标
 **/
void cal_centroid(std::queue<int> group_x,std::queue<int> group_y,int *centroid)
{
    int sum_x=0,sum_y=0,num=0;
    num=group_x.size();
    while(!group_x.empty())
    {
        sum_x += group_x.front();
        sum_y += group_y.front();

        group_x.pop();
        group_y.pop();
    }
	if(num!=0)
	{
		centroid[0] = (int) (sum_x/num);
	    centroid[1] = (int) (sum_y/num);
	}

}

