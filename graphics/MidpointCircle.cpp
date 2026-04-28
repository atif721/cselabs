#include <GL/glut.h>
#include <iostream>

using namespace std;

int radiusVal;

void drawCirclePoints(int cx, int cy, int px, int py) {
    glVertex2i(cx + px, cy + py);
    glVertex2i(cx + py, cy + px);
    glVertex2i(cx + py, cy - px);
    glVertex2i(cx + px, cy - py);
    glVertex2i(cx - px, cy - py);
    glVertex2i(cx - py, cy - px);
    glVertex2i(cx - py, cy + px);
    glVertex2i(cx - px, cy + py);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glPointSize(4);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-10, 620, -10, 450);

    int xPos = 0;
    int yPos = radiusVal;
    int decision = 1 - radiusVal;

    int centerX = radiusVal;
    int centerY = radiusVal;

    glBegin(GL_POINTS);
    glColor3f(0.2f, 0.8f, 0.5f);

    while (xPos <= yPos) {
        drawCirclePoints(centerX, centerY, xPos, yPos);

        if (decision < 0) {
            decision += (2 * xPos) + 3;
        } else {
            decision += (2 * xPos) - (2 * yPos) + 5;
            yPos--;
        }
        xPos++;
    }

    glEnd();
    glFlush();
}

int main(int argc, char **argv) {
    cout << "Radius: ";
    cin >> radiusVal;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    glutInitWindowSize(620, 450);
    glutInitWindowPosition(400, 100);

    glutCreateWindow("Circle Drawing - Midpoint Method");

    glClearColor(1.0, 1.0, 1.0, 1.0);
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}