#include "Menu.h"
void processMenuEvents(int option) {
}

void createGLUTMenus() {
	int menu, mFile, mEdit, mTools, mFill;
         mFile = glutCreateMenu(processMenuEvents);
         glutAddMenuEntry("新建", mNew);
         glutAddMenuEntry("打开", mOpen);
         glutAddMenuEntry("关闭", mClose);
         glutAddMenuEntry("保存", mSave);

	 mEdit = glutCreateMenu(processMenuEvents);
	 glutAddMenuEntry("选择", mSelect);
	 glutAddMenuEntry("拷贝", mCopy);
	 glutAddMenuEntry("粘贴", mPaste);
	 glutAddMenuEntry("删除", mDel);

	 mFill = glutCreateMenu(processMenuEvents);
	 glutAddMenuEntry("扫描线填充", mScan);
	 glutAddMenuEntry("边界填充", mEdge);
	 glutAddMenuEntry("洪泛填充", mFlood);

	 mTools = glutCreateMenu(processMenuEvents);
	 glutAddMenuEntry("线段", mLine);
	 glutAddMenuEntry("矩形", mSquare);
	 glutAddMenuEntry("多边形", mPolygon);
	 glutAddMenuEntry("圆形", mCircle);
	 glutAddMenuEntry("椭圆形", mEllipse);
	 glutAddMenuEntry("Bezier曲线", mBezier);
	 glutAddSubMenu("填充", mFill);
	 glutAddMenuEntry("擦子", mEraser);

         menu = glutCreateMenu(processMenuEvents);
	 glutAddSubMenu("文件", mFile);
	 glutAddSubMenu("编辑", mEdit);
	 glutAddSubMenu("工具", mTools);
         glutAttachMenu(GLUT_RIGHT_BUTTON);
}
