// epsilon.cpp
// Measure smallest value that makes a difference for float, double and long 
// double.
// Reference: https://www.youtube.com/playlist?list=PLzn6LN6WhlN1Lic9M9mbzqV3ASokOdnFM
// Course: Programming Techniques for Scientific Simulation 1
// Lecturer: Matthias Troyer

#include <iostream>

using namespace std;

template <typename T>
T epsilon()
{
  T one = 1.0;  
  T eps = one;
  while (true) {
    // cout << "T eps = " << eps << endl;
    T eps_next = eps / 2.0;
    if (one == one + eps_next) {
      break;
    }
    eps = eps_next;
  }
  return eps;
}

int main()
{
  cout << "hello\n";

  float f_eps = epsilon<float>();
  cout << "float eps = " << f_eps << endl;

  double d_eps = epsilon<double>();
  cout << "double eps = " << d_eps << endl;

  long double ld_eps = epsilon<long double>();
  cout << "long double eps = " << ld_eps << endl;

  return 0;
}
