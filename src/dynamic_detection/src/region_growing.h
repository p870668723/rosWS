#ifndef REGION_GROWING_H
#define REGION_GROWING_H

typedef struct pt
{
	int x;
	int y;
	bool status_search;
	int value;
}
Point_custom;

void search_8_neighbor();
queue<int> Search_region(int** map,int x_total, int y_total);

#endif
