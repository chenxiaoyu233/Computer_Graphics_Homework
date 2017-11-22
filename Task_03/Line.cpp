#include "Line.h"
#include "DrawAlgorithm.h"
#include "KeyPoint.h"
#include "Automaton.h"

Line::Line(Paper *paper):Shape(paper){ maxKeyNumber = 2; }
void Line::display(){
	if(!isOver()) return;
	LineAlgorithm <Pen> lin((Pen(this -> paper)));
	lin.LineBresenhamAlgorithm(key[0]->x, key[0]->y, key[1]->x, key[1]->y);
}
