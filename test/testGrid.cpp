#include <catch2/catch_test_macros.hpp>

#include <cstdint>

#include "../src/APF.h"

TEST_CASE("Grid Class functions") {
  Grid *sqrRoom = new Grid(10, 10);
  Grid *recRoom = new Grid(5, 10);

  REQUIRE(sqrRoom->getWidth() == 10);
  REQUIRE(sqrRoom->getHeight() == 10);
  REQUIRE(recRoom->getWidth() == 5);
  REQUIRE(recRoom->getHeight() == 10);

  SECTION("Grid sets values") {
    sqrRoom->setObstacle(9, 9);
    recRoom->setObstacle(4, 9);
    REQUIRE(sqrRoom->map[9][9][0] == 1);
    REQUIRE(recRoom->map[4][9][0] == 1);
  }
}
