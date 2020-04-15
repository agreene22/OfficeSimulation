#include "Registrar.h"

Registrar::Registrar(){
  m_numWindows = 0;
}

void Registrar::setNumWindows(int num){
  m_numWindows = num;
  windows = new Window[num];
  for(int i = 0; i < num; ++i){//do we even have to do this? its already an array of windows
    //windows[i] = new Window();
  }
}

Registrar::~Registrar(){
  //for(int i = 0; i < m_numWindows; ++i){
    //delete windows[i];
  //}
  delete windows;
}

void Registrar::assignWindow(Student* s){
  for(int i = 0; i < m_numWindows; ++i){//what was before wont work because the first few windows arent necessarily the ones that are open
    if(windows[i].isOpen()){//changed -> to .  lets see if it works
      windows[i].setStudent(s);
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

void Registrar::checkTime(int index, int currTick){
  if(windows[index].getStudent()->getEndTime() == currTick){
    windows[index].setStudent(NULL);//removing students from the window
  }
}

bool Registrar::checkOpen(){
  for(int i = 0; i < m_numWindows; ++i){
    if(windows[i].isOpen()){
      windows[i].incrementIdleTime();
    }else{
      return false; // if any window is occupied it will return false
    }
  }
  return true;
}

bool Registrar::isEmpty(){
  return (occupiedWindows == 0);
}

bool Registrar::isFull(){
  return (occupiedWindows == m_numWindows);
}
