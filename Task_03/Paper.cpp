#include "Paper.h"

Paper::Paper(int Width, int Height):Width(Width), Height(Height){
	paper = new GLubyte[Width * Height * 3];
}
void Paper::display(GLfloat x, GLfloat y){
	glRasterPos2f(x, y);
	glDrawPixels(Width, Height, GL_RGB, GL_UNSIGNED_BYTE, paper);
}
void Paper::setPixel(int x, int y, int R, int G, int B){
	paper[y*Width*3 + x*3 + 0] = R;
	paper[y*Width*3 + x*3 + 1] = G;
	paper[y*Width*3 + x*3 + 2] = B;
}
GLubyte Paper::accessPixel(int x, int y, int C){
	return paper[y*Width*3 + x*3 + C];
}
Paper::~Paper(){
	delete[] paper;
}
