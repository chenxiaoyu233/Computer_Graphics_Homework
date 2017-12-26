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
int isSettingColor;
Interface *curColorBar;
int curColorFlag;

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

extern int KeyPointSize;
void keyboard(unsigned char key, int x, int y){
	switch(key){
		case '+': KeyPointSize++;
			  break;
		case '-': 
			  if(KeyPointSize > 0) KeyPointSize--;
			  break;
		case 'h': 
			hideFlag ^= 1; 
			break;
		case '1':
			processMenuEvents(mLine);
			break;
		case '2':
			processMenuEvents(mSquare);
			break;
		case '3':
			processMenuEvents(mPolygon);
			break;
		case '4':
			processMenuEvents(mCircle);
			break;
		case '5':
			processMenuEvents(mEllipse);
			break;
		case '6':
			processMenuEvents(mBezier);
			break;
		case 'd':
			processMenuEvents(mDel);
			break;
		case 's':
			processMenuEvents(mSave);
			break;
		case 'c':
			processMenuEvents(mSelect);
			break;
		case 't':
			processMenuEvents(mColorTable);
			break;
		case 'l':
			processMenuEvents(mColorAttach);
			break;
		case 'f':
			processMenuEvents(mFlood);
			break;
		case 'n':
			processMenuEvents(mNormal);
			break;
		case 'q':
			processMenuEvents(mClose);
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
			}
			if(curState == mSelect && curInterface != NULL){
				curInterface -> setSPoint(x, y);
				curInterface -> select();
			}
			curColorFlag = 0;
			if(isSettingColor){
				if(y >= 0 && y <= 90 && x >= 90 && x <= 90 + 255 && curColorBar != NULL){
					if(y <= 30) curColorBar -> Bx = x - 90, curColorFlag = 1;
					if(y > 30 && y <= 60) curColorBar -> Gx = x - 90, curColorFlag = 2;
					if(y > 60 && y <= 90) curColorBar -> Rx = x - 90, curColorFlag = 3;
				}
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
	if(curColorFlag && curColorBar != NULL){
		int tmpx = x - 90;
		if(tmpx > 255) tmpx = 255;
		if(tmpx < 1) tmpx = 1;
		switch (curColorFlag){
			case 1: curColorBar -> Bx = tmpx; break;
			case 2: curColorBar -> Gx = tmpx; break;
			case 3: curColorBar -> Rx = tmpx; break;
		}
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

	isSettingColor = 1; // Debug;
	curColorBar = new Bar(Pen(paper));
	interface.push_back(curColorBar); // 次行用于测试Bar类是否可用

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

void ColorAttach(){ // 如果有多个被选中的图形的话, 选取最开始绘制那一个来附着颜色
	for(int i = 0; i < shape.size(); i++){
		int fla = 1;
		for(int j = 0; j < shape[i] -> key.size(); j++){
			for(int k = 0; k < keyPoints.size(); k++){
				if(keyPoints[k] == shape[i] -> key[j] && !isSelected[k]) {
					fla = 0; goto bk;
				}
			}
		}
bk:
		if(fla) {
			(curColorBar -> penPointer) = &(shape[i] -> pen);
			curColorBar -> getColor();
			return;
		}
	}
}

void turn(GLubyte *buffer, int w, int h){
	for(int i = 0; i < w; i++){
		for(int j = 0; j < h; j++) {
			int p = h-j-1;
			if(j > p) break;
			for(int k = 0; k < 3; k++){
				swap(buffer[j*w*3 + i*3 + k], buffer[p*w*3 + i*3 + k]);
			}
		}
	}
}

#include <jpeglib.h>
void write_JPEG_file (char *filename = "新作品.jpeg", 
		      int quality = 90,
		      int image_width = 0,
		      int image_height = 0,
		      GLubyte *image_buffer = NULL) {
	turn(image_buffer, image_width, image_height);
	struct jpeg_compress_struct cinfo;
	struct jpeg_error_mgr jerr;
	FILE *outfile;                
	JSAMPROW row_pointer[1];      
	int row_stride;               
	cinfo.err = jpeg_std_error(&jerr);
	jpeg_create_compress(&cinfo);
	if ((outfile = fopen(filename, "wb")) == NULL) {
		fprintf(stderr, "can't open %s\n", filename);
		exit(1);
	}
	jpeg_stdio_dest(&cinfo, outfile);
	cinfo.image_width = image_width;      
	cinfo.image_height = image_height;
	cinfo.input_components = 3;           
	cinfo.in_color_space = JCS_RGB;       
	jpeg_set_defaults(&cinfo);
	jpeg_set_quality(&cinfo, quality, TRUE /* limit to baseline-JPEG values */);
	jpeg_start_compress(&cinfo, TRUE);
	row_stride = image_width * 3; 
	while (cinfo.next_scanline < cinfo.image_height) {
		row_pointer[0] = & image_buffer[cinfo.next_scanline * row_stride];
		(void) jpeg_write_scanlines(&cinfo, row_pointer, 1);
	}
	jpeg_finish_compress(&cinfo);
	fclose(outfile);
	jpeg_destroy_compress(&cinfo);
	turn(image_buffer, image_width, image_height);
}
