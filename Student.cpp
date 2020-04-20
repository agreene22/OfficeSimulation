#include "Student.h"

Student::Student(){
  m_timeNeeded = 0;
  m_arrivalTime = 0;
  m_timeIdle = 0;
  m_windowStartTime = 0;
}

Student::Student(int windowTime, int arrival){
  m_timeNeeded = windowTime;
  m_arrivalTime = arrival;
  m_timeIdle = 0;
  m_windowStartTime = 0;
}


int Student::getEndTime(){
  return(m_windowStartTime + m_timeNeeded);
}

bool Student::checkTime(int currTick){
  return (getEndTime() == currTick);
}

void Student::incrementIdleTime(int currTick){
  if(currTick >= m_arrivalTime){
    m_timeIdle++;
  }
}

int Student::getArrival(){
  return m_arrivalTime;
}

void Student::calculateWaitTime(){
  m_timeIdle = m_arrivalTime - m_windowStartTime;
}

int Student::getWaitTime(){
  return m_timeIdle;
}
