// epsilon.cpp
// Measure smallest value that makes a difference for float, double and long 
// double.
// Reference: https://www.youtube.com/playlist?list=PLzn6LN6WhlN1Lic9M9mbzqV3ASokOdnFM
// Course: Programming Techniques for Scientific Simulation 1
// Lecturer: Matthias Troyer


#define BOOST_TEST_MODULE TestEpsilon
#include <boost/test/unit_test.hpp>
#include "epsilon.h"

BOOST_AUTO_TEST_CASE(TestLT)
{
  BOOST_CHECK_LT(EPS::epsilon<float>(), 0.0001);
  BOOST_CHECK_LT(EPS::epsilon<double>(), EPS::epsilon<float>());
  BOOST_CHECK_LT(EPS::epsilon<long double>(), EPS::epsilon<double>());
}
  
BOOST_AUTO_TEST_CASE(TestGT)
{
  BOOST_CHECK_GT(EPS::epsilon<float>(), 0.0);
  BOOST_CHECK_GT(EPS::epsilon<float>(), 0.0);
  BOOST_CHECK_GT(EPS::epsilon<double>(), 0.0);
  BOOST_CHECK_GT(EPS::epsilon<long double>(), 0.0);
}

// =====================================================================
// =====================================================================

/* ---------------------------------------------------------------------
#include <gtest/gtest.h>
#include "epsilon.h"

TEST(EpsilonTest, f_eps) {
  ASSERT_TRUE(EPS::epsilon<float>() < 0.0001);
}

TEST(EpsilonTest, d_eps) {
  ASSERT_LE(EPS::epsilon<double>(), EPS::epsilon<float>());
}

TEST(EpsilonTest, ld_eps) {
  ASSERT_LE(EPS::epsilon<long double>(), EPS::epsilon<double>());
}

int main(int argc, char **argv)
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

*/

