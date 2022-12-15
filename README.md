# Multi-objective multi-robot path planning in continuous enviornment using an enhanced genetic algorithm
An implementation in C++ of: https://www.sciencedirect.com/science/article/pii/S0957417418305165

## This project is still a WIP
There are many volitaile changes and restructuring happening often

## Dependencies:
- fmt: https://github.com/fmtlib/fmt
- Catch2 (optional) for Unit tests: https://github.com/catchorg/Catch2
- glfw3 (for ImGui): https://github.com/glfw/glfw
- FreeType (for ImGui): https://gitlab.freedesktop.org/freetype/freetype
- Dear ImGui: https://github.com/ocornut/imgui
    - File Dialog Enxtension: https://github.com/aiekick/ImGuiFileDialog
    - ImPlot Extension: https://github.com/epezent/implot

## Build information
Dear ImGui is auto downloaded by the cmake file
- other dependencies need to be installed seperately
- linux systems can use the package manager
- windows systems should consider installing vcpkg and using Ninja as the generator
- If you are on windows, the vcpkg.json manifest file should auto install the dependcies as long as vcpkg is installed

## Build Instructions (linux):
```
git clone https://github.com/xTechon/Multi-Robot-PP-EGA.git
cd Multi-Robot-PP-EGA
mkdir build
cmake -S . -B build
cmake --build build
```
## Build Instructions (windows with vcpkg installed) [Not Working]:
```
git clone https://github.com/xTechon/Multi-Robot-PP-EGA.git
cd Multi-Robot-PP-EGA
mkdir build
cmake -S . -B build -DCMAKE_TOOLCHAIN_FILE=[path to vcpkg]/scripts/buildsystems/vcpkg.cmake
cd build
cmake --build .
```
---
Unit tests can be run using `Multi-Robot-PP-EGA/bin/tests`
<br>The built binary will be in `Multi-Robot-PP-EGA/bin/EGA`
