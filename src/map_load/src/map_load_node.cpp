#include <ros/ros.h>
#include <nav_msgs/GetMap.h>
#include <vector>

using namespace std;

// grid map
int rows,cols;
double mapResolution;

vector<vector<char> > grid;

bool requestMap(ros::NodeHandle &nh);
void readMap(const nav_msgs::OccupancyGrid& msg);
void printGrid(void);

int main(int argc, char *argv[])
{
    ros::init(argc, argv, "load_ogm");
    ros::NodeHandle nh;

    if(!requestMap(nh))
    {
        exit(-1);
    }

    printGrid();
    return 0;
}


bool requestMap(ros::NodeHandle &nh)
{
    nav_msgs::GetMap::Request req;
    nav_msgs::GetMap::Response res;

    while(!ros::service::waitForService("static_map",ros::Duration(3.0)))
    {
        ROS_INFO("waiting for service static_map to become available");
    }

    ROS_INFO("requesting the map...");
    ros::ServiceClient mapClient = nh.serviceClient<nav_msgs::GetMap>("static_map");

    if(mapClient.call(req,res))
    {
        readMap(res.map);
        return true;
    }
    else
    {
        ROS_INFO("failed to call map service");
        return false;
    }
}

void readMap(const nav_msgs::OccupancyGrid& map)
{
    ROS_INFO("Receive a %dX%d map @%.3fm/px \n",map.info.width,map.info.height,map.info.resolution);
    rows=map.info.height;
    cols=map.info.width;
    mapResolution=map.info.resolution;

    //dynamically resice the grid
    grid.resize(rows);
    for (int i = 0; i < rows; i++)
	{
		grid[i].resize(cols);
	}
	int currCell = 0;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			grid[i][j] = map.data[currCell]; // occupied (100) or unknown cell (-1)
			//if (map.data[currCell] == 0) // unoccupied cell
			//	grid[i][j] = false;
			//else
			//	grid[i][j] = true; // occupied (100) or unknown cell (-1)
			currCell++;
		}
	}
}

void printGrid()
{
	printf("Grid map:\n");
	int freeCells = 0;
	for (int i = 0; i < rows; i++)
	{
		//printf("Row no. %d\n", i);
		for (int j = 0; j < cols; j++)
		{
			printf("%d\t ", grid[i][j]);
			//printf("%d ", grid[i][j] ? 1 : 0);
		}
		printf("\n");
	}
}

