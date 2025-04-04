#include <GL/glut.h>

float x_position = 0.0f;  
float velocidade = 2.0f;    

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.5f, 0.0f, 0.5f); //Roxo

    glBegin(GL_QUADS);
    glVertex2f(-10 + x_position, 10);
    glVertex2f(-10 + x_position, -10);
    glVertex2f(10 + x_position, -10);
    glVertex2f(10 + x_position, 10);
    glEnd();

    glFlush();
}

void update(int value) {
    x_position += velocidade;
    //Se atingir a borda, inverte a direção
    if (x_position > 90 || x_position < -90) {
        velocidade = -velocidade;
    }
    glutPostRedisplay(); 
    glutTimerFunc(16, update, 0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutInitWindowSize(640, 640);
    glutCreateWindow("Animacao Quadrado");

    glutDisplayFunc(display);
    glutTimerFunc(0, update, 0);

    gluOrtho2D(-100, 100, -100, 100);
    glClearColor(1, 1, 1, 0); 

    glutMainLoop();
    return 0;
}
