# Multi-objective multi-robot path planning in continuous environment using an enhanced genetic algorithm
An implementation in C++ of: https://www.sciencedirect.com/science/article/pii/S0957417418305165

## This project is still a WIP
There are many volitaile changes and restructuring happening often

## Dependencies:
Now handled by vcpkg in a submodule (except for ImGuiFileDialog)
- fmt: https://github.com/fmtlib/fmt
- Catch2 (optional) for Unit tests: https://github.com/catchorg/Catch2
- glfw3 (for ImGui): https://github.com/glfw/glfw
- FreeType (for ImGui): https://gitlab.freedesktop.org/freetype/freetype
- Dear ImGui: https://github.com/ocornut/imgui
    - File Dialog Enxtension: https://github.com/aiekick/ImGuiFileDialog
    - ImPlot Extension: https://github.com/epezent/implot

## Build Instructions (Windows and Linux):
```
git clone --recurse-submodules https://github.com/xTechon/Multi-Robot-PP-EGA.git
cd Multi-Robot-PP-EGA
mkdir build
cmake -S . -B build -DCMAKE_TOOLCHAIN_FILE=[path to vcpkg]/scripts/buildsystems/vcpkg.cmake
cmake --build build
```
---
Unit tests can be run using `Multi-Robot-PP-EGA/bin/tests`
<br>The built binary will be in `Multi-Robot-PP-EGA/bin/EGA`

## Development
The project is built using Clang from LLVM and the Ninja Build system, consider installing those from the link or your linux package manager:
- LLVM: https://releases.llvm.org/
- Ninja: https://github.com/ninja-build/ninja

Reccomend using these extensions in VS Code:
- C++ Themes: https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools-themes
- C++ Cmake Tools: https://marketplace.visualstudio.com/items?itemName=ms-vscode.cmake-tools
- Clangd: https://marketplace.visualstudio.com/items?itemName=llvm-vs-code-extensions.vscode-clangd
- Code LLDB https://marketplace.visualstudio.com/items?itemName=vadimcn.vscode-lldb

VS Code Settings:
- Set CMake to use [Clang... ...pc-windows-msvc] and it should lead to the LLVM install path
- In Linux, Cmake should be set to use the [Clang... ...pc-linux-gnu] kit
- in settings.json, make sure the forward/backslashes match for OS
- in launch.json, set the program path to the built binary for debugging
