#ifndef PAPER_H_
#define PAPER_H_
#include <GLUT/GLUT.h>

struct Paper{
	int Width, Height;
	int posX, posY;
	GLubyte *paper;

	Paper(int Width = 0, int Height = 0);
	void reSize(int Width, int Height);
	void clearBuffer(int R = 0, int G = 0, int B = 0);
	void display();
	void setPos(int x, int Y);
	void setPixel(int x, int y, int R = 255, int G = 255, int B = 255);
	GLubyte accessPixel(int x, int y, int C);
	~Paper();
};
#endif
