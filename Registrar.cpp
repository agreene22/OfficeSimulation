#include "Registrar.h"

Registrar::Registrar(){
  m_numWindows = 0;
}

void Registrar::setNumWindows(int num){
  m_numWindows = num;
  windows = new int[num];
}

Registrar::~Registrar(){
  delete windows;
}

void Registrar::assignWindow(int index){
  if(windows[index] == 0){ // 0 is empty, 1 is occupied
    windows[index] = 1;
  }
}

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
