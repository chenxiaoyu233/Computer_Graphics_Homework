#ifndef SELECT_BOX_H_
#define SELECT_BOX_H_

#include <vector>
#include "Interface.h"
using namespace std;
struct KeyPoint;

extern vector <KeyPoint*> keyPoint;
extern vector <bool> isSelected;

struct SelectBox: public Interface{
	int sx, sy; // 起点
	int tx, ty; // 终点
	bool isSeted; // 判断鼠标是否至少点击过一次
	SelectBox(Pen pen);
	bool isSet();
	void init();
	void setSPoint(int x, int y);
	void setTPoint(int x, int y);
	void display();
	void select();
};

#endif
