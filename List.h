#ifndef LIST_H
#define LIST_H
#include <iostream>

using namespace std;

template <class T>
class List{
public:
  virtual void enqueue(T* element) = 0;
  virtual T* dequeue() = 0;
  virtual T* peek() = 0;

  virtual bool isEmpty() = 0;
  virtual int getSize() = 0;
};

#endif
