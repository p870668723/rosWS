#include <ros/ros.h>
#include <std_msgs/Header.h>
#include <sensor_msgs/Range.h>
#include <sensor_msgs/LaserScan.h>
#include <map_msgs/ProjectedMap.h>
#include <nav_msgs/OccupancyGrid.h>
#include <nav_msgs/Odometry.h>
#include <geometry_msgs/Pose.h>
#include <unistd.h>
#include <tf/transform_broadcaster.h>
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <time.h>
#include <queue>
#include <vector>
#include <math.h>

#define PI 3.14159
#define BEAM_THRESH 0.05
#define BEAMS 1081
#define MAX_RANGE 5
#define SOLUTION 0.05
#define map_x 200
#define map_y 200

/********************************话题订阅回调函数声明*****************************************/
/*************************************************************************************/
void data_substract(const sensor_msgs::LaserScan& msg);
void rbtPose(const nav_msgs::Odometry& rvtPs);

/********************************普通函数声明*****************************************/
/*************************************************************************************/
void data_substract(const sensor_msgs::LaserScan& msg);
void rbtPose(const nav_msgs::Odometry& rvtPs);
void cal_centroid(std::queue<int> group_x,std::queue<int> group_y,int *centroid);
void pthread_publish(void);
std::queue<int> beam_substract(float *minuend,float * subtrahend,int n );//激光束对应的beam作差,如果超过阈值,则认为有动态物体.
void map_update(int **map,float *beams, std::queue<int> mark_beam,float AglRbt_m);//地图更新函数,根据mark_beam来跟新动态物体的位置
void kalman_vel(int *coordinate);//kalman filter

/********************************全局变量声明*****************************************/
/*************************************************************************************/
time_t tm;
float scan_data[11][1081]={{0}};      //一共保存11帧数据,每组数据有1081个beams.
static int frames=0;            //静态数据
nav_msgs::OccupancyGrid Map_Msg;//栅格地图消息
geometry_msgs::Pose RobotCenter;//地图中心,应该定义为机器人的中心
int map[map_x][map_y];          //地图数组
float AngleIncrement;
float AglRbt;

int main(int argc, char *argv[])
{
    ros::init(argc,argv,"dynamic_detection");
    ros::NodeHandle nh;
    ROS_INFO("***********START*************");

    ros::Publisher pub=nh.advertise<nav_msgs::OccupancyGrid>("/substracted",1000);
    ros::Subscriber sub=nh.subscribe("/base_scan",1000,&data_substract);
    ros::Subscriber robot_pose=nh.subscribe("/odom",1000,&rbtPose);

    ros::Rate rate(5);
    while(ros::ok())
    {
        pub.publish(Map_Msg);
        ROS_INFO("PUBLISH...");
        ros::spinOnce();
        rate.sleep();
    }

    return 0;
}


//在回调函数中建立地图,回调函数0.1s执行一次
void data_substract(const sensor_msgs::LaserScan& msg)
{
    std::queue<int> mark_beam;
    tm=time(NULL);
    AngleIncrement=msg.angle_increment;
    //ROS_INFO("TIME: %ld",tm);
    for(int j=0;j<BEAMS;j++)
    {
        scan_data[frames][j] = msg.ranges[j];
    }
    //激光束作差
    if(frames==10) { mark_beam = beam_substract(scan_data[10],scan_data[0],BEAMS);}
    else mark_beam = beam_substract(scan_data[frames],scan_data[frames+1],BEAMS);

    for(int i=0;i<map_x*map_y;i++)// clear the whole map
    {
        *((int*)map+i)=0;
    }
    if(!mark_beam.empty())
    {
        ROS_INFO("MARKED_BEAM: %d",mark_beam.front());
        mark_beam.pop();
        /*调用地图更新函数*/
        map_update((int **)map,*(scan_data+frames),(std::queue<int>)mark_beam,AglRbt);
    }

    std::vector<signed char> VMap(*map,*map+(map_x*map_y));//将数组地图转化为向量,用以发布消息的赋值.
    Map_Msg.data=VMap;//

    frames++;
    if(frames>10) {frames=0;}

}

//订阅机器人位姿的回调函数.
void rbtPose(const nav_msgs::Odometry& rbtPs)
{
    //地图中心初始化
    RobotCenter.position.x=rbtPs.pose.pose.position.x-5;
    RobotCenter.position.y=rbtPs.pose.pose.position.y-5;
    RobotCenter.orientation.z=0;
    AglRbt=tf::getYaw(rbtPs.pose.pose.orientation);
    //地图信息配置
    Map_Msg.info.width=map_x;
    Map_Msg.info.height=map_y;
    Map_Msg.info.resolution=SOLUTION;
    Map_Msg.info.origin=RobotCenter;
    ROS_INFO("IN RBTPOSE");

}



/******************************普通函数************************************/
//两帧激光束之间作差函数,
std::queue<int> beam_substract(float *minuend,float * subtrahend,int n )
{
    std::queue<int> marked_beam;

    float result;
    for(int i=0;i<n;i++)
    {
      result=  minuend[i]-subtrahend[i];
      if(result>BEAM_THRESH || result<-BEAM_THRESH  )
      {
          marked_beam.push(i);
      }
    }
    return marked_beam;
}

//地图更新函数
void map_update(int **map,float *beams, std::queue<int> mark_beam,float AglRbt_m)
{
    int x_grid;
    int y_grid;
    float theta=0;
    float range=0;
    std::queue<int> x_group;
    std::queue<int> y_group;
    int ctrd[2]={0,0};

    while(!mark_beam.empty())
    {
        theta=2.355+AglRbt_m+AngleIncrement*mark_beam.front();//此处的2.355为地图与机器人坐标的矫正值
//        while(1)//normalize the angle
//        {
//            if(theta>PI)
//                theta = theta-2*PI;
//            else if(theta<-PI)
//                theta =theta+2*PI;
//            else break;
//        }
        range=beams[mark_beam.front()];
        mark_beam.pop();
//        if(range>5) continue;//雷达边界附近的激光舍去 ...this code will cause running error :Floating point exception  (core dumped)

        x_grid=(range*cos(theta)/SOLUTION);//变动激光击中的点的x坐标
        y_grid=-(range*sin(theta)/SOLUTION);//变动激光击中的点的y坐标

        x_group.push(x_grid);
        y_group.push(y_grid);

        //*((int *)map +(map_x*map_y/2+map_y/2)+ (x_grid-1)*map_y + y_grid)=100;
    }
    cal_centroid(x_group,y_group,ctrd);
    *((int *)map +(map_x*map_y/2+map_y/2)+ (ctrd[0]-1)*map_y + ctrd[1])=100;
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
    centroid[0] = sum_x/num;
    centroid[1] = sum_y/num;
}
/*@des
 * @
 * @
 * @
 * */
void kalman_vel(int *coordinate)
{
}
