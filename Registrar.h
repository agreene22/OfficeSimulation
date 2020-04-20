#include <string>
#include "GenQueue.h"
#include "Window.h"
using namespace std;

class Registrar{
  public:
    Registrar();
    ~Registrar();

    void setNumWindows(int numWindows);
    int getSize();

    void assignWindow(Student* s);
    void checkTime(int currTick);
    bool checkOpen();
    bool isEmpty();
    bool isFull();
    Window getWindow(int);
    void incrementWindows();

    Window* windows;

  private:
    int m_numWindows;
    int occupiedWindows;

};
