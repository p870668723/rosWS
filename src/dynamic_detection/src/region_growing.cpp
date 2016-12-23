#include <iostream>
#include <queue>
#include "math.h"
#include "region_growing.h"

using namespace std;

queue<int> Search_region(int** map,int x_total, int y_total)
{
    queue<int> regions;
    queue<Point_custom> points;
    Point_custom pnt;

    Point_custom map_copy[x_total][y_total];

    for(int i=0 ; i<x_total; i++)
        for(int j=0 ; j<y_total;j++)
        {

            map_copy[i][j].value = *( (int *)map + i*y_total + j );//将地图元素拷贝到一个二维数组
            map_copy[i][j].x = i;
            map_copy[i][j].y = j;
            map_copy[i][j].status_search=0;
        }

    //s搜索地图,找出不为零的点
    for(int i=0 ; i<x_total; i++)
        for(int j=0 ; j<y_total;j++)
        {
            if( map_copy[i][j].value )//地图元素值不为零,并标记为已经搜索.
            {
                 pnt.x=i;
                 pnt.y=j;
                 pnt.status_search=1;
                 points.push(pnt);
            }
        }

    while(!points.empty())
    {
        queue<Point_custom> region_front;//搜索前沿,里面包含待搜索的点

        Point_custom check_point;//待考察的点的周围的点,即检查这些点的值是否为占据状态;
        Point_custom temp_p;//待考察的点

        region_front.push(points.front());//搜索起始点
        points.pop();

        while(!region_front.empty()) //存在待搜索的点
        {
            temp_p=region_front.front();//取出待考察的点
            region_front.pop();

            check_point = map_copy[temp_p.x][temp_p.y+1];//search the right point
            if(check_point.value && check_point.status_search==0)
            {
                region_front.push(check_point);
                map_copy[temp_p.x][temp_p.y+1].status_search=1;
            }

            check_point = map_copy[temp_p.x-1][temp_p.y+1];//search the right top point
            if(check_point.value && check_point.status_search==0)
            {
                region_front.push(check_point);
                map_copy[temp_p.x-1][temp_p.y+1].status_search=1;
            }

            check_point = map_copy[temp_p.x-1][temp_p.y];//search the top point
            if(check_point.value && check_point.status_search==0)
            {
                region_front.push(check_point);
                map_copy[temp_p.x-1][temp_p.y].status_search=1;
            }

            check_point = map_copy[temp_p.x-1][temp_p.y-1];//search the left top point
            if(check_point.value && check_point.status_search==0)
            {
                region_front.push(check_point);
                map_copy[temp_p.x-1][temp_p.y-1].status_search=1;
            }

            check_point = map_copy[temp_p.x-1][temp_p.y];//search the left  point
            if(check_point.value && check_point.status_search==0)
            {
                region_front.push(check_point);
                map_copy[temp_p.x-1][temp_p.y].status_search=1;
            }

            check_point = map_copy[temp_p.x-1][temp_p.y-1];//search the left down point
            if(check_point.value && check_point.status_search==0)
            {
                region_front.push(check_point);
                map_copy[temp_p.x-1][temp_p.y-1].status_search=1;
            }

            check_point = map_copy[temp_p.x+1][temp_p.y];//search the down point
            if(check_point.value && check_point.status_search==0)
            {
                region_front.push(check_point);
                map_copy[temp_p.x+1][temp_p.y].status_search=1;
            }

            check_point = map_copy[temp_p.x+1][temp_p.y+1];//search the right down point
            if(check_point.value && check_point.status_search==0)
            {
                region_front.push(check_point);
                map_copy[temp_p.x+1][temp_p.y+1].status_search=1;
            }

        }
    }

    return regions;
}





void search_8_neighbor(Point_custom *map, Point_custom pt, int x_total, int y_total)
{
    //int x=x_total;
    //*( (Point_custom*) map + (pt->x) * y_total + pt->y + 1).value=1;
}
