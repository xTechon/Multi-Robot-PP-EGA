#include "APF.h"
#include "ImGuiFileDialog.h"

std::string *FileHandler::drawGUI(std::string *fileP) {
  // open Dialog Simple
  // std::cout << fmt::format("DrawGUI");
  if (ImGui::Button("Open File Dialog")) {
    ImGuiFileDialog::Instance()->OpenDialog("ChooseFileDlgKey", "Choose File",
                                            ".txt", ".");
  }
  static std::string filePathName;
  static std::string filePath;
  // display
  if (ImGuiFileDialog::Instance()->Display("ChooseFileDlgKey")) {
    // action if OK
    if (ImGuiFileDialog::Instance()->IsOk()) {
      filePathName = ImGuiFileDialog::Instance()->GetFilePathName();
      filePath = ImGuiFileDialog::Instance()->GetCurrentPath();
      // const char *fileP = filePathName.c_str();
      //  action
      //  ImGui::Text("%s", fileP);
      //  std::cout << fmt::format("{}", filePathName) << std::endl;
      ImGuiFileDialog::Instance()->Close();
      if (ImGui::GetIO().KeyAlt)
        printf(""); // Set a debugger breakpoint here!
      return &filePathName;
    }

    // close
    ImGuiFileDialog::Instance()->Close();
    return nullptr;
  }
  if (fileP != nullptr)
    return fileP;
  return nullptr;
}
