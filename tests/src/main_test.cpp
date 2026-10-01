#include "gtest/gtest.h"

TEST(test, test)
{
  EXPECT_TRUE(true);
  if (true)
  {
    EXPECT_TRUE(true);
  }
  else
  {
    EXPECT_TRUE(false);
  }
}

