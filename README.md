# Multi-objective multi-robot path planning in continuous enviornment using an enhanced genetic algorithm
An implementation in C++ of: https://www.sciencedirect.com/science/article/pii/S0957417418305165

## Dependencies:
- fmt: https://github.com/fmtlib/fmt
- Catch2 (optional) for Unit tests: https://github.com/catchorg/Catch2
- Dear ImGui: https://github.com/ocornut/imgui
- glfw3 (for ImGui): https://github.com/glfw/glfw
- FreeType (for ImGui): https://gitlab.freedesktop.org/freetype/freetype

Dear ImGui is auto downloaded by the cmake file
<br>other dependencies need to be installed seperately
<br>linux systems can use the package manager
<br>windows systems should consider using vcpkg as the cmake generator and install the dependencies via vcpkg


## Build Instructions:
```
git clone https://github.com/xTechon/Multi-Robot-PP-EGA.git
cd Multi-Robot-PP-EGA
mkdir build
cd build
cmake ..
cmake --build .
```

Unit tests can be run using `Multi-Robot-PP-EGA/bin/tests`
<br>The built binary will be in `Multi-Robot-PP-EGA/bin/EGA`
