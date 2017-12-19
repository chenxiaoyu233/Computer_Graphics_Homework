#include "Bar.h"
#include "DrawAlgorithm.h"

Bar::Bar(Pen pen):Interface(pen){
	penPointer = NULL;
	Rx = 100;
	Gx = 200;
	Bx = 255;
}
Bar::Bar(Pen pen, Pen *penPointer):Interface(pen, penPointer){
	getColor();
}
#include <iostream>
using namespace std;
void Bar::getColor(){
	if(penPointer == NULL) return;
	Rx = penPointer -> R;
	Gx = penPointer -> G;
	Bx = penPointer -> B;
}
void Bar::setPenPointer(Pen *p){
	penPointer = p;
}

extern int winWidth, winHeigth;
extern int isSettingColor;
void Bar::display(){
	if(!isSettingColor) return;
	pen.setColor(255, 255, 255);
	LineAlgorithm <Pen> lin((pen));
	FillAlgorithm <Pen> fil((pen));

	pen.setColor(100, 100, 100);
	for(int i = 0; i < 90 + 255; i++)
		for(int j = 0; j < 90; j++)
			pen.drawPoint(i, j);

	lin.LineBresenhamAlgorithm(0, 90, 90 + 255, 90);
	lin.LineBresenhamAlgorithm(89, 0, 89, 90);
	lin.LineBresenhamAlgorithm(90 + 255, 0, 90 + 255, 90);

	fil.pen.setColor(0, 0, 255);
	lin.LineBresenhamAlgorithm(90, 30, 90 + 255, 30);
	lin.LineBresenhamAlgorithm(Bx + 90, 0, Bx + 90, 30);
	fil.FillFloodAlgorithm(90, 30-1);

	fil.pen.setColor(0, 255, 0);
	lin.LineBresenhamAlgorithm(90, 60, 90 + 255, 60);
	lin.LineBresenhamAlgorithm(Gx + 90, 30, Gx + 90, 60);
	fil.FillFloodAlgorithm(90, 60-1);

	fil.pen.setColor(255, 0, 0);
	lin.LineBresenhamAlgorithm(90, 90, 255, 90);
	lin.LineBresenhamAlgorithm(Rx + 90, 60, Rx + 90, 90);
	fil.FillFloodAlgorithm(90, 90-1);


	fil.pen.setColor(Rx, Gx, Bx);
	fil.FillFloodAlgorithm(0, 0);

	if(penPointer != NULL){
		penPointer -> setColor(Rx, Gx, Bx);
	}
}
