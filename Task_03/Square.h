#ifndef SQUARE_H_
#define SQUARE_H_
#include "Shape.h"
struct Square: public Shape{
	Square(Paper *paper);
	void display();
};

#endif
