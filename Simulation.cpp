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
  GenQueue<Student>* queue = new GenQueue<Student>();
  ifstream inFS;

  int windowsOpen = 0;
  int time = 0;
  int students = 0;
  int studentTime = 0;
  int windowsOccupied = 0;

  inFS.open(fileName);

  if(!inFS.is_open()){
    cout << "Error: Could not open file." << endl;
    return 1;
  }
  cout << "Processing file." << endl;

  while(!inFS.eof()){
    inFS >> windowsOpen; // this line is only read once while all the others need to be repeated
    while(!inFS.eof()){
      inFS >> time;
      inFS >> students;
      for(int i = 0; i < students; ++i){
        inFS >> studentTime;
        Student* s = new Student(studentTime, time); // maybe this shouldn't be a pointer?
        queue->enqueue(s);
      }
      while(windowsOccupied < 5 && !queue->isEmpty()){
        queue->dequeue();
        windowsOccupied++;
        windowsOpen--; //How do we keep track of clock ticks/how long they are at the window
      }
    }
    break;
  }

  delete queue;
  delete s;
}
