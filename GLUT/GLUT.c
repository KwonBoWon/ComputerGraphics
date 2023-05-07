#include <stdio.h>
#include <GL/glut.h>
#include <stdbool.h>
// R G B
#define BLACK 0.0, 0.0, 0.0
#define WHITE 1.0, 1.0, 1.0
#define RED 1.0, 0.0, 0.0
#define GREEN 0.0, 1.0, 0.0
#define BLUE 0.0, 0.0, 1.0
#define YELLOW 1.0, 1.0, 0.0
#define MAGENTA 1.0, 0.0, 1.0
#define CYAN 0.0, 1.0, 1.0
GLubyte cubeIndices[24] = { 0,3,2,1,2,3,7,6,0,4,7,3,1,2,6,54,5,6,7,0,1,5,4 };
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
void mouseMotion(int x, int y);

bool startMovement = false;
int mouseCurPositionX = 0;
int mouseCurPositionY = 0;
int mouseCurButton = 0;
float scale = 0;
/*
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
	glutMotionFunc(mouseMotion);
	glutMainLoop();


}*/

void init() {
	glClearColor(BLACK, 1.0); // 배경색 

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-1.0, 1.0, -1.0, 1.0); //  카메라 크기
}
void mydisplay() {
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POLYGON);
	glColor3f(newColor.R, newColor.G, newColor.B);
	glVertex2f(-1.0, -1.0);
	glVertex2f(-1.0, 0.0);
	glVertex2f(0.0, 0.0);

	
	glDrawElements(GL_QUADS, 24, GL_UNSIGNED_BYTE, cubeIndices);
	glEnd();
	/*
	glBegin(GL_POLYGON);
	glColor3f(newColor.R, newColor.G, newColor.B);
	glVertex2f(0.5, -0.5);
	glVertex2f(1.0, -1.0);
	glVertex2f(1.0, 0.5);
	glVertex2f(0.5, 1.0);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(newColor.R, newColor.G, newColor.B);
	glVertex2f(-1.0, 0.7);
	glVertex2f(-0.8, 1.0);
	glVertex2f(-0.6, 0.7);
	glVertex2f(-0.7, 0.3);
	glVertex2f(-0.9, 0.3);
	*/
	//glEnd();

	glFlush();
}
void mouseStatus(int button, int state, int x, int y) {
	// button: GLUT_LEFT_BUTTON, GLUT_MIDDLE_BUTTON, GLUT_RIGHT_BUTTON
	// state: GLUT_DOWN, GLUT_UP

	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		//startMovement = GL_TRUE;
		printf("LEFTCLICK\n");
		if (x < 250) {
			newColor.R = 0.0, newColor.G = 0.0, newColor.B = 1.0;
		}
		else {
			newColor.R = 1.0, newColor.G = 0.0, newColor.B = 0.0;
		}
	}
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) { // 왼쪽 마우스를 뗄떼도 적용이 되어버림
		printf("RIGHTCLICK\n");
		if (y < 250) {
			newColor.R = 1.0, newColor.G = 1.0, newColor.B = 1.0;
		}
		else {
			newColor.R = 0.0, newColor.G = 0.0, newColor.B = 0.0;
		}
	}
	mouseCurPositionX = x;
	mouseCurPositionY = y;
	mouseCurButton = button;
}


void mouseMotion(int x, int y) {
	printf("%d, %d\n", x, y); //  현재 좌표
	if (mouseCurButton != GLUT_LEFT_BUTTON) {//왼쪽 누를때
		//x_angle += 360.0 * (x-mouseCurPositonX)/width
		//y_angle += 360.0 * (y-mouseCurPositonY)/width
		mouseCurPositionX = x;
		mouseCurPositionY = y;
	}
	else {
		if (mouseCurPositionX < x) { // 오른쪽으로 드래그할 때
			newColor.R = 1.0, newColor.G = 0.0, newColor.B = 0.0;
		}
		if (mouseCurPositionX > x) {
			newColor.R = 0.0, newColor.G = 1.0, newColor.B = 0.0;
		}
	}
	/*
	if (mouseCurButton == GLUT_RIGHT_BUTTON) {
		scale += (y - mouseCurPositionY) / 100.0;
	}
	*/
	mouseCurPositionX = x;
	mouseCurPositionY = y;
	glutPostRedisplay();

}