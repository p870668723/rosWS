#include "wanderer.h"
#include "geometry_msgs/Twist.h"
Stopper::Stopper()
{
	keepMoving = true;
	// Advertise a new publisher for the robot's velocity command topic
	commandPub = node.advertise<geometry_msgs::Twist>("cmd_vel", 10);
	// Subscribe to the simulated robot's laser scan topic
	laserSub = node.subscribe("base_scan", 1, &Stopper::scanCallback, this);
}
// Send a velocity command
void Stopper::moveForward()
{
	geometry_msgs::Twist msg; // The default constructor will set all commands to 0
	msg.linear.x = FORWARD_SPEED_MPS;
	commandPub.publish(msg);
}

void Stopper::turnRight()
{
	geometry_msgs::Twist msg; // The default constructor will set all commands to 0
	msg.angular.z = -FORWARD_SPEED_MPS;
	commandPub.publish(msg);
}
void Stopper::turnLeft()
{
	geometry_msgs::Twist msg; // The default constructor will set all commands to 0
	msg.angular.z = FORWARD_SPEED_MPS;
	commandPub.publish(msg);
}

// Process the incoming laser scan message
void Stopper::scanCallback(const sensor_msgs::LaserScan::ConstPtr& scan)
{
	// Find the closest range between the defined minimum and maximum angles
	// pf: float32 angle_min        # start angle of the scan
	// pf: float32 angle_max        # end angle of the scan
	// pf: float32 angle_increment  # angular distance between measurements
	int minIndex = ceil((MIN_SCAN_ANGLE_RAD - scan->angle_min) / scan->angle_increment);
	int maxIndex = floor((MAX_SCAN_ANGLE_RAD - scan->angle_min) / scan->angle_increment);
	float closestRange = scan->ranges[minIndex];
	for (int currIndex = minIndex + 1; currIndex <= maxIndex; currIndex++)
	{
		if (scan->ranges[currIndex] < closestRange)
		{
			closestRange = scan->ranges[currIndex];
		}
	}
	ROS_INFO_STREAM("Closest range: " << closestRange);
	if (closestRange < MIN_PROXIMITY_RANGE_M)
	{
		ROS_INFO("turnRight!");
		keepMoving = turn_r;
	}
    else if (closestRange < MIN_PROXIMITY_RANGE_M)
	{
		ROS_INFO("turnLeft!");
		keepMoving = turn_l;
	}
    else if(closestRange > MIN_PROXIMITY_RANGE_M)
    {
        ROS_INFO("moveForward!");
        keepMoving=true;
    }

}
void Stopper::startMoving()
{
	ros::Rate rate(10);
	ROS_INFO("Start moving");
// Keep spinning loop until user presses Ctrl+C or the robot got tooclose to an obstacle
	while(1)
    {

    while (ros::ok() && (keepMoving==1))
	{
		moveForward();
		ros::spinOnce(); // Need to call this function often to allow ROS to process incoming messages
		rate.sleep();
	}
    while(ros::ok() && (keepMoving==turn_r))
    {
		turnRight();
		ros::spinOnce(); // Need to call this function often to allow ROS to process incoming messages
		rate.sleep();
	}
    while(ros::ok() && (keepMoving==turn_l))
    {
        turnLeft();
        ros::spinOnce();
        rate.sleep();
    }

   }
}
