#include <stdio.h>
#include <GL/glut.h>
#include <stdbool.h>

#define BLACK 0.0, 0.0, 0.0
#define WHITE 1.0, 1.0, 1.0
#define RED 1.0, 0.0, 0.0
#define GREEN 0.0, 1.0, 0.0
#define BLUE 0.0, 0.0, 1.0
#define YELLOW 1.0, 1.0, 0.0
#define MAGENTA 1.0, 0.0, 1.0
#define CYAN 0.0, 1.0, 1.0

typedef struct _objColor {
	GLfloat R;
	GLfloat G;
	GLfloat B;
}objColor;

objColor newColor = { .R = 1.0, .G = 1.0, .B = 1.0 };

// ctrl K C, ctrl K U
void init();
void mydisplay();
void mouseStatus(int button, int state, int x, int y);

bool startMovement = false;
int mouseCurPositionX = 0;
int mouseCurPositionY = 0;
int mouseCurButton = 0;

int main(int argc, char** argv) {
	// glut init
	glutInit(&argc, argv);
	//
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	// 
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
	glutMouseFunc(mouseStatus);
	//
	glutMainLoop();


}
void init() {
	glClearColor(BLACK, 1.0); // 배경색 
	//glColor3f(WHITE); //빨 초 파
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-1.0, 1.0, -1.0, 1.0); //  카메라 크기
}
void mydisplay() {
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POLYGON);
	glColor3f(newColor.R, newColor.G, newColor.B);
	glutMouseFunc(mouseStatus);
	glVertex2f(-0.5, -0.5);
	glVertex2f(-0.5, 0.5);
	glVertex2f(0.5, 0.5);
	glEnd();
	glFlush();
}
void mouseStatus(int button, int state, int x, int y) {
	// button: GLUT_LEFT_BUTTON, GLUT_MIDDLE_BUTTON, GLUT_RIGHT_BUTTON
	// state: GLUT_DOWN, GLUT_UP

	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		startMovement = GL_TRUE;
		printf("blue\n");
		newColor.R = 0.0, newColor.G = 0.0, newColor.B = 1.0;

	}
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) { // 왼쪽 마우스를 뗄떼도 적용이 되어버림
		printf("red\n");
		newColor.R = 1.0, newColor.G = 0.0, newColor.B = 0.0;

	}
	mouseCurPositionX = x;
	mouseCurPositionY = y;
	mouseCurButton = button;


}