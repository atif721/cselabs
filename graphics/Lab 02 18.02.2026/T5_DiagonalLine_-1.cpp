#include <GL/glut.h>
#include <bits/stdc++.h>
using namespace std;

void display() {
  glClearColor(1, 1, 1, 1);
  glClear(GL_COLOR_BUFFER_BIT);

  glPointSize(3.0);
  glColor3f(0.6, 0.1, 1.0);

  float xs = -0.7, ys = 0.7;
  float xe = -0.1, ye = 0.1;

  float x = xs;
  float y = ys;

  float m = (ye - ys) / (xe - xs);
  cout << "Value of m : " << m << endl;

  glBegin(GL_POINTS);
  while (x <= xe) {
    glVertex2f(x, y);
    x += 0.001;
    y -= 0.001;   // since slope = -1
  }
  glEnd();

  glFlush();
}

int main(int argc, char **argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(500, 500);
  glutCreateWindow("Diagonal Line m = -1");
  glutDisplayFunc(display);
  glutMainLoop();
  return 0;
}