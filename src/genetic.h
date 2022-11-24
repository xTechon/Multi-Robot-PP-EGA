#import "grid.h"
#include <random>
#include <tuple>

class Genetic {
  Grid *terrain; // reference to grid for other functions
  std::vector<std::vector<std::pair<int, int>>> potPaths;
  std::vector<std::pair<int, int>> initPath;
  std::pair<int, int> start;
  std::pair<int, int> dest;
  void genInitPath();

public:
  Genetic(Grid *grid);
  void crossover();
  void deletion();
  void mutation();
};
