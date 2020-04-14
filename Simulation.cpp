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

  Registar* office = new Registar();
  ifstream inFS;

  int clockTick = 0;
  int nextClockTickLine = 1;
  int lineCount = 0;

  int windowsOpen = 0;
  int time = 0;
  int numStudents = 0;
  int studentTime = 0;
  int windowsOccupied = 0;

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
        if(windows[i]->getEndTime() == clockTick){
          windows[i] = NULL;//removing students from the window
        }
      }
      //here we need to check if all the students time at the window was satisfied
      //if the time wasnt satisfied we decrement the time m_timeNeeded
      //if it was satisfied we take them out of the window
      ++lineCount;
    }else if (lineCount == (nextClockTickLine + 1)){
      inFS >> numStudents;
      nextClockTickLine += numStudents + 2;
      ++lineCount;
    }else{
      inFS >> studentTime;
      Student* s = new Student(studentTime, clockTick);
      queue->enqueue(s);
      if(!office->isFull()){//office isnt full so we send the first student in line to a window
        Student* first = queue->dequeue();
        for(int i = 0; i < windowsOpen; ++i){
          if(windows[i] == NULL){
            windows[i] = first;//putting a student in a window
          }
        }
      }
      ++lineCount;
    }
  }

  // while(!inFS.eof()){
  //   inFS >> windowsOpen; // this line is only read once while all the others need to be repeated
  //   while(!inFS.eof()){
  //     inFS >> time;
  //     inFS >> students;
  //     for(int i = 0; i < students; ++i){
  //       inFS >> studentTime;
  //       Student* s = new Student(studentTime, time); // maybe this shouldn't be a pointer?
  //       queue->enqueue(s);
  //     }
  //     while(windowsOccupied < 5 && !queue->isEmpty()){
  //       queue->dequeue();
  //       windowsOccupied++;
  //       windowsOpen--; //How do we keep track of clock ticks/how long they are at the window
  //     }
  //   }
  //   break;
  // }

  delete queue;
  delete s;
}
