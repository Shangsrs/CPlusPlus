#ifndef CONVERHULL_H
#define CONVERHULL_H
#include "listAlgorithm.h"

struct Point
{
	int _x;
	int _y;
    Point(int x,int y):_x(x),_y(y){}
    Point():_x(0),_y(0){}
	bool operator!=(Point pt)
	{
		return (_x!=pt._x) || (_y!=pt._y);
    }
};



ChainList<Point>* createPoints(int number)
{
	ChainList<Point> *ptList = new ChainList<Point>;
    srand((unsigned)time(0));
    srand(rand());
    srand(rand());
    for(int i=0;i<number;i++)
	{
        int x = rand()%450+25;
        int y = rand()%450+25;
		Point *pt = new Point(x,y);
		ptList->insert(0,*pt);
	}
	return ptList;
}

#endif
