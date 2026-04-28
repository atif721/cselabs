#include <GL/glut.h>
#include <bits/stdc++.h>
using namespace std;

void display() {
  glClearColor(1, 1, 1, 1);
  glClear(GL_COLOR_BUFFER_BIT);
  glPointSize(3.0);
  glBegin(GL_POINTS);
  float xs = 0.1, ys = 0.1;
  float xe = 0.7, ye = 0.9;
  if (ys > ye) {
    swap(ys, ye);
  }
  float x = xs;
  float y = ys;
  while (y <= ye) {
    glColor3f(0.1, 0.1, 1.0);
    glVertex2f(x, y);
    y += 0.001;
  }
  glEnd();
  glFlush();
}
int main(int argc, char **argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(500, 500);
  glutInitWindowPosition(100, 100);
  glutCreateWindow("Drawing Vertical Line using Points");
  glutDisplayFunc(display);
  glutMainLoop();
  return 0;
}
