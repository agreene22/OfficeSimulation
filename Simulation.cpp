#include "Simulation.h"
#include <fstream>

Simulation::Simulation(){
  m_meanStudentWait = 0.0;
  m_medianStudentWait = 0.0; // store waits in an array and find median?
  m_longestStudentWait = 0.0;
  m_studentsOverTen = 0.0;
  m_meanWindowIdle = 0.0;
  m_longestWindowIdle = 0.0;
  m_windowsIdleOver5 = 0.0;
  queue = new GenQueue<Student>(10); // we need to be able to make this the correct size
  students = new DoublyLinkedList<Student>();
  office = new Registrar();
}

Simulation::~Simulation(){
  delete queue;
  delete students;
}

void Simulation::Run(string fileName){
  // GenQueue<Student>* queue = new GenQueue<Student>(10);

  // Registrar* office = new Registrar();
  // Student* first;
  ifstream inFS;

  int clockTick = 0;
  int nextClockTickLine = 1;
  int lineCount = 0;

  float windowsOpen = 0.0;
  float time = 0.0;
  float numStudents = 0.0;
  float studentTime = 0.0;
  // float windowsOccupied = 0.0;

  inFS.open(fileName);

  if(!inFS.is_open()){
    cout << "Error: Could not open file." << endl;
    exit(1);
  }
  cout << "Processing file." << endl;

  while(!inFS.eof()){
    if(!inFS.fail()){
      cout << lineCount << endl; // delete later
      if(lineCount == 0){
        inFS >> windowsOpen;
        office->setNumWindows(windowsOpen); // giving seg fault
        ++lineCount;
      }else if(lineCount == nextClockTickLine){
        inFS >> clockTick;
        // for(int i = 0; i < windowsOpen; ++i){
        //   cout << "here" << endl;
        //   office->checkTime(windowsOpen, clockTick);//checking if each student is done
        //   cout << "i think this is the problem" << endl;
        // }
        ++lineCount;
        //here we need to check if all the students time at the window was satisfied
        //if the time wasnt satisfied we decrement the time m_timeNeeded
        //if it was satisfied we take them out of the window
      }else if (lineCount == (nextClockTickLine + 1)){
        inFS >> numStudents;
        nextClockTickLine += numStudents + 2;
        ++lineCount;
      }else{
        inFS >> studentTime;
        Student* s = new Student(studentTime, clockTick);
        queue->enqueue(s); // when I run it with the test file it enqueue's 9 times.... (number of lines in file)
        cout << "enqueue" << endl;
        // if(!office->isFull()){//office isnt full so we send the first student in line to a window
        //   for(int i = 0; i < windowsOpen; ++i){
        //     first = queue->dequeue(); // what if we move this part to a separate loop so first we queue all the students then start removing them
        //     office->assignWindow(first);
        //     // delete first;
        //   }
        // }
        ++lineCount;
        delete s;
      }
    }
  }

  // could be a while(!queue->isEmpty() && office->checkOpen()) and run all code in there
  // checkOpen could return a boolean if all windoows are open (currently have this method only incrementing idleTime)
  time = 0;
  Student* first; // declaring up here so we don't redeclare every time
  while(!queue->isEmpty() || !office->checkOpen()){//it should run if there is someone in the queue or someone at a window now
    if(!office->isFull() && !queue->isEmpty()){
      first = queue->peek();
      cout << "peek" << endl;
      if(first->getArrival() < time){
        cout << "get arrival" << endl;
        continue;
      }else{
        cout << "to dequeue" << endl;
        first = queue->dequeue();
        cout << "dequeue" << endl;
        office->assignWindow(first);
        students->insertBack(first); //Linked List of students after being helped
      }
    }
    if(!office->isFull() && queue->isEmpty()){
      cout << "at window but queue empty" << endl;
      office->checkOpen(); // increments idle time for open windows without a student
      office->checkTime(time);
    }
    // else{ // this else might not be necessary anymore because I created a getWaitTime method
    //   for(int i = 0; i < queue->getSize(); ++i){
    //     // student->incrementIdleTime(time);
    //     // ^^for each student in the queue call incrementIdleTime
    //     // need to be able to access each element of the queue
    //   }
    // }
    time++;
  }

  delete first;
  delete queue;
  delete office;
  delete students;
}

void Simulation::Calculate(){
  float totalStudentWait = 0.0;
  float waitTime = 0.0;
  int size = 0;

  size = students->getSize();

  for(int i = 0; i < size; ++i){
    Student* s = students->accessAtPos(i);
    waitTime = s->getWaitTime();
    totalStudentWait += waitTime;
    if(waitTime > m_longestStudentWait){
      m_longestStudentWait = waitTime;
    }
    if(i == (size/2)){
      m_medianStudentWait = waitTime;
    }
    if(waitTime > 10){
      m_studentsOverTen++;
    }

    delete s;
  }
  m_meanStudentWait = (totalStudentWait/size);

  float totalWindowIdle = 0.0;
  float idle = 0.0;
  for(int i = 0; i < office->getSize(); ++i){
    idle = office->getWindow(i).getIdleTime();
    totalWindowIdle += idle;
    if(idle > m_longestWindowIdle){
      m_longestWindowIdle = idle;
    }
    if(idle > 5){
      m_windowsIdleOver5++;
    }
  }
  m_meanWindowIdle = (totalWindowIdle/(office->getSize()));;

  cout << "Mean Student Wait: " << m_meanStudentWait << endl;
  cout << "Median Student Wait: " << m_medianStudentWait << endl;
  cout << "Longest Student Wait: " << m_longestStudentWait << endl;
  cout << "Students who waited over ten minutes: " << m_studentsOverTen << endl;
  cout << "Mean Window Idle Time: " << m_meanWindowIdle << endl;
  cout << "Longest Window Idle Time: " << m_longestWindowIdle << endl;
  cout << "Windows idle over five minutes: " << m_windowsIdleOver5 << endl;
}
