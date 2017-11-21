#ifndef AUTOMATON_H_
#define AUTOMATON_H_
#include <GLUT/GLUT.h>
#include "Menu.h"
#include "Paper.h"
	
extern Paper *paper;
extern int winWidth, winHeigth;
extern GLfloat zoomFactor;

void display();
void init();
void mouseMotion(int x, int y);
void myReshape(int w, int h);

#endif
