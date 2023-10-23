cmake_minimum_required(VERSION 3.20)
set(CMAKE_CXX_STANDARD 17)

# Setup the project.
set(PROJECT "EGA")
project(${PROJECT} LANGUAGES CXX)

#Export the compile commands for the LSP
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../bin)


# install libraries from vcpkg
find_package(fmt REQUIRED)
find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)
find_package(Freetype REQUIRED)
find_package(imgui REQUIRED)
find_package(implot REQUIRED)

set(LIBRARIES
    fmt::fmt
    glfw
    Freetype::Freetype
    ${OPENGL_LIBRARIES}
    imgui::imgui
    implot::implot
)

# Add ImGuiFileDialog sources to project
set(FileDialog
    lib/ImGuiFileDialog/ImGuiFileDialog.h
    lib/ImGuiFileDialog/ImGuiFileDialog.cpp
)

# Get C or C++ sources in the current directory (only).
file(GLOB CPP_SOURCES src/*.cpp)
set(SOURCES ${CPP_SOURCES} ${FileDialog})

#optional Catch2 for unit testing
find_package(Catch2 3)
if(Catch2_FOUND)
  message(STATUS "CATCH2 found")
  # Collect all testing source files
  file(GLOB TEST_SOURCES test/*.cpp ${SOURCES})

  # remove example from build now that unit tests for projects exist
  list(REMOVE_ITEM TEST_SOURCES ${PROJECT_SOURCE_DIR}/test/example.cpp)

  # remove main loop from test executable
  list(REMOVE_ITEM TEST_SOURCES ${PROJECT_SOURCE_DIR}/src/main.cpp)

  add_executable(tests ${TEST_SOURCES} ${EXTENSIONS})
  target_link_libraries(tests PUBLIC ${LIBRARIES} PRIVATE Catch2::Catch2WithMain)
  set_target_properties(tests PROPERTIES COMPILE_FLAGS "-DTESTS")
  #Catch 2 options
  include(CTest)
  include(Catch)
  catch_discover_tests(tests)
endif()

# Setup the target executable.
add_executable(${PROJECT} ${SOURCES})
target_link_libraries(${PROJECT} ${LIBRARIES})
