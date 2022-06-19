#ifndef MYQUEUE_H_
#define MYQUEUE_H_
#include <iostream>
#include <list>
#include <memory>
/*
Implement using linked-list, with tail pointer:
enqueue(value) - adds value at position at tail
dequeue() - returns value and removes least recently added element (front)
empty()
*/

namespace myqueue {
template <typename T> class MyQueue {

public:
  void enqueue(T value) { items.push_back(value); }

  T dequeue() {
    T item = items.front();
    items.pop_front();
    return item;
  }

  bool empty() { return items.size() == 0; }

private:
  std::list<T> items;
};

template <typename T> class ArrayQueue {
public:
  ArrayQueue() : size(0), capacity(2), start(0), end(0) {
    array = std::make_unique<T[]>(capacity);
  }
  void enqueue(T value) {
    resize();
    array[end] = value;
    end = (end + 1) % capacity;
    size++;
  }

  T dequeue() {
    T item = array[start];
    start = (start + 1) % capacity;
    size--;
    resize();
    return item;
  }

  bool empty() { return size == 0; }
  bool full() { return capacity == size; }

private:
  std::size_t size;
  std::size_t capacity;
  std::size_t start;
  std::size_t end;
  std::unique_ptr<T[]> array;

  void resize() {
    std::size_t cap;
    if (2 < capacity && size < capacity / 2) {
      cap = 2;
      while (cap < size) {
        cap *= 2;
      }
    } else if (size == capacity) {
      cap = capacity * 2;
    } else {
      return;
    }
    std::unique_ptr<T[]> next_array = std::make_unique<T[]>(cap);
    for (size_t i = 0; i < size; i++) {
      next_array[i] = array[(start + i) % capacity];
    }
    array = move(next_array);
    capacity = cap;
    start = 0;
    end = size;
  }
};
} // namespace myqueue
#endif
