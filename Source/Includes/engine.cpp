#include "engine.hpp"

#include <GL/freeglut.h>
#include <GL/glut.h>

#include <chrono>
#include <thread>

Engine::Engine() : speed(300), level(1), isPaused(0) {
  srand(time(NULL));
}

// what is thread mean ?
// it's a function that run in parallel with the main function


void Engine::startGameLoop() {
  // Create a new thread that runs a game loop
  std::thread gameLoop([this]() {
    // This is the game loop. It will run indefinitely because of the "while (1)" condition
    while (1) {
      // Call the moveDown function of the Game instance (GM) to move the shape down
      this->GM.moveDown();

      // Pause the current thread for a duration equal to the value of the speed variable (in milliseconds)
      // This creates a delay between each moveDown call, which controls the speed at which the shape moves down
      std::this_thread::sleep_for(std::chrono::milliseconds(this->speed));
    }
  });

  // Detach the game loop thread from the main thread
  // This allows the game loop to run independently of the main thread, so it won't block other operations
  gameLoop.detach();
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
