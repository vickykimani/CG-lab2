#include<GL/freeglut.h>
#include<GL/GL.h>
#include<math.h>
#include<stdlib.h>

void circle(GLfloat rx, GLfloat ry, GLfloat cx, GLfloat cy) {

	glBegin(GL_TRIANGLE_FAN);

	for (int i = 0; i <= 100; i++) {
		float angle = 2 * 3.1416*i / 100;

		float x = rx * cosf(angle);
		float y = ry * sinf(angle);
		glVertex2f(x + cx, y + cy);
	}
	glEnd();
}
void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 1.0); //white circle color                              (original circle)
	circle(7, 7, 1, 1);  //positioning of the overlapping circle

	glColor3f(0.0, 0.0, 0.0);  //black circle color                             (overlapping circle)
	circle(7, 7, 4, 4); //positioning of the overlapping circle
	glFlush();
}
void init(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0); //black background color
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-20, 20, -20, 20);
}
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE
		| GLUT_RGB);
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("crescent moon");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}