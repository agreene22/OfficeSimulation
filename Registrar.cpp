#include "Registrar.h"

Registrar::Registrar(){
  m_numWindows = 0;
}

void Registrar::setNumWindows(int num){
  m_numWindows = num;
  windows = new Student[num];
}

Registrar::~Registrar(){
  delete windows;
}

void Registrar::assignWindow(int index, Student s){
  if(windows[index] == NULL){
    windows[index] = s;
  }
}

void Registrar::checkTime(int index, int currTick){
  if(windows[index].getEndTime() == currTick){
    delete windows[index];
    windows[index] = NULL;//removing students from the window
  }
}

bool Registrar::isEmpty(){
  return (occupiedWindows == 0);
}

bool Registrar::isFull(){
  return (occupiedWindows == m_numWindows);
}
