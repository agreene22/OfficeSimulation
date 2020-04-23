/* Anna Greene - 2314663
  Brandon Kleinman - 2291703
  Assignment 4 - Registrar Office Simulation
 */

#include "Registrar.h"

Registrar::Registrar(){//constructor
  m_numWindows = 0;
}

//this function sets the size of the array of windows
void Registrar::setNumWindows(int num){
  m_numWindows = num;
  windows = new Window[num];
}

//this function returns the size of the array of windows
int Registrar::getSize(){
  return m_numWindows;
}

Registrar::~Registrar(){//destructor
  delete[] windows;
}

//this function assigns students to windows and calculates their wait time
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

//this function iterates through the array of windows and check if students are done
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

//this function returns true if all windows are open and false if one window is filled
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

//this function iterates through the array of windows and increments their idle time
void Registrar::incrementWindows(){
  for(int i = 0; i < m_numWindows; ++i){
    if(windows[i].isOpen()){
      windows[i].incrementIdleTime();
      //cout << "Window: " << i << " was incremented" << endl;
    }
  }
}

//this function returns true if there are no filled windows
bool Registrar::isEmpty(){
  return (occupiedWindows == 0);
}

//this function returns true if all the windows are filled, false if one window is open
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

//this function returns a window at a specific position
Window Registrar::getWindow(int pos){
  for(int i = 0; i < m_numWindows; ++i){
    if(i == pos){
      return windows[i];
    }
  }
}
