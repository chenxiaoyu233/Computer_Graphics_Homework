#include "Circle.h"
#include "DrawAlgorithm.h"
#include "KeyPoint.h"
#include "Automaton.h"

Circle::Circle(Paper *paper):Shape(paper){ maxKeyNumber = 2; }
void Circle::display(){
	if(!isOver()) return;
	CircleAlgorithm <Pen> cir((Pen(this -> paper)));
	int dx = (key[0] -> x - key[1] -> x);
	int dy = (key[0] -> y - key[1] -> y);
	int R = sqrt(dx * dx + dy * dy);
	cir.CircleMidPoint(key[0] -> x, key[0] -> y, R);
}
