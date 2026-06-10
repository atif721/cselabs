#include <GL/glut.h>
#include<bits/stdc++.h>
using namespace std;

int x1_, y1_, x2_, y2_, x3_, y3_, tx, ty;

void display() {
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glLineWidth(2.0);

    glColor3f(1.0, 0.0, 0.8);
    glBegin(GL_LINES);
    glVertex2i(x1_, y1_); glVertex2i(x2_, y2_);
    glVertex2i(x2_, y2_); glVertex2i(x3_, y3_);
    glVertex2i(x3_, y3_); glVertex2i(x1_, y1_);
    glEnd();

    glColor3f(0.5, 0.0, 0.8);
    glBegin(GL_LINES);
    glVertex2i(x1_ + tx, y1_ + ty); glVertex2i(x2_ + tx, y2_ + ty);
    glVertex2i(x2_ + tx, y2_ + ty); glVertex2i(x3_ + tx, y3_ + ty);
    glVertex2i(x3_ + tx, y3_ + ty); glVertex2i(x1_ + tx, y1_ + ty);
    glEnd();

    glFlush();
}

int main(int argc, char **argv) {
    cout << "Enter Values of x1 y1 x2 y2 x3 y3 : ";
    cin >> x1_ >> y1_ >> x2_ >> y2_ >> x3_ >> y3_;

    cout << "Enter values of tx ty : ";
    cin >> tx >> ty;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Translation");
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 600.0, 0.0, 600.0);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}

// 200 250 400 250 300 400 