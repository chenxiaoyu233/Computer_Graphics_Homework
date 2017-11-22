#ifndef DRAW_ALGORITHM_H_
#define DRAW_ALGORITHM_H_
#include "Automaton.h"
#include <cmath>

struct Point{
	int x, y;
	Point(int x = 0, int y = 0):x(x), y(y){}
	friend Point operator + (const Point &a, const Point &b){ return Point(a.x + b.x, a.y + b.y); }
	friend Point operator - (const Point &a, const Point &b){ return Point(a.x - b.x, a.y - b.y); }
	friend Point operator * (const Point &a, double b){ return Point(a.x * b, a.y * b); }
	friend Point operator / (const Point &a, double b){ return Point(a.x / b, a.y / b); }
};
double Dot(const Point &a, const Point &b){ return a.x * b.x + a.y * b.y; }
double Cross(const Point &a, const Point &b){ return a.x * b.y - a.y * b.x; }
double Length(const Point &a){ return sqrt(Dot(a, a)); }

template <class type>
void swap(type &a, type &b) { type t = a; a = b, b = t;}

#include "CircleAlgorithm.h"
#include "LineAlgorithm.h"


#endif
