#include <GL/glut.h>
#include<bits/stdc++.h>
using namespace std;

int xs, ys, xe, ye;

void display() {
  glClearColor(1.0, 1.0, 1.0, 1.0);
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f(0.2, 0.0, 0.8);
  glPointSize(2.0);
  glBegin(GL_POINTS);

  float m = (float)(ye - ys) / (xe - xs);
  cout << "Slope m: " << m << endl;

  if (abs(m) <= 1) {
    if (xs > xe) { swap(xs, xe); swap(ys, ye); }

    float X = xs, Y = ys;

    while (X <= xe) {
      glVertex2i(round(X), round(Y));
      X += 1;
      Y += m;
    }
  }
  else {
    if (ys > ye) { swap(xs, xe); swap(ys, ye); }

    float X = xs, Y = ys;

    while (Y <= ye) {
      glVertex2i(round(X), round(Y));
      Y += 1;
      X += 1.0 / m;
    }
  }

  glEnd();
  glFlush();
}

int main(int argc, char **argv) {
  cout << "Enter xs ys: ";
  cin >> xs >> ys;
  cout << "Enter xe ye: ";
  cin >> xe >> ye;

  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(640, 480);
  glutCreateWindow("DDA Line Drawing Algorithm m<1");

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0.0, 640.0, 0.0, 480.0);
  glutDisplayFunc(display);
  glutMainLoop();

  return 0;
}
