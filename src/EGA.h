#include <fmt/color.h>
#include <fmt/core.h>
#ifndef NDEBUG
  #include "debug.h"
#endif

#ifndef EGenA
  #define EGenA

namespace Env {
class APF;         // to contain the algorithms for generating an APF map
class Grid;        // to contain the actual map enviornment
class Edges;       // to contain the edges of the map
class FileHandler; // to handle file imports
} // namespace Env

namespace EGA {
class Interact;
class Genetic;
} // namespace EGA

// GRID Class TODO:
// DONE create a grid of size w x h x 2
// DONE set individual values of grid
// DONE: import map from file
// DONE: ability to set map potentials

// GRID GUI TODO:
// DONE import maps from gui
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
#endif
