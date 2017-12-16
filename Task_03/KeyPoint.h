#ifndef KEY_POINT_H_
#define KEY_POINT_H_

#include "Paper.h"
#include "Pen.h"
#include "DrawAlgorithm.h"

extern const int KeyPointSize;

struct KeyPoint{
	int x, y;
	Paper *paper;
	KeyPoint(int x, int y, Paper *paper):x(x), y(y), paper(paper){ }
	bool isIn(int x, int y);
	void setPos(int x, int y);
	void display();
	void display(int R, int G, int B);
};

#endif
