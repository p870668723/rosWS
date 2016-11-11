#include "std_msgs/String.h"
#include "ros/ros.h"

void call_back(const std_msgs::String::ConstPtr& msg)
{
    ROS_INFO("I heard %s",msg->data.c_str());
}
int main(int argc, char **argv)
{
    ros::init(argc,argv,"subscribe");
    ros::NodeHandle nh;

    ros::Subscriber sub= nh.subscribe("chatter",1000,call_back);
    ros::spin();
    return 0;
}
