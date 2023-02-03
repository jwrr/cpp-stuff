// epsilon.cpp
// Measure smallest value that makes a difference for float, double and long 
// double.
// Reference: https://www.youtube.com/playlist?list=PLzn6LN6WhlN1Lic9M9mbzqV3ASokOdnFM
// Course: Programming Techniques for Scientific Simulation 1
// Lecturer: Matthias Troyer

#include <iostream>
#include "epsilon.h"

using namespace std;

int main()
{
  cout << "hello\n";

  float f_eps = EPS::epsilon<float>();
  cout << "float eps = " << f_eps << endl;

  double d_eps = EPS::epsilon<double>();
  cout << "double eps = " << d_eps << endl;

  long double ld_eps = EPS::epsilon<long double>();
  cout << "long double eps = " << ld_eps << endl;

  return 0;
}

