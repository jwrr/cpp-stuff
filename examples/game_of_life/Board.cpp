// Board.cpp
// Implements a board of YxX of cells.

#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <time.h>
#include<unistd.h>
#include "Board.h"

// Create board of of defined number of rows and columns. The cells
// will be initialized to Alive with a probability defined by p.
Board::Board(int r, int c, int p)
{
  m_rows = r;
  m_cols = c;
  m_probAliveAtStart = p;
}


Board::Board()
{
  int rows = 20;
  int cols = 20;
  int prob = 35;
  Board(rows, cols, prob);
}


void Board::countDown(int numSec)
{
  const unsigned int second = 1000000;
  for (int s=numSec; s>0; s--) {
    std::cout << s << "... " << std::flush;
    usleep(1 * second);
  }
  std::cout << "Go! " << std::endl;
  usleep(0.5 * second);
}


void Board::run()
{
  init();
  print();
  int response = 0;
  while (true) {
    std::cout << "Enter number of iterations to perform: ";
    std::cin >> response;
    if (response <= 0) break;
    for (int i=0; i<response; i++) {
      std::cout << "Iteration " << i+1 << std::endl;
      calc();
      update();
      print();
      countDown(3);
    }
  }
}


void Board::init()
{
  srand(time(0));
  for (int r=0; r<m_rows; r++) {
    std::vector<Cell> vRow;
    for (int c=0; c<m_cols; c++) {
      Cell cell;
      cell.init(m_probAliveAtStart);
      vRow.push_back(cell);
    }
    board.push_back(vRow);
  }
}


int Board::countNeighbors(int row, int col)
{
  int first_row = std::max(row-1, 0);
  int last_row  = std::min(row+1, m_rows-1);
  int first_col = std::max(col-1, 0);
  int last_col  = std::min(col+1, m_cols-1);
  int cnt = 0;
  for (int r=first_row; r<=last_row; r++) {
    for (int c=first_col; c<=last_col; c++) {
      bool isCenter = (r==row) && (c==col);
      if (!isCenter && board[r][c].isAlive()) {
        cnt++;
      }
    }
  }
  return cnt;
}


void Board::calc()
{
  int r = 0;
  for (auto& row : board) {
    int c = 0;
    for (auto& cell : row) {
      int cnt = countNeighbors(r, c);
      cell.calc(cnt);
      c++;
    }
    r++;
  }
}


void Board::update()
{
  for (auto& row : board) {
    for (auto& cell : row) {
      cell.update();
    }
  }
}


void Board::print()
{
  for (auto& row : board) {
    for (auto& cell : row) {
      std::cout << cell.toString();
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
}

