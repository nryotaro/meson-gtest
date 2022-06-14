#ifndef MYARRAY_H_
#define MYARRAY_H_
#include <cstddef>
#include <initializer_list>
#include <memory>

namespace myarray {
template <typename T> class MyArray {
public:
  MyArray(std::initializer_list<T> list) {
    size = capacity = list.size();
    ptr = std::make_unique<T[]>(capacity);
    T *p = ptr.get();
    int i = 0;
    for (T item : list)
      *(p + i++) = item;
  }

  const T &operator[](size_t i) { return ptr[i]; }

private:
  std::unique_ptr<T[]> ptr;
  size_t capacity;
  size_t size;
};
} // namespace myarray
#endif
