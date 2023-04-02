#include "collatz.hpp"

#include "gtest/gtest.h"

TEST(collatz, 5)
{
   EXPECT_EQ(collatz(5), 6UL);
}

TEST(collatz, 1)
{
   EXPECT_EQ(collatz(1), 1UL);
}

TEST(collatz, 0)
{
   EXPECT_EQ(collatz(0), 0UL);
}

TEST(verify, 1000) 
{
   EXPECT_EQ(verify(1000), true);
}


int main(int argc, char* argv[])
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}