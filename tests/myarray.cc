#include "myarray.h"
#include <gtest/gtest.h>
using namespace myarray;

TEST(ArrayAccess, 1) {
  MyArray<int> sut = {23, 2};

  EXPECT_EQ(sut[1], 2);
}
