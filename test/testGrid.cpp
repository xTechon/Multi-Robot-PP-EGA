#include <catch2/catch_test_macros.hpp>

#include <cstdint>

#include "../src/APF.h"

TEST_CASE("Grid Class functions") {
  Grid *sqrRoom = new Grid(10, 10);
  Grid *recRoom = new Grid(5, 10);
  Grid *hallway = new Grid(2, 1);

  REQUIRE(sqrRoom->getWidth() == 10);
  REQUIRE(sqrRoom->getHeight() == 10);
  REQUIRE(recRoom->getWidth() == 5);
  REQUIRE(recRoom->getHeight() == 10);

  SECTION("Grid sets Values") {
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
    std::cout << "recRoom" << recRoom->printVal(4, 9, 0) << std::endl;
#endif

    /*Grid sets PMVs*/
    REQUIRE(sqrRoom->setPMV(0, 0, 100) == true);
    REQUIRE(recRoom->setPMV(4, 4, 100) == true);
#ifndef NDEBUG
    std::cout << "sqrRoom " << sqrRoom->printVal(0, 0, 1) << std::endl;
    std::cout << "recRoom " << recRoom->printVal(4, 4, 1) << std::endl;
#endif
    REQUIRE(sqrRoom->map[0][0][1] == 100);
    REQUIRE(recRoom->map[4][4][1] == 100);
  }

  SECTION("Grid Clears values") {
    // test sqrRoom
    REQUIRE(sqrRoom->clearObstacle(9, 9) == true);
    REQUIRE(sqrRoom->clearObstacle(9, -1) == false);
    REQUIRE(sqrRoom->map[9][9][0] == 0);

    // test recRoom
    REQUIRE(recRoom->clearObstacle(4, 9) == true);
    REQUIRE(recRoom->clearObstacle(4, 9) == true);
    REQUIRE(recRoom->map[4][9][0] == 0);

    // Test clear maps
  }
}
