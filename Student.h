#include <iostream>

using namespace std;

class Student{
  public:
    Student(int time, int arrivalTime);
    ~Student();

  private:
    int timeNeeded;
    int arrrivalTime;
    int timeIdle;

}
