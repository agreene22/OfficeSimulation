#include <iostream>
using namespace std;

template <typename T>
class ListNode{
public:
  T* data;
  ListNode<T> *next;
  ListNode<T> *prev;

  ListNode(); //constructor
  ListNode(T* d); //overloaded constructor
  ~ListNode();
};

template <typename T>
ListNode<T>::ListNode(){
  data = NULL;
  next = NULL;
  prev = NULL;
}

template <typename T>
ListNode<T>::ListNode(T* d){
  data = d;
  next = NULL;
  prev = NULL;
}

template <typename T>
ListNode<T>::~ListNode(){
  next = NULL;
  prev = NULL;
  delete next;
  delete prev;
}
