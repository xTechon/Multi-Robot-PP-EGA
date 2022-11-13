#include "APF.h"

int Grid::getWidth() { return width; }
int Grid::getHeight() { return height; }

// default values for a grid size
Grid::Grid(void) {
  this->width = 10;
  this->height = 10;
  this->map = std::vector<std::vector<std::vector<int>>>(
      this->width,
      std::vector<std::vector<int>>(this->height, std::vector<int>(2, 0)));
}

Grid::Grid(int w, int h) {
  this->width = w;
  this->height = h;
  this->map = std::vector<std::vector<std::vector<int>>>(
      this->width,
      std::vector<std::vector<int>>(this->height, std::vector<int>(2, 0)));
}

bool Grid::setObstacle(int w, int h) {
  if (!checkIndex(w, h))
    return false;
  this->map[w][h][0] = 1;
  return true;
}

bool Grid::clearObstacle(int w, int h) {
  if (!checkIndex(w, h))
    return false;
  this->map[w][h][0] = 0;
  return true;
}

// Returns true if index is in bounds, false if not
bool Grid::checkIndex(int w, int h) {
  if ((w >= this->width) || (h >= this->height) || (w < 0) || (h < 0)) {
#ifndef NDEBUG
    std::cout << fmt::format("ERROR: INDEX OUT OF BOUNDS") << std::endl;
#endif
    return false;
  } else
    return true;
}

bool Grid::setPMV(int w, int h, int val) {
  if (!checkIndex(w, h))
    return false;
  this->map[w][h][1] = val;
  return true;
}

bool Grid::clearPMV(int w, int h) {
  if (!checkIndex(w, h))
    return false;
  this->map[w][h][1] = 0;
  return true;
}

void Grid::clearObstacles() {
  for (int i = 0; i < this->width; i++) {
    for (int j = 0; j < this->height; j++) {
      this->map[i][j][0] = 0;
    }
  }
}

void Grid::clearPMVs() {
  for (int i = 0; i < this->width; i++) {
    for (int j = 0; j < this->height; j++) {
      this->map[i][j][1] = 0;
    }
  }
  return;
}

void Grid::clearMap() {
  this->clearObstacles();
  this->clearPMVs();
  return;
}

std::string Grid::printVal(int x, int y, int z) {
  std::string result;
  result =
      fmt::format("value at ({}, {}, {}): {}", x, y, z, this->map[x][y][z]);
  return result;
}
