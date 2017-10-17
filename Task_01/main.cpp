#include <GLUT/GLUT.h>
#include <cstdlib>
#include <ctime>

#define FOR(i, l, r) for(int (i) = (l); (i) < (r); (i)++)
GLint point[6][2] = {
	{50, 100}, {100, 100},
	{150, 150}, {100, 200},
	{50, 200}, {0, 150}
};
GLint pt[8][3] = {
	{0, 0, 0}, {0, 100, 0}, {100, 0, 0}, 
	{100, 100, 0}, {0, 0, 100}, {0, 100, 100},
       	{100, 0, 100}, {100, 100, 100}
};
int randint(int l, int r){
	int del = r - l + 1;
	return del + rand() % del;
}
void mydisplay(){
	glClear(GL_COLOR_BUFFER_BIT);

	glColor3f(1.0, 1.0, 1.0);
	FOR(i, 0, 1000){
		glBegin(GL_LINES);
			glVertex2i(randint(0, 300), randint(0,300));
			glVertex2i(randint(0, 300), randint(0,300));
		glEnd();
	}
	glBegin(GL_POLYGON);
		FOR(i, 0, 6) glVertex2iv( point[i] );
	glEnd();
	glColor3f(0, 1.0, 1.0);
	glEnableClientState(GL_VERTEX_ARRAY);
		glVertexPointer(3, GL_INT, 0, pt);
		GLubyte vertIndex [] = {
			6, 2, 3, 7, 5, 1, 0, 4, 7,
			3, 1, 5, 4, 0, 2, 6, 2, 0,
			1, 3, 7, 5, 4, 6
		};
		glDrawElements(GL_QUADS, 24, GL_UNSIGNED_BYTE, vertIndex);
	glDisableClientState(GL_VERTEX_ARRAY);
	glFlush();
	glutSwapBuffers();
}

void init(){
	srand(time(NULL));
	glClearColor(0, 0, 0, 0.0);

	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, 300.0, 0.0, 300.0);
}

void myReshape(int w,int h){
	glViewport(0, 0, w, h);
	//winWidth = w;
	//winHeight = h;
}

int main(int argc, char **argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowPosition(50, 100);
	glutInitWindowSize(500, 500);
	glutCreateWindow("task_01");
	glutReshapeFunc(myReshape);

	init();
	glutDisplayFunc(&mydisplay);

	glutMainLoop();
	return 0;
}
