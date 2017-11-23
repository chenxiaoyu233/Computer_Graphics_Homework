
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
	LineAlgorithm <Pen> lin((Pen(this -> paper)));
	for(int i = 1; i < key.size(); i++) {
		lin.LineBresenhamAlgorithm(key[i-1] -> x, key[i-1] -> y, key[i] -> x, key[i] -> y);
	}
}
