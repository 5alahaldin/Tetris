#include <GL/glut.h>

#include <iostream>

#include "Includes/engine.hpp"

Engine eng;

void display() {
  glClear(GL_COLOR_BUFFER_BIT);
  eng.run();
  glutSwapBuffers();
}

void updatingLoop(int value) {
  glutTimerFunc(1000 / 30, updatingLoop, 0);

  glutPostRedisplay();
}

void normalKey(unsigned char key, int x, int y) {
  eng.normalKey(key, x, y);
}

void specialKey(int key, int x, int y) {
  eng.specialKey(key, x, y);
}
int main(int argc, char **argv) {
  int red = 196, green = 200, blue = 183;
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
  glutInitWindowSize(400, 800);
  glutInitWindowPosition(glutGet(GLUT_SCREEN_WIDTH) / 2 - 200, glutGet(GLUT_SCREEN_HEIGHT) / 2 - 400);
  glutCreateWindow("Tetris");

  glClearColor(red / 255.0, green / 255.0, blue / 255.0, 1.0);

  // left, right, bottom, top, near, far
  glOrtho(0, 10 * 10, 10 * 20, 0, 0.0, 0.1);

  // glDisable(GL_DEPTH_TEST);

  glutDisplayFunc(display);

  glutKeyboardFunc(normalKey);

  glutSpecialFunc(specialKey);

  glutTimerFunc(0, updatingLoop, 0);

  glutMainLoop();
}