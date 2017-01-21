#include <iostream>
#include <ros/ros.h>
#include <serial/serial.h>
#include <std_msgs/String.h>
#include <std_msgs/Empty.h>
#include <geometry_msgs/Twist.h>
#include <stdlib.h>
using namespace std;

serial::Serial ser;

void write_callback(const std_msgs::String::ConstPtr& msg)
{
    ROS_INFO_STREAM("Writing to serial port"<<msg->data);
    ser.write(msg->data);
}
int main(int argc, char *argv[])
{
    ros::init(argc,argv,"serial_example_node");
    ros::NodeHandle nh;
    geometry_msgs::Twist vel;

    ros::Subscriber write_sub=nh.subscribe("write",1,write_callback);
    ros::Publisher read_pub=nh.advertise<std_msgs::String>("read",1);
    ros::Publisher vel_pub=nh.advertise<geometry_msgs::Twist>("/cmd_vel",1);
    srand(time(0));
    try
    {
        ser.setPort("/dev/ttyUSB0");
        ser.setBaudrate(115200);
        serial::Timeout to = serial::Timeout::simpleTimeout(1000);
        ser.setTimeout(to);
        ser.open();
    }
    catch(serial::IOException& e)
    {
        ROS_ERROR("Unable to open port");
        ROS_INFO("err: %s",e.what());
        return -1;
    }
    if(ser.isOpen())
    {
        ROS_INFO("Serial Port Initialized");
    }
    else return -1;

    ros::Rate rate(100);

    while(ros::ok())
    {
        if(ser.available())
        {
            //ROS_INFO("Reading from serial port\n");
            std_msgs::String result;
            result.data = ser.read(ser.available());
            if(result.data.size()==12)
                for(int i=0;i<(int)result.data.size();i++)
                {
                    ROS_INFO("data[%d]:  %d",i,result.data[i]);
                    vel.linear.x=result.data[2]-0x30+double(rand())/double(RAND_MAX);
                    vel.linear.y=result.data[6]-0x30+double(rand())/double(RAND_MAX);
                    vel.angular.z=result.data[10]-0x30+double(rand())/double(RAND_MAX);
                    ROS_INFO("x:%f",vel.linear.x);
                    ROS_INFO("y:%f",vel.linear.y);
                    ROS_INFO("z:%f",vel.angular.z);
                }
            read_pub.publish(result);
            vel_pub.publish(vel);
        }
        ros::spinOnce();
        rate.sleep();
    }
    return 0;
}
