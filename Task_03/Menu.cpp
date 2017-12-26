#include "Menu.h"
#include "Automaton.h"

void processMenuEvents(int option) {
	switch(option){
		case mSave:
			write_JPEG_file("新文档.jpeg", 
					100, 
					paper-> Width,
				       	paper -> Height,
				       	paper -> paper);
			break;
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
			curColorBar -> penPointer = NULL;
			break;
		case mColorTable:
			isSettingColor ^= 1;
			break;
		case mColorAttach:
			ColorAttach();
			break;
		case mClose:
			exit(0);
			break;
		default: curState = mNormal;
	}
}

void createGLUTMenus() {
	int menu, mFile, mEdit, mTools, mFill, mAntialiase;
         mFile = glutCreateMenu(processMenuEvents);
         glutAddMenuEntry("新建(未实现)", mNew);
         glutAddMenuEntry("打开(未实现)", mOpen);
         glutAddMenuEntry("关闭(q)", mClose);
         glutAddMenuEntry("保存(s)", mSave);

	 mEdit = glutCreateMenu(processMenuEvents);
	 glutAddMenuEntry("普通模式(n)", mNormal);
	 glutAddMenuEntry("添加关键点", mKeyPoint);
	 glutAddMenuEntry("选择(c)", mSelect);
	 //glutAddMenuEntry("拷贝", mCopy);
	 //glutAddMenuEntry("粘贴", mPaste);
	 glutAddMenuEntry("删除(d)", mDel);

	 mFill = glutCreateMenu(processMenuEvents);
	 glutAddMenuEntry("扫描线填充(未实现)", mScan);
	 glutAddMenuEntry("边界填充(未实现)", mEdge);
	 glutAddMenuEntry("洪泛填充(f)", mFlood);

	 mAntialiase = glutCreateMenu(processMenuEvents);
	 glutAddMenuEntry("Bresenham算法", mBresenham);
	 glutAddMenuEntry("WuXiaoLin算法", mWuXiaoLin);

	 mTools = glutCreateMenu(processMenuEvents);
	 glutAddMenuEntry("线段(1)", mLine);
	 glutAddMenuEntry("矩形(2)", mSquare);
	 glutAddMenuEntry("多边形(3)", mPolygon);
	 glutAddMenuEntry("圆形(4)", mCircle);
	 glutAddMenuEntry("椭圆形(5)", mEllipse);
	 glutAddMenuEntry("Bezier曲线(6)", mBezier);
	 glutAddSubMenu(  "填充", mFill);
	 glutAddMenuEntry("擦子(d)", mEraser);
	 glutAddSubMenu(  "抗锯齿", mAntialiase);
	 glutAddMenuEntry("调色板(t)", mColorTable);
	 glutAddMenuEntry("附着颜色到调色板(l)", mColorAttach);

         menu = glutCreateMenu(processMenuEvents);
	 glutAddSubMenu("文件", mFile);
	 glutAddSubMenu("编辑", mEdit);
	 glutAddSubMenu("工具", mTools);
         glutAttachMenu(GLUT_RIGHT_BUTTON);
}

