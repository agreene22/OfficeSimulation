#include <iostream>
#include <string>
#include "GenQueue.h"
#include "Student.h"
using namespace std;

class Registrar{
  public:
    Registrar();
    ~Registrar();

    void setNumWindows(int numWindows);

    void assignWindow(Student s);
    void checkTime(int index, int clockTick);
    bool isEmpty();
    bool isFull();

    Student* windows;

  private:
    int m_numWindows;
    int occupiedWindows;

};
