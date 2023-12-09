// engine.h
// #pragma once

#include <GL/glut.h>

#include <cstdlib>
#include <ctime>

#include "game.hpp"

class Engine {
 private:
  int speed;
  int level;
  bool isPaused;
  bool isStarted;
  Game GM;

 public:
  Engine();
  void run();
  int getSpeed();
  void normalKey(unsigned char key, int x, int y);
  void specialKey(int key, int x, int y);
  void startGame();
};