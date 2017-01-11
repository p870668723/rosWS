#include "cal_vel.h"
#include "region_growing.h"
#include <iostream>
#include <math.h>
#include <ros/ros.h>
#include <iostream>
using namespace std;

float cal_distance(Point_custom p1, Point_custom p2, float solution)
{
    float delta_x = (p1.x-p2.x)*solution;
    float delta_y = (p1.y-p2.y)*solution;
    return sqrt(delta_x * delta_x + delta_y * delta_y);
}

/***********************************************************
 * @des
 * @mao_last 上一帧地图中的动态物体的重心点
 * @p 当前地图中的需要匹配点
 * @return 上一帧地图中匹配到的点.
 * ********************************************************/
/*
Point_custom point_match(list<Point_custom> map_last, Point_custom p)
{
    Point_custom matched_p;
    float distance=0;
    matched_p.x=0;
    matched_p.y=0;

    if(!map_last.empty())
    {
        distance = cal_distance(map_last.front(),p,0.05);
        matched_p = map_last.front();
    }
    while(!map_last.empty())
    {
        if(cal_distance(map_last.front(), p, 0.05) < distance)
        {
             matched_p = map_last.front();
             distance = cal_distance(matched_p, p, 0.05);
        }
        map_last.pop_back();
    }
    ROS_INFO("ditance: %f",distance);
    if(distance>0.5)
    {
        matched_p.x=0;
        matched_p.y=0;
        return matched_p;
    }

    return matched_p;
}
*/
Point_custom point_match(list<Point_custom> map_last, Point_custom p)//This method of point_match is better than that one above
{
    Point_custom matched_p;
    float distance=0;
    matched_p.x=0;
    matched_p.y=0;

    while(!map_last.empty() )
    {
        distance = cal_distance(map_last.front(), p, 0.05);
        if(distance < 0.3)
        {
            matched_p = map_last.front();
        }
        map_last.pop_front();
    }
    return matched_p;
}



/******************************************************************************************
 * @vx 两点的x方向的速度
 * @vy 两点的y方向的速度
 * ***************************************************************************************/
void cal_velocity(Point_custom current_p, Point_custom matched_p, float *vx, float *vy)
{
    int delta_X = current_p.x - matched_p.x;
    int delta_Y = current_p.y - matched_p.y;
    //*vx = delta_X*0.05/0.1; //换算到世界尺度下的速度
    //*vy = delta_Y*0.05/0.1;
    if(delta_X>-10 && delta_X<10)// 10格是速度的上限
        *vx = delta_X;
    if(delta_Y>-10 && delta_Y<10)
        *vy = delta_Y;
}


