#ifndef LINE_H_
#define LINE_H_
#include "Shape.h"

struct Line: public Shape{
	Line(Paper *paper);
	void display();
};

#endif
