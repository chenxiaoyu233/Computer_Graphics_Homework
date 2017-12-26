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

#include <jpeglib.h>
void write_JPEG_file (char *filename = "新作品.jpeg", 
		      int quality = 90,
		      int image_width = 0,
		      int image_height = 0,
		      GLubyte *image_buffer = NULL) {
  /* This struct contains the JPEG compression parameters and pointers to
   * working space (which is allocated as needed by the JPEG library).
   * It is possible to have several such structures, representing multiple
   * compression/decompression processes, in existence at once.  We refer
   * to any one struct (and its associated working data) as a "JPEG object".
   */
  struct jpeg_compress_struct cinfo;
  /* This struct represents a JPEG error handler.  It is declared separately
   * because applications often want to supply a specialized error handler
   * (see the second half of this file for an example).  But here we just
   * take the easy way out and use the standard error handler, which will
   * print a message on stderr and call exit() if compression fails.
   * Note that this struct must live as long as the main JPEG parameter
   * struct, to avoid dangling-pointer problems.
   */
  struct jpeg_error_mgr jerr;
  /* More stuff */
  FILE *outfile;                /* target file */
  JSAMPROW row_pointer[1];      /* pointer to JSAMPLE row[s] */
  int row_stride;               /* physical row width in image buffer */

  /* Step 1: allocate and initialize JPEG compression object */

  /* We have to set up the error handler first, in case the initialization
   * step fails.  (Unlikely, but it could happen if you are out of memory.)
   * This routine fills in the contents of struct jerr, and returns jerr's
   * address which we place into the link field in cinfo.
   */
  cinfo.err = jpeg_std_error(&jerr);
  /* Now we can initialize the JPEG compression object. */
  jpeg_create_compress(&cinfo);

  /* Step 2: specify data destination (eg, a file) */
  /* Note: steps 2 and 3 can be done in either order. */

  /* Here we use the library-supplied code to send compressed data to a
   * stdio stream.  You can also write your own code to do something else.
   * VERY IMPORTANT: use "b" option to fopen() if you are on a machine that
   * requires it in order to write binary files.
   */
  if ((outfile = fopen(filename, "wb")) == NULL) {
    fprintf(stderr, "can't open %s\n", filename);
    exit(1);
  }
  jpeg_stdio_dest(&cinfo, outfile);

  /* Step 3: set parameters for compression */

  /* First we supply a description of the input image.
   * Four fields of the cinfo struct must be filled in:
   */
  cinfo.image_width = image_width;      /* image width and height, in pixels */
  cinfo.image_height = image_height;
  cinfo.input_components = 3;           /* # of color components per pixel */
  cinfo.in_color_space = JCS_RGB;       /* colorspace of input image */
  /* Now use the library's routine to set default compression parameters.
   * (You must set at least cinfo.in_color_space before calling this,
   * since the defaults depend on the source color space.)
   */
  jpeg_set_defaults(&cinfo);
  /* Now you can set any non-default parameters you wish to.
   * Here we just illustrate the use of quality (quantization table) scaling:
   */
  jpeg_set_quality(&cinfo, quality, TRUE /* limit to baseline-JPEG values */);

  /* Step 4: Start compressor */

  /* TRUE ensures that we will write a complete interchange-JPEG file.
   * Pass TRUE unless you are very sure of what you're doing.
   */
  jpeg_start_compress(&cinfo, TRUE);

  /* Step 5: while (scan lines remain to be written) */
  /*           jpeg_write_scanlines(...); */

  /* Here we use the library's state variable cinfo.next_scanline as the
   * loop counter, so that we don't have to keep track ourselves.
   * To keep things simple, we pass one scanline per call; you can pass
   * more if you wish, though.
   */
  row_stride = image_width * 3; /* JSAMPLEs per row in image_buffer */

  while (cinfo.next_scanline < cinfo.image_height) {
    /* jpeg_write_scanlines expects an array of pointers to scanlines.
     * Here the array is only one element long, but you could pass
     * more than one scanline at a time if that's more convenient.
     */
    row_pointer[0] = & image_buffer[cinfo.next_scanline * row_stride];
    (void) jpeg_write_scanlines(&cinfo, row_pointer, 1);
  }

  /* Step 6: Finish compression */

  jpeg_finish_compress(&cinfo);
  /* After finish_compress, we can close the output file. */
  fclose(outfile);

  /* Step 7: release JPEG compression object */

  /* This is an important step since it will release a good deal of memory. */
  jpeg_destroy_compress(&cinfo);

  /* And we're done! */
}
