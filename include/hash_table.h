// #ifndef TABLE_HEADER_H_
// #define TABLE_HEADER_H_

// #endif // TABLE_HEADER_H_
#include <optional>
#include <vector>
template <typename T> class HashTable {
public:
  HashTable(int size);
  bool add(int key, int value);
  //  bool exist(int key);
  //  std::optional<T> get(int key);
  //  void remove(int key);

private:
  std::vector<std::optional<std::pair<int, int>>> table;
  int hash(int key);
};

/*
  #include <filesystem>
#include <hash_table.h>
#include <optional>
#include <vector>

/**
   hash(k, m) - m is size of hash table
   add(key, value) - if key already exists, update value
   exists(key)
   get(key)
   remove(key)
 */
HashTable::HashTable(int size) {
  table.resize(size);
  for (int i = 0; i < size; i++)
    table[i] = std::nullopt;
}
// template <typename T> HashTable<T>::HashTable(int size) {
//   table.resize(size);
//   for (int i = 0; i < size; i++)
//     table[i] = std::nullopt;
// }
// template <typename T> bool HashTable<T>::add(int key, T value) {
//   for (int k, i = 0; i < table.size(); i++) {
//     k = hash(key + i);
//     if (table[k] == std::nullopt) {
//       table[k] = {key, value};
//       return true;
//     }
//   }
//   return false;
// }
// template <typename T> int HashTable<T>::hash(int key) {
//   return key % table.size();
// }

/*

  bool add(int key, T value) {

    for (int h_key = hash(key), i = 0; i < table.size(); i++) {
      int k = (h_key + i) % table.size();
      if (table[k] == std::nullopt) {
        table[k] = {key, value};
        return true;
      }
    }
    return false;
  }

  bool exist(int key) {
    std::optional<T> v = get(key);
    return v != std::nullopt;
  }
  std::optional<T> get(int key) {
    for (int h_key = hash(key), i = 0; i < table.size(); i++) {
      int k = (h_key + i) % table.size();
      if (table[k] == std::nullopt)
        return std::nullopt;
      else if (table[k].first == key)
        return table[k].second;
    }
    return std::nullopt;
  }
  void remove(int key) {
    int pos = -1;
    for (int h_key = hash(key), i = 0; i < table.size(); i++) {
      int k = (h_key + i) % table.size();
      if (table[k] == std::nullopt)
        return;
    }
  }

private:
  std::vector<std::optional<std::pair<int, T>>> table;

  int hash(int key) { return key % table.size(); }
};
*/
