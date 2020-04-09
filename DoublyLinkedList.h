#include <iostream>
#include "ListNode.h"
using namespace std;

template <class T>
class DoublyLinkedList{
public:
  DoublyLinkedList();
  ~DoublyLinkedList();

  void insertFront(T data);
  void insertBack(T data);
  T removeFront();
  // T removeBack(); // Need to write this method still
  T remove(T value);
  int search(T val); //will return position of node depending where it is in the list
  T removeAtPos(int pos);

  unsigned int getSize();
  bool isEmpty();
  void printList();

private:
  ListNode<T> *front;
  ListNode<T> *back;
  unsigned int size;
};

template <class T>
DoublyLinkedList<T>::DoublyLinkedList(){
  size = 0;
  front = NULL;
  back = NULL;
}

template <class T>
DoublyLinkedList<T>::~DoublyLinkedList(){
  front = NULL;
  back = NULL;
  delete front;
  delete back;
}

template <class T>
unsigned int DoublyLinkedList<T>::getSize(){
  return size;
}

template <class T>
bool DoublyLinkedList<T>::isEmpty(){
  return (size==0);
}

template <class T>
void DoublyLinkedList<T>::printList(){
  ListNode<T> *curr = front;
  while(curr != NULL){
    cout << curr->data << endl;
    curr = curr->next;
  }
}

template <class T>
void DoublyLinkedList<T>::insertFront(T d){
  ListNode<T> *node = new ListNode<T>(d);

  if(isEmpty()){
    back = node;
  }
  else{
    //not isEmpty
    front->prev = node;
    node->next = front;
  }
  front = node;
  size++;
}

template <class T>
void DoublyLinkedList<T>::insertBack(T d){
  ListNode<T> *node = new ListNode<T>(d);

  if(isEmpty()){
    front = node;
  }
  else{
    //not isEmpty
    back->next = node;
    node->prev = back;
  }
  back = node;
  size++;
}

template <class T>
T DoublyLinkedList<T>::removeFront(){
  ListNode<T> *tempNode = front;

  //error check, make sure list is not empty before attempting to remove
  if(front->next = NULL){
    //there is only one node in the list
    back = NULL;
  }
  else{
    //more than one node in the list
    front->next->prev = NULL;
  }

  front = front->next;
  tempNode->next = NULL;
  T temp = tempNode->data;
  size--;
  delete tempNode;

  return temp;
}

//need to find the value in the list before we can delete
//this function does not take position as a parameter
template <class T>
T DoublyLinkedList<T>::remove(T value){
  ListNode<T> *curr = front;

  //let's look for this value
  while(curr->data != value){
    curr = curr->next;

    if(curr == NULL){
      return -1;
    }
  }

  //if we get here, we found our node/value, now let's proceed to delete
  if(curr == front){
    // if node to be deleted is the front
    front = curr->next;
  }
  else{
    //node to be deleted is somewhere in between front and back
    curr->prev->next = curr->next;
  }

  if(curr == back){
    back = curr->prev;
  }
  else{
    //node to be deleted is somewhere in between front and back
    curr->next->prev = curr->prev;
  }

  curr->next = NULL;
  curr->prev = NULL;
  T temp = curr->data;
  size--;
  delete curr;

  return temp;
}

template <class T>
int DoublyLinkedList<T>::search(T val){
  int pos = -1;
  ListNode<T> *curr = front;
  // let's loop and attempt to find the value
  while(curr != NULL){
    ++pos;
    if(curr->data == val){
      //we found it
      break;
    }
    else{
      //we didn't find it, continue iterating
      curr = curr->next;
    }

    if(curr == NULL){
      //we didn't find it
      pos = -1;
    }
    return pos;
  }
}

template <class T>
T DoublyLinkedList<T>::removeAtPos(int pos){
  //error to make sure pos does not exceed size of ListNode
  int idx = 0;
  ListNode<T> *curr = front;
  ListNode<T> *prev = front;

  while(idx != pos){
    // loop until find the position
    prev = curr;
    curr = curr->next;
    idx++;
  }

  //now let's continue with the deletion process
  prev->next = curr->next;
  curr->next = NULL;
  T temp = curr->data;
  delete curr;
  size--;

  return temp;
}
