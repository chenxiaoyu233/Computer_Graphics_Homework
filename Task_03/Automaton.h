#ifndef AUTOMATON_H_
#define AUTOMATON_H_
#include <GLUT/GLUT.h>
#include "Menu.h"
#include "Paper.h"
#include "KeyPoint.h"
#include "Shape.h"
#include "Interface.h"
	
extern Paper *paper;
extern int winWidth, winHeigth;
extern GLfloat zoomFactor;
extern int curState, curKey, curAlgorithm, isAddingKeyPoint;
extern Shape *curShape;
extern vector <Shape*> shape;
extern vector <KeyPoint*> keyPoints;
extern vector <bool> isSelected;
struct Interface;
extern vector <Interface*> interface;
extern Interface* curInterface;
extern int isAddingSelect;
extern int isSettingColor;
extern Interface *curColorBar;
extern int curColorFlag;

void display();
void init();
void mouseMotion(int x, int y);
void mouseButton(int botton, int state, int x, int y);
void myReshape(int w, int h);
void deleteKeyPoint();
void ColorAttach();
void write_JPEG_file (char *filename,
		      int quality,
		      int image_width,
		      int image_height,
		      GLubyte *image_buffer) ;

#endif
