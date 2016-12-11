#include <ros/ros.h>
#include <std_msgs/Header.h>
#include <sensor_msgs/Range.h>
#include <sensor_msgs/LaserScan.h>
#include <map_msgs/ProjectedMap.h>
#include <nav_msgs/OccupancyGrid.h>
#include <nav_msgs/Odometry.h>
#include <geometry_msgs/Pose.h>
#include <unistd.h>
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <time.h>
#include <queue>
#include <vector>
#include <math.h>

#define BEAM_THRESH 0.05
#define BEAMS 1080
#define MAX_RANGE 6
#define SOLUTION 0.1
#define map_x 120
#define map_y 120

/********************************话题订阅回调函数声明*****************************************/
/*************************************************************************************/
void data_substract(const sensor_msgs::LaserScan& msg);
void rbtPose(const nav_msgs::Odometry& rvtPs);

/********************************普通函数声明*****************************************/
/*************************************************************************************/
void data_substract(const sensor_msgs::LaserScan& msg);
void rbtPose(const nav_msgs::Odometry& rvtPs);

void pthread_publish(void);
std::queue<int> beam_substract(float *minuend,float * subtrahend,int n );//激光束对应的beam作差,如果超过阈值,则认为有动态物体.
void map_update(int **map,float *beams, std::queue<int> mark_beam);//地图更新函数,根据mark_beam来跟新动态物体的位置

/********************************全局变量声明*****************************************/
/*************************************************************************************/
time_t tm;
float scan_data[11][1081]={{0}};      //一共保存11帧数据,每组数据有1081个beams.
static int frames=0;            //静态数据
nav_msgs::OccupancyGrid Map_Msg;//栅格地图消息
geometry_msgs::Pose RobotCenter;//地图中心,应该定义为机器人的中心
int map[map_x][map_y];          //地图数组
float AngleIncrement;


int main(int argc, char *argv[])
{
    ros::init(argc,argv,"dynamic_detection");
    ros::NodeHandle nh;
    ROS_INFO("***********START*************");

    ros::Publisher pub=nh.advertise<nav_msgs::OccupancyGrid>("/substracted",1000);
    ros::Subscriber sub=nh.subscribe("/base_scan",1000,&data_substract);
    ros::Subscriber robot_pose=nh.subscribe("/odom",1000,&rbtPose);
    ros::Rate rate(2);
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
    for(int j=0;j<1081;j++)
    {
        scan_data[frames][j] = msg.ranges[j];
    }
    frames++;
    if(frames>10) {frames=0;}
    //激光束作差
    if(frames==10) { mark_beam = beam_substract(scan_data[10],scan_data[0],BEAMS);}
    else mark_beam = beam_substract(scan_data[frames],scan_data[frames+1],BEAMS);

    for(int i=0;i<14400;i++)
    {
        *((int*)map+i)=0;
    }
    if(!mark_beam.empty())
    {
        ROS_INFO("MARKED_BEAM: %d",mark_beam.front());
        mark_beam.pop();
        /*调用地图更新函数*/
        map_update((int **)map,*(scan_data+frames),(std::queue<int>)mark_beam);
    }

    std::vector<signed char> VMap(*map,*map+(map_x*map_y));//将数组地图转化为向量,用以发布消息的赋值.
    Map_Msg.data=VMap;//
}

//订阅机器人位姿的回调函数.
void rbtPose(const nav_msgs::Odometry& rbtPs)
{
    //地图中心初始化
    RobotCenter.position.x=rbtPs.pose.pose.position.x+3;
    RobotCenter.position.y=rbtPs.pose.pose.position.y+3;
    RobotCenter.orientation.z=rbtPs.pose.pose.orientation.z;
    //地图信息配置
    Map_Msg.info.width=map_x;
    Map_Msg.info.height=map_y;
    Map_Msg.info.resolution=0.05;
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
      if(result>BEAM_THRESH || result<-BEAM_THRESH)
      {
          marked_beam.push(i);
      }
    }
    return marked_beam;
}

//地图更新函数
void map_update(int **map,float *beams, std::queue<int> mark_beam)
{
    int x_grid;
    int y_grid;
    float theta=0;
    float range=0;
    while(1)
    {
        if(!mark_beam.empty())
        {
            theta=AngleIncrement*mark_beam.front();
            range=beams[mark_beam.front()];
            mark_beam.pop();
            x_grid=range*cos(theta)/SOLUTION;//变动激光击中的点的x坐标
            y_grid=range*sin(theta)/SOLUTION;//变动激光击中的点的y坐标
            //for(int i=0;i<14400;i++)
            //*((int *)map+i)=0;

            *((int *)map +(map_x*map_y/2+map_y/2)+ (x_grid-1)*map_y + y_grid)=100;

        }
        else break;
    }
}

//独立线程来发布
void pthread_publish(void)
{
}
