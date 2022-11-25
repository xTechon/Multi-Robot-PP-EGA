#import "grid.h"

#include <random>
#include <tuple>

#ifndef GENETIC_ALGORITHM
  #define GENETIC_ALGORITHM

class Genetic {
  Grid* terrain;                                          // reference to grid for other functions
  std::vector<std::vector<std::pair<int, int>>> potPaths; // vector of potential paths
  std::vector<std::pair<int, int>> initPath;              // stores the initally generated path
  std::vector<std::pair<int, int>> solPath;               // stores the solution path
  std::pair<int, int> start;
  std::pair<int, int> dest;
  void genInitPath();

public:
  Genetic(Grid* grid);
  void crossover();
  void deletion();
  void mutation();
};
#endif
