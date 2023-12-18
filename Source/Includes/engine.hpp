
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
  bool isGameLoopStarted;
  Game GM;

 public:
  Engine();
  void run();
  void normalKey(unsigned char key, int x, int y);
  void specialKey(int key, int x, int y);
  void startGame();
  void startGameLoop();
  bool getIsStarted();
  bool getIsPaused();
};