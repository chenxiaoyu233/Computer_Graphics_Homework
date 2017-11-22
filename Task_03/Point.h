#ifndef POINT_H_
#define POINT_H_
#include <cmath>

struct Point{
	int x, y;
	Point(int x = 0, int y = 0):x(x), y(y){}
	friend Point operator + (Point a, Point b);
	friend Point operator - (Point a, Point b);
	friend Point operator * (Point a, double b);
	friend Point operator / (Point a, double b);
};
double Dot(Point, Point);
double Cross(Point,  Point);
double Length(Point);


#endif
