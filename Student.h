#include <iostream>

using namespace std;

class Student{
  public:
    Student(int time, int arrivalTime);
    ~Student();

  private:
    int m_timeNeeded;
    int m_arrrivalTime;
    int m_timeIdle;

}
