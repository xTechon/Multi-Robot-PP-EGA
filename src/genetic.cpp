#include "genetic.h"

#include <random>

void Genetic::genInitPath() {
  std::vector<std::pair<int, int>> temp;
  std::random_device rd;
  std::mt19937 gen(rd());
  // Generate the inital path to run genetic operations on
  for (unsigned int i = 0; i < 2; i++) {
    this->initPath.push_back(start);

    while (true) {
      int row    = this->initPath.back().first;
      int col    = this->initPath.back().second;
      int rowMod = 1;

      temp.clear();

      for (int j = 0; j < 3; j++) {
        int colMod = 1;
        for (int k = 0; k < 3; k++) {
          if (row + rowMod == -1 || col + colMod == -1 || row + rowMod == this->terrain->getHeight()
              || col + colMod == this->terrain->getWidth())
            break;
          if (this->terrain->getPMV(row + rowMod, col + colMod) > this->terrain->getPMV(row, col))
            temp.push_back(std::make_pair(row + rowMod, col + colMod));

          colMod--;
        }
        rowMod--;
      }

      int count = 0;
      int size  = temp.size();

      if (size == 0) break;

      else if (size > 1) {
        std::uniform_int_distribution<> rand(0, size - 1);
        count = rand(gen);
      }

      this->initPath.push_back(std::make_pair(temp[count].first, temp[count].second));

      if (initPath.back() == dest) {
        this->potPaths.push_back(initPath);
        break;
      }
    }

    // initPath.clear();
  }
}

Genetic::Genetic(Grid* grid) {
  this->terrain = grid;
  this->start   = grid->getStart();
  this->dest    = grid->getDest();
}

void Genetic::deletion() {
  std::vector<std::pair<int, int>> deletion;
  std::vector<std::tuple<float, int, int>> smooth;
  for (int i = 1; initPath[i] != dest; i++) {
    int row  = initPath[i].first;
    int col  = initPath[i].second;
    int row1 = initPath[i + 1].first;
    int row2 = initPath[i - 1].first;
    int col1 = initPath[i + 1].second;
    int col2 = initPath[i - 1].second;

    // float midx = float(row1 + row2) / 2;
    // float midy = float(col1 + col2) / 2;
    float midx1 = float(row + row1) / 2;
    float midy1 = float(col + col1) / 2;
    float midx2 = float(row + row2) / 2;
    float midy2 = float(col + col2) / 2;

    if (this->terrain->isObstacle(row, col)) break;
    else if (this->terrain->isObstacle(midx1, midy1) || this->terrain->isObstacle(int(round(midx1)), midy1)
             || this->terrain->isObstacle(midx1, int(round(midy1)))
             || this->terrain->isObstacle(int(round(midx1)), int(round(midy1))) || this->terrain->isObstacle(midx2, midy2)
             || this->terrain->isObstacle(int(round(midx2)), midy2) || this->terrain->isObstacle(midx2, int(round(midy2)))
             || this->terrain->isObstacle(int(round(midx2)), int(round(midy2))))
      continue;
    else deletion.push_back(std::make_pair(row, col));
  }

  float length;
  int rough;
  int safe;
  float sqrtTwo = sqrt(2);

  for (int i = 0; initPath.size() - 1; i++) {
    float x      = initPath[i].first - initPath[i + 1].first;
    float y      = initPath[i].second - initPath[i + 1].second;
    float distUp = sqrt((x * x) + (y * y));

    length += distUp;

    float x1       = initPath[i].first - initPath[i - 1].first;
    float y1       = initPath[i].second - initPath[i - 1].second;
    float distDown = sqrt((x1 * x1) + (y1 * y1));

    float x2      = initPath[i - 1].first - initPath[i + 1].first;
    float y2      = initPath[i - 1].second - initPath[i + 1].second;
    float distOut = sqrt((x2 * x2) + (y2 * y2));

    bool turn45 = distUp != distDown;
    bool turn90 = distUp == distDown ? ((distOut == 2 && distUp == sqrtTwo) || (distOut == sqrtTwo && distUp == 1)) : false;

    if (turn45) rough += 1;
    else if (turn90) rough += 2;
  }
}
