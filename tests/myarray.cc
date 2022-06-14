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

TEST(insert, 1) {
  MyArray<int> sut = {0};
  sut.insert(0, 1);

  EXPECT_EQ(2, sut.size());
  EXPECT_EQ(1, sut[0]);
  EXPECT_EQ(0, sut[1]);
}

TEST(prepent, 1) {
  MyArray<int> sut = {0, 1, 3, 43};
  sut.prepend(5);
  EXPECT_EQ(5, sut[0]);
}
