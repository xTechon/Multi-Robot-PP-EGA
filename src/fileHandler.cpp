#include "APF.h"
#include "ImGuiFileDialog.h"

std::string FileHandler::drawGUI() {
  // open Dialog Simple
  // std::cout << fmt::format("DrawGUI");
  if (ImGui::Button("Open File Dialog"))
    ImGuiFileDialog::Instance()->OpenDialog("ChooseFileDlgKey", "Choose File",
                                            ".cpp,.h,.hpp", ".");
  std::string filePathName = "";
  std::string filePath = "";
  // display
  if (ImGuiFileDialog::Instance()->Display("ChooseFileDlgKey")) {
    // action if OK
    if (ImGuiFileDialog::Instance()->IsOk()) {
      std::string filePathName = ImGuiFileDialog::Instance()->GetFilePathName();
      std::string filePath = ImGuiFileDialog::Instance()->GetCurrentPath();
      const char *fileP = filePathName.c_str();
      // action
      // ImGui::Text("%s", fileP);
      // std::cout << fmt::format("{}", filePathName) << std::endl;
      ImGuiFileDialog::Instance()->Close();
      if (ImGui::GetIO().KeyAlt)
        printf(""); // Set a debugger breakpoint here!
      return filePathName;
    }

    // close
    ImGuiFileDialog::Instance()->Close();
    return filePathName;
  }
  return filePathName;
}
