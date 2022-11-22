#ifdef _WIN32
#include <windows.h> //windows only header required
#endif
#include <GL/gl.h>
#include <GLFW/glfw3.h>
#include <cstddef>
#include <math.h>
#include <stdio.h>

#include "APF.h"
#include "implot.h"

namespace EGA {
class Interact;
}

class Interact {
public:
  void drawMapTest(); // draws a map onscreen using implots
};
