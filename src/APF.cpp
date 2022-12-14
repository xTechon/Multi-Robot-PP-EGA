#include "APF.h"

APF::APF(void) {};

void APF::GenerateAPF(Grid* grid) {
  // Code based off of PsudoCode from pg 111 of paper
  // Code can only work as the paper describes if temp is FIFO
  /*INITALIZATION SECTION*/
  std::map<std::pair<int, int>, int> open;   // list of all nodes w/out potential value
  std::queue<std::pair<int, int>> temp;      // list of all nodes w/potential value, but their neighbors do not
  std::map<std::pair<int, int>, int> closed; // list of all nodes w/ potential values, including neighbors
  int alpha = 1;                             // Decrement step

  std::pair<int, int> start = grid->getStart();
  std::pair<int, int> dest  = grid->getDest();

  int Eo = grid->getWidth() * grid->getHeight(); // set Gamma0

  // generate list of all nodes
  for (int h = 0; h < grid->getHeight(); h++) {
    for (int w = 0; w < grid->getWidth(); w++) {
      if (grid->isObstacle(w, h)) {
        closed[std::make_pair(w, h)] = -Eo; // Q <- all nodes assoc. w/obs, CLOSED <- Q
        grid->setPMV(w, h, -Eo);            // Assign -E0 potential to all nodes of Q
      } else {
        open[std::make_pair(w, h)] = 0; // OPEN <- All nodes
      }
    }
  }

  std::pair<int, int> Q; // Q appears to never really contain more than 1 node
  Q = dest;
  grid->setPMV(dest.first, dest.second, Eo); // Pq = Gamma0
  temp.push(Q);                              // Pq = Gamma0, Temp <- Q
  open.erase(dest);                          // OPEN[Q] = {}

  std::vector<std::pair<int, int>> N;

  // std::pair<int, int> node;

  /*MAIN LOOP*/
  while (!temp.empty()) {          // while ~isempty{TEMP}
    auto firstElem = temp.front(); // TEMP{1}
    Q              = firstElem;    // Q <- TEMP{1} (put the first element of TEMP in Q)

    /*N <-OPEN{neighbors of Q}*/
    N.push_back(std::make_pair(Q.first + 1, Q.second + 1)); // Top Right
    N.push_back(std::make_pair(Q.first + 1, Q.second));     // Right
    N.push_back(std::make_pair(Q.first + 1, Q.second - 1)); // Bottom Right
    N.push_back(std::make_pair(Q.first, Q.second - 1));     // Bottom
    N.push_back(std::make_pair(Q.first - 1, Q.second - 1)); // Bottom Left
    N.push_back(std::make_pair(Q.first - 1, Q.second));     // Left
    N.push_back(std::make_pair(Q.first - 1, Q.second + 1)); // Top Left
    N.push_back(std::make_pair(Q.first, Q.second + 1));     // Top

    for (auto i = N.begin(); i != N.end(); i++) {
      auto node = open.find(*i);
      if (node != open.end()) { // check if the neighbor was in open
        grid->setPMV(node->first.first, node->first.second, (grid->getPMV(Q.first, Q.second)) - alpha); // Pn = Pq - alpha
        temp.push(node->first);                                                                         // TEMP <- N
        open.erase(node->first);                                                                        // OPEN{N} = []

      }         // End if
    }           // End for
    temp.pop(); // TEMP{Q} = []
    N.clear();  // Empty N of all the old values
  }             // END - While
} // end GenerateAPF()

