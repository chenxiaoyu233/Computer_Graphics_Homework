#ifndef FILL_H_
#define FILL_H_
#include "Shape.h"

struct Fill: public Shape{
	Fill(Paper *paper);
	void display();
};

#endif
