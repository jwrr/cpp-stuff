// epsilon.cpp
// Measure smallest value that makes a difference for float, double and long 
// double.
// Reference: https://www.youtube.com/playlist?list=PLzn6LN6WhlN1Lic9M9mbzqV3ASokOdnFM
// Course: Programming Techniques for Scientific Simulation 1
// Lecturer: Matthias Troyer

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

// =====================================================================
// =====================================================================

int main(int argc, char **argv)
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

