#ifndef MENU_N_
#define MENU_N_
#include <GLUT/GLUT.h>


enum {mNormal = 0, mNew = 1, mOpen, mClose, mSave,
      mSelect, mCopy, mPaste, mDel,
      mLine, mSquare, mPolygon, mCircle, mEllipse, mBezier, mFill, mEraser,
      mScan, mEdge, mFlood
} mOptions;

void processMenuEvents(int option);
void createGLUTMenus();

#endif
