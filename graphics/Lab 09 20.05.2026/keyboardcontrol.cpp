#include <GL/gl.h>
#include <GL/glut.h>
#include <iostream>
#include <math.h>

float Ax = 100, Ay = 300, Bx = 500, By = 300, Cx = 300, Cy = 50;


void display() {
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f(0.0, 0.0, 0.0);
  glLineWidth(2);

  glBegin(GL_LINE_LOOP);
  glVertex2f(Ax, Ay);
  glVertex2f(Bx, By);
  glVertex2f(Cx, Cy);
  glEnd();

  glFlush();
}

void translate(int Tx = 5, int Ty = 5) {
  Ax = Ax + Tx;
  Ay = Ay + Ty;

  Bx = Bx + Tx;
  By = By + Ty;

  Cx = Cx + Tx;
  Cy = Cy + Ty;
}

void scale(double Sx = 5, double Sy = 5) {
  Ax = Ax * Sx;
  Ay = Ay * Sy;

  Bx = Bx * Sx;
  By = By * Sy;

  Cx = Cx * Sx;
  Cy = Cy * Sy;
}

void rotatePoint(float &x, float &y, float angle = 2) {
  float oldX = x;
  float oldY = y;
  double radian = angle * 3.14 / 180.0;
  x = oldX * cos(radian) - oldY * sin(radian);
  y = oldX * sin(radian) + oldY * cos(radian);
}



void keyboard(unsigned char key, int x, int y) {
  switch (key) {
  case 27:
  case 'q':
    exit(0);
    break;
  case 't':
    translate(5, 5);
    break;
  case 'T':
    translate(-5, -5);
    break;
  case 's':
    scale(1.1, 1.1);
    break;
  case 'S':
    scale(0.9, 0.9);
    break;
  case 'R':
    rotatePoint(Ax, Ay);
    rotatePoint(Bx, By);
    rotatePoint(Cx, Cy);
    break;
  case 'r':
    rotatePoint(Ax, Ay, -1);
    rotatePoint(Bx, By, -1);
    rotatePoint(Cx, Cy, -1);
    break;
  default:
    std::cout << "ASCII key `" << key << "` pressed\n";
  }
  glutPostRedisplay();
}

int main(int argc, char **argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(800, 600);
  glutCreateWindow("GLUT Project");

  gluOrtho2D(0, 600, 0, 600);
  glClearColor(1.0, 1.0, 1.0, 1.0);

  glutDisplayFunc(display);
  glutKeyboardFunc(keyboard);
  glutMainLoop();

  return 0;
}