#ifndef ELLIPSE_H_
#define ELLIPSE_H_
#include "Shape.h"

struct Ellipse: public Shape{
	Ellipse(Paper *paper);
	void display();
};

#endif
