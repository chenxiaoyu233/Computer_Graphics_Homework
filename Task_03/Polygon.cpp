
#include "Polygon.h"
#include "DrawAlgorithm.h"
#include "KeyPoint.h"
#include "Automaton.h"

Polygon::Polygon(Paper *paper):Shape(paper){ maxKeyNumber = -1; }
bool Polygon::isOver(){
	return key.size() > 2 && key[0] == key[(int)key.size()-1];
}
void Polygon::display(){
	if(key.size() < 2) return;
	pen.paper = this -> paper;
	LineAlgorithm <Pen> lin(pen);
	for(int i = 1; i < key.size(); i++) {
		if(curAlgorithm == mBresenham) lin.LineBresenhamAlgorithm(key[i-1] -> x, key[i-1] -> y, key[i] -> x, key[i] -> y);
		else if(curAlgorithm == mWuXiaoLin) lin.LineWuXiaoLinAlgorithm(key[i-1] -> x, key[i-1] -> y, key[i] -> x, key[i] -> y);
	}
}
