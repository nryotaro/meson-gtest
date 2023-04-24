#include <gtest/gtest.h>
#include <hash_table.h>

TEST(hash_table_add, 1) {
  HashTable<int> sut(2);
  EXPECT_TRUE(sut.add(10, 2));
  EXPECT_TRUE(sut.add(9, 2));
  EXPECT_TRUE(sut.add(9, 2));
  EXPECT_FALSE(sut.add(8, 2));
}

TEST(hash_table_get, 1) {
  HashTable<int> sut(4);
  sut.add(1, 3);
  sut.add(5, 4);
  EXPECT_EQ(sut.get(1), 3);
  EXPECT_EQ(sut.get(5), 4);
}

TEST(hash_table_remove, 1) {
  HashTable<int> sut(4);
  sut.add(1, 3);
  sut.add(5, 4);
  EXPECT_EQ(sut.get(1), 3);
  sut.remove(1);
  EXPECT_FALSE(sut.exist(1));
}
