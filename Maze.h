#pragma once
#include <vector>
#include "Cell.h"

class Maze {
  public:

    Maze(int width, int height);

    void Compute(int x, int y);

    void Print();

  private:

    int Rand(int n);
    int H, W;
    std::vector< std::vector<Cell> > cells;

};
