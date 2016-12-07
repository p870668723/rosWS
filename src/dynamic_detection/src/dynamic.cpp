#include <ros/ros.h>
#include <std_msgs/Header.h>
#include <sensor_msgs/Range.h>
#include <sensor_msgs/LaserScan.h>
#include <unistd.h>
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <time.h>
#include <queue>

#define BEAM_THRESH 0.1
#define BEAMS 1080
sensor_msgs::LaserScan LaserMsg;

void data_substract(const sensor_msgs::LaserScan& msg);
void pthread_publish(void);
std::queue<int> beam_substract(float *minuend,float * subtrahend,int n );//激光束对应的beam作差,如果超过阈值,则认为有动态物体.

time_t tm;
float scan_data[11][1081];
static int i=0;

//主函数.订阅"/Base_Scan".
int main(int argc, char *argv[])
{
    ros::init(argc,argv,"dynamic_detection");
    ros::NodeHandle nh;
    ROS_INFO_STREAM("test...");



    ros::Publisher pub=nh.advertise<sensor_msgs::LaserScan>("/substracted",1000);
    ros::Subscriber sub=nh.subscribe("/base_scan",1000,&data_substract);

    ros::Rate rate(2);
    while(ros::ok())
    {
        LaserMsg.scan_time=0;
        pub.publish(LaserMsg);
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
    //ROS_INFO("range[]: %f",msg.ranges[1080]);
    //ROS_INFO("ANGLE_MAX: %f",(msg.angle_max-msg.angle_min)/msg.angle_increment);
    //ROS_INFO("ANGLE_MIN: %f",msg.angle_min);
    //ROS_INFO("ANGLE_INCRE: %f",msg.angle_increment);
    for(int j=0;j<1081;j++)
    {
        scan_data[i][j] = msg.ranges[j];
    }
    i++;
    if(i>10) {i=0;}
    if(i==10) { mark_beam = beam_substract(scan_data[10],scan_data[0],BEAMS);}
    else mark_beam = beam_substract(scan_data[i],scan_data[i+1],BEAMS);

    if(!mark_beam.empty())
    ROS_INFO("MARKED_BEAM: %d",mark_beam.front());
}



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

//独立线程来发布
void pthread_publish(void)
{
}
