#include "Shape.h"
#include "DrawAlgorithm.h"
#include "KeyPoint.h"
#include "Automaton.h"

Shape::Shape(Paper *paper, Pen pen):paper(paper), pen(pen){ key.clear(); }
void Shape::addKey(KeyPoint *kp){ if(!isOver()) key.push_back(kp); }
bool Shape::isOver(){ return key.size() >= maxKeyNumber; }
