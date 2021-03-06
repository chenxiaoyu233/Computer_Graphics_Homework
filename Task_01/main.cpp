#include <GLUT/GLUT.h>
#include <cstdlib>
#include <ctime>

#define FOR(i, l, r) for(int (i) = (l); (i) < (r); (i)++)
GLfloat poly1[5][2] = {
	{0, 0}, {0.01, 1.48}, {1.12, 1.85},
	{1.46, 2.35}, {2.53, 0.01}
};
GLfloat poly2[4][2] = {
	{4.29, 0.03}, {4.21, 1.83},
	{5.95, 1.26}, {6.0, 0}
};
GLfloat poly3[6][2] = {
	{3.18, 0.22}, {2.78, 0.66},
       	{3.18, 1.06}, {3.42, 1.05},
       	{3.88, 0.69}, {3.58, 0.46}
};
GLfloat poly4[4][2] = {
	{3.11, 0.02}, {3.18, 0.22}, 
	{3.58, 0.46}, {3.79, 0.01}
};
GLfloat poly5[6][2] = {
	{1.10, 4.50}, {1.46, 4.59},
	{1.59, 4.71}, {1.55, 4.37},
	{1.45, 4.40}, {1.18, 4.38}
};
GLfloat poly6[19][2] = {
	{1.59, 4.71}, {1.55, 4.37}, {1.45, 4.40}, {1.18, 4.38},
	{1.79, 4.89}, {2.06, 4.94}, {2.35, 4.96}, {2.63, 4.96},
	{2.90, 4.91}, {3.01, 4.79}, {3.00, 4.50}, {2.95, 4.22},
	{2.72, 3.90}, {2.60, 3.83}, {2.27, 3.81}, {1.95, 3.82},
	{1.77, 3.88}, {1.64, 4.05}, {1.56, 4.28}
};
GLfloat poly7[4][2] = {
	{3.01, 4.79}, {3.22, 4.81},
	{3.22, 4.53}, {3.00, 4.50}
};
GLfloat poly8[15][2] = {
	{3.22, 4.81}, {3.34, 4.94}, {3.60, 5.00}, {4.00, 5.00},
	{4.36, 4.97}, {4.52, 4.90}, {4.63, 4.69}, {4.65, 4.44},
	{4.59, 4.09}, {4.48, 3.93}, {4.22, 3.84}, {3.84, 3.82},
	{3.53, 3.88}, {3.29, 4.17}, {3.22, 4.53}
};
GLfloat poly9[4][2] = {
	{4.63, 4.69}, {4.79, 4.55},
	{4.81, 4.44}, {4.65, 4.44}
};
GLfloat poly10[14][2] = {
	{1.65, 4.41}, {1.68, 4.68}, {1.80, 4.80}, {2.02, 4.88},
	{2.47, 4.91}, {2.77, 4.88}, {2.91, 4.75}, {2.94, 4.34},
	{2.79, 4.06}, {2.58, 3.93}, {2.26, 3.87}, {2.00, 3.88},
	{1.77, 3.96}, {1.66, 4.16}
};
GLfloat poly11[14][2] = {
	{3.29, 4.68}, {3.36, 4.84}, {3.65, 4.92}, {4.18, 4.91},
	{4.42, 4.85}, {4.55, 4.70}, {4.56, 4.32}, {4.50, 4.07},
	{4.34, 3.95}, {4.02, 3.92}, {3.70, 3.94}, {3.52, 4.01},
	{3.37, 4.19}, {3.30, 4.46}
};
GLfloat line1[8][2] = {
	{1.49, 2.27}, {3.15, 1.06},
	{4.18, 1.84}, {3.47, 1.07},
	{2.46, 0.21}, {3.15, 1.06},
	{3.47, 1.07}, {4.27, 0.00}
};
GLfloat line2[32][2] = {
	{1.45, 2.38}, {1.25, 3.16}, {1.14, 3.17}, {1.03, 3.66},
	{0.90, 4.40}, {1.01, 4.44}, {0.86, 5.08}, {0.91, 5.67},
	{1.14, 6.19}, {1.52, 6.54}, {2.10, 6.72}, {2.67, 6.85},
	{3.38, 6.86}, {3.90, 6.75}, {4.43, 6.50}, {4.83, 6.04},
	{5.04, 5.58}, {5.00, 5.00}, {4.99, 4.65}, {4.86, 4.52},
	{4.90, 4.45}, {4.98, 4.43}, {4.98, 3.79}, {4.83, 3.55},
	{4.85, 3.28}, {4.75, 3.16}, {4.65, 3.17}, {4.54, 2.68},
	{4.38, 2.36}, {4.24, 2.17}, {4.14, 2.03}, {4.12, 1.88},
};
GLfloat line3[7][2] = {
	{1.60, 2.62}, {1.86, 2.25}, {2.81, 1.79}, {3.28, 1.80},
	{3.68, 1.91}, {4.27, 2.28}, {4.47, 2.58}
};
GLfloat line4[4][2] = {
	{2.65, 3.82}, {2.14, 3.23},
	{3.61, 3.77}, {3.97, 3.39}
};
int randint(int l, int r){
	int del = r - l + 1;
	return del + rand() % del;
}
void mydisplay(){
#define draw(TYPE, OBJ, NUM) do{ \
	glBegin(TYPE); \
	FOR(i, 0, NUM) glVertex2fv(OBJ[i]); \
	glEnd(); \
}while(0)

	glClear(GL_COLOR_BUFFER_BIT);

	glColor3f(0, 0, 0);
	draw(GL_POLYGON, poly1, 5);
	draw(GL_POLYGON, poly2, 4);
	draw(GL_POLYGON, poly3, 6);
	draw(GL_POLYGON, poly4, 4);
	draw(GL_LINES, line1, 8);
	draw(GL_LINES, line4, 4);
	draw(GL_LINE_STRIP, line2, 32);
	draw(GL_POLYGON, poly5, 6);
	draw(GL_POLYGON, poly6, 19);
	draw(GL_POLYGON, poly7, 4);
	draw(GL_POLYGON, poly8, 15);
	draw(GL_POLYGON, poly9, 4);
	draw(GL_LINE_STRIP, line3, 7);
	glColor3f(1.0, 1.0, 1.0);
	draw(GL_POLYGON, poly10, 14);
	draw(GL_POLYGON, poly11, 14);

	glFlush();

#undef draw
}

void init(){
	srand(time(NULL));
	glClearColor(1, 1, 1, 0.0);

	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, 6.0, 0.0, 8.0);
}

void myReshape(int w,int h){
	glViewport(0, 0, w, h);
	//winWidth = w;
	//winHeight = h;
}

int main(int argc, char **argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(50, 100);
	glutInitWindowSize(600, 800);
	glutCreateWindow("task_01");
	glutReshapeFunc(myReshape);

	init();
	glutDisplayFunc(&mydisplay);

	glutMainLoop();
	return 0;
}
