#include "EGA.h"

void printGraphObs(Grid *grid) {
  for (int i = 0; i < grid->getWidth(); i++) {
    for (int j = 0; j < grid->getHeight(); j++) {
      if (grid->map[i][j][0] == 1) {
        fmt::print(fmt::emphasis::bold | fg(fmt::color::red), "{^:2d}", 1);
      } else {
        fmt::print(fmt::emphasis::conceal | fg(fmt::color::aqua), "{^:2d}", 0);
      }
    }
    fmt::print("\n");
  }
}
