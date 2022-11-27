#include "interact.h"

#include "imgui.h"
#include "implot.h"

void Interact::drawMapObs(Grid* map, std::string& fileName) {
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

  static ImPlotLocation loc = ImPlotLocation_NorthWest;
  const char* file          = fileName.c_str();
  // ImGui::Begin("Imported Map");
  if (ImPlot::BeginPlot(file)) {
    ImPlotLegendFlags flags = ImPlotLegendFlags_None;
    flags |= ImPlotLegendFlags_Outside;
    ImPlot::SetupLegend(loc, flags);
    ImPlot::SetupAxes("x", "y");
    ImPlot::SetNextLineStyle(ImVec4(1, 0, 0, 1)); // color is RGBA value
    ImPlot::PlotLine("border", this->borderx, this->bordery, 5);
    ImPlot::SetNextMarkerStyle(ImPlotMarker_Circle);
    ImPlot::PlotScatter("Obstacle", &x[0], &y[0], count);
    ImPlot::EndPlot();
    // ImGui::End();
  }
}

void Interact::resizeBorder(Grid* map) {
  // bottom left corner
  this->borderx[0] = 0;
  this->bordery[0] = 0;

  // bottom right corner
  this->borderx[1] = map->getWidth() - 1;
  this->bordery[1] = 0;

  // top right corner
  this->borderx[2] = map->getWidth() - 1;
  this->bordery[2] = map->getHeight() - 1;

  // top left corner
  this->borderx[3] = 0;
  this->bordery[3] = map->getHeight() - 1;

  // back to bottom right corner
  this->borderx[4] = 0;
  this->bordery[4] = 0;
}

// class constructor
Interact::Interact() {
  // initalize arrays with 0s
  this->clearBorder();
}

void Interact::clearBorder() {
  for (int i = 0; i < 5; i++) {
    this->borderx[i] = 0;
    this->bordery[i] = 0;
  }
}

void addStartAndDest() { }
