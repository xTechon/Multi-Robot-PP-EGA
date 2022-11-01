#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
//#include <GLES2/gl2.h>
#include <GLFW/glfw3.h>
#include <cstddef>
#include <math.h>
#include <stdio.h>

// code from:
// https://github.com/ocornut/imgui/blob/master/examples/example_glfw_opengl3/main.cpp

static void glfw_error_callback(int error, const char *description) {
  fprintf(stderr, "Glfw Error %d: %s\n", error, description);
}

int main(int, char **) {
  // Setup window
  glfwSetErrorCallback(glfw_error_callback);
  if (!glfwInit())
    return 1;

  const char *glsl_version = "#version 130";
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);

  // Create window
  GLFWwindow *window = glfwCreateWindow(
      1280, 720, "Dear ImGUI GLFW+OpenGL3 example", NULL, NULL);
  if (window == NULL)
    return 1;
  glfwMakeContextCurrent(window);
  glfwSwapInterval(1); // VSync Enable

  return 0;
}
