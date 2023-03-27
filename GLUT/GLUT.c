#include <stdio.h>
#include<GL/glut.h>

void init() {
	glClearColor(0.0, 0.0, 0.0, 1.0); // 배경색
	glColor3f(1.0 , 0.0, 1.0); //빨 초 파
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-1.0, 1.0, -1.0, 1.0); //  카메라 크기

}
void mydisplay() {
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POLYGON);
	glVertex2f(-0.5, -0.5);
	glVertex2f(-0.5, 0.5);
	glVertex2f(0.5, 0.5);
	glVertex2f(0.5, -0.5);
	glEnd();
	glFlush();
}
int main(int argc, char** argv) {
	// glut init
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	// actuall
	glutInitWindowSize(500, 500);
	//
	glutInitWindowPosition(0, 0);
	//
	glutCreateWindow("simple");
	//
	glutDisplayFunc(mydisplay);
	//
	init();
	//
	glutMainLoop();


}
