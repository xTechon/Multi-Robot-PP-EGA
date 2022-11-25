#include "grid.h"

#include <cstdlib>

#ifndef INTERACT
  #define INTERACT

class Interact {
public:
  void drawMapTest(); // draws a map onscreen using implots
  void drawMapObs(Grid* map);
};
#endif
