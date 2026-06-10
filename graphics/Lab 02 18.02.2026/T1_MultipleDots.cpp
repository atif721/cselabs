#include <GL/glut.h>
#include <bits/stdc++.h>

void display() {
  glClearColor(1, 1, 1, 1);
  glClear(GL_COLOR_BUFFER_BIT);
  glPointSize(8.0);
  glBegin(GL_POINTS);

  glColor3f(0.2, 0.3, 1.9);
  glVertex2f(0.5, -0.5);

  glColor3f(0.3, 0.5, 1.5);
  glVertex2f(0.3, 0.7);

  glColor3f(0.9, 0.1, 0.5);
  glVertex2f(0.0, 0.7);

  glColor3f(0.1, 1.6, 0.9);
  glVertex2f(-0.3, -0.3);

  glColor3f(0.5, 0.6, 0.6);
  glVertex2f(0.5, 0.9);

  glEnd();

  glFlush();
}

int main(int argc, char **argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
  glutInitWindowSize(500, 500);
  glutInitWindowPosition(100, 100);
  glutCreateWindow("Multiple Pixel Printing");
  glutDisplayFunc(display);
  glutMainLoop();

  return 0;
}
