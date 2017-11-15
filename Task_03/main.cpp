#include <GLUT/GLUT.h>
#include "Menu.h"
#include "Paper.h"
#include <iostream>
using namespace std;

void makeCheckImage(Paper &p) {
	for(int i = 0; i < 100; i++)
		for(int j = 0; j < 100; j++)
			p.setPixel(i, j, 255, 255, 255);
	for(int i = 89; i < 95; i++)
		for(int j = 4; j < 10; j++)
			p.setPixel(i, j, 0, 0, 255);
}

Paper paper(100, 100);
void display(void) {
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	paper.display(-t, 0);
	glFlush();
	glutSwapBuffers();
}

void init(){
	glClearColor(0, 0, 0, 0.0);
	makeCheckImage(paper);
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
}

int main(int argc, char **argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowPosition(50, 100);
	glutInitWindowSize(500, 500);
	glutCreateWindow("task_03");

	init();
	glutDisplayFunc(&display);
	glutIdleFunc(&display);

	createGLUTMenus();

	glutMainLoop();
	return 0;
}
