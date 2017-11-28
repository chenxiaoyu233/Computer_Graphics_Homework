#ifndef AUTOMATON_H_
#define AUTOMATON_H_
#include <GLUT/GLUT.h>
#include "Menu.h"
#include "Paper.h"
#include "KeyPoint.h"
#include "Shape.h"
	
extern Paper *paper;
extern int winWidth, winHeigth;
extern GLfloat zoomFactor;
extern int curState, curKey, curAlgorithm;
extern Shape *curShape;
extern vector <Shape*> shape;

void display();
void init();
void mouseMotion(int x, int y);
void mouseButton(int botton, int state, int x, int y);
void myReshape(int w, int h);

#endif
