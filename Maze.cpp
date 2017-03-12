#include "Maze.h"
#include <iostream>
#include <vector>
#include "stdlib.h"
#include "Cell.h"

Maze::Maze(const int width, const int height){
  if ( width <= 0 || height <= 0)
  {
    std::cerr<<"Both Width and Height must be an int of at least 1.";
    exit(EXIT_FAILURE);
  }
  H = height;
  W = width;
  std::vector<std::vector<Cell>> tmp(width, std::vector<Cell>(height));
  cells = tmp;
}

void Maze::Compute (int x, int y){
  std::cout<<"started compute1-"<<std::endl;
  (cells[x][y]).MarkVisited();
  std::cout<<"started compute2"<<std::endl;
  std::vector<int> UnvisitedRooms(4,1);
std::cout<<"started compute3"<<std::endl;
  if (x == 0 || cells[x-1][y].Visited() == 1) UnvisitedRooms[0] = 0;
  if (x == W || cells[x+1][y].Visited() == 1) UnvisitedRooms[1] = 0;

  if (y == 0 || cells[x][y-1].Visited() == 1) UnvisitedRooms[2] = 0;
  if (y == H || cells[x][y+1].Visited() == 1) UnvisitedRooms[3] = 0;
  int NoOfRoomsLeft = 0;
  for (auto i : UnvisitedRooms)
    NoOfRoomsLeft += i;

std::cout<<"1"<<std::endl;
  while (NoOfRoomsLeft > 0){
    int Rint = Rand(NoOfRoomsLeft);
    int count = 0;
    for (auto i : UnvisitedRooms)
      {
        if (i == 1)
        {
          --Rint;
          if (Rint ==0) break;
        }
        ++count;
      }
  switch(count) {
    case 0: cells[x-1][y].BreakRight(); Compute(x-1,y); break;
    case 1: cells[x][y].BreakRight(); Compute(x+1,y); break;
    case 2: cells[x][y].BreakBottom(); Compute(x,y-1); break;
    case 3: cells[x][y+1].BreakBottom(); Compute(x,y+1); break;
  }

  if (x == 0 || cells[x-1][y].Visited() == 1) UnvisitedRooms[0] = 0;
  if (x == W || cells[x+1][y].Visited() == 1) UnvisitedRooms[1] = 0;

  if (y == 0 || cells[x][y-1].Visited() == 1) UnvisitedRooms[2] = 0;
  if (y == H || cells[x][y+1].Visited() == 1) UnvisitedRooms[3] = 0;

  NoOfRoomsLeft = 0;
  for (auto i : UnvisitedRooms)
    NoOfRoomsLeft += i;

  std::cout<<"2"<<std::endl;

}
}

int Maze::Rand(int n){

  return rand()%n;
}
