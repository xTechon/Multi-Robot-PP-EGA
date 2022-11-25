#include "EGA.h"

void printGraphObs(Grid* grid) {
  for (int j = (grid->getHeight() - 1); j >= 0; j--) {
    for (int i = 0; i < grid->getWidth(); i++) {
      if (grid->map[i][j][0] == 1) {
        std::cout << fmt::format(fmt::emphasis::bold | fg(fmt::color::red), "{:>4d}", 1);
      } else {
        std::cout << fmt::format(fmt::emphasis::faint | fg(fmt::color::dark_cyan), "{:>4d}", 0);
      }
    }
    std::cout << std::endl << std::endl;
  }
}

void printGraphAPF(Grid* grid) {
  for (int j = (grid->getHeight() - 1); j >= 0; j--) {
    for (int i = 0; i < grid->getWidth(); i++) {
      if (grid->map[i][j][1] > 0) {
        std::cout << fmt::format(fmt::emphasis::bold | fg(fmt::color::red), "{:>4d}", grid->map[i][j][1]);
      } else {
        std::cout << fmt::format(fmt::emphasis::faint | fg(fmt::color::dark_cyan), "{:>4d}", grid->map[i][j][1]);
      }
    }
    std::cout << std::endl << std::endl;
  }
}
