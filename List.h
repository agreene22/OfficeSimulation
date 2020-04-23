/* Anna Greene - 2314663
  Brandon Kleinman - 2291703
  Assignment 4 - Registrar Office Simulation
  List interface for the queue
 */

#ifndef LIST_H
#define LIST_H
#include <iostream>

using namespace std;

// Template class List interface
template <class T>
class List{
public:
  virtual void enqueue(T* element) = 0; // virtual methods for queue
  virtual T* dequeue() = 0;
  
  virtual T* peek() = 0;
  virtual bool isFull() = 0;
  virtual bool isEmpty() = 0;
  virtual int getSize() = 0;
};

#endif
