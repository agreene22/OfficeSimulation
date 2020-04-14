#include <iostream>
#include <string>
#include "GenQueue.h"
#include "Student.cpp"
using namespace std;

class Registrar{
  public:
    Registrar();
    ~Registrar();

    void assignWindow(Student* s);
    bool isEmpty();
    bool isFull();
    void setNumWindows();

  private:
    m_numWindows;
    Student* windows;



}
