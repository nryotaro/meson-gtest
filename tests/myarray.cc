#include "myarray.h"
#include <gtest/gtest.h>
using namespace myarray;

TEST(acess, 1) {
  MyArray<int> sut = {23, 2};
  EXPECT_EQ(2, sut[1]);
}

TEST(size, 2) {
  MyArray<int> sut = {23, 2};
  EXPECT_EQ(2, sut.size());
}
