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

template <class Pen>
class CircleAlgorithm{
	private:
		Pen pen;
		void midPointSetPixel(Point c, Point pt){
			pen.drawPoint(c.x + pt.x, c.y + pt.y);
			pen.drawPoint(c.x - pt.x, c.y + pt.y);
			pen.drawPoint(c.x + pt.x, c.y - pt.y);
			pen.drawPoint(c.x - pt.x, c.y - pt.y);
			pen.drawPoint(c.x + pt.y, c.y + pt.x);
			pen.drawPoint(c.x - pt.y, c.y + pt.x);
			pen.drawPoint(c.x + pt.y, c.y - pt.x);
			pen.drawPoint(c.x - pt.y, c.y - pt.x);
		}
	public:
		CircleAlgorithm(Pen pen):pen(pen){ }
		void CircleMidPoint(int cx, int cy, int R){
			Point c(cx, cy), pt(0, R);
			int p = 1 - R;
			while(pt.x <= pt.y){
				midPointSetPixel(c, pt);
				++ pt.x;
				if(p < 0) p = p + 2 * pt.x + 1;
				else -- pt.y, p = p + 2 * pt.x + 1 - 2 * pt.y;
			}
		}
};

#endif
