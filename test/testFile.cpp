#include "../src/fileHandler.h"
#include "test.h"

TEST_CASE("Test filepath") {
  // set the structure to compare against
  Grid* exampleMap = new Grid(4, 4);
  exampleMap->setObstacle(0, 0);
  exampleMap->setObstacle(1, 1);
  exampleMap->setObstacle(2, 2);
  exampleMap->setObstacle(3, 3);
  exampleMap->setObstacle(0, 3);

  Grid* fileImport = (Grid*) nullptr;

  FileHandler* handler = new FileHandler();

  std::string wrongPath   = "./exampleMap.txt";
  std::string correctPath = "./maps/exampleGrid.txt";

  // test an invalid path
  SECTION("Test an invlaid path") {
    fileImport = handler->importGrid(&wrongPath, fileImport);

    REQUIRE(fileImport == (Grid*) nullptr);
  }

  fileImport = handler->importGrid(&correctPath, fileImport);
  // test a valid path
  SECTION("Test a valid path") { REQUIRE(fileImport != (Grid*) nullptr); }

  // Test comparison works properly
  SECTION("Test map comparison works correctly") {
    // correct map
    REQUIRE(fileImport->map == exampleMap->map);

    // change comparison map
    exampleMap->setObstacle(1, 3);
    // incorrect map
    REQUIRE(fileImport->map != exampleMap->map);
  }
}
