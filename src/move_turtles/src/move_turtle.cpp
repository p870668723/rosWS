#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
#include "turtlesim/Pose.h"

bool stop;
geometry_msgs::Twist vel;
static int flag=1;
turtlesim::Pose initial_pose;
void call_back(const turtlesim::PoseConstPtr& msg)
{
    ROS_INFO("in call back and the \"stop\" is %d",stop);
    if(flag)//将第一次的pose值保存起来.
    {
        initial_pose.x = msg->x;
        flag=0;
    }
    if((msg->x)-(initial_pose.x)>1)
    {
        stop=1;
    }
    ROS_INFO("pos_initial->x:%f",initial_pose.x);
}
int main(int argc, char *argv[])
{
    ros::init(argc,argv,"move_turtles");
    ros::NodeHandle nh;
    ros::Rate rt(1);
    ros::Publisher pub= nh.advertise<geometry_msgs::Twist>("turtle1/cmd_vel",10);
    ros::Subscriber sub=nh.subscribe("turtle1/pose",10,call_back);
    while(ros::ok())
    {
        if (stop==0)
        {
            vel.linear.x=0.2;
        }
        else
        {
            vel.linear.x=0;
            vel.angular.z=0.5;
        }

        pub.publish(vel);

        ros::spinOnce();
        rt.sleep();
    }
    return 0;
}
