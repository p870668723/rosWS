#include "ros/ros.h"
#include <string.h>
#include <ros/time.h>
#include <tf/transform_broadcaster.h>
#include "std_msgs/String.h"

int main(int argc,char **argv)
{
    ros::init(argc,argv,"timer_");
    ros::NodeHandle nh;
    ros::Rate loop(10);
    ros::Publisher chatter_pub=nh.advertise<std_msgs::String>("chatter",1000);
    std_msgs::String msg;
    while(ros::ok())
    {
        char str[]="today is a good day";
        ROS_INFO("publish:%s",str);
        msg.data=str;
        //std::strcpy(&msg.data,str);
        chatter_pub.publish(msg);
        loop.sleep();
        ros::spinOnce();

    }

    return 0;
}
