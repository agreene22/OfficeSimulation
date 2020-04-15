#include "Registrar.h"

// The simulation will start at time 0, and run until all student requests have been addressed,
// meaning the queue is empty and no more students are going to arrive. (This should tell
// you the main body of the program is going to be a huge loop.)
// At the end of the simulation, your program will display (on standard out) the following
// (labeled) metrics:
// 1. The mean student wait time.
// 2. The median student wait time.
// 3. The longest student wait time.
// 4. The number of students waiting over 10 minutes
// 5. The mean window idle time
// 6. The longest window idle time
// 7. Number of windows idle for over 5 minutes.

class Simulation{
public:
  Simulation();

  void Run(string fileName);
  void Calculate();

private:
  float m_meanStudentWait; 
  float m_medianStudentWait;
  float m_longestStudentWait;
  float m_studentsOverTen;
  float m_meanWindowIdle;
  float m_longestWindowIdle;
  float m_windowsIdleOver5;
};
