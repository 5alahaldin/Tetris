#include "engine.hpp"

#include <GL/freeglut.h>
#include <GL/glut.h>

Engine::Engine() : speed(200), level(1), isPaused(0) {
  srand(time(NULL));
}

void Engine::run() {
  if (!isStarted) {
    GM.StartScreen();
    return;
  }
  if (isPaused) {
    glutSwapBuffers();

    return;
  }

  GM.removeLine();
  GM.drawGrid();
  GM.drawTetris();
  GM.drawScore();
  GM.drawLevel();

  GM.moveDown();

  if (GM.isGameOver()) {
    GM.restart();
    speed = 300;
  } else if (GM.getScore() >= GM.getLevel() * 500) {
    GM.levelUp();
    if (speed >= 100) speed = 300 - 20;
  }
}

int Engine::getSpeed() {
  return speed;
}

void Engine::normalKey(unsigned char key, int x, int y) {
  char lower = tolower(key);
  switch (lower) {
    case 'q':
      exit(0);
      break;
    case 'r':
      GM.restart();
      break;
    case ' ':
      GM.fullDown();
      break;
    case 'p':
      isPaused = !isPaused;
      break;
    case 's':
      isStarted = true;
      break;
    default:
      break;
  }
}

void Engine::specialKey(int key, int x, int y) {
  switch (key) {
    case GLUT_KEY_UP:
      GM.rotate();
      break;
    case GLUT_KEY_DOWN:
      GM.moveDown();
      break;
    case GLUT_KEY_LEFT:
      GM.moveLeft();
      break;
    case GLUT_KEY_RIGHT:
      GM.moveRight();
      break;
    default:
      break;
  }
}
