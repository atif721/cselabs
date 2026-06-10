// Topic: 2D Geometric Transformations Using OpenGL

#include <GL/glut.h>
#include <bits/stdc++.h>
using namespace std;

int P_X, P_Y, choice = 0, edges;
vector<int> Vec_X;
vector<int> Vec_Y;

int tx, ty;
double sx, sy, xf, yf, xr, yr;
double theta, thetaRad;
char reflectionAxis, shearingAxis;
int ShX, ShY;

int Round(double d) {
  return floor(d + 0.5);
}

void drawPolygon() {
  glBegin(GL_POLYGON);
  glColor3f(1.0, 0.0, 0.0);

  for (int i = 0; i < edges; i++) {
    glVertex2i(Vec_X[i], Vec_Y[i]);
  }

  glEnd();
}

void Translation(int x, int y) {
  glBegin(GL_POLYGON);
  glColor3f(0.0, 1.0, 0.0);

  for (int i = 0; i < edges; i++) {
    glVertex2i(Vec_X[i] + x, Vec_Y[i] + y);
  }

  glEnd();
}

void Scaling(double x, double y) {
  glBegin(GL_POLYGON);
  glColor3f(0.0, 1.0, 0.0);

  for (int i = 0; i < edges; i++) {
    glVertex2i(
      Round((Vec_X[i] * x) + xf * (1 - x)),
      Round((Vec_Y[i] * y) + yf * (1 - y))
    );
  }

  glEnd();
}

void Rotation(double thetaRad) {
  glBegin(GL_POLYGON);
  glColor3f(0.0, 1.0, 0.0);

  for (int i = 0; i < edges; i++) {
    glVertex2i(
      Round(xr + (Vec_X[i] - xr) * cos(thetaRad) - (Vec_Y[i] - yr) * sin(thetaRad)),
      Round(yr + (Vec_X[i] - xr) * sin(thetaRad) + (Vec_Y[i] - yr) * cos(thetaRad))
    );
  }

  glEnd();
}

void Reflection(char reflectionAxis) {
  glBegin(GL_POLYGON);
  glColor3f(0.0, 1.0, 0.0);

  if (reflectionAxis == 'a' || reflectionAxis == 'A') {
    // X Axis
    for (int i = 0; i < edges; i++) {
      glVertex2i(Vec_X[i], -Vec_Y[i]);
    }
  } else if (reflectionAxis == 'b' || reflectionAxis == 'B') {
    // Y Axis
    for (int i = 0; i < edges; i++) {
      glVertex2i(-Vec_X[i], Vec_Y[i]);
    }
  } else if (reflectionAxis == 'c' || reflectionAxis == 'C') {
    // X = Y Axis
    for (int i = 0; i < edges; i++) {
      glVertex2i(Vec_Y[i], Vec_X[i]);
    }
  } else if (reflectionAxis == 'd' || reflectionAxis == 'D') {
    // Origin
    for (int i = 0; i < edges; i++) {
      glVertex2i(-Vec_X[i], -Vec_Y[i]);
    }
  }

  glEnd();
}

void Shearing() {
  glBegin(GL_POLYGON);
  glColor3f(0.0, 1.0, 0.0);

  if (shearingAxis == 'x' || shearingAxis == 'X') {
    for (int i = 0; i < edges; i++) {
      glVertex2i(Vec_X[i] + ShX * Vec_Y[i], Vec_Y[i]);
    }
  } else if (shearingAxis == 'y' || shearingAxis == 'Y') {
    for (int i = 0; i < edges; i++) {
      glVertex2i(Vec_X[i], Vec_Y[i] + ShY * Vec_X[i]);
    }
  }

  glEnd();
}

void drawAxis() {
  glColor3f(1.0, 1.0, 1.0);

  glBegin(GL_LINES);
  glVertex2i(-100, 0);
  glVertex2i(100, 0);

  glVertex2i(0, -100);
  glVertex2i(0, 100);
  glEnd();
}

void display(void) {
  glClear(GL_COLOR_BUFFER_BIT);

  drawAxis();

  if (choice == 1) {
    drawPolygon();
    Translation(tx, ty);
  } else if (choice == 2) {
    drawPolygon();
    Scaling(sx, sy);
  } else if (choice == 3) {
    drawPolygon();
    Rotation(thetaRad);
  } else if (choice == 4) {
    drawPolygon();
    Reflection(reflectionAxis);
  } else if (choice == 5) {
    drawPolygon();
    Shearing();
  }

  glFlush();
}

void init(void) {
  glClearColor(0.10, 0.10, 0.10, 0.0);
  glMatrixMode(GL_PROJECTION);
  gluOrtho2D(-100.0, 100.0, -100.0, 100.0);
}

int main(int argc, char **argv) {
  cout << "2D Geometric Transformation" << endl;
  cout << "---------------------------" << endl;
  cout << "1. Translation" << endl;
  cout << "2. Scaling (Fixed Point)" << endl;
  cout << "3. Rotation (Rotation/Pivot Point)" << endl;
  cout << "4. Reflection" << endl;
  cout << "5. Shearing" << endl;
  cout << "6. Quit" << endl;

  cout << "Enter Choice: ";
  cin >> choice;

  if (choice == 6) {
    return 0;
  }

  cout << "Enter the No. of Edges of Polygon: ";
  cin >> edges;

  for (int i = 0; i < edges; i++) {
    cout << "Enter the Co-ordinates for Vertex " << i + 1 << " : ";
    cin >> P_X >> P_Y;

    Vec_X.push_back(P_X);
    Vec_Y.push_back(P_Y);
  }

  if (choice == 1) {
    cout << "Enter the Values of Translation Pair (tx, ty): ";
    cin >> tx >> ty;
  } else if (choice == 2) {
    cout << "Enter the Scaling Factors (sx, sy): ";
    cin >> sx >> sy;

    cout << "Enter the Fixed Point (xf, yf): ";
    cin >> xf >> yf;
  } else if (choice == 3) {
    cout << "Enter the Value of Theta for Rotation Degree: ";
    cin >> theta;

    thetaRad = theta * 3.1416 / 180;

    cout << "Enter the Rotation/Pivot Point (xr, yr): ";
    cin >> xr >> yr;
  } else if (choice == 4) {
    cout << "Choose Reflection Axis" << endl;
    cout << "-----------------------" << endl;
    cout << "a) X Axis" << endl;
    cout << "b) Y Axis" << endl;
    cout << "c) X = Y Axis" << endl;
    cout << "d) About the Origin" << endl;
    cout << "-----------------------" << endl;

    cout << "Enter Reflection Axis: ";
    cin >> reflectionAxis;
  } else if (choice == 5) {
    cout << "Enter Shearing Axis (X or Y): ";
    cin >> shearingAxis;

    if (shearingAxis == 'x' || shearingAxis == 'X') {
      cout << "Enter the Shearing Factor for X Axis (ShX): ";
      cin >> ShX;
      ShY = 0;
    } else if (shearingAxis == 'y' || shearingAxis == 'Y') {
      cout << "Enter the Shearing Factor for Y Axis (ShY): ";
      cin >> ShY;
      ShX = 0;
    }
  }

  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowPosition(100, 100);
  glutInitWindowSize(500, 500);
  glutCreateWindow("2D Geometric Transformations");

  init();
  glutDisplayFunc(display);
  glutMainLoop();

  return 0;
}