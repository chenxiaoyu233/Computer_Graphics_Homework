#include "Square.h"
#include "DrawAlgorithm.h"
#include "KeyPoint.h"
#include "Automaton.h"

Square::Square(Paper *paper):Shape(paper){ maxKeyNumber = 2; }
void Square::display(){
	if(!isOver()) return;
	LineAlgorithm <Pen> lin((Pen(this -> paper)));
	Point <int> p1(key[0] -> x, key[0] -> y), p2(key[1] -> x, key[1] -> y);
	if(p1.x > p2.x) swap(p1, p2);
	lin.LineBresenhamAlgorithm(p1.x, p1.y, p2.x, p1.y);
	lin.LineBresenhamAlgorithm(p2.x, p1.y, p2.x, p2.y);
	lin.LineBresenhamAlgorithm(p2.x, p2.y, p1.x, p2.y);
	lin.LineBresenhamAlgorithm(p1.x, p2.y, p1.x, p1.y);
}
