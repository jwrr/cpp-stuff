// epsilon.h

#ifndef EPSILON_H_
#define EPSILON_H_

namespace EPS
{
  template <typename T>
  T epsilon()
  {
    T one = 1.0;  
    T eps = one;
    while (true) {
      T eps_next = eps / 2.0;
      if (one == one + eps_next) {
        break;
      }
      eps = eps_next;
    }
    return eps;
  }
}

#endif // EPSILON_H_
