#include "grid.h"

#include <random>
#include <tuple>

#ifndef APotF
  #define APotF

class APF {
public:
  APF(void);
  void GenerateAPF(Grid* grid); // generates an APF given a grid
};

#endif
