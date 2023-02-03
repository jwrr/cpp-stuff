// Cell.h

#include <string>

class Cell {
  public:
    void init(int prob_of_life);
    void calc(int num_neighbors);
    void update();
    bool isAlive();
    std::string toString();

  private:
    int m_currState = 1;
    int m_nextState = 2;
};

