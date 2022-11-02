#include "APF.h"
#include <fmt/core.h>

int Grid::getWidth() { return width; }
int Grid::getHeight() { return height; }

// default values for a grid size
Grid::Grid(void) {
  this->width = 10;
  this->height = 10;
}

Grid::Grid(int w, int h) {
  this->width = w;
  this->height = h;
  this->map = std::vector<std::vector<std::vector<int>>>(
      width, std::vector<std::vector<int>>(height, std::vector<int>(2, 0)));
}

void Grid::setObstacle(int w, int h) {
  DEVIMPLMSG();
  return;
}

void Grid::clearObstacle(int w, int h) {
  DEVIMPLMSG();
  return;
}

void Grid::setPMV(int w, int h, int val) {
  DEVIMPLMSG();
  return;
}

void Grid::clearMap() {
  DEVIMPLMSG();
  return;
}
