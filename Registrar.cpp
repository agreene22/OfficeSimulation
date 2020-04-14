#include "Registrar.h"

Registar::Registrar(){
  m_numWindows = 0;
  
}

void Registrar::setNumWindows(int num){
  m_numWindows = num;
  Student* windows = new Student[num];//not sure if i declared the array correctly
}
