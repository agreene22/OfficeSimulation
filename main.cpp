#include <iostream>
#include "DoublyLinkedList.h"

using namespace std;

int main(int argc, char **argv){

  DoublyLinkedList<int>* dl = new DoublyLinkedList<int>();

  delete dl;

  return 1;
}
