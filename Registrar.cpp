#include "Registrar.h"

Registrar::Registrar(){
  m_numWindows = 0;
}

void Registrar::setNumWindows(int num){
  m_numWindows = num;
  windows = new Window[num];
  for(int i = 0; i < num; ++i){
    windows[i] = new Window();
  }
}

Registrar::~Registrar(){
  delete windows;
}

void Registrar::assignWindow(Student* s){
  int openWindows = m_numWindows-occupiedWindows;
  for(int i = 0; i < openWindows; ++i){
    if(windows[index]->isOpen()){
      windows[index]->setStudent(s);
    }
  }
  occupiedWindows++;
}

// void Registrar::checkWindows(Student* s){
//   for(int i = 0; i < m_numWindows; ++i){
//     if(windows[i]->studentOccupy == s){
//       return (windows[i]->isOpen());
//     }
//   }
// }

// void Registrar::checkTime(int index, int currTick){
//   if(windows[index].getEndTime() == currTick){
//     delete windows[index];
//     windows[index] = NULL;//removing students from the window
//   }
// }

bool Registrar::isEmpty(){
  return (occupiedWindows == 0);
}

bool Registrar::isFull(){
  return (occupiedWindows == m_numWindows);
}
