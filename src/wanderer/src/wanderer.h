#include "ros/ros.h"
#include "sensor_msgs/LaserScan.h"

#define turn_r 2
#define turn_l 3
class Stopper
{
public:
    const static double FORWARD_SPEED_MPS=0.5;
    const static double MIN_SCAN_ANGLE_RAD = -30.0/180*M_PI;
    const static double MAX_SCAN_ANGLE_RAD = +30.0/180*M_PI;
    const static double MIN_PROXIMITY_RANGE_M = 0.5;// Should be smaller than sensor_msgs::LaserScan::range_max

    Stopper();
    void startMoving();
private:
    ros::NodeHandle node;
    ros::Publisher commandPub;
    ros::Subscriber laserSub;
    int keepMoving;

    void moveForward();
	void turnRight();
	void turnLeft();
    void scanCallback(const sensor_msgs::LaserScan::ConstPtr& scan);
};
