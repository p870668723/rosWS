#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
    ros::init(argc, argv, "cmd_line");
    ros::NodeHandle nh;
    ROS_INFO("***************CMD_LINE****************");

    ros::Publisher line_vel = nh.advertise<geometry_msgs::Twist>("/cmd_vel",1);
    geometry_msgs::Twist vel;

    vel.linear.x = atof(argv[1]);
    //ROS_INFO("argv[1]: %f",atof(argv[1]));
    vel.linear.y = 0;
    ros::Rate rate(10);
    while(ros::ok())
    {
        line_vel.publish(vel);
        ROS_INFO("SNED CMD_VEL ...");
        rate.sleep();
    }
    return 0;
}
