#include <fmt/core.h>
#include <stdlib.h>

#include <cmath>
#include <iostream>
#include <map>
#include <random>
#include <vector>

#include "imgui.h"

namespace Env {
class APF;          // to contain the algorithms for generating an APF map
class Grid;         // to contain the actual map enviornment
class Edges;        // to contain the edges of the map
class FileHandler;  // to handle file imports
}  // namespace Env

class APF {
 public:
  APF(Grid grid);
};

class Grid {
 public:
  Grid(void);
  Grid(int w, int h);
  int getWidth();
  int getHeight();

  // These functions return false if index given out of bounds
  bool setObstacle(int w, int h);
  bool clearObstacle(int w, int h);
  bool setPMV(int w, int h, int val);
  bool clearPMV(int w, int h);
  bool isObstacle(int w, int h);

  int getPMV(int w, int h);

  std::pair<int, int> getStart();
  std::pair<int, int> getDest();

  void clearObstacles();                      // clears all obstacles in map
  void clearPMVs();                           // clears all the PMVs on the map
  void clearMap();                            // sets all values in map to 0
  std::string printVal(int x, int y, int z);  // prints out a value from the map
  // obstacles are stored in [w][h][0]
  // PMVs are stored in [w][h][1]
  std::vector<std::vector<std::vector<int>>>
      map;  // 3d array to store obstacle and PMV information

 private:
  int height;
  int width;
  bool checkIndex(int w, int h);  // returns false if index out of bounds
};

class FileHandler {
 public:
  std::string *drawGUI(std::string *fileP);  // generate the file picker dialog
};

inline void DEVIMPLMSG() { fmt::print("\nFUNCTION NOT IMPLEMENTED"); }
// GRID Class TODO:
// DONE create a grid of size w x h x 2
// DONE set individual values of grid
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
