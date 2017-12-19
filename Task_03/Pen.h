#ifndef PEN_H_
#define PEN_H_
#include "Paper.h"

struct Pen{
	Paper *paper;
	int R, G, B;
	Pen(){ R = G = B = 255; }
	Pen(Paper *paper, int R = 255, int G = 255, int B = 255);
	int getColor(int which);
	void setColor(int R = 255, int G = 255, int B = 255);
	void drawPoint(int x, int y, int grayScale = 255);// grayScale: 0 -> 255 || 8 bit
	void mixPoint(int x, int y, int grayScale = 255);
};

#endif
