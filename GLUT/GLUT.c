#include <stdio.h>
#include<GL/glut.h>

#define BLACK 0.0, 0.0, 0.0
#define WHITE 1.0, 1.0, 1.0
#define RED 1.0, 0.0, 0.0
#define GREEN 0.0, 1.0, 0.0
#define BLUE 0.0, 0.0, 1.0
#define YELLOW 1.0, 1.0, 0.0
#define MAGENTA 1.0, 0.0, 1.0
#define CYAN 0.0, 1.0, 1.0
// ctrl K C, ctrl K U

void init() {
	glClearColor(GREEN, 1.0); // 배경색 
	//glColor3f(WHITE); //빨 초 파
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-1.0, 1.0, -1.0, 1.0); //  카메라 크기
}
void mydisplay() {
	

	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POLYGON);
	glColor3f(MAGENTA);

	glVertex2f(-0.5, -0.5);
	glVertex2f(-0.5, 0.5);
	glVertex2f(0.0, 0.5);
	glVertex2f(0.0, -0.5);

	glEnd();
	
	/*glColor3f(WHITE);
	glBegin(GL_POLYGON);
	glVertex2f(0.1, 0.5);
	glVertex2f(0.5, 0.5);
	glVertex2f(0.1, -0.5);
	glEnd();*/
	
	

	//glEnd();
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
	glutCreateWindow("19011521권보원");
	//
	glutDisplayFunc(mydisplay);
	//
	init();
	//
	glutMainLoop();


}
