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
vector <Interface*> interface;
vector <bool> isSelected;
Shape *curShape;
int curState, curKey, curAlgorithm, isAddingKeyPoint;
Interface* curInterface;
int isAddingSelect;

bool hideFlag;

void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	paper -> clearBuffer();

	for(int i = 0; i < shape.size(); i++) shape[i] -> display();
	if(!hideFlag) for(int i = 0; i < keyPoints.size(); i++)
	      	isSelected[i] ? keyPoints[i] -> display(0, 255, 0) : keyPoints[i] -> display();
	for(int i = 0; i < interface.size(); i++) interface[i] -> display();

	paper -> display();
	glFlush();
	glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y){
	switch(key){
		case 'h': 
			hideFlag ^= 1; 
			break;
		case 'c':
			break;
		case 'a': 
			isAddingSelect ^= 1;
			break;
	}
}

void mouseButton(int botton, int state, int x, int y){
	y = winHeigth - y;
	switch(state){
		int flag;
		case GLUT_DOWN :
			if(curState != mSelect){
				flag = 1;
				for(int i = 0; i < keyPoints.size(); i++) 
					if(keyPoints[i] -> isIn(x, y)){
						flag = 0; curKey = i; break;
					}
				if(isAddingKeyPoint){
					if(flag) {
						keyPoints.push_back(new KeyPoint(x, y, paper));
						isSelected.push_back(false);
						curKey = keyPoints.size() - 1;
					}
				}
				if(curState >= mLine && curState <= mFlood && curShape != NULL && !curShape -> isOver() && curKey != -1){
					curShape -> addKey(keyPoints[curKey]);
				}
				if(curShape != NULL && curShape -> isOver()) {
					curState = mNormal;
					curShape = NULL;
					isAddingKeyPoint = 0;
				}
			}else if(curState == mSelect && curInterface != NULL){
				curInterface -> setSPoint(x, y);
				curInterface -> select();
			}
			break;
		case GLUT_UP :
			curKey = -1;
			if(curState == mSelect){
				if(!isAddingSelect){
					interface.erase(interface.end()-1, interface.end());
					delete curInterface;
					curInterface = NULL;
					curState = mNormal;
				} else if(isAddingSelect){
					curInterface -> init(); 
				}
			}
			break;
	}
}

void mouseMotion(int x, int y){
	y = winHeigth - y;
	if(curKey != -1) keyPoints[curKey] -> setPos(x, y);
	if(curState == mSelect && curInterface != NULL && curInterface -> isSet()){
		curInterface -> setTPoint(x, y);
		curInterface -> select();
	}
}

void init(){
	paper = new Paper(500, 500);
	curState = mNormal;
	curAlgorithm = mBresenham;
	isAddingKeyPoint = 0;
	curInterface = NULL;
	curShape = NULL;
	curKey = -1;
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowPosition(50, 100);
	glutInitWindowSize(500, 500);
	glutCreateWindow("task_03");
	glutMotionFunc(&mouseMotion);
	glutMouseFunc(&mouseButton);
	glutKeyboardFunc(&keyboard);
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

void deleteKeyPoint(){
	vector <KeyPoint*> checklist; checklist.clear();
	for(int i = 0; i < keyPoints.size(); i++) 
		if(isSelected[i]) checklist.push_back(keyPoints[i]);
	for(int now = 0; now < checklist.size(); now++){
		for(vector<Shape*> :: iterator i = shape.begin(); i != shape.end(); ){
			int df = 1;
			for(int j = 0; j < (*i) -> key.size(); j++)
			       	if(checklist[now] == (*i) -> key[j]) {
					delete (*i);
					i = shape.erase(i);
					df = 0;
					break;
				}
			i += df;
		}
		vector<bool> :: iterator j = isSelected.begin();
		for(vector<KeyPoint*> :: iterator i = keyPoints.begin(); i != keyPoints.end(); ){
			if((*i) == checklist[now]) {
				delete (*i);
				i = keyPoints.erase(i);
				j = isSelected.erase(j);
			}
			else i++, j++;
		}
	}
}
