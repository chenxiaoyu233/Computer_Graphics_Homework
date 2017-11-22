#ifndef CIRCLE_H_
#define CIRCLE_H_
#include "Shape.h"

struct Circle: public Shape{
	Circle(Paper *paper);
	void display();
};

#endif
