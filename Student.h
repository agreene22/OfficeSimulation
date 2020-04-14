#include <iostream>

using namespace std;

class Student{
public:
  Student();
  Student(int time, int arrivalTime);
  ~Student();

  int getEndTime();
  bool checkTime();

private:
  int m_timeNeeded;
  int m_arrivalTime;
  int m_windowStartTime;
  int m_timeIdle;
};
