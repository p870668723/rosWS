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

    int x=0,y=0;

    for(int i=0 ; i<x_total; i++)
        for(int j=0 ; j<y_total;j++)
        {

            map_copy[i][j].value = *( (int *)map + i*y_total + y );//将地图元素拷贝到一个二维数组
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
        Point_custom temp_p = points.front();
        points.pop();
        if(map_copy[temp_p.x][temp_p.y].value)
        {

        }
    }

    return regions;
}





void search_8_neighbor(Point_custom *map, Point_custom pt, int x_total, int y_total)
{
    //int x=x_total;
    //*( (Point_custom*) map + (pt->x) * y_total + pt->y + 1).value=1;
}
