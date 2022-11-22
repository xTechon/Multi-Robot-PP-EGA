#include "implot.h"
#include "main.h"

void Interact::drawMapTest() {
  static int x[5], y[5];
  x[0] = 1;
  y[0] = 1;

  x[1] = 10;
  y[1] = 1;

  x[2] = 10;
  y[2] = 10;

  x[3] = 1;
  y[3] = 10;

  x[4] = 1;
  y[4] = 1;

  static int xs[5], ys[5];
  srand(0);
  for (int i = 0; i < 5; i++) {
    xs[i] = 1 + ((int)rand() % 9);
    ys[i] = 1 + ((int)rand() % 9);
  }

  if (ImPlot::BeginPlot("Map test")) {
    ImPlot::SetupAxes("x", "y");
    ImPlot::PlotLine("border", x, y, 5);
    ImPlot::SetNextMarkerStyle(ImPlotMarker_Circle);
    ImPlot::PlotScatter("Obstacle test", xs, ys, 5);
    ImPlot::EndPlot();
  }
}
