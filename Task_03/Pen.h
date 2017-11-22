#ifndef PEN_H_
#define PEN_H_
#include "Paper.h"

struct Pen{
	Paper *paper;
	Pen(Paper *paper):paper(paper){ }
	void drawPoint(int x, int y) {
		paper -> setPixel(x, y);
	}
};

#endif
