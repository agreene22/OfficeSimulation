#include <iostream>
#include "Student.h"

using namespace std;

class Window{ //this is getting complicated but i think this class is necessary so we can link the window occupied with the student who occupies it
public:
  Window();
  Window(Student* s, int idleTime);
  ~Window();

  bool isOpen();
  void setStudent(Student* s);
  void open();

private:
  Student* m_currStudent;
  int m_idleTime;
};
