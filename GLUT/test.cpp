#include <GL/glut.h>
/*
// Set up camera
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(1.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
*/
void display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glColor3f(1.0, 0.0, 0.0);  // Set x-axis color to red
	glBegin(GL_LINES);
	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(5.0, 0.0, 0.0);
	glEnd();

	glColor3f(0.0, 1.0, 0.0);  // Set y-axis color to green
	glBegin(GL_LINES);
	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(0.0, 5.0, 0.0);
	glEnd();

	glColor3f(0.0, 0.0, 1.0);  // Set z-axis color to blue
	glBegin(GL_LINES);
	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(0.0, 0.0, 5.0);
	glEnd();

	// Set up camera
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(1.0, 1.0, 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);


	// Draw a large cube
	//glRotatef(45.0f, 1.0f, 0.0f, 0.0f);
	glColor3f(1.0, 0.0, 0.0); // red
	glTranslatef(0.5f, 0.5f, 0.5f);
	glutSolidCube(0.1f);
	glColor3f(0.0, 1.0, 1.0); // line
	glutWireCube(0.1f);

	glColor3f(0.0, 0.0, 1.0); // blue
	glTranslatef(0.5f, 0.0f, 0.0f);
	glutSolidCube(0.1f);
	glColor3f(0.0, 1.0, 1.0); // line
	glutWireCube(0.1f);


	
	//glTranslatef(+0.0, +5.0, 0.0);
	//glutSolidCube(1.0);
	// Swap buffers
	glutSwapBuffers();
}

void DrawGLScene()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, -10.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_LINE_LOOP);
	glVertex3f(-1.0f, 1.0f, 1.0f);
	glVertex3f(1.0f, 1.0f, 1.0f);
	glVertex3f(1.0f, -1.0f, 1.0f);
	glVertex3f(-1.0f, -1.0f, 1.0f);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glVertex3f(-1.0f, 1.0f, -1.0f);
	glVertex3f(1.0f, 1.0f, -1.0f);
	glVertex3f(1.0f, -1.0f, -1.0f);
	glVertex3f(-1.0f, -1.0f, -1.0f);
	glEnd();

	glBegin(GL_LINES);
	glVertex3f(-1.0f, 1.0f, 1.0f);
	glVertex3f(-1.0f, 1.0f, -1.0f);
	glVertex3f(1.0f, 1.0f, 1.0f);
	glVertex3f(1.0f, 1.0f, -1.0f);
	glVertex3f(1.0f, -1.0f, 1.0f);
	glVertex3f(1.0f, -1.0f, -1.0f);
	glVertex3f(-1.0f, -1.0f, 1.0f);
	glVertex3f(-1.0f, -1.0f, -1.0f);
	glEnd();
	glutSwapBuffers();
}

int main(int argc, char** argv) {
	// Initialize GLUT
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutCreateWindow("19011521 ±Çº¸¿ø");

	// Set the display function
	glutDisplayFunc(display);

	// Start the main loop
	glutMainLoop();

	return 0;
}
