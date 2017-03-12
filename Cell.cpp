#include "Cell.h"

//constructors

Cell::Cell() : bottomwall(1), rightwall(1), visited(0) {}

bool Cell::Visited() const { return visited; }
bool Cell::RightWall() const { return rightwall; }
bool Cell::BottomWall() const { return bottomwall; }

void Cell::MarkVisited() { visited = 1; }
void Cell::BreakRight() { rightwall = 0; }
void Cell::BreakBottom() { bottomwall = 0; }
