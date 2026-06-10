#include <GL/glut.h>
#include <bits/stdc++.h>
using namespace std;

int x1_, y1_, x2_, y2_, x3_, y3_;
float angle_;

void rotatePoint(int x, int y, int &xr, int &yr) {
  float rad = angle_ * M_PI / 180.0;
  xr = x * cos(rad) - y * sin(rad);
  yr = x * sin(rad) + y * cos(rad);
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

  int rx1, ry1, rx2, ry2, rx3, ry3;
  rotatePoint(x1_, y1_, rx1, ry1);
  rotatePoint(x2_, y2_, rx2, ry2);
  rotatePoint(x3_, y3_, rx3, ry3);

  glColor3f(0.4, 0.3, 0.8);
  glBegin(GL_LINES);
  glVertex2i(rx1, ry1); glVertex2i(rx2, ry2);
  glVertex2i(rx2, ry2); glVertex2i(rx3, ry3);
  glVertex2i(rx3, ry3); glVertex2i(rx1, ry1);
  glEnd();

  glFlush();
}

int main(int argc, char **argv) {
  cout << "Enter Values of x1 y1 x2 y2 x3 y3 : ";
  cin >> x1_ >> y1_ >> x2_ >> y2_ >> x3_ >> y3_;

  cout << "Enter rotation angle : ";
  cin >> angle_;

  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(600, 600);
  glutCreateWindow("Rotation");
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(-600, 600, -600, 600);
  glutDisplayFunc(display);
  glutMainLoop();
  return 0;
}

// 0 300 -260 -150 260 -150