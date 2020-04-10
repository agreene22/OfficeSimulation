#include <iostream>
using namespace std;

template <class T>
class ListNode{
public:
  T data;
  ListNode<T> *next;
  ListNode<T> *prev;

  ListNode(); //constructor
  ListNode(T d); //overloaded constructor
  ~ListNode();
};

template <class T>
ListNode<T>::ListNode(){
  data = 0;
  next = NULL;
  prev = NULL;
}

template <class T>
ListNode<T>::ListNode(T d){
  data = d;
  next = NULL;
  prev = NULL;
}

template <class T>
ListNode<T>::~ListNode(){
  next = NULL;
  prev = NULL;
  delete next;
  delete prev;
}
