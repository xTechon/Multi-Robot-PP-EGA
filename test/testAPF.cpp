#include "../src/APF.h"
#include "../src/fileHandler.h"
#include "test.h"

#ifndef NDEBUG
  #include "../src/debug.h"
#endif

TEST_CASE("Generate APF Given Map") {
  // setup
  Grid* imported       = (Grid*) nullptr;
  FileHandler* handler = new FileHandler();
  APF generator        = APF();

  std::string path = "./maps/map.csv";

  imported = handler->importGrid(&path, imported);
  REQUIRE(imported != (Grid*) nullptr);
  imported->setStart(1, 9);
  imported->setDest(8, 1);
#ifndef NDEBUG
  printGraphObs(imported);
#endif
  generator.GenerateAPF(imported);

#ifndef NDEBUG
  printGraphAPF(imported);
#endif
}
