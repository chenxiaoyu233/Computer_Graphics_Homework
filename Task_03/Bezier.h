#ifndef BEZIER_H_
#define BEZIER_H_
#include "Shape.h"

struct Bezier: public Shape{
	Bezier(Paper *paper);
	bool isOver();
	void display();
};

#endif
