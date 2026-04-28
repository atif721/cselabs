#include <GL/glut.h>
#include<bits/stdc++.h>
using namespace std;

void drawLine(int xs, int ys, int xe, int ye) {
  glPointSize(2.0);
  glColor3f(0.2, 0.0, 0.8);
  glBegin(GL_POINTS);

  if (xe == xs) {
    if (ys > ye) swap(ys, ye);
    for (int y = ys; y <= ye; y++)
      glVertex2i(xs, y);
    glEnd();
    return;
  }

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
  } else {
    if (ys > ye) { swap(xs, xe); swap(ys, ye); }
    float X = xs, Y = ys;
    while (Y <= ye) {
      glVertex2i(round(X), round(Y));
      Y += 1;
      X += 1.0 / m;
    }
  }

  glEnd();
}

void drawCirclePoints(int cx, int cy, int px, int py) {
  glVertex2i(cx + px, cy + py);
  glVertex2i(cx + py, cy + px);
  glVertex2i(cx + py, cy - px);
  glVertex2i(cx + px, cy - py);
  glVertex2i(cx - px, cy - py);
  glVertex2i(cx - py, cy - px);
  glVertex2i(cx - py, cy + px);
  glVertex2i(cx - px, cy + py);
}

void drawCircle(int centerX, int centerY, int radiusVal) {
  glPointSize(2.0);
  glColor3f(0.2, 0.0, 0.8);
  glBegin(GL_POINTS);

  int xPos = 0;
  int yPos = radiusVal;
  int decision = 1 - radiusVal;

  while (xPos <= yPos) {
    drawCirclePoints(centerX, centerY, xPos, yPos);

    if (decision < 0) {
      decision += (2 * xPos) + 3;
    } else {
      decision += (2 * xPos) - (2 * yPos) + 5;
      yPos--;
    }
    xPos++;
  }
  glEnd();
}

void display() {
  glClearColor(1.0, 1.0, 1.0, 1.0);
  glClear(GL_COLOR_BUFFER_BIT);

  drawLine(160, 260, 480, 260);
  drawLine(480, 260, 320, 100);
  drawLine(160, 260, 320, 100);
  drawCircle(320, 260 + 80, 80);

  glFlush();
}

int main(int argc, char **argv) {

  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(800, 600);
  glutCreateWindow("DDA Line Drawing Algorithm m<1");
  glMatrixMode(GL_PROJECTION);

  glLoadIdentity();
  gluOrtho2D(0.0, 800.0, 0.0, 600.0);

  glutDisplayFunc(display);
  glutMainLoop();

  return 0;
}
