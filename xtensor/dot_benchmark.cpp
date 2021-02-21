#include <iostream>
#include <vector>
#include <set>
#include <chrono>
#include "xtensor/xarray.hpp"
#include "xtensor/xio.hpp"
#include "xtensor/xmath.hpp"
#include "xtensor/xview.hpp"
#include "xtensor/xrandom.hpp"
#include "xtensor-blas/xlinalg.hpp"

#define print(x) std::cout << x << std::endl;
#define print2(x,y) std::cout << x << " " << y << std::endl;
#define print3(x,y,z) std::cout << "" << x << " " << y << " " << z << std::endl;
#define np_array xt::xarray<int>

int main() {

  print("\n=========================")
  print("Speed Test")
  
  auto a = eval(xt::random::randn<double>({100}));
  auto b = eval(xt::random::randn<double>({100}));
  int  loops = 100000;

  auto start_time = std::chrono::high_resolution_clock::now();
  double result = 0.0;  
  for (int i : xt::arange(loops)) {  
    result += xt::linalg::dot(a,b)[0];
  }
  auto stop_time = std::chrono::high_resolution_clock::now();
  print2("Sum of dots: ", result)
  auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop_time - start_time);
  print2("duration (msec): ", duration.count())

} // main