/*
void APF::GenerateAPF(Grid* grid) {
  std::vector<std::pair<int, int>> open;
  std::vector<std::pair<int, int>> Q;
  std::vector<std::pair<int, int>> temp;

  std::pair<int, int> start = grid->getStart();
  std::pair<int, int> dest  = grid->getDest();

  int Pq = grid->getWidth() * grid->getHeight();

  for (int h = 0; h < grid->getHeight(); h++) {
    for (int w = 0; w < grid->getWidth(); w++) {
      if (grid->isObstacle(w, h)) grid->setPMV(w, h, -1);
      else {
        open.push_back(std::make_pair(w, h));
        temp.push_back(std::make_pair(w, h));
        grid->setPMV(w, h, Pq);
      }
    }
  }

  while (!temp.empty()) {
    Q.push_back(temp[0]);
    temp.erase(temp.begin());

    std::vector<std::pair<int, int>> N;

    for (unsigned int i = 0; i < open.size(); i++) {
      if (((open[i].first == Q[0].first - 1 && open[i].second == Q[0].second - 1)
           || (open[i].first == Q[0].first - 1 && open[i].second == Q[0].second)
           || (open[i].first == Q[0].first - 1 && open[i].second == Q[0].second + 1)
           || (open[i].first == Q[0].first && open[i].second == Q[0].second - 1)
           || (open[i].first == Q[0].first && open[i].second == Q[0].second + 1)
           || (open[i].first == Q[0].first + 1 && open[i].second == Q[0].second - 1)
           || (open[i].first == Q[0].first + 1 && open[i].second == Q[0].second)
           || (open[i].first == Q[0].first + 1 && open[i].second == Q[0].second + 1))) {
        N.push_back(open[i]);

        grid->setPMV(open[i].first, open[i].second, grid->getPMV(Q[0].first, Q[0].second) - 1);

        temp.push_back(open[i]);
      }
    }

    for (unsigned int i = 0; i < N.size(); i++)
      for (unsigned int j = 0; j < open.size(); j++)
        if (N[i].first == open[j].first && N[i].second == open[j].second) {
          open.erase(open.begin() + j);
          break;
        }
    N.clear();
    Q.erase(Q.begin());
  }

  open.clear();
  temp.clear();


  std::vector<std::vector<std::pair<int, int>>> potPaths;
  std::vector<std::pair<int, int>> initPath;

  std::random_device rd;
  std::mt19937 gen(rd());
*/
/*
// Generate the inital path to run genetic operations on
for (unsigned int i = 0; i < 2; i++) {
  initPath.push_back(start);

  while (true) {
    int row = initPath.back().first;
    int col = initPath.back().second;
    int rowMod = 1;

    temp.clear();

    for (int j = 0; j < 3; j++) {
      int colMod = 1;
      for (int k = 0; k < 3; k++) {
        if (row + rowMod == -1 || col + colMod == -1 ||
            row + rowMod == grid->getHeight() ||
            col + colMod == grid->getWidth())
          break;
        if (grid->getPMV(row + rowMod, col + colMod) > grid->getPMV(row, col))
          temp.push_back(std::make_pair(row + rowMod, col + colMod));

        colMod--;
      }
      rowMod--;
    }

    int count = 0;
    int size = temp.size();

    if (size == 0)
      break;

    else if (size > 1) {
      std::uniform_int_distribution<> rand(0, size - 1);
      count = rand(gen);
    }

    initPath.push_back(std::make_pair(temp[count].first, temp[count].second));

    if (initPath.back() == dest) {
      potPaths.push_back(initPath);
      break;
    }
  }

  initPath.clear();
}
*/
// std::vector<std::vector<std::pair<int, int>>> potKin;

// crossover
/*if (potPaths[0].size() == potPaths[1].size()) {
  for (int i = 1; i < potPaths[0].size(); i++) {
    int x = (potPaths[0][i].first + potPaths[1][i].first) >> 1;
    int y = (potPaths[0][i].second + potPaths[1][i].second) >> 1;

    initPath.push_back(make_std::pair(x, y));
  }
  potKin.push_back(initPath);
  initPath.clear();
}*/
// else

// mutation
/*uniform_real_distribution<float> rand(0, 1);
initPath = potPaths[0];

for (int i = 1; i < initPath.size() - 1; i++) {
  int x = initPath[i].first;
  float alpha = rand(gen);
  float beta = rand(gen);
  x = x + (float)(initPath[i - 1].first - x) * alpha +
      (float)(initPath[i + 1].first - x) * beta;
  int y = initPath[i].second;
  y = y + (float)(initPath[i - 1].second - y) * alpha +
      (float)(initPath[i + 1].second - y) * beta;

  initPath[i].first = x;
  initPath[i].second = y;
}
potKin.push_back(initPath);*/

/*
initPath = potPaths[0];

// deletion
std::vector<std::pair<int, int>> deletion;
std::vector<std::tuple<float, int, int>> smooth;
for (int i = 1; initPath[i] != dest; i++) {
  int row = initPath[i].first;
  int col = initPath[i].second;
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

  if (grid->isObstacle(row, col))
    break;
  else if (grid->isObstacle(midx1, midy1) ||
           grid->isObstacle(int(round(midx1)), midy1) ||
           grid->isObstacle(midx1, int(round(midy1))) ||
           grid->isObstacle(int(round(midx1)), int(round(midy1))) ||
           grid->isObstacle(midx2, midy2) ||
           grid->isObstacle(int(round(midx2)), midy2) ||
           grid->isObstacle(midx2, int(round(midy2))) ||
           grid->isObstacle(int(round(midx2)), int(round(midy2))))
    continue;
  else
    deletion.push_back(std::make_pair(row, col));
}

float length;
int rough;
int safe;
float sqrtTwo = sqrt(2);

for (int i = 0; initPath.size() - 1; i++) {
  float x = initPath[i].first - initPath[i + 1].first;
  float y = initPath[i].second - initPath[i + 1].second;
  float distUp = sqrt((x * x) + (y * y));

  length += distUp;

  float x1 = initPath[i].first - initPath[i - 1].first;
  float y1 = initPath[i].second - initPath[i - 1].second;
  float distDown = sqrt((x1 * x1) + (y1 * y1));

  float x2 = initPath[i - 1].first - initPath[i + 1].first;
  float y2 = initPath[i - 1].second - initPath[i + 1].second;
  float distOut = sqrt((x2 * x2) + (y2 * y2));

  bool turn45 = distUp != distDown;
  bool turn90 = distUp == distDown ? ((distOut == 2 && distUp == sqrtTwo) ||
                                      (distOut == sqrtTwo && distUp == 1))
                                   : false;

  if (turn45)
    rough += 1;
  else if (turn90)
    rough += 2;
}
}
*/
