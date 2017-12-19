#ifndef BAR_H_
#define BAR_H_

#include "Interface.h"
#include "Pen.h"

struct Bar : public Interface{
	//Pen *penPointer; // 指向具体图元的指针
	Bar(Pen pen);
	Bar(Pen pen, Pen *penPointer);
	void display();
	void getColor();
	void setPenPointer(Pen *p);
	//下面是兄弟类中使用的函数
	virtual bool isSet(){}
	virtual void init(){}
	virtual void select(){}
	virtual void setTPoint(int x, int y){}
	virtual void setSPoint(int x, int y){}
};

#endif
