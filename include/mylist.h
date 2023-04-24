#ifndef MYLIST_H_
#define MYLIST_H_
#include <bits/stdc++.h>
#include <cassert>
#include <cstddef>
#include <memory>
using namespace std;

template <typename T> class MyNode {
public:
  MyNode() {}
  MyNode(T value, std::unique_ptr<MyNode<T>> next)
      : value(value), next(move(next)) {}
  MyNode(T value) : value(value), next(nullptr) {}
  T value;
  std::unique_ptr<MyNode<T>> next;
};

namespace mylist {
template <typename T> class MyList {
public:
  MyList() : siz(0), head(nullptr) {}
  size_t size() { return siz; }

  bool empty() { return size() == 0; }

  T value_at(size_t index) { return node_at(index)->value; }

  void push_front(T value) {
    std::unique_ptr<MyNode<T>> next = move(head);
    head = std::make_unique<MyNode<T>>(value);
    head->next = move(next);
    siz++;
  }

  T pop_front() {
    T result = head->value;
    head = move(head->next);
    siz--;
    return result;
  }

  void push_back(T value) {
    if (empty()) {
      push_front(value);
    } else {
      MyNode<T> *tail = node_at(size() - 1);
      tail->next = make_unique<MyNode<T>>(value);
      siz++;
    }
  }

  T pop_back() {
    T val;
    if (size() == 1) {
      val = head->value;
      head.reset();
    } else {
      MyNode<T> *node = node_at(size() - 2);
      val = node->next->value;
      node->next.reset();
    }
    siz--;
    return val;
  }

  T front() { return value_at(0); }

  T back() { return value_at(size() - 1); }

  void insert(size_t index, T value) {
    if (index == 0) {
      push_front(value);
    } else {
      MyNode<T> *node = node_at(index - 1);
      node->next = make_unique<MyNode<T>>(value, move(node->next));
      siz++;
    }
  }

  void erase(size_t index) {
    if (size() == 1) {
      pop_front();
    } else if (index == size() - 1) {
      pop_back();
    } else {
      MyNode<T> *prev = node_at(index - 1);
      MyNode<T> *target = node_at(index);
      prev->next = move(target->next);
      siz--;
    }
  }
  T value_n_from_end(size_t n) { return value_at(size() - 1 - n); }

  void reverse() {
    size_t n = size();
    if (n < 2)
      return;
    std::unique_ptr<MyNode<T>> cur = move(head);
    std::unique_ptr<MyNode<T>> next = move(cur->next);
    for (size_t i = 0; i < n - 1; i++) {
      std::unique_ptr<MyNode<T>> next_next = move(next->next);
      next->next = move(cur);
      cur = move(next);
      next = move(next_next);
    }
    head = move(cur);
  }
  void remove_value(T value) {
    MyNode<T> *cur;
    cur = head.get();
    for (size_t i = 0; i < size(); i++) {
      if (cur->value == value) {
        erase(i);
        return;
      }
      cur = cur->next.get();
    }
  }

private:
  size_t siz;
  std::unique_ptr<MyNode<T>> head;

  MyNode<T> *node_at(size_t index) {
    MyNode<T> *result = head.get();
    for (int i = 0; i < static_cast<int>(index); i++) {
      result = result->next.get();
    }
    return result;
  }
};

} // namespace mylist

#endif
