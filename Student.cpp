#include "Student.h"

Student::Student(){
  m_timeNeeded = 0;
  m_arrivalTime = 0;
  m_timeIdle = 0;
}

Student::Student(int windowTime, int arrival){
  m_timeNeeded = windowTime;
  m_arrivalTime = arrival;
  m_timeIdle = 0;
}

Student::~Student(){
  //delete something
}

int Student::getEndTime(){
  return(m_windowStartTime + m_timeNeeded);
}
