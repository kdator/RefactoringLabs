#include "pch.h"

#include "../LinearEquation.h"

TEST(Lab2, RunAllPossibleTests) {
  std::string equation1 = LinearEquation_solveEquation(1, 1, 1, 1, 1, 1);
  std::string equation2 = LinearEquation_solveEquation(0, 0, 0, 0, 0, 0);
  std::string equation3 = LinearEquation_solveEquation(5, -2, 0, 8, 8, 2);
  std::string equation4 = LinearEquation_solveEquation(0, -1, 0, 0, -2, -10);
  std::string equation5 = LinearEquation_solveEquation(0, 0, -23, 0, 0, -5);
  std::string equation6 = LinearEquation_solveEquation(0, 0, 0, 3, 0, 4);
  std::string equation7 = LinearEquation_solveEquation(32, 0, 423, 4, 0, 2);

  ASSERT_STREQ(equation1.c_str(), "1 -1 1");
  ASSERT_STREQ(equation2.c_str(), "5");
  ASSERT_STREQ(equation3.c_str(), "2 1.7 0.25");
  ASSERT_STREQ(equation4.c_str(), "0");
  ASSERT_STREQ(equation5.c_str(), "3 0.217391");
  ASSERT_STREQ(equation6.c_str(), "4 1.33333");
  ASSERT_STREQ(equation7.c_str(), "2 0 0.5");
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
