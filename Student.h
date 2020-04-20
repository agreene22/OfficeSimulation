/* Anna Greene - 2314663
  Brandon Kleinman - 2291703
  Assignment 4 - Registrar Office Simulation
 */

#include <iostream>

using namespace std;

class Student{
public:
  Student();
  Student(int time, int arrivalTime);

  int getEndTime();
  bool checkTime(int currTick);
  void incrementIdleTime(int currTick);
  int getArrival();
  void calculateWaitTime();
  int getWaitTime();
  void setWindowTime(int startTime);

private:
  int m_timeNeeded;
  int m_arrivalTime;
  int m_windowStartTime;
  int m_timeIdle;
};
