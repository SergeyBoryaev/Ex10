// Copyright 2021 GHA Test Team
#ifndef INCLUDE_MYSTACK_H_
#define INCLUDE_MYSTACK_H_
#include <iostream>
#include <string>

template <typename T>
class MyStack {
 private:
  unsigned max;
  unsigned current;
  T* stack;

 public:
  MyStack() {
    max = 0;
    current = 0;
    stack = nullptr;
  }

  explicit MyStack(unsigned size) {
    max = size;
    current = 0;
    stack = new T[size];
  }

  explicit MyStack(const MyStack& b) {
    max = b.max;
    current = b.current;
    stack = new T[max];
    for (unsigned i = 0; i < current; i++)
      stack[i] = b.stack[i];
  }

  ~MyStack() {
    delete stack;
  }

  T get() const {
    if (!isEmpty())
      return stack[current-1];
    return 0;
  }

  T pop() {
    if (!isEmpty()) {
      current--;
      return stack[current];
    }
    return 0;
  }

  void push(T var) {
    if (current < max) {
      stack[current] = var;
      current++;
    }
  }

  bool isFull() const {
    return max == current;
  }

  bool isEmpty() const {
    return current == 0;
  }
};

#endif  // INCLUDE_MYSTACK_H_
