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

    void assignWindow(int index, Student* s);
    // void checkTime(int index, int currTick);
    bool isEmpty();
    bool isFull();

    int* windows;

  private:
    int m_numWindows;
    int occupiedWindows;

};
