//the iostream and boost libraries are included to be able to make use of cin, cout and  multiply very very long integers
#include <iostream>
#include <boost/multiprecision/cpp_int.hpp>

#define BOOST_TEST_MODULE MyTest
#include <boost/test/unit_test.hpp>

using namespace boost::multiprecision;
using namespace std;


BOOST_AUTO_TEST_CASE(MyTestCase)
{
	// To simplify this example test, let's suppose we'll test 'float'.
	// Some test are stupid, but all should pass.
	float x = 9.5f;

	BOOST_CHECK(x != 0.0f);
	BOOST_CHECK_EQUAL((int)x, 9);
	BOOST_CHECK_CLOSE(x, 9.5f, 0.0001f); // Checks differ no more then 0.0001%
}


/*
int main()
{
  //two very very long integers are stored in two respective variables called 
  // first and second  and then multiplied with each other and stored in a 
  // variable of type big data integer type  prod and then their product is 
  // displayed as the output on the screen.
  
  long long first = 123456789987654321;
  long long second=987654321123456789;
  int128_t prod = (int128_t) first * second;
  cout << "The product of the given two long long integers is:" << "\n" << prod << endl;
  return 0;
}
*/


