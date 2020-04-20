/* Anna Greene - 2314663
  Brandon Kleinman - 2291703
  Assignment 4 - Registrar Office Simulation
 */

#include "Registrar.h"

Registrar::Registrar(){
  m_numWindows = 0;
}

void Registrar::setNumWindows(int num){
  m_numWindows = num;
  windows = new Window[num];
}

int Registrar::getSize(){
  return m_numWindows;
}

Registrar::~Registrar(){
  delete[] windows;
}

void Registrar::assignWindow(Student* s){
  for(int i = 0; i < m_numWindows; ++i){
    if(windows[i].isOpen()){
      windows[i].setStudent(s);
      s->calculateWaitTime();
      break;
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

void Registrar::checkTime(int currTick){
  for(int i = 0; i < m_numWindows; ++i){
    if(windows[i].isOpen()){
      continue;
    }else{
      if(windows[i].getStudent()->getEndTime() == currTick){
        //cout << "Opening a window" << endl;
        windows[i].open();//removing students from the window
      }
    }
  }
}

bool Registrar::checkOpen(){
  for(int i = 0; i < m_numWindows; ++i){
    if(windows[i].isOpen()){
      continue;
    }else{
      return false; // if any window is occupied it will return false
    }
  }
  return true;
}

void Registrar::incrementWindows(){
  for(int i = 0; i < m_numWindows; ++i){
    if(windows[i].isOpen()){
      windows[i].incrementIdleTime();
      //cout << "Window: " << i << " was incremented" << endl;
    }
  }
}

bool Registrar::isEmpty(){
  return (occupiedWindows == 0);
}

bool Registrar::isFull(){
  for(int i = 0; i < m_numWindows; ++i){
    if(windows[i].isOpen()){
      return false;
    }
  }
  return true;
}

// float Registrar::calculateWindowIdleTime(){
//   float totalWindowIdle = 0.0;
//   for(int i = 0; i < m_numWindows; ++i){
//     windows[i].getIdleTime();
//   }
// }

Window Registrar::getWindow(int pos){
  for(int i = 0; i < m_numWindows; ++i){
    if(i == pos){
      return windows[i];
    }
  }
  // return NULL; // cannot return NULL
}
