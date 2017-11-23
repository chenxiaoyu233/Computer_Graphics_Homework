#include "Automaton.h"
#include "DrawAlgorithm.h"
#include "Pen.h"
#include <cmath>
#include <vector>
#include <iostream>
using namespace std;

Paper *paper;
int winWidth, winHeigth;
GLfloat zoomFactor;
vector <KeyPoint*> keyPoints;
vector <Shape*> shape;
Shape *curShape;
int curState, curKey;

void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	paper -> clearBuffer();

	for(int i = 0; i < keyPoints.size(); i++) keyPoints[i] -> display();
	for(int i = 0; i < shape.size(); i++) shape[i] -> display();

	paper -> display();
	glFlush();
	glutSwapBuffers();
}

void mouseButton(int botton, int state, int x, int y){
	y = winHeigth - y;
	switch(state){
		int flag;
		case GLUT_DOWN :
			flag = 1;
			for(int i = 0; i < keyPoints.size(); i++) 
				if(keyPoints[i] -> isIn(x, y)){
					flag = 0; curKey = i; break;
				}
			if(flag) {
				keyPoints.push_back(new KeyPoint(x, y, paper));
				curKey = keyPoints.size() - 1;
			}
			if(curState >= mLine && curState <= mFill && curShape != NULL && !curShape -> isOver()){
				curShape -> addKey(keyPoints[curKey]);
			}
			if(curShape != NULL && curShape -> isOver()) {
				curState = mNormal;
				curShape = NULL;
			}
			break;
		case GLUT_UP :
			curKey = -1;
			break;
	}
}

void mouseMotion(int x, int y){
	y = winHeigth - y;
	if(curKey != -1) keyPoints[curKey] -> setPos(x, y);
}

void init(){
	paper = new Paper(500, 500);
	curState = mNormal;
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowPosition(50, 100);
	glutInitWindowSize(500, 500);
	glutCreateWindow("task_03");
	glutMotionFunc(&mouseMotion);
	glutMouseFunc(&mouseButton);
	glutReshapeFunc(&myReshape);
	glClearColor(0.3, 0.3, 0.3, 0.0);
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	glutDisplayFunc(&display);
	glutIdleFunc(&display);
	createGLUTMenus();
}

void myReshape(int w, int h){
	winWidth = w, winHeigth = h;
	glLoadIdentity();
	gluOrtho2D(0, w, 0, h);
	paper -> reSize(w, h);
}
