#include "engine.hpp"

#include <GL/freeglut.h>
#include <GL/glut.h>

#include <chrono>
#include <thread>

Engine::Engine() : speed(300), level(1), isPaused(0) {
  srand(time(NULL));
}

void Engine::startGameLoop() {
  std::thread gameLoop([this]() {
    while (1) {
      if (!this->isPaused) this->GM.moveDown();
      std::this_thread::sleep_for(std::chrono::milliseconds(this->speed));
    }
  });
  gameLoop.detach();
}

bool Engine::getIsStarted() {
  return isStarted;
}

bool Engine::getIsPaused() {
  return isPaused;
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

  GM.drawScore();
  GM.drawLevel();

  GM.removeLine();
  GM.drawGrid();
  GM.drawTetris();

  if (!isGameLoopStarted) {
    startGameLoop();
    isGameLoopStarted = true;
  }

  if (GM.isGameOver()) {
    GM.restart();
  } else if (GM.getScore() >= GM.getLevel() * 500) {
    GM.levelUp();
    if (speed > 100) speed = 300 - 20;
  }
}

void Engine::normalKey(unsigned char key, int x, int y) {
  char lower = tolower(key);
  if (!isPaused and isStarted) {
    switch (lower) {
      case 'r':
        GM.restart();
        break;
      case ' ':
        GM.fullDown();
        break;
      default:
        break;
    }
  }
  if (lower == 'q') exit(0);
  if (lower == 13) isStarted = 1;
  if (lower == 'p') isPaused = !isPaused;
}

void Engine::specialKey(int key, int x, int y) {
  if (!isPaused) {
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
}
