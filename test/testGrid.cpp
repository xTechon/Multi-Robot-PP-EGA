#include "../src/debug.h" //already includes grid.h
#include "test.h"

TEST_CASE("Grid Class functions") {
  Grid* sqrRoom = new Grid(10, 10);
  Grid* recRoom = new Grid(5, 10);
  Grid* hallway = new Grid(2, 1);

  REQUIRE(sqrRoom->getWidth() == 10);
  REQUIRE(sqrRoom->getHeight() == 10);
  REQUIRE(recRoom->getWidth() == 5);
  REQUIRE(recRoom->getHeight() == 10);

  SECTION("Grid sets obstacles") {
    /*Grid sets Obstacles*/
    // test sqrRoom
    REQUIRE(sqrRoom->setObstacle(9, 9) == true);
    REQUIRE(sqrRoom->setObstacle(10, 9) == false);
    REQUIRE(sqrRoom->map[9][9][0] == 1);

    // test sqrRoom
    REQUIRE(recRoom->setObstacle(4, 9) == true);
    REQUIRE(recRoom->setObstacle(4, 9) == true);
    REQUIRE(recRoom->map[4][9][0] == 1);

    // set hallway
    REQUIRE(hallway->setObstacle(0, 0) == true);
    REQUIRE(hallway->setObstacle(1, 0) == true);
    // verify hallway set correctly
    REQUIRE(hallway->map[0][0][0] == 1);
    REQUIRE(hallway->map[1][0][0] == 1);

#ifndef NDEBUG
    std::cout << "sqrRoom " << sqrRoom->printVal(9, 9, 0) << std::endl;
    printGraphObs(sqrRoom);
    std::cout << "recRoom" << recRoom->printVal(4, 9, 0) << std::endl;
    printGraphObs(recRoom);
#endif
  }
  SECTION("GRID SETS PMVs") {
    /*Grid sets PMVs*/
    REQUIRE(sqrRoom->setPMV(0, 0, 100) == true);
    REQUIRE(recRoom->setPMV(4, 4, 100) == true);

    // fill in hallway
    REQUIRE(hallway->setPMV(-1, 0, -90) == false); // test error handling
    REQUIRE(hallway->setPMV(0, 0, 100) == true);
    REQUIRE(hallway->setPMV(1, 0, 100) == true);

#ifndef NDEBUG
    std::cout << "sqrRoom " << sqrRoom->printVal(0, 0, 1) << std::endl;
    printGraphAPF(sqrRoom);
    std::cout << "recRoom " << recRoom->printVal(4, 4, 1) << std::endl;
    printGraphAPF(recRoom);
#endif
    REQUIRE(sqrRoom->map[0][0][1] == 100);
    REQUIRE(recRoom->map[4][4][1] == 100);
  }

  SECTION("Grid Clears Obstacles") {
    // test sqrRoom
    REQUIRE(sqrRoom->clearObstacle(9, 9) == true);
    REQUIRE(sqrRoom->clearObstacle(9, -1) == false); // test error handling
    REQUIRE(sqrRoom->map[9][9][0] == 0);

    // test recRoom
    REQUIRE(recRoom->clearObstacle(4, 9) == true);
    REQUIRE(recRoom->clearObstacle(4, 9) == true);
    REQUIRE(recRoom->map[4][9][0] == 0);

    // Test clear map
    hallway->clearObstacles();
    REQUIRE(hallway->map[0][0][0] == 0);
    REQUIRE(hallway->map[1][0][0] == 0);
  }

  SECTION("Grid Clears PMVs") {
    // test sqrRoom
    REQUIRE(sqrRoom->clearPMV(0, 0) == true);
    REQUIRE(sqrRoom->clearPMV(9, -1) == false); // test error handling
    REQUIRE(sqrRoom->map[0][0][1] == 0);

    // test recRoom
    REQUIRE(recRoom->clearPMV(4, 4) == true);
    REQUIRE(recRoom->map[4][4][1] == 0);

    // test clear PMV map
    hallway->clearPMVs();
    REQUIRE(hallway->map[0][0][1] == 0);
    REQUIRE(hallway->map[1][0][1] == 0);
  }
}

TEST_CASE("Grid Deconstruction") {
  Grid* shed = new Grid(); // init a 10 by 10 square
  // set obstacltes
  shed->setObstacle(0, 0);
  shed->setObstacle(0, 1);
  shed->setObstacle(7, 5);

  REQUIRE(shed->map[0][0][0] == 1);
  REQUIRE(shed->map[0][1][0] == 1);
  REQUIRE(shed->map[7][5][0] == 1);

  // set PMVs
  shed->setPMV(2, 2, 30);
  shed->setPMV(6, 8, 100);
  shed->setPMV(0, 4, 60);

  REQUIRE(shed->map[2][2][1] == 30);
  REQUIRE(shed->map[6][8][1] == 100);
  REQUIRE(shed->map[0][4][1] == 60);

  shed->clearMap();
  // Check for cleared obstacles
  REQUIRE(shed->map[0][0][0] == 0);
  REQUIRE(shed->map[0][1][0] == 0);
  REQUIRE(shed->map[7][5][0] == 0);

  // Check for cleared PMVs
  REQUIRE(shed->map[2][2][1] == 0);
  REQUIRE(shed->map[6][8][1] == 0);
  REQUIRE(shed->map[0][4][1] == 0);

  // delete grid
  delete shed;
}
