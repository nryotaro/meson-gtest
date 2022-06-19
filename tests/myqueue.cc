#include "myqueue.h"
#include <gtest/gtest.h>

using namespace myqueue;

TEST(enqueue, 1) {
  MyQueue<int> sut;
  sut.enqueue(1);
  sut.enqueue(2);
  sut.enqueue(3);
  EXPECT_EQ(1, sut.dequeue());
  EXPECT_EQ(2, sut.dequeue());
  EXPECT_EQ(3, sut.dequeue());
  EXPECT_EQ(true, sut.empty());
}

TEST(array, 1) {
  ArrayQueue<int> sut;
  sut.enqueue(1);
  EXPECT_EQ(1, sut.dequeue());
}

TEST(array, 2) {
  ArrayQueue<int> sut;
  sut.enqueue(1);
  sut.enqueue(2);
  EXPECT_EQ(1, sut.dequeue());
  EXPECT_EQ(2, sut.dequeue());
}

TEST(array, 3) {
  ArrayQueue<int> sut;
  sut.enqueue(1);
  sut.enqueue(2);
  sut.enqueue(3);
  EXPECT_EQ(1, sut.dequeue());
  EXPECT_EQ(2, sut.dequeue());
  EXPECT_EQ(3, sut.dequeue());
}
