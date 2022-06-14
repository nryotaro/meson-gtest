#include "myarray.h"
#include <gtest/gtest.h>
using namespace myarray;

TEST(acess, 1) {
  MyArray<int> sut = {23, 2};
  EXPECT_EQ(2, sut[1]);
}

TEST(size, 1) {
  MyArray<int> sut = {23, 2};
  EXPECT_EQ(2, sut.size());
}

TEST(capacity, 1) {
  MyArray<int> sut = {};
  EXPECT_EQ(16, sut.capacity());
}

TEST(capacity, 2) {
  MyArray<int> sut = {};
  for (int i = 0; i < 17; i++) {
    sut.push(i);
  }

  EXPECT_EQ(32, sut.capacity());
}
