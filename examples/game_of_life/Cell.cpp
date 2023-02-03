// Cell.cpp

#include <cstdlib>
#include "Cell.h"

void Cell::init(int prob_of_life)
{
  int r = (std::rand() % 100) + 1;
  bool isBorn = (r <= prob_of_life);
  m_currState = isBorn ? 3 : 0;
  m_nextState = m_currState;
}
 
 
bool Cell::isAlive()
{
  return (m_currState >= 2);
}
 
 
void Cell::calc(int num_neighbors)
{
  if (isAlive()) {
    bool livesAgain = (num_neighbors == 2) ||  (num_neighbors == 3);
    m_nextState = livesAgain ? 3 : 1;
  } else {
    bool startsLiving = (num_neighbors == 3);
    m_nextState = startsLiving ? 2 : 0;
  }
}
 
 
void Cell::update()
{
  m_currState = m_nextState;
}


std::string  Cell::toString()
{
  switch (m_currState) {
    case 0: return " ";
    case 1: return "-";
    case 2: return "+";
    case 3: return "*";
    default: return "?";
  }
}

