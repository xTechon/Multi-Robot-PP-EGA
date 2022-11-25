#include "grid.h"

#ifndef EXTRA_DEBUGGER
  #define EXTRA_DEBUGGER

inline void DEVIMPLMSG() { fmt::print("\nFUNCTION NOT IMPLEMENTED"); }

void printGraphObs(Grid* grid);
void printGraphAPF(Grid* grid);
#endif
