#include <iostream>
#include <queue>
#include <list>
#include "math.h"
#include "region_growing.h"
#include <ros/ros.h>
using namespace std;


std::queue<Point_custom> Search_region(int** map,int x_total, int y_total)
{
    queue<Point_custom> regions_centers;

    list<Point_custom> points;
    int sum_x=0,sum_y=0,num_pt_region=0;//used for caculate the data of one region
    Point_custom map_copy[x_total][y_total];

    for(int i=0 ; i<x_total; i++)
        for(int j=0 ; j<y_total;j++)
        {
            map_copy[i][j].value = *( (int *)map + i*y_total + j );//将地图元素拷贝到一个二维数组
            map_copy[i][j].x = i;
            map_copy[i][j].y = j;
            map_copy[i][j].status_search=0;
            if( map_copy[i][j].value )                             //找出不为零的点,压入非空点集中
                points.push_back(map_copy[i][j]);
        }

    ROS_INFO("total number of points: %ld",points.size() );//test code
    //ROS_INFO("size of points : %ld",points.size());

    //对list进行分类,分类标准为:互不联通的单独成为一个组,形成一个独立的区域.
    //1.建立一个队列,
    //2.从第一个点开始搜索,搜索其四周,如果有非零点,则加入队列中,并从list中删除该非零点.
    //3.从步骤2中搜出的非零点作为新的搜索点,继续搜索其四周,重复2,3步骤
    //4.新的搜索点附近没有新的点是,则完成一个区域的搜索,计算该区域的中心值
    //5,重复步骤1

    queue<Point_custom> region_front;//搜索前沿,里面包含待搜索的点
    Point_custom region_center;     //一个区域中心
    Point_custom check_point;//待考察的点的周围的点,即检查这些点的值是否为占据状态;
    Point_custom temp_p;//待考察的点

    while(!points.empty())
    {
        region_front.push(points.front());//搜索起始点
        points.pop_front();

        while(!region_front.empty()) //存在待搜索的点
        {
            temp_p=region_front.front();//取出待考察的点
            region_front.pop();

            num_pt_region++;                        //搜索起始点一定在区域中
            sum_x+=temp_p.x;                        //add x value
            sum_y+=temp_p.y;                        //add y value

            check_point = map_copy[temp_p.x+1][temp_p.y];//search the right point
            if( find(points.begin(),points.end(),check_point) !=points.end())//该点位于points点集中
            {
                region_front.push(check_point); //将点压入新边界
                points.erase( find(points.begin(),points.end(),check_point) );     //该点已有归属,从点集中删除该点
                //ROS_INFO("R");
            }

            check_point = map_copy[temp_p.x+1][temp_p.y+1];//search the right top point
            if( find(points.begin(),points.end(),check_point) !=points.end())//该点位于points点集中
            {
                region_front.push(check_point); //将点压入新边界
                points.erase( find(points.begin(),points.end(),check_point) );     //该点已有归属,从点集中删除该点
                //ROS_INFO("RT");
            }

            check_point = map_copy[temp_p.x][temp_p.y+1];//search the top point
            if( find(points.begin(),points.end(),check_point) !=points.end())//该点位于points点集中
            {
                region_front.push(check_point); //将点压入新边界
               points.erase( find(points.begin(),points.end(),check_point) );     //该点已有归属,从点集中删除该点
                //ROS_INFO("T");
            }

            check_point = map_copy[temp_p.x-1][temp_p.y+1];//search the left top point
            if( find(points.begin(),points.end(),check_point) !=points.end())//该点位于points点集中
            {
                region_front.push(check_point); //将点压入新边界
                points.erase( find(points.begin(),points.end(),check_point) );     //该点已有归属,从点集中删除该点
                //ROS_INFO("LT");
            }

            check_point = map_copy[temp_p.x-1][temp_p.y];//search the left  point
            if( find(points.begin(),points.end(),check_point) !=points.end())//该点位于points点集中
            {
                region_front.push(check_point); //将点压入新边界
                points.erase( find(points.begin(),points.end(),check_point) );     //该点已有归属,从点集中删除该点
                //ROS_INFO("L");
            }

            check_point = map_copy[temp_p.x-1][temp_p.y-1];//search the left down point
            if( find(points.begin(),points.end(),check_point) !=points.end())//该点位于points点集中
            {
                region_front.push(check_point); //将点压入新边界
                points.erase( find(points.begin(),points.end(),check_point) );     //该点已有归属,从点集中删除该点
                //ROS_INFO("LD");
            }

            check_point = map_copy[temp_p.x][temp_p.y-1];//search the down point
            if( find(points.begin(),points.end(),check_point) !=points.end())//该点位于points点集中
            {
                region_front.push(check_point); //将点压入新边界
                points.erase( find(points.begin(),points.end(),check_point) );     //该点已有归属,从点集中删除该点
                //ROS_INFO("D");
            }

            check_point = map_copy[temp_p.x+1][temp_p.y-1];//search the right down point
            if( find(points.begin(),points.end(),check_point) !=points.end())//该点位于points点集中
            {
                region_front.push(check_point); //将点压入新边界
                points.erase( find(points.begin(),points.end(),check_point) );     //该点已有归属,从点集中删除该点
                //ROS_INFO("RD");
            }
        }
        if(num_pt_region!=0)
        {
            region_center.x=sum_x / (num_pt_region);
            region_center.y=sum_y / (num_pt_region);
            regions_centers.push(region_center);
            ROS_INFO("region points number: %d",num_pt_region);//test code
            //一个区域完成,清零,准备下一个区域搜索
            sum_x=0;
            sum_y=0;
            num_pt_region=0;
        }

    }
    return regions_centers;

}

