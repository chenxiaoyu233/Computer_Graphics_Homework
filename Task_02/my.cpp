#include <GLUT/GLUT.h>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <cmath>
using namespace std;

#define FOR(i, l, r) for(int (i) = (l); (i) < (r); (i)++)
#define draw(TYPE, OBJ, NUM) do{ \
	glBegin(TYPE); \
	FOR(i, 0, NUM) glVertex2fv(OBJ[i]); \
	glEnd(); \
}while(0)
GLfloat winW, winH;
GLfloat initW = 400.0, initH = 400.0;
GLint state; // 0 static, 1 move
GLfloat p[35][3] = { 
	{0,0,0}, // no use
	{1, -1, -1}, {0, -1, 0}, {-1, -1, -1}, {0, 0, -1},
	{-1, 1, -1}, {1, 1, -1}, {1, -1, 1}, {-1, -1, 1},
	{-1, 1, 1}, {1, 1, 1}, {-1, 0, 1}, {0, 1, 1},
	{0, -1, 1}, {1, 0 , 1}, {-1, -1, 0}, {1, -1, 0},
	{1, 1, 0}, {-1, 0, -1}, {0, -1, -1}, {-1, 1, 0},
	{0, 1, -1}, {1, 0, -1}, {0, 1, 0}, {-1, 0, 0},
	{0, 0, 1}, {1, 0, 0}
};
struct Surface{
	GLint w[4];
	GLfloat c[3];
	Surface(GLint a = 0, GLint b = 0, GLint c = 0, 
			GLint d = 0, GLfloat R = 0, GLfloat G = 0, GLfloat B = 0){
		w[0] = a, w[1] = b, w[2] = c, w[3] = d;
		this -> c[0] = R, this -> c[1] = G, this -> c[2] = B;
	}
	void drawSelf(){
		glColor3fv(c);
		glBegin(GL_POLYGON);
			FOR(i, 0, 4) glVertex3fv(p[w[i]]);
		glEnd();
	}
};
Surface s[30] = {
	Surface(0, 0, 0, 0, 0, 0),// no use

	Surface(12, 25, 14, 10, 1.0, 1.0, 1.0),
	Surface(25, 13, 7, 14, 1.0, 1.0, 1.0),
	Surface(9, 11, 25, 12, 1.0, 1.0, 1.0),
	Surface(11, 8, 13, 25, 1.0, 1.0, 1.0),

	Surface(20, 24, 11, 9, 0.0, 1.0, 0.0),
	Surface(24, 15, 8, 11, 0.0, 1.0, 0.0),
	Surface(5, 18, 24, 20, 0.0, 1.0, 0.0),
	Surface(18, 3, 15, 24, 0.0, 1.0, 0.0),

	Surface(15, 2, 13, 8, 1.0, 0.0, 0.0),
	Surface(2, 16, 7, 13, 1.0, 0.0, 0.0),
	Surface(3, 19, 2, 15, 1.0, 0.0, 0.0),
	Surface(19, 1, 16, 2, 1.0, 0.0, 0.0),

	Surface(16, 26, 14, 7, 0.0, 0.0, 1.0),
	Surface(26, 17, 10, 14, 0.0, 0.0, 1.0),
	Surface(1, 22, 26, 16, 0.0, 0.0, 1.0),
	Surface(22, 6, 17, 26, 0.0, 0.0, 1.0),

	Surface(17, 23, 12, 10, 1.0, 0.0, 1.0),
	Surface(23, 20, 9, 12, 1.0, 0.0, 1.0),
	Surface(6, 21, 23, 17, 1.0, 0.0, 1.0),
	Surface(21, 5, 20, 23, 1.0, 0.0, 1.0),

	Surface(22, 4, 21, 6, 0.0, 1.0, 1.0),
	Surface(4, 18, 5, 21, 0.0, 1.0, 1.0),
	Surface(1, 19, 4, 22, 0.0, 1.0, 1.0),
	Surface(19, 3, 18, 4, 0.0, 1.0, 1.0)
};

