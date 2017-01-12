#ifndef REGION_GROWING_H
#define REGION_GROWING_H
#include <queue>

struct Point_custom
{
	int x;
	int y;
	bool status_search;
	int value;
	float x_vel;
	float y_vel;
	bool operator==(const Point_custom& rhs)
    {
        return( x == rhs.x) && (y == rhs.y)&& (value == rhs.value);
 
    }
};

std::queue<Point_custom> Search_region(int** map,int x_total, int y_total);
void preDealExpand(int **map,int MAP_X, int MAP_Y,int threshold);

#endif
