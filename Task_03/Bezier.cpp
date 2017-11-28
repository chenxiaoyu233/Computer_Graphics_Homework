#include "Bezier.h"
#include "DrawAlgorithm.h"
#include "KeyPoint.h"
#include "Automaton.h"

Bezier::Bezier(Paper *paper):Shape(paper){ maxKeyNumber = 15; }
bool Bezier::isOver(){
	return key.size() >= maxKeyNumber || (key.size() >= 2 && key[0] == key[key.size() - 1]);
}
void Bezier::display(){
	if(key.size() < 2) return;
	BezierAlgorithm <Pen> bez((Pen(this -> paper)));
	for(int i = 0; i < (int)key.size()-1; i++){
		bez.addPoint(key[i] -> x, key[i] -> y);
	}
	if(key[key.size()-1] != key[0]) 
		bez.addPoint(key[key.size()-1] -> x, key[key.size()-1] -> y);
	bez.BezierCompute(30);
}
