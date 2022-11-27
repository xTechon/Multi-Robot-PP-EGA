#include "grid.h"

#include <cstdlib>

#ifndef INTERACT
  #define INTERACT

class Interact {
  int borderx[5];
  int bordery[5];

public:
  Interact(void);
  void resizeBorder(Grid* map); // add a border to the grid
  void clearBorder();           // resets border corners to 0
  void addStartAndDest();       // allows the user to add start and end points
  void drawMapObs(Grid* map);   // draws a loaded map to screen
};
#endif
