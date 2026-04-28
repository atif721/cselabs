#include <GL/glut.h>
#include <bits/stdc++.h>
using namespace std;

void display() {
  glClearColor(1, 1, 1, 1);
  glClear(GL_COLOR_BUFFER_BIT);
  glPointSize(3.0);
  glBegin(GL_POINTS);
  float xs = 0.1, ys = 0.2;
  float xe = 0.9, ye = 0.9;
  if (xs > xe) {
    swap(xs, xe);
  }
  float x = xs;
  float y = ys;
  while (x <= xe) {
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(x, y);
    x += 0.001;
  }
  glEnd();
  glFlush();
}
int main(int argc, char **argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(500, 500);
  glutInitWindowPosition(100, 100);
  glutCreateWindow("Drawing Horizontal Line using Points");
  glutDisplayFunc(display);
  glutMainLoop();

  return 0;
}