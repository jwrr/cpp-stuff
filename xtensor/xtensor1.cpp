#include <iostream>
#include <vector>
#include <set>
#include "xtensor/xarray.hpp"
#include "xtensor/xio.hpp"
#include "xtensor/xmath.hpp"
#include "xtensor/xview.hpp"
#include "xtensor-blas/xlinalg.hpp"


#define print(x) std::cout << x << std::endl;
#define print2(x,y) std::cout << x << " " << y << std::endl;
#define print3(x,y,z) std::cout << "" << x << " " << y << " " << z << std::endl;
#define np_array xt::xarray<int>

int main() {


  // print("Numpy array")
  // aarr = np.array([1,2,3])
  // print(aarr)


  print("Numpy array")
//  xt::xarray<int> aarr = {1, 2, 3};
//  auto aarr = xt::xarray<int> {1, 2, 3};
  auto aarr = np_array({1, 2, 3});
  print(aarr)


  // print("for loop over array")
  // for item in aarr:
  //   print(item)

  print("for loop over array")
//   for(auto const& item : aarr)
//     print(item)
  for(auto item : aarr)
    print(item)


  // print("Arrays are fixed size, so you can't append, so use concatenate")
  // barr = np.array([4])
  // carr = np.concatenate((aarr, barr))
  // print(carr)

  print("concatenate arrays")
  xt::xarray<int> barr = {4};
  xt::xarray<int> carr = xt::concatenate(xt::xtuple(aarr, barr));
//   auto barr = np_array({4});
//   auto carr = xt::concatenate(aarr, barr);
  print(carr)

  // print("Add number (7 in this case) to each element of array")
  // darr = carr + 7
  // print(darr)

  print("Add number (7 in this case) to each element of array")
  xt::xarray<int> darr = carr + 7;
  print(darr)

  // print("Add two arrays")
  // darr += carr
  // print(darr)

  print("Add two arrays")
  darr += carr;
  print(darr)

  // print("Multiply scalar * array")
  // earr = 2 * darr
  // print(earr)
  //

  print("Multiply scalar * array")
  xt::xarray<int> earr = 2 * darr;
  print(earr)


  // print("Square each element in array **")
  // farr = earr**2
  // print(farr)

  print("Square each element in array **")
  xt::xarray<int> farr = xt::square(earr);
  print(farr)

  // print("Square root (np.sqrt) all items in array")
  // garr = np.sqrt(farr)
  // print(garr)

  print("Square root (np.sqrt) all items in array")
  xt::xarray<int> garr = xt::sqrt(farr);
  print(garr)

  // print("np.log2")
  // harr = np.log2(garr)
  // print(harr)

  print("np.log2")
  xt::xarray<int> harr = xt::log2(garr);
  print(harr)

  print("====================================")


  xt::xarray<double> arr1
    {{1.0, 2.0, 3.0},
     {2.0, 5.0, 7.0},
     {2.0, 5.0, 7.0}};

  print(arr1(0, 0))

  xt::xarray<int> arr2
    {1, 2, 3, 4, 5, 6, 7, 8, 9};

  print(arr2(0))


  print("====================================")
  print("====================================")
  print("====================================")
  print("====================================")


// a = np.array([1,2])
// print(a)
// b = np.array([3,4])
// print(b)
// c = a * b
// print(c)

//  auto aarr = xt::xarray<int> {1, 2, 3};

  auto a = xt::xarray<int>({1,2});
  print("this is a")
  print(a)
  auto b = xt::xarray<int>({3,4});
  print("this is b")
  print(b)
  auto c = a + b;
  print("this is c")
  print(c)

// print("===================")
// print("dot product using for loop and zip. sum of products")
// dot = 0
// for e,f in zip(a,b):
//   dot += e * f
// print(dot)

{
  print("=1==================")
  print("dot product using for loop. sum of products")
  print2(a,b)
  int dot = 0;
  for (auto ita=a.begin(),itb=b.begin(); ita!=a.end(); ++ita, ++itb) {
    dot += *ita * *itb;
  }
  print(dot)
}

{
  print("=2a==================")
  print2(a,b)
  int dot = 0;
  auto ib = b.begin();
  for (auto& ia : a) {
    dot += ia * *ib++;
  }
  print(dot)
}


// {
// print("=2b==================")
// print2(a,b)
// int dot = 0;
// for (auto& [ia,ib] : a,b) {
//   dot += ia * ib;
//   print3(ia, ib, dot)
// }
// print(dot)
// }

{
  // print("dot product using * and np.sum. sum of products")
  // prod = a * b
  // sum_of_prod = np.sum(prod)
  // print(sum_of_prod)

  print("dot product using * and xt::sum. sum of products")
  auto prod = a * b;
  auto sum_of_prod = xt::sum(prod);
  print(sum_of_prod)
}


{
  // print("dot product using (a*b).sum()")
  // print("dot product using (a*b).sum()")
  // print( (a*b).sum() )

  print("=================================")
  print("Dot product using sum((a*b)")
  auto prod = xt::xarray<int>(a*b);
  auto dot = xt::sum(prod);
  print(dot)
}


{
  // print("dot product using np.dot")
  // dotprod = np.dot(a,b)
  // print(dotprod)
  print("=================================")
  print("Dot product using dot()")
  auto dotc2 = xt::linalg::dot(a, b);
  print(dotc2)
}


{
  print("=================================")
  print("Dot product using @ symbol")
  // print(a@b)
  print("  Nope, I don't think it's supported")
}




{
  print("=================================")
  print("Create 2d and 1d arrays")
  xt::xarray<double> arr1
    {{1.0, 2.0, 3.0},
     {2.0, 5.0, 7.0},
     {2.0, 5.0, 7.0}};
  print(arr1(0, 0))
  xt::xarray<int> arr2
    {1, 2, 3, 4, 5, 6, 7, 8, 9};
  print(arr2(0))
}


{
  print("=================================")
  print("Add 2d + 1d")
  xt::xarray<double> arr1
    {{1.0, 2.0, 3.0},
     {2.0, 5.0, 7.0},
     {2.0, 5.0, 7.0}};
  xt::xarray<double> arr2 {5.0, 6.0, 7.0};
  xt::xarray<double> res = xt::view(arr1, 1) + arr2;
  print(res)
}


{
  print("=================================")
  print("Reshape 2d array")
  xt::xarray<int> arr {1, 2, 3, 4, 5, 6, 7, 8, 9};
  arr.reshape({3, 3});
  print(arr)
}


} // main

