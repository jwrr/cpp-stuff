// main.cpp for game_of_life

#include <iostream>
#include "Board.h"
    
using std::cout;
using std::endl;

int main(int argc, char *argv[])
{
  Board board(25, 80, 30);
  board.run();
  cout << "Done" << endl;
  return 0;
}
    
    

