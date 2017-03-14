#include "Cell.h"
#include <iostream>
#include "Maze.h"
#include <sstream>


int main()
{
  srand(time(NULL));
  std::string sinput;

  int width = -1;
  int height = -1;

  std::cout<< "Welcome to the Maze Creator"<<std::endl;


  std::cout << "Please enter the width of the maze."<<std::endl;
  while (width < 1){
    std::getline (std::cin,sinput);
    std::istringstream convert(sinput);
    if( !(convert >> width) ){
      width = 0;
      std::cout<<"err"<<std::endl;
    }
    if (width < 1)
      std::cout<<"Please enter an integer greater than 0. Values greater than ~40 may not fit on the screen."<<width<<std::endl;

  }

  std::cout << "Please enter the height of the maze."<<std::endl;

  while (height < 1){
    std::getline (std::cin,sinput);
    std::istringstream convert(sinput);
    if( !(convert >> height))
      height = 0;
    if ( height < 1)
      std::cout<<"Please enter an integer greater than 0. Values greater than ~20 may not fit on the screen."<<std::endl;

  }

  Maze a(width,height);
  a.Compute(0,0);         //The starting point of the maze.
  a.Print();

  return 0;
}
