#include "Pen.h"

int value[3][3] = {
	{1, 2, 1},
	{2, 4, 2},
	{1, 2, 1}
};

Pen::Pen(Paper *paper):paper(paper){ 
	R = G = B = 255;
}
void Pen::setColor(int R, int G, int B){
	this -> R = R;
	this -> G = G;
	this -> B = B;
}
void Pen::drawPoint(int x, int y, int grayScale){ 
	int r = (R * grayScale) >> 8;
	int g = (G * grayScale) >> 8;
	int b = (B * grayScale) >> 8;
	paper -> setPixel(x, y, r, g, b);
}
