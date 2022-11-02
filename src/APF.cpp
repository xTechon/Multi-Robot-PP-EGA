#include "APF.h"

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
}
