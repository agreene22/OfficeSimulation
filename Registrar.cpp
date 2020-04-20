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

int Registrar::getSize(){
  return m_numWindows;
}

Registrar::~Registrar(){
  //for(int i = 0; i < m_numWindows; ++i){
    //delete windows[i];
  //}
  delete[] windows;
}

void Registrar::assignWindow(Student* s){
  for(int i = 0; i < m_numWindows; ++i){//what was before wont work because the first few windows arent necessarily the ones that are open
    if(windows[i].isOpen()){//changed -> to .  lets see if it works
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
        cout << "Opening a window" << endl;
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
