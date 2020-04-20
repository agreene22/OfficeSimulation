#include <iostream>
#include "Simulation.h"

using namespace std;

int main(int argc, char **argv){
  string fileName = "";

  //GenQueue<int> *queue = new GenQueue<int>();
  //queue->insert(4);
  //cout << queue->peak() << endl;

  // Student* s = new Student(3, 4);
  // Window* winds = new Window[3];
  // winds[2].setStudent(s);
  // for(int i = 0; i < 3; ++i){
  //   if(winds[i].isOpen()){
  //     cout << "Window: " << i << " is open" << endl;
  //   }
  // }
  // winds[2].open();
  // for(int i = 0; i < 3; ++i){
  //   if(winds[i].isOpen()){
  //     cout << "Window: " << i << " is open" << endl;
  //   }
  // }

  Simulation* sim;
  if(argc > 1){
    fileName = argv[1];

    sim = new Simulation();
    sim->Run(fileName);
    sim->Calculate();


  }else{
   cout << "INVALID USAGE: please enter name of a text file" << endl;
   cout << "USAGE: ./a.out [file name]" << endl;
  }



  // Student* p1 = new Student();
  // Student* p2 = new Student();
  // Student* p3 = new Student();
  // Student* p4 = new Student();
  //
  // DoublyLinkedList<Student>* dll = new DoublyLinkedList<Student>();
  //
  // dll->insertBack(p1);
  // dll->insertBack(p2);
  // dll->insertBack(p3);
  // dll->insertBack(p4);
  //
  // cout << dll->getSize() << endl;
  //
  // for(int i = 0; i < 4; ++i){
  //   Student* p = dll->accessAtPos(i);
  //   cout << p->getWaitTime() << endl;
  //   delete p;
  // }

  //delete sim;
  return 0;
}
