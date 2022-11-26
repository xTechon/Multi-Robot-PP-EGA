#include "grid.h"

#include <cstdlib>

#ifndef INTERACT
  #define INTERACT

class Interact {
  int borderx[5];
  int bordery[5];

public:
  Interact(Grid* map);
  void drawMapTest(); // draws a map onscreen using implots
  void drawMapObs(Grid* map);
};
#endif
