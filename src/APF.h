#include <fmt/core.h>
#include <iostream>
#include <map>
#include <stdlib.h>
#include <vector>

namespace Env {
class APF;   // to contain the algorithms for generating an APF map
class Grid;  // to contain the actual map enviornment
class Edges; // to contain the edges of the map
} // namespace Env

class APF {
public:
};

class Grid {
public:
  Grid(void);
  Grid(int w, int h);
  int getWidth();
  int getHeight();
  void setObstacle(int w, int h);
  void clearObstacle(int w, int h);
  void setPMV(int w, int h, int val); // potential map value
  void clearPMV(int w, int h);
  void clearMap();
  std::vector<std::vector<std::vector<int>>>
      map; // 3d array to store obstacle and PMV information

private:
  int height;
  int width;
};

inline void DEVIMPLMSG() { fmt::print("\nFUNCTION NOT IMPLEMENTED"); }
// GRID Class TODO:
// DONE create a grid of size w x h x 2
// TODO: set individual values of grid
// TODO: import map from file
// TODO: ability to set map potentials

// GRID GUI TODO:
// TODO: import maps from gui
// TODO: edit maps from gui
// TODO: export maps from gui

// EDGES Class TODO:
// TODO: use Grid Class object to pull map points from
// TODO: create a map to store the map edges
// TODO: store the edges in the map

// EDGES GUI TODO:
// TODO: display edges over map points

// APF Class TODO:
// TODO: use Grid and Edges classes to contain map data
// TODO: set start and end points
// TODO: generate potential map from start and end points
// TODO: gernate set of feasible solutions

// APF GUI TODO:
// TODO: set start and end points in gui
// TODO: view potential map overlay
// TODO: view all/subset of generated solution paths
