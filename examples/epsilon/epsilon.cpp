// epsilon.cpp
// Measure smallest value that makes a difference for float, double and long 
// double.

#include <iostream>

using namespace std;


int main()
{
  cout << "hello\n";

  float f_one = 1.0;  
  float f_eps = f_one;
  while (f_one != f_one + f_eps) {
    cout << "float f_eps = " << f_eps << endl;
    f_eps /= 2.0;
  }

  double d_one = 1.0;  
  double d_eps = d_one;
  while (d_one != d_one + d_eps) {
    cout << "double d_eps = " << d_eps << endl;
    d_eps /= 2.0;
  }
  
  long double ld_one = 1.0;
  long double ld_eps = ld_one;
  while (ld_one != ld_one + ld_eps) {
    cout << "long double ld_eps = " << ld_eps << endl;
    ld_eps /= 2.0;
  }
  
  return 0;
}
