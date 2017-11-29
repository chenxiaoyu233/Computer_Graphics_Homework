#include "KeyPoint.h"

const int KeyPointSize = 11;

void KeyPoint::setPos(int x, int y){
	this -> x = x, this -> y = y;
}

void KeyPoint::display(){
	CircleAlgorithm <Pen> cir((Pen(this -> paper)));
	if(curAlgorithm == mBresenham) cir.CircleMidPoint(x, y, KeyPointSize);
	else if(curAlgorithm == mWuXiaoLin) cir.CircleWuXiaoLinAlgorithm(x, y, KeyPointSize);
}

bool KeyPoint::isIn(int x, int y){
	int X = x - this -> x;
	int Y = y - this -> y;
	return KeyPointSize * KeyPointSize >= X*X + Y*Y;
}
