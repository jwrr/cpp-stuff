// Board.h

#include <vector>
#include "Cell.h"

class Board {
  public:
    Board(int r, int c, int probAliveAtStart);
    Board();
    void run();
  private:
    void init();
    void calc();
    int  countNeighbors(int r, int c);
    void update();
    void print();
    void countDown(int numSec);


    std::vector<std::vector<Cell>> board;
    int m_rows = 25;
    int m_cols = 80;
    int m_probAliveAtStart = 30;
};



