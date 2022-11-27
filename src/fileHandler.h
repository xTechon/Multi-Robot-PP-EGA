#include "grid.h"

#ifndef FILEHANDLER
  #define FILEHANDLER

class FileHandler {
private:
  bool error;
  void fillGrid(Grid* terrain, std::fstream& f, std::string word, std::string line);

public:
  FileHandler(void);
  // returns a vector containing info about the file
  //[0] Full file path
  //[1] Path to the directory
  //[2] file Name
  std::vector<std::string>* drawGUI(std::vector<std::string>* fileP); // generate the file picker dialog
  // return a pointer to a static grid object
  // if successful, null otherwise
  Grid* importGrid(std::string* filePath, Grid* check);
  void errorMsg(bool* display);
};
#endif
