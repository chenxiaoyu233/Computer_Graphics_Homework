#include "Menu.h"
#include "Automaton.h"

void processMenuEvents(int option) {
	switch(option){
		case mKeyPoint:
			isAddingKeyPoint = 1;
			break;
		case mNormal:
			if(curState == mSelect){
				interface.erase(interface.end()-1, interface.end());
				delete curInterface;
				curInterface = NULL;
				isAddingSelect = 0;
			}
			if(curState >= mLine && curState <= mFlood){
				shape.erase(shape.end()-1, shape.end());
				delete curShape;
				curShape = NULL;
				isAddingKeyPoint = 0;
			}
			curState = mNormal;
			isAddingKeyPoint = 0;
			break;
		case mBresenham:
			curAlgorithm = mBresenham;
			break;
		case mWuXiaoLin:
			curAlgorithm = mWuXiaoLin;
			isAddingKeyPoint = 1;
			break;
		case mLine: 
			curState = mLine; 
			curShape = new Line(paper);
			shape.push_back(curShape);
			isAddingKeyPoint = 1;
			break;
		case mCircle:
			curState = mCircle;
			curShape = new Circle(paper);
			shape.push_back(curShape);
			isAddingKeyPoint = 1;
			break;
		case mSquare:
			curState = mSquare;
			curShape = new Square(paper);
			shape.push_back(curShape);
			isAddingKeyPoint = 1;
			break;
		case mPolygon:
			curState = mPolygon;
			curShape = new Polygon(paper);
			shape.push_back(curShape);
			isAddingKeyPoint = 1;
			break;
		case mBezier:
			curState = mBezier;
			curShape = new Bezier(paper);
			shape.push_back(curShape);
			isAddingKeyPoint = 1;
			break;
		case mEllipse:
			curState = mEllipse;
			curShape = new Ellipse(paper);
			shape.push_back(curShape);
			isAddingKeyPoint = 1;
			break;
		case mFlood:
			curState = mFlood;
			curShape = new Fill(paper);
			shape.push_back(curShape);
			isAddingKeyPoint = 1;
			break;
		case mSelect:
			isAddingKeyPoint = 0;
			curState = mSelect;
			curInterface = new SelectBox(Pen(paper, 255, 0, 0));
			interface.push_back(curInterface);
			break;
		case mDel: // 这两个东西本质相同
		case mEraser:
			deleteKeyPoint();
			break;
		default: curState = mNormal;
	}
}

void createGLUTMenus() {
	int menu, mFile, mEdit, mTools, mFill, mAntialiase;
         mFile = glutCreateMenu(processMenuEvents);
         glutAddMenuEntry("新建", mNew);
         glutAddMenuEntry("打开", mOpen);
         glutAddMenuEntry("关闭", mClose);
         glutAddMenuEntry("保存", mSave);

	 mEdit = glutCreateMenu(processMenuEvents);
	 glutAddMenuEntry("普通模式", mNormal);
	 glutAddMenuEntry("添加关键点", mKeyPoint);
	 glutAddMenuEntry("选择", mSelect);
	 //glutAddMenuEntry("拷贝", mCopy);
	 //glutAddMenuEntry("粘贴", mPaste);
	 glutAddMenuEntry("删除", mDel);

	 mFill = glutCreateMenu(processMenuEvents);
	 glutAddMenuEntry("扫描线填充", mScan);
	 glutAddMenuEntry("边界填充", mEdge);
	 glutAddMenuEntry("洪泛填充", mFlood);

	 mAntialiase = glutCreateMenu(processMenuEvents);
	 glutAddMenuEntry("Bresenham算法", mBresenham);
	 glutAddMenuEntry("WuXiaoLin算法", mWuXiaoLin);

	 mTools = glutCreateMenu(processMenuEvents);
	 glutAddMenuEntry("线段", mLine);
	 glutAddMenuEntry("矩形", mSquare);
	 glutAddMenuEntry("多边形", mPolygon);
	 glutAddMenuEntry("圆形", mCircle);
	 glutAddMenuEntry("椭圆形", mEllipse);
	 glutAddMenuEntry("Bezier曲线", mBezier);
	 glutAddSubMenu("填充", mFill);
	 glutAddMenuEntry("擦子", mEraser);
	 glutAddSubMenu("抗锯齿", mAntialiase);

         menu = glutCreateMenu(processMenuEvents);
	 glutAddSubMenu("文件", mFile);
	 glutAddSubMenu("编辑", mEdit);
	 glutAddSubMenu("工具", mTools);
         glutAttachMenu(GLUT_RIGHT_BUTTON);
}

