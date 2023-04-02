#include "collatz.hpp"

#include "gtest/gtest.h"

TEST(collatz, 5)
{
   EXPECT_EQ(collatz(5), 6UL);
}

int main(int argc, char* argv[])
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}