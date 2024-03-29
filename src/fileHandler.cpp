#include "fileHandler.h"

#include "../lib/ImGuiFileDialog/ImGuiFileDialog.h"

FileHandler::FileHandler() { this->error = false; }

std::vector<std::string>* FileHandler::drawGUI(std::vector<std::string>* fileP) {
  // open Dialog Simple std::cout << fmt::format("DrawGUI");
  if (ImGui::Button("Open File Dialog")) {
    ImGuiFileDialog::Instance()->OpenDialog("ChooseFileDlgKey", "Choose File", ".csv,.txt", ".");
  }
  static std::vector<std::string> fileInfo;
  static std::string filePathName;
  static std::string filePath;
  static std::string fileName;
  // display
  if (ImGuiFileDialog::Instance()->Display("ChooseFileDlgKey")) {
    // action if OK
    if (ImGuiFileDialog::Instance()->IsOk()) {
      filePathName = ImGuiFileDialog::Instance()->GetFilePathName();
      filePath     = ImGuiFileDialog::Instance()->GetCurrentPath();
      fileName     = filePathName.substr(filePath.length() + 1);

      fileInfo.push_back(filePathName);
      fileInfo.push_back(filePath);
      fileInfo.push_back(fileName);

      // const char *fileP = filePathName.c_str();
      //  action
      //  ImGui::Text("%s", fileP);
#ifndef NDEBUG
      std::cout << fmt::format("{}", fileInfo[2]) << std::endl;
#endif
      ImGuiFileDialog::Instance()->Close();
      if (ImGui::GetIO().KeyAlt) printf(""); // Set a debugger breakpoint here!
      return &fileInfo;
    }

    // close
    ImGuiFileDialog::Instance()->Close();
    return nullptr;
  }
  if (fileP != nullptr) return fileP;
  return nullptr;
}

Grid* FileHandler::importGrid(std::string* filePath, Grid* check) {
  int x = 0, y = 0; // init the length and height of the map
  std::string line, word;
  static Grid* terrain;
  std::fstream fin(*filePath, std::ios::in); // open the file for reading
  if ((fin.is_open()) && (check == (Grid*) nullptr)) {
    getline(fin, line);
    std::stringstream str(line);
    getline(str, word, ',');
    x = stoi(word); // set x
    getline(str, word, ',');
    y = stoi(word); // set y

    terrain = new Grid(x, y);           // init a new map of size x,y
    fillGrid(terrain, fin, word, line); // fill the grid with info from file
  } else if (check != (Grid*) nullptr) {
    return check; // check has already been set, just return it's value
  } else {
#ifndef NDEBUG
  #ifndef TESTS
    errorMsg(&(this->error));
  #endif
    std::cout << fmt::format("FILE NOT FOUND") << std::endl;
#endif
    return (Grid*) nullptr;
  }
  fin.close();
  return terrain;
}

void FileHandler::fillGrid(Grid* terrain, std::fstream& f, std::string word, std::string line) {
  for (int j = (terrain->getHeight() - 1); j >= 0; j--) { // Columns
    getline(f, line);
    std::stringstream str(line);
    for (int i = 0; i < terrain->getWidth(); i++) { // Rows
      getline(str, word, ',');
      if (stoi(word) == 1) {
        terrain->setObstacle(i, j); // set the obstacle at that point
      }
    }
  }
}

void FileHandler::errorMsg(bool* display) {
  ImGui::Begin("ERROR", display);
  ImGui::Text("The file could not be opened for importing");
  if (ImGui::Button("Close")) *display = false;
  ImGui::End();
}
