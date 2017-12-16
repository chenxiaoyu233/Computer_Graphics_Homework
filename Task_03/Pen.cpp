#include "Pen.h"

int value[3][3] = {
	{1, 2, 1},
	{2, 4, 2},
	{1, 2, 1}
};

Pen::Pen(Paper *paper, int R, int G, int B):paper(paper), R(R), G(G), B(B){ }

int Pen::getColor(int which){
	switch(which){
		case 0: return R;
		case 1: return G;
		case 2: return B;
	}
	return 0;
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

void Pen::mixPoint(int x, int y, int grayScale){
	int nGrayScale = grayScale^255;
	int r = (R * grayScale) >> 8; 
	int g = (G * grayScale) >> 8; 
	int b = (B * grayScale) >> 8;
	r += ((paper -> accessPixel(x, y, 0)) * nGrayScale) >> 9;
	g += ((paper -> accessPixel(x, y, 1)) * nGrayScale) >> 9;
	b += ((paper -> accessPixel(x, y, 2)) * nGrayScale) >> 9;
	paper -> setPixel(x, y, r, g, b);
}
