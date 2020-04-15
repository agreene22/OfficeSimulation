#include <string>
#include "GenQueue.h"
#include "Window.h"//no need to include student because it is included in the window.h file
using namespace std;

class Registrar{
  public:
    Registrar();
    ~Registrar();

    void setNumWindows(int numWindows);

    void assignWindow(Student* s);//was a pointer im changing it to just student for now
    void checkTime(int index, int currTick);
    bool isEmpty();
    bool isFull();

    Window* windows;

  private:
    int m_numWindows;
    int occupiedWindows;

};
