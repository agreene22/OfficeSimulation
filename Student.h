#include <iostream>

using namespace std;

class Student{
  public:
    Student(int time, int arrivalTime);
    ~Student();

    int getEndTime();



  private:
    int m_timeNeeded;
    int m_arrrivalTime;
    int m_windowStartTime;
    int m_timeIdle;

}
