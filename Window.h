/* Anna Greene - 2314663
  Brandon Kleinman - 2291703
  Assignment 4 - Registrar Office Simulation
  Window class to define methods and member variables
 */

#include <iostream>
#include "Student.h"

using namespace std;

class Window{
public:
  Window();
  Window(Student* s, int idleTime);
  ~Window();

  bool isOpen();
  void setStudent(Student* s);
  void open();
  void incrementIdleTime();
  Student* getStudent();
  float getIdleTime();

private:
  Student* m_currStudent;
  float m_idleTime;
};
