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
  std::cout<< "Initializing Maze object with height " << height<< " and width "<< width<<"."<<std::endl;
  H = height;
  W = width;
  std::vector<std::vector<Cell> > tmp(width, std::vector<Cell>(height));
  cells = tmp;
}

void Maze::Compute (int x, int y){
  std::cout<<x<<" "<<y<<std::endl;
  (cells[x][y]).MarkVisited();
  std::vector<int> UnvisitedRooms(4,1);
  if (x == 0 || cells[x-1][y].Visited() == 1) UnvisitedRooms[0] = 0;
  if (x == W-1 || cells[x+1][y].Visited() == 1) UnvisitedRooms[1] = 0;

  if (y == 0 || cells[x][y-1].Visited() == 1) UnvisitedRooms[2] = 0;
  if (y == H-1 || cells[x][y+1].Visited() == 1) UnvisitedRooms[3] = 0;
  int NoOfRoomsLeft = 0;
  for (auto i : UnvisitedRooms){
    NoOfRoomsLeft += i;
  }
  while (NoOfRoomsLeft > 0){
    int Rint = Rand(NoOfRoomsLeft);
    int count = 0;
    for (auto i : UnvisitedRooms)
      {
        if (i == 1) --Rint;
        if (Rint ==0) break;
        ++count;
      }
  switch(count) {
    case 0: cells[x-1][y].BreakRight();std::cout<<"BreakLeft"<<std::endl; Compute(x-1,y); break;
    case 1: cells[x][y].BreakRight();std::cout<<"Breakright"<<std::endl; Compute(x+1,y); break;
    case 2: cells[x][y].BreakBottom();std::cout<<"BreakBottom"<<std::endl; Compute(x,y-1); break;
    case 3: cells[x][y+1].BreakBottom();std::cout<<"BreakTop"<<std::endl; Compute(x,y+1); break;
  }

  if (x == 0 || cells[x-1][y].Visited() == 1) UnvisitedRooms[0] = 0;
  if (x == W-1 || cells[x+1][y].Visited() == 1) UnvisitedRooms[1] = 0;

  if (y == 0 || cells[x][y-1].Visited() == 1) UnvisitedRooms[2] = 0;
  if (y == H-1 || cells[x][y+1].Visited() == 1) UnvisitedRooms[3] = 0;

  NoOfRoomsLeft = 0;
  for (auto i : UnvisitedRooms)
    NoOfRoomsLeft += i;

}
}

int Maze::Rand(int n){

  return 1+rand()%n;
}

void Maze::Print(){

  int cellHeight = 1;

  std::cout<< " ";
  for (int p =0; p < W; ++p)
    std::cout<<"---";

  std::cout<<std::endl;

  for (int i = 0; i < H-1; ++i){
    for (int j = 0; j<cellHeight; ++j){
      std::cout<< "|";
      for (int k =0; k< W-1; ++k){
        std::cout<< "  ";
        if (cells[i][k].RightWall() == 0)
          std::cout<<" ";
        else
          std::cout<<"|";
      }

      std::cout<<"  |"<<std::endl;
    }
    for (int k = 0; k < W; ++k){
      if (cells[i][k].BottomWall() == 0)
        std::cout<<"   ";
      else
        std::cout<<"---";
    }
    std::cout<<std::endl;
  }

 int i = H-1;
  for (int j = 0; j<cellHeight; ++j){
    std::cout<< "|";
    for (int k =0; k< W-1; ++k){
      std::cout<< "  ";
      if (cells[i][k].RightWall() == 0)
        std::cout<<" ";
      else
        std::cout<<"|";
    }
  std::cout<<"  |"<<std::endl;
  }
for (int k = 0; k < W; ++k)
  std::cout<<"---";
std::cout<<std::endl;

}
