#ifndef SHAPE_H_
#define SHAPE_H_
#include <vector>
#include "Pen.h"
#include <cmath>
using namespace std;

struct KeyPoint;

struct Shape{
	Paper *paper;
	Pen pen;
	vector <KeyPoint*> key;
	int maxKeyNumber;
	Shape(Paper *paper, Pen pen = Pen());
	virtual bool isOver();
	virtual void display() = 0;
	void addKey(KeyPoint *kp);
};

#include "Circle.h"
#include "Line.h"
#include "Square.h"
#include "Polygon.h"
#include "Bezier.h"
#include "Ellipse.h"
#include "Fill.h"

#endif
