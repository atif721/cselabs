#include <GL/glut.h>

float x = 0.0f;
float y = 0.0f;

void display() {

    glClear(GL_COLOR_BUFFER_BIT);
    glPointSize(30.0f);
    glColor3f(15.0f / 255.0f,
        217.0f / 255.0f,
        1.0f);

    glBegin(GL_POINTS);
    glVertex2f(x, y);
    glEnd();
    glFlush();
}

void update(int v) {
    if (x >= 600 || y >= 600) {
        x = 0.0f;
        y = 0.0f;
    } else {
        x += 50.0f;
        y += 50.0f;
    }
    glutPostRedisplay();
    glutTimerFunc(160, update, 0);
}

int main(int argc, char* argv[]) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Moving pixel");
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    gluOrtho2D(0.0, 600.0, 0.0, 600.0);
    glutDisplayFunc(display);
    glutTimerFunc(160, update, 0);
    glutMainLoop();
    return 0;
}