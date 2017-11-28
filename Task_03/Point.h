#ifndef POINT_H_
#define POINT_H_
#include <cmath>

extern const float pi;

template <class Type>
struct Point{
	Type x, y;
	Point(Type x = 0, Type y = 0):x(x), y(y){}
	friend Point operator + (Point a, Point b){ return Point(a.x + b.x, a.y + b.y); }
	friend Point operator - (Point a, Point b){ return Point(a.x - b.x, a.y - b.y); }
	friend Point operator * (Point a, Type b){ return Point(a.x * b, a.y * b); }
	friend Point operator / (Point a, Type b){ return Point(a.x / b, a.y / b); }
};
template <class Type>
Type Dot(Point <Type> a, Point <Type> b){ return a.x * b.x + a.y * b.y; }

template <class Type>
Type Cross(Point <Type> a,  Point <Type> b) { return a.x * b.y - a.y * b.x; }

template <class Type>
Type Length(Point <Type> a){ return sqrt(Dot(a, a)); }

template <class Type>
Point<Type> Rotate(Point <Type> a, double t){
	return Point <Type> (a.x * cos(t) - a.y * sin(t), a.x * sin(t) + a.y * cos(t));
}


#endif
