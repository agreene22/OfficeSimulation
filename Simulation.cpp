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

  float clockTick = 0.0;
  float nextClockTickLine = 1.0;
  float lineCount = 0.0;

  float windowsOpen = 0.0;
  float time = 0.0;
  float numStudents = 0.0;
  float studentTime = 0.0;
  float windowsOccupied = 0.0;

  float totalTime = 0.0;

  inFS.open(fileName);

  if(!inFS.is_open()){
    cout << "Error: Could not open file." << endl;
    exit(1);
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
        //office->checkTime(clockTick);
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
      queue->enqueue(s);//derefence it?
      if(!office->isFull()){//office isnt full so we send the first student in line to a window
        for(int i = 0; i < windowsOpen; ++i){
          Student* first = queue->dequeue(); // what if we move this part to a separate loop so first we queue all the students then start removing them
          office->assignWindow(first);
          delete first;
        }
      }
      delete s;
      ++lineCount;
    }
  }

  // totalTime /= numWindows; this isn't right but we can do something to totalTime
  while(totalTime > 0){ // something like this or a for loop with increasing clock tick
    if(!office->isFull()){
      for(int i = 0; i < windowsOpen; ++i){
        Student* first = queue->dequeue();
        office->assignWindow(first);
      }
    }
    for(int i = 0; i < windowsOpen; ++i){
      //office->
    }
    totalTime--;
  }

  delete queue;
  delete office;
}

void Simulation::Calculate(){
  // Define this later
}
