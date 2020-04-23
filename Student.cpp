/* Anna Greene - 2314663
  Brandon Kleinman - 2291703
  Assignment 4 - Registrar Office Simulation
 */

#include "Student.h"

Student::Student(){//default constructor
  m_timeNeeded = 0;
  m_arrivalTime = 0;
  m_timeIdle = 0;
  m_windowStartTime = 0;
}

Student::Student(int windowTime, int arrival){//overloaded constructor
  m_timeNeeded = windowTime;
  m_arrivalTime = arrival;
  m_timeIdle = 0;
  m_windowStartTime = 0;
}

//this function sets the time when the student started at the window
void Student::setWindowTime(int startTime){
  m_windowStartTime = startTime;
}

//this function returns the time when the student leaves the window
int Student::getEndTime(){
  return(m_windowStartTime + m_timeNeeded);
}

//this function returns true if the student is done at the window
bool Student::checkTime(int currTick){
  return (getEndTime() == currTick);
}

//increments idle time
void Student::incrementIdleTime(int currTick){
  if(currTick >= m_arrivalTime){
    m_timeIdle++;
  }
}

//returns the time at which the student arrived at the office
int Student::getArrival(){
  return m_arrivalTime;
}

//calculates the amount of time which the student was idle
void Student::calculateWaitTime(){
  m_timeIdle = m_windowStartTime - m_arrivalTime;
}

//returns the amount of time the student was idle
int Student::getWaitTime(){
  return m_timeIdle;
}
