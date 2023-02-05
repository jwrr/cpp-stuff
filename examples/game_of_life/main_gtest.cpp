// main.cpp for game_of_life

#include <iostream>
#include <gtest/gtest.h>
#include "Board.h"
    
using std::cout;
using std::endl;

TEST(Board, Constructor) {
  int rows = 25;
  int cols = 80;
  int prob = 20;
  int size = rows * cols;
  Board board(rows, cols, prob);
  
  ASSERT_TRUE( 5 == 5);
  ASSERT_EQ(rows, board.rows);
  ASSERT_EQ(cols, board.cols);
  ASSERT_EQ(prob, board.prob);
  int expect_cnt = size * prob / 100;
  board.init();
  EXPECT_LT(expect_cnt-40, board.count());
  EXPECT_GT(expect_cnt+40, board.count());
}

TEST(Board, Update) {
  ASSERT_TRUE( 5 == 5);
}

// =====================================================================
// =====================================================================

int main(int argc, char **argv)
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}


/*
int main(int argc, char *argv[])
{
  Board board(25, 80, 30);
  board.run();
  cout << "Done" << endl;
  return 0;
}
*/

