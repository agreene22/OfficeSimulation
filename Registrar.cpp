#include "Registrar.h"

Registrar::Registrar(){
  m_numWindows = 0;
}

void Registrar::setNumWindows(int num){
  m_numWindows = num;
  windows = new Student[num];//not sure if i declared the array correctly
}

Registrar::~Registrar(){
  delete windows;
}

void Registrar::setNumWindows(int numWindows){
  m_numWindows = numWindows;
}

void Registrar::assignWindow(Student* s){
  windows[occupiedWindows++] = s;
}

void Registrar::checkTime(int index, int clocktick){
  if(windows[index]->getEndTime() == clockTick){
    windows[index] = NULL;//removing students from the window
  }
}

bool Registrar::isEmpty(){
  return (occupiedWindows == 0);
}

bool Registrar::isFull(){
  return (occupiedWindows == m_numWindows);
}
