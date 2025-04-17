#include <GL/glut.h>

void init() {
    glClearColor(1.0f, 0.9569f, 0.8157f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 400.0, 0.0, 400.0); 
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    //casco vermelho 
    glColor3f(0.9294f, 0.1098f, 0.1412f);
    glBegin(GL_POLYGON);
    glVertex2i(100, 200);
    glVertex2i(300, 200);
    glVertex2i(250, 170);
    glVertex2i(150, 170);
    glEnd();

    //vela cinza 
    glColor3f(0.7647f, 0.7647f, 0.7647f);
    glBegin(GL_TRIANGLES);
    glVertex2i(200, 310);
    glVertex2i(150, 200);
    glVertex2i(250, 200);
    glEnd();

    //mastro marrom
    glColor3f(0.5020f, 0.2510f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2i(195, 200);
    glVertex2i(205, 200);
    glVertex2i(205, 320);
    glVertex2i(195, 320);
    glEnd();

    //bandeira azul
    glColor3f(0.2471f, 0.2824f, 0.8f);
    glBegin(GL_QUADS);
    glVertex2i(200, 320);
    glVertex2i(230, 320);
    glVertex2i(230, 310);
    glVertex2i(200, 310);
    glEnd();

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 640);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Barco");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
