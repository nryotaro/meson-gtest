#ifndef MYARRAY_H_
#define MYARRAY_H_
#include <cstddef>
#include <initializer_list>
#include <memory>

namespace myarray {
template <typename T> class MyArray {
public:
  MyArray(std::initializer_list<T> list) {
    siz = list.size();
    cap = 16;
    while (cap < siz) {
      cap *= 2;
    }
    ptr = std::make_unique<T[]>(cap);
    T *p = ptr.get();
    int i = 0;
    for (T item : list)
      *(p + i++) = item;
  }

  const T &operator[](size_t i) { return ptr[i]; }

  size_t size() const { return siz; }

  size_t capacity() const { return cap; }

  bool is_empty() const { return size() == 0; }

  void push(T item) {
    resize();
    ptr[++siz] = item;
  }

  void insert(size_t index, T item) {
    resize();
    std::unique_ptr<T[]> next_ptr = std::make_unique<T[]>(capacity());
    for (size_t i = 0; i < index; i++) {
      next_ptr[i] = ptr[i];
    }
    next_ptr[index] = item;
    for (size_t i = index; i < size(); i++) {
      next_ptr[i + 1] = ptr[i];
    }
    ptr = move(next_ptr);
    siz++;
  }

  void prepend(T item) { insert(0, item); }

  T pop() {
    T item = ptr[size() - 1];
    siz--;
    resize();
    return item;
  }

  void del(size_t index) {
    std::unique_ptr<T[]> next_ptr = std::make_unique<T[]>(capacity());
    for (size_t i = 0, idx = 0; i < size(); i++) {
      if (i != index) {
        next_ptr[idx++] = ptr[i];
      }
    }
    ptr = move(next_ptr);
    siz--;
    resize();
  }

private:
  std::unique_ptr<T[]> ptr;
  size_t cap;
  size_t siz;

  // private function
  // when you reach capacity, resize to double the size
  // when popping an item, if size is 1/4 of capacity, resize to half
  void resize() {
    size_t next_cap;
    if (size() == capacity()) {
      next_cap = cap * 2;
    } else if (size() * 4 <= capacity()) {
      next_cap = capacity() / 2;
    } else {
      return;
    }
    std::unique_ptr<T[]> next_ptr = std::make_unique<T[]>(next_cap);
    for (size_t i = 0; i < size(); i++) {
      next_ptr[i] = ptr[i];
    }
    ptr = move(next_ptr);
    cap = next_cap;
  }
};
} // namespace myarray
#endif
