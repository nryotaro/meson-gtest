#ifndef TABLE_HEADER_H_
#define TABLE_HEADER_H_
#include <iostream>
#include <optional>
#include <vector>
template <typename T> class HashTable {
public:
  HashTable(int size) {
    values.resize(size);
    keys.resize(size);
    for (int i = 0; i < size; i++)
      values[i] = keys[i] = std::nullopt;
  }
  bool add(int key, T value) {
    for (int k = key, i = 0; i < get_size(); i++) {
      k = hash(key + i);
      if (values[k] == std::nullopt) {
        keys[k] = key;
        values[k] = value;
        return true;
      } else if (keys[k] == key)
        return true;
    }
    return false;
  }
  std::optional<T> get(int key) {
    for (int k = key, i = 0; i < get_size(); i++) {
      k = hash(key + i);

      if (keys[k] == std::nullopt || hash(key) != hash(keys[k].value()))
        return std::nullopt;
      if (keys[k].value() == key)
        return values[k];
    }
    return std::nullopt;
  }
  bool exist(int key) { return get(key) != std::nullopt; }
  void debug() {
    for (int i = 0; i < get_size(); i++) {
      std::cout << i << " -> ";
      if (keys[i] == std::nullopt) {
        std::cout << "null, null\n";
      } else {
        std::cout << keys[i].value() << " " << values[i].value() << "\n";
      }
    }
  }
  void remove(int key) {
    if (!exist(key))
      return;

    int current, last;
    for (int k = key, i = 0; i < get_size(); i++) {
      k = hash(key + i);
      if (keys[k] == std::nullopt || hash(key) != hash(keys[k].value())) {
        last = k - 1;
        if (last < 0)
          last += get_size();
        break;
      } else if (keys[k].value() == key) {
        current = k;
      }
    }
    if (current == last) {
      values[current] = keys[current] = std::nullopt;
    } else {
      values[current] = values[last];
      keys[current] = keys[last];
      keys[last] = values[last] = std::nullopt;
    }
  }

private:
  std::vector<std::optional<T>> values;
  std::vector<std::optional<int>> keys;
  int hash(int key) { return key % values.size(); }
  int get_size() { return static_cast<int>(values.size()); }
};
#endif // TABLE_HEADER_H_
