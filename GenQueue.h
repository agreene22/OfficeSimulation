/* Anna Greene - 2314663
  Brandon Kleinman - 2291703
  Assignment 4 - Registrar Office Simulation
  GenQueue is a template queue using a Doubly Linked List
 */
#ifndef GENQUEUE_H
#define GENQUEUE_H

#include <iostream>
#include "DoublyLinkedList.h"
#include "List.h"
using namespace std;

// GenQueue class inheriting the List interface
template <typename T>
class GenQueue : public List<T>{
public:
  GenQueue(); //default constructor
  GenQueue(int maxSize); //overloaded constructor
  ~GenQueue();

  //core functions
  void enqueue(T* d); //insert
  T* dequeue(); //remove

  //aux functions
  T* peek();
  bool isFull();
  bool isEmpty();
  int getSize();

  // member variables
  int front; // head
  int rear; // tail
  int mSize;
  int numElements;

  DoublyLinkedList<T> *myQueue; //LinkedList to build queue
};

#endif

// Default contructor
template <typename T>
GenQueue<T>::GenQueue(){
  myQueue = new DoublyLinkedList<T>(); // initializing member variables to defualt values
  mSize = 5;
  front = 0;
  rear = -1;
  numElements = 0;
}

//overloaded constructor
template <typename T>
GenQueue<T>::GenQueue(int maxSize){
  myQueue = new DoublyLinkedList<T>();
  mSize = maxSize; // using max size to initialize mSize variable
  front = 0;
  rear = -1;
  numElements = 0;
}

// destructor
template <typename T>
GenQueue<T>::~GenQueue(){
  delete myQueue; // delete doubly linked list pointer
}

// Enqueue function inserts data into linked list
template <typename T>
void GenQueue<T>::enqueue(T* d){
  if(isFull()){ // cannot insert into full queue so return
    return;
  }else{
    myQueue->insertBack(d); // insert into back of linked list
    ++rear; // increment member variables
    ++numElements;
  }
}

// Dequeue function removes node at the front of the list
template <typename T>
T* GenQueue<T>::dequeue(){
  if(isEmpty()){ //error checking (if it is not empty)
    cout << "Trying to dequeue from an empty queue" << endl;
    exit(1); // exits program
  }else{
    T* c = myQueue->removeFront(); // stores front data into pointer
    ++front;
    --numElements;
    return c;
  }
}

// Peek returns pointer to front element of the linked list
template <typename T>
T* GenQueue<T>::peek(){
  return myQueue->getFront();
}

// isFull returns a boolean representing if the queue is full
template <typename T>
bool GenQueue<T>::isFull(){
  return (numElements == mSize);
}

// isEmpty returns a boolean representing if the queue is empty
template <typename T>
bool GenQueue<T>::isEmpty(){
  return (numElements == 0);
}

// getSize returns the number of elements in the list
template <typename T>
int GenQueue<T>::getSize(){
  return numElements;
}
