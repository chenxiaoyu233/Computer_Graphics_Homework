#ifndef PEN_H_
#define PEN_H_
#include "Paper.h"

struct Pen{
	Paper *paper;
	int R, G, B;
	Pen(Paper *paper);
	void setColor(int R, int G, int B);
	void drawPoint(int x, int y, int grayScale = 255);// grayScale: 0 -> 255 || 8 bit
};

#endif
