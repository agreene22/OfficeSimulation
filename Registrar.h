/* Anna Greene - 2314663
  Brandon Kleinman - 2291703
  Assignment 4 - Registrar Office Simulation
 */

#include <string>
#include "GenQueue.h"
#include "Window.h"
using namespace std;

class Registrar{
  public:
    Registrar();//constructor
    ~Registrar();//destructor

    //getters and setters
    void setNumWindows(int numWindows);
    int getSize();

    //helper functions
    void assignWindow(Student* s);
    void checkTime(int currTick);
    bool checkOpen();
    bool isEmpty();
    bool isFull();
    Window getWindow(int);
    void incrementWindows();

    Window* windows;

  private://member variables
    int m_numWindows;
    int occupiedWindows;

};
