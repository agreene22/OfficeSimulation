#include <iostream>
#include "DoublyLinkedList.h"
using namespace std;

template <typename T>
class GenQueue{
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

  //vars
  int front; //aka head
  int rear; //aka tail
  int mSize;
  int numElements;

  DoublyLinkedList<T> *myQueue; //LinkedList
};

template <typename T>
GenQueue<T>::GenQueue(){
  //default constructor
  myQueue = new DoublyLinkedList<T>();
  mSize = 5;
  front = 0;
  rear = -1;
  numElements = 0;
}
//overloaded constructor
template <typename T>
GenQueue<T>::GenQueue(int maxSize){
  myQueue = new DoublyLinkedList<T>();
  mSize = maxSize;
  front = 0;
  rear = -1;
  numElements = 0;
}

template <typename T>
GenQueue<T>::~GenQueue(){
  delete myQueue;
}

template <typename T>
void GenQueue<T>::enqueue(T* d){
  if(isFull()){
    return;
  }else{
    myQueue->insertBack(d);
    // rear = (rear+1)&mSize;
    ++rear;
    ++numElements;
  }
}

template <typename T>
T* GenQueue<T>::dequeue(){
  //error checking (if it is not empty)
  if(isEmpty()){
    cout << "Trying to dequeue from an empty queue" << endl;
    exit(1);
  }else{
    T* c = myQueue->removeFront();
    //This^ does not work because front is private in the LinkedList are we allowed to make it public or should we write a method getFront
    ++front; //does this do anything?
    // front = (front+1)%mSize //for circular queue
    --numElements;
    return c;
  }
}

template <typename T>
T* GenQueue<T>::peek(){
  return myQueue->getFront();
  //This^ does not work because front is private in the LinkedList are we allowed to make it public or should we write a method getFront
}

template <typename T>
bool GenQueue<T>::isFull(){
  return (numElements == mSize);
  // return ((rear+1)%mSize == front);
}

template <typename T>
bool GenQueue<T>::isEmpty(){
  return (numElements == 0);
}

template <typename T>
int GenQueue<T>::getSize(){
  return numElements;
}
