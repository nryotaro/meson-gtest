#include "mylist.h"
#include <gtest/gtest.h>
using namespace mylist;

TEST(push_front, 1) {
  MyList<int> sut;
  sut.push_front(1);
  sut.push_front(2);
  sut.push_front(3);
  EXPECT_EQ(3, sut.size());

  EXPECT_EQ(3, sut.value_at(0));
  EXPECT_EQ(2, sut.value_at(1));
  EXPECT_EQ(1, sut.value_at(2));
}

TEST(popfront, 1) {
  MyList<int> sut;
  sut.push_back(2);
  EXPECT_EQ(2, sut.value_at(0));
  EXPECT_EQ(2, sut.pop_front());
  sut.push_back(3);
  EXPECT_EQ(1, sut.size());
  EXPECT_EQ(3, sut.value_at(0));

  sut.push_back(-1);
  sut.push_back(2);
  sut.push_back(1);
  sut.push_back(0);
  EXPECT_EQ(5, sut.size());
  EXPECT_EQ(3, sut.pop_front());
}

TEST(popback, 1) {
  MyList<int> sut;
  sut.push_back(1);
  sut.push_back(2);
  sut.push_back(3);
  EXPECT_EQ(1, sut.value_at(0));
  EXPECT_EQ(2, sut.value_at(1));
  EXPECT_EQ(3, sut.value_at(2));
  EXPECT_EQ(3, sut.pop_back());
}

TEST(insert, 1) {
  MyList<int> sut;
  sut.insert(0, 1);
  sut.insert(1, 2);
  sut.insert(2, 3);
  EXPECT_EQ(1, sut.value_at(0));
  EXPECT_EQ(2, sut.value_at(1));
  EXPECT_EQ(3, sut.value_at(2));
  sut.insert(1, 9);
  EXPECT_EQ(9, sut.value_at(1));
  EXPECT_EQ(2, sut.value_at(2));
  EXPECT_EQ(3, sut.value_at(3));
}

TEST(erase, 1) {
  MyList<int> sut;
  sut.push_front(3);
  sut.push_front(2);
  sut.push_front(1);

  sut.erase(1);

  EXPECT_EQ(1, sut.value_at(0));
  EXPECT_EQ(3, sut.value_at(1));
  EXPECT_EQ(2, sut.size());
}
TEST(value_n_fron_end, 1) {
  MyList<int> sut;
  sut.push_front(3);
  sut.push_front(2);
  sut.push_front(1);

  EXPECT_EQ(3, sut.value_n_from_end(0));
  EXPECT_EQ(2, sut.value_n_from_end(1));
  EXPECT_EQ(1, sut.value_n_from_end(2));
}

TEST(reverse, 1) {
  MyList<int> sut;
  sut.push_front(3);
  sut.push_front(2);
  sut.push_front(1);

  sut.reverse();

  EXPECT_EQ(3, sut.value_at(0));
  EXPECT_EQ(2, sut.value_at(1));
  EXPECT_EQ(1, sut.value_at(2));
}

TEST(remove_value, 1) {
  MyList<int> sut;
  sut.push_front(3);
  sut.push_front(2);
  sut.push_front(1);

  sut.remove_value(2);

  EXPECT_EQ(1, sut.value_at(0));
  EXPECT_EQ(3, sut.value_at(1));
}
