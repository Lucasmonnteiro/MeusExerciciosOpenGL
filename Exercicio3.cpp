#include <GL/glut.h>
float y_position;

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1, 0, 0); //Vermelho
	glBegin(GL_QUADS);
	glVertex2f(10, 10 + y_position);
	glVertex2f(10, -10 + y_position);
	glVertex2f(-10, -10 + y_position);
	glVertex2f(-10, 10 + y_position);
	glEnd();
	glFlush();
}
void teclado(unsigned char key, int x, int y) {
	if (key == 32)  //Espaço
		y_position += 1.0f;
	glutPostRedisplay();
}
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutInitWindowSize(640, 640);
	glutCreateWindow("Keyboard");
	glutDisplayFunc(display);
	glutKeyboardFunc(teclado);
	gluOrtho2D(-100, 100, -100, 100);
	glClearColor(1, 1, 1, 0);
	glutMainLoop();
	return 0;
}
