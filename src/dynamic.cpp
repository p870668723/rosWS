#include <ros/ros.h>
#include <std_msgs/Header.h>
#include <sensor_msgs/Range.h>

int main(int argc, char *argv[])
{
    ros::init(argc,argv,"dynamic_detection");
    ros::NodeHandle nh;
    ROS_INFO_STREAM("test...");
    return 0;
}
