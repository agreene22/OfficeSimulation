#include "Simulation.h"
#include <fstream>

Simulation::Simulation(){
  m_meanWait = 0.0;
  m_medianWait = 0.0; // store waits in an array and find median?
  m_longestWait = 0.0;
  m_overTen = 0.0;
  m_meanIdle = 0.0;
  m_longestIdle = 0.0;
  m_windowsIdle = 0.0;
}

void Simulation::Run(string fileName){
  GenQueue<Student>* queue = new GenQueue<Student>(10);

  Registrar* office = new Registrar();
  ifstream inFS;

  int clockTick = 0;
  int nextClockTickLine = 1;
  int lineCount = 0;

  int windowsOpen = 0;
  int time = 0;
  int numStudents = 0;
  int studentTime = 0;
  int windowsOccupied = 0;

  int totalTime = 0;

  inFS.open(fileName);

  if(!inFS.is_open()){
    cout << "Error: Could not open file." << endl;
    return 1;
  }
  cout << "Processing file." << endl;

  while(!inFS.eof()){
    if(lineCount = 0){
      inFS >> windowsOpen;
      office->setNumWindows(windowsOpen);
      ++lineCount;
    }else if(lineCount == nextClockTickLine){
      inFS >> clockTick;
      for(int i = 0; i < windowsOpen; ++i){
        office->checkTime(clockTick);
      }
      //here we need to check if all the students time at the window was satisfied
      //if the time wasnt satisfied we decrement the time m_timeNeeded
      //if it was satisfied we take them out of the window
      ++lineCount;
    }else if (lineCount == (nextClockTickLine + 1)){
      inFS >> numStudents;
      nextClockTickLine += numStudents + 2; // why is this + 2? im probably just dumb but im confused
      ++lineCount;
    }else{
      inFS >> studentTime;
      totalTime += studentTime;
      Student* s = new Student(studentTime, clockTick);
      queue->enqueue(s);
      if(!office->isFull()){//office isnt full so we send the first student in line to a window
        Student* first = queue->dequeue(); // what if we move this part to a separate loop so first we queue all the students then start removing them
        for(int i = 0; i < windowsOpen; ++i){
          office->assignWindow(i);
        }
      }
      ++lineCount;
      //++clockTick; i dont think we increment these but i could be wrong
      //++nextClockTickLine;
    }
  }


  delete queue;
  delete office;
  delete s;
}

void Simulation::Calculate(){
  // Define this later
}
