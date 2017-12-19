#ifndef INTERFACE_H_
#define INTERFACE_H_

#include "DrawAlgorithm.h"
#include "Pen.h"
#include "KeyPoint.h"

struct Interface{
	Pen pen;
	int Rx, Gx, Bx;
	Pen *penPointer;
	Interface(Pen pen);
	Interface(Pen pen, Pen *penPointer):pen(pen), penPointer(penPointer){}
	virtual bool isSet() = 0;
	virtual void init() = 0;
	virtual void display() = 0;
	virtual void select() = 0;
	virtual void setTPoint(int x, int y) = 0;
	virtual void setSPoint(int x, int y) = 0;

	virtual void getColor() = 0;
	virtual void setPenPointer(Pen *p) = 0;
};

#include "SelectBox.h"
#include "Bar.h"
//#include "SelectedAction.h"

#endif