struct Motion{
	
};
struct Point{
	GLdouble x,y,z;
	Point(GLdouble x = 0.0f, GLdouble y = 0.0f, GLdouble z = 0.0f):
		x(x), y(y), z(z){}
	friend Point operator + (const Point &a, const Point &b){
		return Point(a.x + b.x, a.y + b.y, a.z + b.z);
	}
	friend Point operator - (const Point &a, const Point &b){
		return Point(a.x - b.x, a.y - b.y, a.z - b.z);
	}
	friend Point operator * (const Point &a, GLdouble b){
		return Point(a.x * b, a.y * b, a.z * b);
	}
	friend Point operator / (const Point &a, GLdouble b){
		return Point(a.x / b, a.y / b, a.z / b);
	}
};
GLdouble Dot(const Point &a, const Point &b){
	return a.x*b.x + a.y*b.y + a.z*b.z;
}
Point Cross(const Point &a, const Point &b){
	return Point(a.y*b.z - a.z*b.y, a.z*b.x - a.x*b.z, a.x*b.y - a.y*b.x);
}
GLdouble Length(const Point &a){
	return sqrt(Dot(a,a));
}

Point lastP, nowP;
Point RoDir;
GLdouble RoAngle;
int bottonFlag;
int moveFlag;
void ClacPos(GLdouble x, GLdouble y, Point &p){
	if(x < 0) x = 0;
	if(y < 0) y = 0;
	if(x > initW) x = initW;
	if(y > initH) y = initH;
	GLdouble dx = x - (initW/2), dy = (initH/2) - y;
	dx /= initW/2, dy /= initH/2;
	GLdouble dz = sqrt(2.0 - dx * dx - dy * dy);
	p = Point(dx, dy, dz);
	//cerr << dx << " " << dy << " " << dz << endl;
}
void mouseButton(int botton, int state, int x, int y){
	//cerr << x << " " << y << endl;
	switch(state){
		case GLUT_DOWN :
			bottonFlag = 1;
			ClacPos(x, y, lastP);
			break;
		case GLUT_UP :
			bottonFlag = 0;
			break;
	}
}
const GLdouble pi = acos(-1);
void mouseMotion(int x,int y){
	if(!bottonFlag) {
		moveFlag = 0;
		return;
	} moveFlag = 1;
	ClacPos(x, y, nowP);
	RoDir = Cross(lastP, nowP);
	RoAngle = acos(Dot(lastP, nowP)/Length(lastP)/Length(nowP));
	RoAngle = RoAngle / pi * 180;
	lastP = nowP;
	if(RoDir.x == 0 && RoDir.y == 0 && RoDir.z == 0) moveFlag = 0;
	cerr << RoAngle << " " << RoDir.x << " " << RoDir.y << " " << RoDir.z << endl;
}
GLfloat angle1, angle2;
void init_axis(){
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glScalef(0.6f, 0.6f, 0.6f);
}
GLfloat tmp[4][4] = {
	{1.0, 0.0, 0.0, 0.0},
	{0.0, 1.0, 0.0, 0.0},
	{0.0, 0.0, 1.0, 0.0},
	{0.0, 0.0, 0.0, 1.0}
};
void mydisplay(){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	init_axis();
	if(moveFlag && bottonFlag){
		glPushMatrix();
			glLoadIdentity();
			glRotatef(RoAngle, RoDir.x, RoDir.y, RoDir.z);
			glMultMatrixf((GLfloat*)tmp);
			glGetFloatv(GL_MODELVIEW_MATRIX, (GLfloat *)tmp);
			moveFlag = 0;
			cerr << 1 << endl;
		glPopMatrix();
	}
	glMultMatrixf((GLfloat*)tmp);
	for(int i = 1; i <= 24; i++) 
		s[i].drawSelf();
	glFlush();
	glutSwapBuffers();
	//angle1 += 0.2f;
	//angle2 += 0.1f;
}

void init(){
	glClearColor(0.3, 0.3, 0.3, 0.0);
	glClearDepth(10.0f);
	glEnable(GL_DEPTH_TEST);
	glDepthRange (-10.0f, 10.0f);
}

void myReshape(int w,int h){
	glViewport(0, 0, w, h);
	glLoadIdentity();
	glScalef(0.6f, 0.6f, 0.6f);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if(w <= h)
		gluOrtho2D(-1.0, 1.0, -1.0 * (GLfloat)h/w, 1.0 * (GLfloat)h/w);
	else 
		gluOrtho2D(-1.0 * (GLfloat)w/h, 1.0 * (GLfloat)w/h, -1.0, 1.0);
	glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char **argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowPosition(50, 100);
	glutInitWindowSize(initW, initH);
	glutCreateWindow("task_02");
	glutReshapeFunc(myReshape);
	glutMouseFunc(&mouseButton);
	glutMotionFunc(&mouseMotion);

	init();
	glutDisplayFunc(&mydisplay);
	glutIdleFunc(&mydisplay);

	glutMainLoop();
	return 0;
}
