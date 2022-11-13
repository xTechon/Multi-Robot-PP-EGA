#include "APF.h"
#include "ImGuiFileDialog.h"

void FileHandler::drawGUI() {
  // open Dialog Simple
  if (ImGui::Button("Open File Dialog"))
    ImGuiFileDialog::Instance()->OpenDialog("ChooseFileDlgKey", "Choose File",
                                            ".cpp,.h,.hpp", ".");
  // display
  if (ImGuiFileDialog::Instance()->Display("ChooseFileDlgKey")) {
    // action if OK
    if (ImGuiFileDialog::Instance()->IsOk()) {
      std::string filePathName = ImGuiFileDialog::Instance()->GetFilePathName();
      std::string filePath = ImGuiFileDialog::Instance()->GetCurrentPath();
      const char *fileP = filePath.c_str();
      // action
      ImGui::Text("%s", fileP);
    }

    // close
    ImGuiFileDialog::Instance()->Close();
  }
}
