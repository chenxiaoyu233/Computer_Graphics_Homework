#include "Point.h"

const float pi = acos(-1);

Point operator + (Point a, Point b){ return Point(a.x + b.x, a.y + b.y); }
Point operator - (Point a, Point b){ return Point(a.x - b.x, a.y - b.y); }
Point operator * (Point a, double b){ return Point(a.x * b, a.y * b); }
Point operator / (Point a, double b){ return Point(a.x / b, a.y / b); }

double Dot(Point a, Point b){ return a.x * b.x + a.y * b.y; }
double Cross(Point a, Point b){ return a.x * b.y - a.y * b.x; }
double Length(Point a){ return sqrt(Dot(a, a)); }
Point Rotate(Point a, double t){
	return Point(a.x * cos(t) - a.y * sin(t), a.x * sin(t) + a.y * cos(t));

}
