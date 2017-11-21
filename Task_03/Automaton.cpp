#include "Automaton.h"
#include "DrawAlgorithm.h"

Paper *paper;
int winWidth, winHeigth;
GLfloat zoomFactor;

void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	paper -> clearBuffer();
	paper -> display();
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
