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

{
  print("=================================")
  print("Magnitude / Norm of vector")


//   auto a = xt::xarray<int>({1,2});
//   print("this is a")
//   print(a)
//   auto b = xt::xarray<int>({3,4});
//  auto dotc2 = xt::linalg::dot(a, b);

  auto a = xt::xarray<double> ({1,2});
  print2("auto a = xt::xarray<double> ({1,2});", a)

  auto b = xt::xarray<double> ({3,4});
  print2("auto b = xt::xarray<double> ({3,4});", b)

  auto amag = xt::sqrt( xt::sum(a*a) );
  print3("auto amag = xt::sqrt( xt::sum(a*a) )", amag,
         "this is the magnitude/norm of vector a")

  auto anorm = xt::linalg::norm(a);
  print2("auto anorm = xt::linalg::norm(a);", anorm)

  auto bmag = xt::sqrt(xt::sum(b*b));
  print3("auto bmag = xt::sqrt(xt::sum(b*b)); = ", bmag,
         "this is the magnitude/norm of vector b")

  auto bnorm = xt::linalg::norm(b);
  print2("auto bnorm = xt::linalg::norm(b);", bnorm)

  auto adotb = xt::linalg::dot(a,b);

  auto cosangle = xt::linalg::dot(a,b) / (xt::linalg::norm(a) * xt::linalg::norm(b));
  print2(
  "auto cosangle = xt::linalg::dot(a,b) / (xt::linalg::norm(a) * xt::linalg::norm(b));",
  cosangle)

  auto ang_radians = xt::acos(cosangle);
  print3("auto ang_radians = xt::acos(cosangle);", ang_radians,
         "  ## np.arccos")
}

{
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
}

{
  print("\n=========================")
  print("Matrices - 2d")

// mat1 = np.array([[1,2],[3,4]])
// print(f"mat1 = np.array([[1,2],[3,4]]) =\n{mat1}")

  auto mat1 = xt::xarray<double>({{1,2}, {3,4}});
  print2("auto mat1 = xt::xarray<double>({{1,2}, {3,4}});\n", mat1)

// element = mat1[0][1]
// element = mat1[0,1]
// print(f"element = mat1[0][1] = {element}")

  auto element = mat1[0,1];
  print2("auto element = mat1[0,1]; = ", element)

// col = mat1[:,0]
// print(f"col = mat1[:,0] = {col}")

  auto cola = xt::col(mat1,0);
  print2("auto col = xt::col(mat1,0); = ", cola)

  auto colb = xt::view(mat1, xt::all(), 1);
  print2("auto col = xt::view(mat1, xt::all(), 1); = ", colb)

// row = mat1[0,:]
// print(f"row = mat1[0,:] = {row}")

  auto rowa = xt::row(mat1, 0);
  print2("auto row = xt::row(mat1, 0); = ", rowa)

  auto rowb = xt::view(mat1, 1, xt::all());
  print2("auto row = xt::view(mat1, 1, xt::all()); = ", rowb)

// transpose = mat1.T
// print(f"transpose = mat1.T = \n{transpose}")

  auto transpose = xt::transpose(mat1);
  print2("auto transpose = xt::transpose(mat1);\n", transpose)


// print(f"exp = np.exp(mat1) =\n{np.exp(mat1)}")
// print(f"exp = np.exp(list1) = converts python list to numpy array\n{np.exp(list1)}")

  auto exp = xt::exp(mat1);
  print2("auto exp = xt::exp(mat1);\n", exp)

// A = np.array([[1,2],[3,4]])
// print("A = np.array([[1,2],[3,4]]) = {A}")

  auto A = xt::xarray<double>({{1,2}, {3,4}});
  print2("auto A = xt::xarray<double>({{1,2}, {3,4}});\n", A)

// B = np.array([[1,2,3],[4,5,6]])
// print(f"B = np.array([[1,2,3],[4,5,6]]) =\n{B}")

  auto B = xt::xarray<double>({{1,2,3}, {4,5,6}});
  print2(" auto B = xt::xarray<double>({{1,2,3}, {4,5,6}});\n", B)

// C = A.dot(B)
// print(f"C = A.dot(B) = performs matix multiply\n{C}")

  auto C = xt::linalg::dot(A,B);
  print2("auto C = xt::linalg::dot(A,B);\n", C)

// det = np.linalg.det(A)
// print(f"det = np.linalg.det(A) = {det} determinant of matrix")

  auto det = xt::linalg::det(A);
  print2("auto det = xt::linalg::det(A);\n", det)

// Ainv = np.linalg.inv(A)
// print(f"Ainv = np.linalg.inv(A) = matrix inverse\n{Ainv}")

  auto Ainv = xt::linalg::inv(A);
  print2("auto Ainv = xt::linalg::inv(A);\n", Ainv)


// identity = A.dot(Ainv)
// print(f"identity = A.dot(Ainv) = returns identity matrix\n{identity}")

  auto identity = xt::linalg::dot(A, Ainv);
  print2("auto indentity = xt::linalg::dot(A, Ainv);\n", identity)

// tr = A.trace()
// print(f"tr = A.trace() = {tr} = np.trace(A) = {np.trace(A)}-- sum of elements on the diagonal")

  auto tr = xt::linalg::trace(A);
  print2("auto tr = A.trace();\n", tr)

// diag = np.diag(A)
// print(f"diag = np.diag(A) = {diag}  -- returns vector")

  auto dvec = xt::xarray<double>({1,2,3,4,5});
  print2("auto dvec = xt::xarray<double>({1,2,3,4,5});\n", dvec)
  auto diag = xt::diag(dvec);
  print2("auto diag = xt::diag(dvec));\n", diag)

  auto diag_vec = xt::diagonal(A);
  print2("auto diag_vec = xt::diagonal(A);", diag_vec)
}

