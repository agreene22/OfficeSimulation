#include <iostream>
using namespace std;

template <class T>
class GenQueue{ // Should we make the queue circular
public:
  GenQueue(); //default constructor
  GenQueue(int maxSize); //overloaded constructor
  ~GenQueue();

  //core functions
  void insert(T d); //enqueue
  T remove(); //dequeue

  //aux functions
  T peak();
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

template <class T>
GenQueue<T>::GenQueue(){
  //default constructor
  myQueue = new DoublyLinkedList<T>();
  mSize = 5;
  front = 0;
  rear = -1;
  numElements = 0;
}
//overloaded constructor
template <class T>
GenQueue<T>::GenQueue(int maxSize){
  myQueue = new DoublyLinkedList<T>();
  mSize = maxSize;
  front = 0;
  rear = -1;
  numElements = 0;
}

template <class T>
GenQueue<T>::~GenQueue(){
  delete myQueue;
}

template <class T>
void GenQueue<T>::insert(T d){
  if(isFull()){
    return;
  }else{
    myQueue->insertBack(d); // rear = (rear+1)&mSize
    ++numElements;
  }
}

template <class T>
T GenQueue<T>::remove(){
  //error checking (if it is not empty)
  if(isEmpty()){
    return NULL;
  }else{
    T c = NULL;
    c = myQueue->front;
    //This^ does not work because front is private in the LinkedList are we allowed to make it public or should we write a method getFront
    ++front; // front = (front+1)%mSize for circular queue
    --numElements;
    return c;
  }
}

template <class T>
T GenQueue<T>::peak(){
  return myQueue->front;
  //This^ does not work because front is private in the LinkedList are we allowed to make it public or should we write a method getFront
}

template <class T>
bool GenQueue<T>::isFull(){
  return (numElements == mSize);
}

template <class T>
bool GenQueue<T>::isEmpty(){
  return (numElements == 0);
}

template <class T>
int GenQueue<T>::getSize(){
  return numElements;
}
