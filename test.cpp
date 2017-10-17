#include <GLUT/GLUT.h>
void display(void) {
	glClear(GL_COLOR_BUFFER_BIT);

	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_POLYGON);
		glVertex3f(0.25, 0.25, 0.0);
		glVertex3f(0.75, 0.25, 0.0);
		glVertex3f(0.75, 0.75, 0.0);
		glVertex3f(0.25, 0.75, 0.0);
	glEnd();
	/*  don’t wait!
	 *  start processing buffered OpenGL routines
	 */
	glFlush(); 
}
void init(void) {
	/*  select clearing (background) color  */
	glClearColor(0.0, 0.0, 0.0, 0.0);
	/*  initialize viewing values  */
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
}
/*
 *  Declare initial window size, position, and display mode
 *  (single buffer and RGBA).  Open window with “hello”
 *  in its title bar.  Call initialization routines.
 *  Register callback function to display graphics.
 *  Enter main loop and process events.
 */
void DEBUG(){
	GLbyte i = 100;
	glVertex2i(2,4); // 整形
	glVertex3f(2.0,4.0,5.0); // 浮点型
}

int main(int argc, char** argv) {
	//DEBUG();
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(250, 250);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("hello");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;   /* ISO C requires main to return int. */
}
