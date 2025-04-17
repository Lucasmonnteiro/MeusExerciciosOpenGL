#include <GL/glut.h>
#include <math.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

float angulo = 0.0f;

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    glTranslatef(0.0f, 0.0f, 0.0f);
    glRotatef(-angulo, 0.0f, 0.0f, 1.0f); 

    int numSegmentos = 100;
    float raio = 30.0f;

    glBegin(GL_TRIANGLE_FAN);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(0.0f, 0.0f);

    for (int i = 0; i <= numSegmentos; ++i) {
        float t = (float)i / numSegmentos;
        float angle = 2.0f * M_PI * t;
        float x = raio * cos(angle);
        float y = raio * sin(angle);

        //degradê
        float r = 0.5f + 0.5f * sin(angle + angulo * 0.05);
        float g = 0.2f + 0.2f * cos(angle - angulo * 0.05);
        float b = 0.6f + 0.4f * sin(angle * 1.5f + angulo * 0.05);

        glColor3f(r, g, b);
        glVertex2f(x, y);
    }

    glEnd();

    glutSwapBuffers();
}

void update(int value) {
    angulo += 0.5f; 
    if (angulo >= 360.0f)
        angulo -= 360.0f;

    glutPostRedisplay();
    glutTimerFunc(16, update, 0);
}

void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0); 
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-100, 100, -100, 100);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(640, 640);
    glutCreateWindow("Círculo em Degradê Girando");

    init();

    glutDisplayFunc(display);
    glutTimerFunc(0, update, 0);

    glutMainLoop();
    return 0;
}
