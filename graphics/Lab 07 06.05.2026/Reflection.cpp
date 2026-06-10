#include <GL/glut.h>
#include <bits/stdc++.h>
using namespace std;

int x1_, y1_, x2_, y2_, x3_, y3_;

void drawTriangle(int ax, int ay, int bx, int by, int cx, int cy) {
  glBegin(GL_LINES);
  glVertex2i(ax, ay); glVertex2i(bx, by);
  glVertex2i(bx, by); glVertex2i(cx, cy);
  glVertex2i(cx, cy); glVertex2i(ax, ay);
  glEnd();
}

void display() {
  glClearColor(1, 1, 1, 1);
  glClear(GL_COLOR_BUFFER_BIT);
  glLineWidth(2.0);
  // Original
  glColor3f(1.0, 0.0, 0.8);
  drawTriangle(x1_, y1_, x2_, y2_, x3_, y3_);
  // Reflection about X-axis
  glColor3f(0.5, 0.0, 0.8);
  drawTriangle(
    x1_, -y1_,
    x2_, -y2_,
    x3_, -y3_
  );
  // Reflection about Y-axis
  glColor3f(0.0, 0.5, 1.0);
  drawTriangle(
    -x1_, y1_,
    -x2_, y2_,
    -x3_, y3_
  );
  // Reflection about y = x
  glColor3f(0.0, 0.8, 0.2);
  drawTriangle(
    y1_, x1_,
    y2_, x2_,
    y3_, x3_
  );

  glFlush();
}

int main(int argc, char **argv) {
  cout << "Enter Values of x1 y1 x2 y2 x3 y3 : ";
  cin >> x1_ >> y1_ >> x2_ >> y2_ >> x3_ >> y3_;

  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(600, 600);
  glutCreateWindow("Reflection");
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(-600, 600, -600, 600);
  glutDisplayFunc(display);
  glutMainLoop();
  return 0;
}

// 200 180 400 180 300 420