#include "Point.h"

double Dot(Point a, Point b){ return a.x * b.x + a.y * b.y; }
double Cross(Point a, Point b){ return a.x * b.y - a.y * b.x; }
double Length(Point a){ return sqrt(Dot(a, a)); }

Point operator + (Point a, Point b){ return Point(a.x + b.x, a.y + b.y); }
Point operator - (Point a, Point b){ return Point(a.x - b.x, a.y - b.y); }
Point operator * (Point a, double b){ return Point(a.x * b, a.y * b); }
Point operator / (Point a, double b){ return Point(a.x / b, a.y / b); }

