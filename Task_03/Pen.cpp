#include "Pen.h"

int value[3][3] = {
	{1, 2, 1},
	{2, 4, 2},
	{1, 2, 1}
};

Pen::Pen(Paper *paper):paper(paper){ ti = 3;}
void Pen::drawPoint(int x, int y){
	paper -> setPixel(x, y);
}