{

  print("\n=========================")
  print("Solve Linear Equations")

//   A = np.array([[1,1],[1.5,4]])
//   print(f"A = np.array([[1,1],[1.5,4]]) =\n{A}")

  auto A = xt::xarray<double>({{1,1}, {1.5,4}});
  print2("auto A = xt::xarray<double>({{1,1}, {1.5,4}});\n", A)

//   b = np.array([2200, 5050])
//   print(f"b = np.array([2020, 5050])] =\n{b}")

  auto b = xt::xarray<double>({2200,5050});
  print2("auto b = xt::array<double>({2200,5050});\n", b)

//   x = np.linalg.inv(A).dot(b)
//   print(f"x = np.linalg.inv(A).dot(b) = DON'T USE THIS METHOD\n{x}")

  auto x1 = xt::linalg::dot(xt::linalg::inv(A), b);
  print2("auto x = xt::linalg::dot(xt::linalg::inv(A), b);\n", x1)

//   X = np.linalg.solve(A,b)
//   print(f"X = np.linalg.solve(A,b) = USE THIS METHOD TO SOLVE \n{X}")

  auto x2 = xt::linalg::solve(A,b);
  print2("auto x2 = xt::linalg::solve(A,b);\n", x2)

}

{
  print("\n=========================")
  print("Generating Data")
  
//   z = np.zeros((2,8))

  auto z = xt::zeros<double>({2,8});
  print2("auto z = xt::zeros<double>({2,8});\n", z)
  
//   ones = np.ones((5,3))
  
  auto ones = xt::ones<double>({5,3});
  print2("auto ones = xt::ones<double>({5,3});\n", ones)
  
//   tens = 10 * np.ones((4,4))

  auto tens = 10 * xt::ones<double>({4,4});
  print2("auto tens = 10.0 * xt::ones<double>({4,4});\n", tens)
  
//   eye = np.eye(5)

  auto eye = xt::eye<double>(5);
  print2("auto eye = xt::eye<double>(5);\n", eye)  
}

{
  print("\n=========================")
  print("Random Numbers")
//   r = np.random.random((2,4))
//   print(f"r = np.random.random((2,4)) = uniform in range 0 to 1\n{r}")

  auto r = xt::random::rand<double>({2,4});
  print2("auto r = xt::random::rand({2,4}); ## Uniform 0->1 Dist\n", r)  
  
//   n = np.random.randn(4,2)
//   print(f"normal = np.random.randn((4,2)) = normal/gaussian\n{n}")
  
  auto n = xt::random::randn<double>({4,2});
  print2("auto n = xt::random::randn<double>({4,2}); ## Guassian/Normal Dist\n", n)
  
//   R = np.random.randn(10000)
//   print(f"R = np.random.randn(1000) = ")

  auto R = xt::random::randn<double>({1000});
  auto shape = R.shape();
  print3("auto R = xt::random::randn<double>(1000);\n", shape[0], " elements")

//   mean = R.mean()
//   print(f"mean = R.mean() = {mean} = np.mean(R) = {np.mean(R)}")

  auto mean = xt::mean(R);
  print2("auto mean = xt::mean(R);\n", mean)
  
//   R = np.random.randn(1000,3)
//   mean_col = R.mean(axis=0)
//   print(f"mean_col = R.mean(axis=0) = calculates mean of each column\n{mean_col}")

  auto R2 = xt::random::randn<double>({1000,3});
  print("auto R2 = xt::random::randn({1000,3});")
  auto mean_col = xt::mean(R2, {0});
  print2("auto mean_col = xt::mean(R2, {0}); ## Mean of each column\n", mean_col)

// mean_of_each_row = R.mean(axis=1)
// print(f"mean_of_each_row = R.mean(axis=1) = mean of each row. 1000 means in this case")

  auto mean_of_each_row = xt::mean(R2, {1});
  print3("auto mean_of_each_row = xt::mean(R2, 1);\n", 
         mean_of_each_row.shape()[0], " elements")

// variance = R.var()
// print(f"variance = R.var() = {variance} = np.var(R) = {np.var(R)}")

  auto variance = xt::variance(R2);
  print2("auto variance = xt::var(R2);\n", variance)


// std = R.std()
// print(f"std = R.std() = {std} = np.std(R) = {np.std(R)} -- sqrt of variance")

  auto standard_deviation = xt::stddev(R2);
  print2("auto standard_deviation = xt::stddev(R2);\n", standard_deviation)

// Rint = np.random.randint(0,100,size=(2,4))
// print(f"Rint = np.random.randint(0,100,size=(2,4)) = \n{Rint}")

  auto Rint = xt::random::randint<int>({2,4}, 300, 400);
  print2("auto Rint = xt::random::randint<int>({2,4}, 300, 400);\n", Rint)

}


{
  print("\n=========================")
  print("Reductions")
  
  auto A = xt::arange(24);
  print2("auto A = xt::arange(24);\n", A)
  
  auto B = A.reshape({6,4});
  print2("auto B = A.reshape({6,4});\n", B)
  print3("B.shape();", B.shape()[0], B.shape()[1] )
  
  auto sum_all = xt::sum(B);
  print2("auto sum_all = xt::sum(B);\n", sum_all)
  
  auto sum_rows = xt::sum(B,{1});
  print2("auto sum_rows = xt::sum(B,{1});\n", sum_rows)

  auto sum_columns = xt::sum(B, {0});
  print2("auto sum_columns = xt::sum(B, {0});\n", sum_columns)

}

} // main

