#ifndef POLYGON_H_
#define POLYGON_H_
#include "Shape.h"

struct Polygon: public Shape{
	Polygon(Paper *paper);
	bool isOver();
	void display();
};

#endif
