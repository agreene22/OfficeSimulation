#include "Student.h"

Student::Student(int windowTime, int arrival){
  m_timeNeeded = windowTime;
  m_arrivalTime = arrival;
  m_timeIdle = 0;
}

Student::~Student(){
  //delete something
}