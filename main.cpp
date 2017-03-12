#include "Cell.h"
#include <iostream>
#include "Maze.h"

int main()
{
  srand(time(NULL));
  std::cout<< "Initializing"<<std::endl;
  Maze a(3,3);
  a.Compute(0,0);
  a.Print();

  return 0;
}
