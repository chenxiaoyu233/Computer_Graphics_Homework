#include "Line.h"
#include "DrawAlgorithm.h"
#include "KeyPoint.h"
#include "Automaton.h"

Line::Line(Paper *paper):Shape(paper){ maxKeyNumber = 2; }
void Line::display(){
	if(!isOver()) return;
	pen.paper = this -> paper;
	LineAlgorithm <Pen> lin(pen);
	//cerr << pen.R << " " << pen.G << " " << pen.B << endl;
	if(curAlgorithm == mBresenham) lin.LineBresenhamAlgorithm(key[0]->x, key[0]->y, key[1]->x, key[1]->y);
	else if(curAlgorithm == mWuXiaoLin) lin.LineWuXiaoLinAlgorithm(key[0]->x, key[0]->y, key[1]->x, key[1]->y);
}
