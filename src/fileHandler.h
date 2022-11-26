#include "grid.h"

#ifndef FILEHANDLER
  #define FILEHANDLER

class FileHandler {
private:
  bool error;
  void fillGrid(Grid* terrain, std::fstream& f, std::string word, std::string line);

public:
  FileHandler(void);
  std::string* drawGUI(std::string* fileP); // generate the file picker dialog
  // return a pointer to a static grid object
  // if successful, null otherwise
  Grid* importGrid(std::string* filePath, Grid* check);
  void errorMsg(bool* display);
};
#endif
