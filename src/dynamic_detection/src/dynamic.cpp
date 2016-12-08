#include <ros/ros.h>
#include <std_msgs/Header.h>
#include <sensor_msgs/Range.h>
#include <sensor_msgs/LaserScan.h>
#include <map_msgs/ProjectedMap.h>
#include <nav_msgs/OccupancyGrid.h>
#include <geometry_msgs/Pose.h>
#include <unistd.h>
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <time.h>
#include <queue>
#include <vector>


#define BEAM_THRESH 0.1
#define BEAMS 1080
#define MAX_RANGE 6
#define SOLUTION 0.05
#define map_x 120
#define map_y 120

/********************************普通函数声明*****************************************/
/*************************************************************************************/
void data_substract(const sensor_msgs::LaserScan& msg);
void pthread_publish(void);
std::queue<int> beam_substract(float *minuend,float * subtrahend,int n );//激光束对应的beam作差,如果超过阈值,则认为有动态物体.
void map_update(float *beams, std::queue<int> mark_beam);//地图更新函数,根据mark_beam来跟新动态物体的位置

/********************************全局变量声明*****************************************/
/*************************************************************************************/
time_t tm;
float scan_data[11][1081];      //一共保存11帧数据,每组数据有1081个beams.
static int frames=0;            //静态数据
nav_msgs::OccupancyGrid Map_Msg;//栅格地图消息
geometry_msgs::Pose RobotCenter;//地图中心
int map[map_x][map_y];          //地图数组



int main(int argc, char *argv[])
{
    //测试地图
    for (int i=0; i < map_x; i++)
    {
        for(int j=0; j<map_y; j++)
        {
            map[i][j]=0;
        }
    }
    std::vector<signed char> VMap(*map,*map+(map_x*map_y));//将数组地图转化为向量,用以发布消息的赋值.
    //地图中心初始化
    RobotCenter.position.x=-3;
    RobotCenter.position.y=-3;
    RobotCenter.orientation.z=0;
    //地图信息配置
    Map_Msg.info.width=map_x;
    Map_Msg.info.height=map_y;
    Map_Msg.info.resolution=0.05;
    Map_Msg.info.origin=RobotCenter;
    Map_Msg.data=VMap;


    ros::init(argc,argv,"dynamic_detection");
    ros::NodeHandle nh;
    ROS_INFO("***********START*************");

    ros::Publisher pub=nh.advertise<nav_msgs::OccupancyGrid>("/substracted",1000);
    ros::Subscriber sub=nh.subscribe("/base_scan",1000,&data_substract);

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
    ROS_INFO("TIME: %ld",tm);

    for(int j=0;j<1081;j++)
    {
        scan_data[frames][j] = msg.ranges[j];
    }
    frames++;
    if(frames>10) {frames=0;}
    if(frames==10) { mark_beam = beam_substract(scan_data[10],scan_data[0],BEAMS);}
    else mark_beam = beam_substract(scan_data[frames],scan_data[frames+1],BEAMS);

    if(!mark_beam.empty())
    {
        ROS_INFO("MARKED_BEAM: %d",mark_beam.front());
        /*调用地图更新函数*/
    }


}




/******************************普通函数************************************/
//两帧激光束之间作差函数,
std::queue<int> beam_substract(float *minuend,float * subtrahend,int n )
{
    std::queue<int> marked_beam;

    for(int i=0;i<n;i++)
    {
      float result=  minuend[i]-subtrahend[i];
      if(result>BEAM_THRESH)
      {
          marked_beam.push(i);
      }
    }
    return marked_beam;
}

//地图更新函数
void map_update(float *beams, std::queue<int> mark_beam)
{

}

//独立线程来发布
void pthread_publish(void)
{
}
