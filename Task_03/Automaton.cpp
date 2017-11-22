#include "Automaton.h"
#include "DrawAlgorithm.h"
#include "Pen.h"
#include <cmath>

Paper *paper;
int winWidth, winHeigth;
GLfloat zoomFactor;

double t;
void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	paper -> clearBuffer();
	LineAlgorithm <Pen> la((Pen(paper)));
	la.LineBresenhamAlgorithm(250, 250, 250 + 100 * cos(t), 250 + 100 * sin(t));
	paper -> display();
	t += 0.001;
	glFlush();
	glutSwapBuffers();
}

void mouseMotion(int x, int y){
}

void init(){
	paper = new Paper(500, 500);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowPosition(50, 100);
	glutInitWindowSize(500, 500);
	glutCreateWindow("task_03");
	glutMotionFunc(&mouseMotion);
	glutReshapeFunc(&myReshape);
	glClearColor(0.3, 0.3, 0.3, 0.0);
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	glutDisplayFunc(&display);
	glutIdleFunc(&display);
	createGLUTMenus();
}

void myReshape(int w, int h){
	winWidth = w, winHeigth = h;
	gluOrtho2D(0, w, 0, h);
}
