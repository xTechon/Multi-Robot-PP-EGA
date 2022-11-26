#include "interact.h"

#include "imgui.h"
#include "implot.h"

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
    xs[i] = 1 + ((int) rand() % 9);
    ys[i] = 1 + ((int) rand() % 9);
  }
  ImGui::Begin("Map Test"); // Start the window
  if (ImPlot::BeginPlot("Map test")) {
    ImPlot::SetupAxes("x", "y");
    ImPlot::PlotLine("border", x, y, 5);
    ImPlot::SetNextMarkerStyle(ImPlotMarker_Circle);
    ImPlot::PlotScatter("Obstacle test", xs, ys, 5);
    ImPlot::EndPlot();
  }
  ImGui::End();
}

void Interact::drawMapObs(Grid* map) {
  std::vector<int> x;
  std::vector<int> y;
  // std::vector<std::pair<int, int>> xy;
  int count = 0;
  // store obstacles as points
  for (int i = 0; i < map->getWidth(); i++) {
    for (int j = 0; j < map->getHeight(); j++) {
      if (map->isObstacle(i, j)) {
        x.push_back(i);
        y.push_back(j);
        // xy.push_back(std::make_pair(i, j));
        count++;
      }
    }
  }

  ImGui::Begin("Imported Map");
  if (ImPlot::BeginPlot("Imported Map")) {
    ImPlot::SetupAxes("x", "y");
    ImPlot::PlotLine("border", this->borderx, this->bordery, 5);
    ImPlot::SetNextMarkerStyle(ImPlotMarker_Circle);
    ImPlot::PlotScatter("Obstacle", &x[0], &y[0], count);
    ImPlot::EndPlot();
    ImGui::End();
  }
}

Interact::Interact(Grid* map) {
  this->borderx[0] = 0;
  this->bordery[0] = 0;

  this->borderx[1] = map->getWidth() - 1;
  this->bordery[1] = 0;

  this->borderx[2] = map->getWidth() - 1;
  this->bordery[2] = map->getHeight() - 1;

  this->borderx[3] = 0;
  this->bordery[3] = map->getHeight() - 1;

  this->borderx[4] = 0;
  this->bordery[4] = 0;
}
