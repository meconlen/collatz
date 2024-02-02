#include "collatz.hpp"

#include "gtest/gtest.h"

TEST(collatz, 1)
{
   EXPECT_EQ(collatz(1), 1UL);
}

TEST(collatz, 0)
{
   EXPECT_EQ(collatz(0), 0UL);
}

TEST(collatz, 5)
{
   // collatz now uses a map to memoize, we want to make sure we've populated it. 
   collatz(2);
   collatz(3);
   collatz(4);
   collatz(16);

   EXPECT_EQ(collatz(5), 6UL);
}

TEST(collatz, 30000000)
{
   EXPECT_EQ(collatz(30000000), 176);
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