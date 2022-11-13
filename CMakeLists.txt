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
set(SOURCES ${CPP_SOURCES})

#check for libraries
find_package(fmt REQUIRED)
find_package(glfw3 REQUIRED)
#find_package(PkgConfig REQUIRED)
#pkg_check_modules(FMT REQUIRED fmt)

#download imgui
include(FetchContent)
FetchContent_Declare(
  imgui
  DOWNLOAD_EXTRACT_TIMESTAMP OFF
  URL "https://github.com/ocornut/imgui/archive/refs/heads/master.tar.gz"
)
FetchContent_MakeAvailable(imgui)

#download file dialog extension
FetchContent_Declare(
  filedialog
  DOWNLOAD_EXTRACT_TIMESTAMP OFF
  URL "https://github.com/aiekick/ImGuiFileDialog/archive/refs/heads/Lib_Only.tar.gz"
)
FetchContent_MakeAvailable(filedialog)

file(
  COPY "${filedialog_SOURCE_DIR}/ImGuiFileDialog.h"
  DESTINATION "${PROJECT_SOURCE_DIR}/src"
)

#message(STATUS "${imgui_SOURCE_DIR}")
#CMakeLists.txt for imgui
file(
  DOWNLOAD
  https://gist.githubusercontent.com/rokups/f771217b2d530d170db5cb1e08e9a8f4/raw/94dd1a018f9bb21ec3ac002978fa8d118c65e0ba/CMakeLists.txt
  "${imgui_SOURCE_DIR}/CMakeLists.txt"
  SHOW_PROGRESS
)

set(IMGUI_EXAMPLES OFF CACHE BOOL "" FORCE)
set(IMGUI_DEMO OFF CACHE BOOL "" FORCE)
set(IMGUI_IMPL_GLUT OFF CACHE BOOL "" FORCE)
set(IMGUI_IMPL_SDL OFF CACHE BOOL "" FORCE)
set(IMGUI_IMPL_VULKAN OFF CACHE BOOL "" FORCE)


if (NOT TARGET imgui)
  add_subdirectory("${imgui_SOURCE_DIR}")
endif()

set (LIBRARIES
  imgui
  imgui-glfw
  imgui-opengl3
  fmt::fmt
)

set(EXTENSIONS
  ${PROJECT_SOURCE_DIR}/src/ImGuiFileDialog.h
  ${filedialog_SOURCE_DIR}/ImGuiFileDialog.cpp
)


#optional Catch2 for unit testing
find_package(Catch2 3)
if(Catch2_FOUND)
  message(STATUS "CATCH2 found")
  file(GLOB TEST_SOURCES test/*.cpp ${SOURCES})
  # remove example from build now that unit tests for projects exist
  list(REMOVE_ITEM TEST_SOURCES ${PROJECT_SOURCE_DIR}/test/example.cpp)
  # remove main loop from test executable
  list(REMOVE_ITEM TEST_SOURCES ${PROJECT_SOURCE_DIR}/src/main.cpp)
  add_executable(tests ${TEST_SOURCES} ${EXTENSIONS})
  target_link_libraries(tests PUBLIC ${LIBRARIES} PRIVATE Catch2::Catch2WithMain)
  #Catch 2 options
  include(CTest)
  include(Catch)
  catch_discover_tests(tests)
endif()

# Setup the target executable.
add_executable(${PROJECT} ${SOURCES} ${EXTENSIONS})
target_link_libraries(${PROJECT} ${LIBRARIES})
