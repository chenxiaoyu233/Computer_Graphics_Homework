#ifndef MENU_N_
#define MENU_N_
#include <GLUT/GLUT.h>


enum {mNormal = 0, mNew = 1, mOpen, mClose, mSave,
      mSelect, mCopy, mPaste, mDel,
      mLine, mKeyPoint, mSquare, mPolygon, mCircle, mEllipse, mBezier, 
      mScan, mEdge, mFlood, mEraser,
      mBresenham, mWuXiaoLin, mColorTable, mColorAttach
} mOptions;

void processMenuEvents(int option);
void createGLUTMenus();

#endif
