#include "Paper.h"
#include <cstring>

Paper::Paper(int Width, int Height):Width(Width), Height(Height){
	paper = new GLubyte[Width * Height * 3];
	posX = posY = 0;
}
void Paper::reSize(int Width, int Height){
	this -> Width = Width; this -> Height = Height;
	delete[] paper;
	paper = new GLubyte[Width * Height * 3];
}
void Paper::clearBuffer(int R, int G, int B){
	for(int i = 0; i < Width; i++)
		for(int j = 0; j < Height; j++){
			paper[j*Width*3 + i*3 + 0] = R;
			paper[j*Width*3 + i*3 + 1] = G;
			paper[j*Width*3 + i*3 + 2] = B;
		}
}
void Paper::display(){
	glRasterPos2i(posX, posY);
	glDrawPixels(Width, Height, GL_RGB, GL_UNSIGNED_BYTE, paper);
}
void Paper::setPos(int x, int y){
	posX = x, posY = y;
}
void Paper::setPixel(int x, int y, int R, int G, int B){
	if(x < 0 || y < 0) return;
	if(x >= Width || y >= Height) return;
	paper[y*Width*3 + x*3 + 0] = R;
	paper[y*Width*3 + x*3 + 1] = G;
	paper[y*Width*3 + x*3 + 2] = B;
}
GLubyte Paper::accessPixel(int x, int y, int C){
	if(x < 0 || y < 0) return 0;
	if(x >= Width || y >= Height) return 0;
	return paper[y*Width*3 + x*3 + C];
}
Paper::~Paper(){
	delete[] paper;
}
