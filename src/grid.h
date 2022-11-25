#include <fmt/core.h>
#include <iostream>
#include <stdlib.h>
#include <vector>

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

  void clearObstacles();                     // clears all obstacles in map
  void clearPMVs();                          // clears all the PMVs on the map
  void clearMap();                           // sets all values in map to 0
  std::string printVal(int x, int y, int z); // prints out a value from the map
  // obstacles are stored in [w][h][0]
  // PMVs are stored in [w][h][1]
  std::vector<std::vector<std::vector<int>>> map; // 3d array to store obstacle and PMV information

private:
  int height;
  int width;
  std::pair<int, int> start;
  std::pair<int, int> dest;
  bool checkIndex(int w, int h); // returns false if index out of bounds
};
