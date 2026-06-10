#include <GL/glut.h>
#include <bits/stdc++.h>
using namespace std;

int x1_, y1_, x2_, y2_, x3_, y3_;
float shx, shy;

void shearPoint(int x, int y, int &xs, int &ys) {
  xs = x + shx * y;
  ys = y + shy * x;
}

void display() {
  glClearColor(1, 1, 1, 1);
  glClear(GL_COLOR_BUFFER_BIT);
  glLineWidth(2.0);

  glColor3f(1.0, 0.0, 0.8);
  glBegin(GL_LINES);
  glVertex2i(x1_, y1_); glVertex2i(x2_, y2_);
  glVertex2i(x2_, y2_); glVertex2i(x3_, y3_);
  glVertex2i(x3_, y3_); glVertex2i(x1_, y1_);
  glEnd();

  int sx1, sy1, sx2, sy2, sx3, sy3;
  shearPoint(x1_, y1_, sx1, sy1);
  shearPoint(x2_, y2_, sx2, sy2);
  shearPoint(x3_, y3_, sx3, sy3);

  glColor3f(0.5, 0.0, 0.8);
  glBegin(GL_LINES);
  glVertex2i(sx1, sy1); glVertex2i(sx2, sy2);
  glVertex2i(sx2, sy2); glVertex2i(sx3, sy3);
  glVertex2i(sx3, sy3); glVertex2i(sx1, sy1);
  glEnd();

  glFlush();
}

int main(int argc, char **argv) {
  cout << "Enter Values of x1 y1 x2 y2 x3 y3 : ";
  cin >> x1_ >> y1_ >> x2_ >> y2_ >> x3_ >> y3_;

  cout << "Enter values of shx shy : ";
  cin >> shx >> shy;

  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(600, 600);
  glutCreateWindow("Shearing");
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0, 600, 0, 600);
  glutDisplayFunc(display);
  glutMainLoop();
  return 0;
}

// 100 100 200 100 150 200