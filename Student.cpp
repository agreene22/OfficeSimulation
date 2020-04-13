#include "Student.h"

Student::Student(int windowTime, int arrival){
  m_timeNeeded = windowTime;
  m_arrivalTime = arrival;
}

Student::~Student(){
  //delete something
}
