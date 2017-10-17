#include <GLUT/GLUT.h>
/* OpenGL使用的过程中涉及了函数注册的概念。
 * 比如这里使用的mytdisplay函数就并不是系统自带的函数
 */
void mydisplay(){
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0,1.0,0);
	glBegin(GL_POLYGON);
		glVertex2f(-0.5,-0.5);
		glVertex2f(0.5,-0.5);
		glVertex2f(0.5,0.5);
		glVertex2f(-0.5,0.5);
	glEnd();
	glColor3f(1.0,0,0);
	glBegin(GL_POLYGON);
		glVertex2f(-0.1,-0.1);
		glVertex2f(0.1,-0.1);
		glVertex2f(0.1,0.1);
		glVertex2f(-0.1,0.1);
	glEnd();
	glFlush();
}

int main(int argc, char **argv){
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(100,100);
	glutCreateWindow("simple");
	glutDisplayFunc(mydisplay);

	glClearColor(0.4,0.0,1.0,0.0);

	glutMainLoop();
	return 0;
}

