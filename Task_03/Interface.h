#ifndef INTERFACE_H_
#define INTERFACE_H_

#include "DrawAlgorithm.h"
#include "Pen.h"
#include "KeyPoint.h"

struct Interface{
	Pen pen;
	Interface(Pen pen);
	virtual bool isSet() = 0;
	virtual void init() = 0;
	virtual void display() = 0;
	virtual void select() = 0;
	virtual void setTPoint(int x, int y) = 0;
	virtual void setSPoint(int x, int y) = 0;
};

#include "SelectBox.h"
//#include "Bar.h"
//#include "SelectedAction.h"

#endif
