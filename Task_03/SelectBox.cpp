#include "SelectBox.h"
#include "DrawAlgorithm.h"

struct Pen;

SelectBox::SelectBox(Pen pen): Interface(pen){ 
	isSeted = false;
}

void SelectBox::init(){
	isSeted = false;
}

void SelectBox::setTPoint(int x, int y){
	tx = x, ty = y;
}
void SelectBox::setSPoint(int x, int y){
	if(isSeted) return;
	isSeted = true;
	tx = sx = x;
	ty = sy = y;
}

bool SelectBox::isSet(){
	return isSeted;
}

#include <iostream>
using namespace std;

void SelectBox::display(){
	if(!isSeted) return;
	LineAlgorithm <Pen> lin((pen));
	lin.LineBresenhamAlgorithm(sx, sy, tx, sy);
	lin.LineBresenhamAlgorithm(tx, sy, tx, ty);
	lin.LineBresenhamAlgorithm(tx, ty, sx, ty);
	lin.LineBresenhamAlgorithm(sx, ty, sx, sy);
}

extern int isAddingSelect;
void SelectBox::select(){
	if(!isAddingSelect) {
		for(int i = 0; i < isSelected.size(); i++){
			isSelected[i] = false;
		}
	}
	int lx = min(sx, tx), rx = max(sx, tx);
	int ly = min(sy, ty), ry = max(sy, ty);
	for(int i = 0; i < keyPoints.size(); i++){
		if(keyPoints[i] -> x < lx || keyPoints[i] -> x > rx) continue;
		if(keyPoints[i] -> y < ly || keyPoints[i] -> y > ry) continue;
		isSelected[i] = true;
	}
	for(int i = 0; i < keyPoints.size(); i++){
		if(keyPoints[i] -> isIn(sx, sy)){
			isSelected[i] = true;
		}
	}
}
