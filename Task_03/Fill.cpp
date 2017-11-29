#include "Fill.h"
#include "DrawAlgorithm.h"
#include "KeyPoint.h"
#include "Automaton.h"

Fill::Fill(Paper *paper):Shape(paper){ maxKeyNumber = 1; }
void Fill::display(){
	if(!isOver()) return;
	FillAlgorithm <Pen> fil((Pen(this -> paper)));
	fil.FillFloodAlgorithm(key[0] -> x, key[0] -> y);
}
