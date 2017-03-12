#include "Cell.h"
#include <iostream>
#include "Maze.h"

int main()
{
  std::cout<< "Initializing"<<std::endl;
  Maze a(1,1);
  std::cout<< "Created instance of Maze"<<std::endl;
  a.Compute(0,0);

  return 0;
}
