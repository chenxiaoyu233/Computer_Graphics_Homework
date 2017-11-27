#ifndef PEN_H_
#define PEN_H_
#include "Paper.h"

struct Pen{
	Paper *paper;
	int ti; // 反走样(抗锯齿)倍数
	//int R, G, B;
	Pen(Paper *paper);
	void drawPoint(int x, int y);
};

#endif
