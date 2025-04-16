#include <GL/glut.h>
#include <cmath>

const int numSegments = 200;
const float PI = 3.14159265359f;

//desenhar um anel entre dois raios
void drawRing(float innerRadius, float outerRadius, float r, float g, float b) {
    glBegin(GL_TRIANGLE_STRIP);
    glColor3f(r, g, b);
    for (int i = 0; i <= numSegments; ++i) {
        float angle = 2 * PI * i / numSegments;
        float xOuter = outerRadius * cos(angle);
        float yOuter = outerRadius * sin(angle);
        float xInner = innerRadius * cos(angle);
        float yInner = innerRadius * sin(angle);

        glVertex2f(xOuter, yOuter);
        glVertex2f(xInner, yInner);
    }
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    drawRing(60.0f, 80.0f, 0.0f, 0.0f, 0.2f); //azul escuro
    drawRing(40.0f, 60.0f, 0.0f, 0.0f, 0.6f); //azul claro
    drawRing(20.0f, 40.0f, 0.0f, 0.0f, 0.2f); //azul escuro
    drawRing(0.0f, 20.0f, 1.0f, 1.0f, 1.0f);  //branco

    glFlush();
}

void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-100.0, 100.0, -100.0, 100.0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutInitWindowSize(640, 640);              
    glutInitWindowPosition(100, 100);            
    glutCreateWindow("Círculo Colorido");         

    init();                
    glutDisplayFunc(display); 
    glutMainLoop();           
    return 0;
}

