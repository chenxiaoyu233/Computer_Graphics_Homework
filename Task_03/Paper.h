#ifndef PAPER_H_
#define PAPER_H_
#include <GLUT/GLUT.h>

struct Paper{
	int Width, Height;
	GLubyte *paper;

	Paper(int Width = 0, int Height = 0);
	void display(GLfloat x, GLfloat y);
	void setPixel(int x, int y, int R, int G, int B);
	GLubyte accessPixel(int x, int y, int C);
	~Paper();
};
#endif
