#include "Circle.h"
#include "DrawAlgorithm.h"
#include "KeyPoint.h"
#include "Automaton.h"

Circle::Circle(Paper *paper):Shape(paper){ maxKeyNumber = 2; }
void Circle::display(){
	if(!isOver()) return;
	pen.paper = this -> paper;
	CircleAlgorithm <Pen> cir(pen);
	int dx = (key[0] -> x - key[1] -> x);
	int dy = (key[0] -> y - key[1] -> y);
	int R = sqrt(dx * dx + dy * dy);
	if(curAlgorithm == mBresenham) cir.CircleMidPoint(key[0] -> x, key[0] -> y, R);
	if(curAlgorithm == mWuXiaoLin) cir.CircleWuXiaoLinAlgorithm(key[0] -> x, key[0] -> y, R);
}
