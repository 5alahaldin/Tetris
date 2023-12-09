// #pragma once
#include <GL/glut.h>

#include <string>

struct Color {
  float r, g, b;
};

class Game {
 private:
  static const int rows = 20;
  static const int cols = 10;
  Color color;
  int x, y;
  int shape[4][4];
  float grid[rows][cols][3];
  int score, level;

 public:
  Game();
  Color getColor();
  void randomTetris();
  void drawGrid();
  void drawTetris();
  int collision();
  void update();
  void drawScore();
  void resetLevel();
  int getLevel();
  void drawLevel();
  void rotate();
  void removeLine();
  int getScore();
  void levelUp();
  bool isGameOver();
  void restart();
  void moveDown();
  void fullDown();
  void moveLeft();
  void moveRight();
  void StartScreen();
  void startGame();
};
