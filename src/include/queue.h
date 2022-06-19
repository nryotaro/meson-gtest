#include <list>
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
} // namespace myqueue
