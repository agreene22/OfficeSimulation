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

private:
  Student* m_currStudent;
  int m_idleTime;
};
