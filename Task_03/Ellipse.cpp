#include "Ellipse.h"
#include "DrawAlgorithm.h"
#include "KeyPoint.h"
#include "Automaton.h"

Ellipse::Ellipse(Paper *paper):Shape(paper){ maxKeyNumber = 3; }
void Ellipse::display(){
	if(!isOver()) return;
	EllipseAlgorithm <Pen> ell((Pen(this -> paper)));
	ell.EllipseCompute(key[0]->x, key[0]->y, key[1]->x, key[1]->y, key[2]->x, key[2]->y, 30);
}
