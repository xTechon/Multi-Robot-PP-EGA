cmake_minimum_required(VERSION 3.20)
set(CMAKE_CXX_STANDARD 17)

# Setup the project.
project(EGA LANGUAGES CXX)
set(PROJECT "EGA")

#Export the compile commands for the LSP
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../bin)

# Get C or C++ sources in the current directory (only).
file(GLOB CPP_SOURCES src/*.cpp)
set(SOURCES ${C_SOURCES} ${CPP_SOURCES})

#download imgui
include(FetchContent)
FetchContent_Declare(
  imgui
  DOWNLOAD_EXTRACT_TIMESTAMP OFF
  URL "https://github.com/ocornut/imgui/archive/refs/heads/master.tar.gz"
)
FetchContent_MakeAvailable(imgui)

#message(STATUS "${imgui_SOURCE_DIR}")
#CMakeLists.txt for imgui
file(
  DOWNLOAD
  https://gist.githubusercontent.com/xTechon/2ceeec48a5cae66e73722f8ef96cb970/raw/4efd2c5ff5acf39f8f1d1514ffaec8d4b3848c52/CMakeLists.txt
  "${imgui_SOURCE_DIR}/CMakeLists.txt"
  SHOW_PROGRESS
)

set(IMGUI_EXAMPLES OFF CACHE BOOL "" FORCE)
set(IMGUI_DEMO OFF CACHE BOOL "" FORCE)
set(IMGUI_IMPL_GLUT OFF CACHE BOOL "" FORCE)

if (NOT TARGET imgui)
  add_subdirectory("${imgui_SOURCE_DIR}")
endif()

#check for libraries
find_package(fmt REQUIRED)
#find_package(PkgConfig REQUIRED)
#pkg_check_modules(FMT REQUIRED fmt)

set (LIBRARIES
  imgui
  imgui-glfw
  imgui-opengl3
  fmt::fmt
)

#optional Catch2 for unit testing
find_package(Catch2 3)
if(Catch2_FOUND)
  message(STATUS "CATCH2 found")
  file(GLOB TEST_SOURCES test/*.cpp)
  add_executable(tests ${TEST_SOURCES})
  target_link_libraries(tests PUBLIC ${LIBRARIES} PRIVATE Catch2::Catch2WithMain)
endif()

# Setup the target executable.
add_executable(${PROJECT} ${SOURCES})
target_link_libraries(${PROJECT} ${LIBRARIES})
