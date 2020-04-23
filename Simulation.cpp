/* Anna Greene - 2314663
  Brandon Kleinman - 2291703
  Assignment 4 - Registrar Office Simulation
  Simulation class which defines methods and implements the queue and registrar class to simulate the office
 */

#include "Simulation.h"
#include <fstream>
#include <algorithm>

using namespace std;

Simulation::Simulation(){ //default constructor
  m_meanStudentWait = 0.0;
  m_medianStudentWait = 0.0;
  m_longestStudentWait = 0.0;
  m_studentsOverTen = 0.0;
  m_meanWindowIdle = 0.0;
  m_longestWindowIdle = 0.0;
  m_windowsIdleOver5 = 0.0;
  queue = new GenQueue<Student>();
  helpedStudents = new DoublyLinkedList<Student>();
  office = new Registrar();
}

Simulation::~Simulation(){//destructor
  delete queue;
  delete helpedStudents;
  delete office;
}

void Simulation::Run(string fileName){
  //initializing variables
  ifstream inFS;

  int clockTick = 0;
  int nextClockTickLine = 1;
  int lineCount = 0;

  int windowsOpen = 0;
  int time = 0;
  int numStudents = 0;
  float studentTime = 0.0;

  Student* s;

  inFS.open(fileName);//opening file stream

  if(!inFS.is_open()){
    cout << "Error: Could not open file." << endl;
    exit(1);
  }
  cout << "Processing file." << endl;


  while(!inFS.eof()){
    if(lineCount == 0){//first line represents number of windows
      inFS >> windowsOpen;
      if(!inFS.fail()){
        office->setNumWindows(windowsOpen);
        ++lineCount;
      }
    }else if(lineCount == nextClockTickLine){ //we are expecting this line to represent the clock tick
      inFS >> clockTick;
      if(!inFS.fail()){
          ++lineCount;
      }
    }else if (lineCount == (nextClockTickLine + 1)){//the line following the clock tick is number of students
      inFS >> numStudents;
      if(!inFS.fail()){
        nextClockTickLine += numStudents + 2;//updating the next clock tick
        ++lineCount;
      }
    }else{
      inFS >> studentTime;//getting the students required time
      if(!inFS.fail()){
        s = new Student(studentTime, clockTick);//creating a student object
        queue->enqueue(s);//enqueue
        cout << "Enqueue at time: " << s->getArrival() << endl;
        ++lineCount;

      }

    }
  }
  inFS.close();


  time = 1;
  Student* first; //= queue->dequeue(); // declaring up here so we don't redeclare every time

  while(!queue->isEmpty() || !office->checkOpen()){//it should run if there is someone in the queue or someone at a window now
    if(!office->isFull() && !queue->isEmpty()){ //open windows and people in queue
      first = queue->peek(); //get first student
      if(first->getArrival() <= time){ // check if first students arrival is the current time
        first = queue->dequeue();
        first->setWindowTime(time);//setting the time at which the student got to the window
        office->assignWindow(first); // assigning student to a window
        helpedStudents->insertBack(first);
      }else if (first->getArrival() > time){ //not time for the student to be dequeued yet
        office->incrementWindows();
        office->checkTime(time);
        time++;

      }
    }
    if(!office->isFull() && queue->isEmpty()){//students in windows(there are still empty windows) but the queue is empty
      office->incrementWindows();
      office->checkTime(time);
      time++;
    }else if(office->isFull() && queue->isEmpty()){//office is full no students waiting
      office->checkTime(time);
      time++;
    }else if(office->isFull() && !queue->isEmpty()){//office is full students are waiting
      office->checkTime(time);
      time++;
    }

  }

}

//this function calculates the summary statistics of the program
void Simulation::Calculate(){
  float totalStudentWait = 0.0;
  int waitTime = 0;
  int size = 0;

  size = helpedStudents->getSize();//getting the number of students
  int medArray[size];//creating an array that we will sort
  for(int i = 0; i < size; ++i){
    medArray[i] = helpedStudents->accessAtPos(i)->getWaitTime();
  }
  int n = sizeof(medArray)/sizeof(medArray[0]);

  sort(medArray, medArray+n);//sorting
  for(int i = 0; i < size; ++i){ // for loop iterating until the median is found
    if(size%2 == 0){ // if the median is an even length
      if(i == ((size+1)/2)){
        m_medianStudentWait = (((float)medArray[i] + (float)medArray[i-1])/2);
      }
    }else{
      if(i == (size/2)){
       m_medianStudentWait = medArray[i];
      }
    }
  }


  for(int i = 0; i < size; ++i){
    //cout << "check1" << endl;
    Student* s = helpedStudents->accessAtPos(i);
    waitTime = s->getWaitTime();
    //cout << "check2" << endl;
    totalStudentWait += waitTime;
    if(waitTime > m_longestStudentWait){//longest wait time adjusting
      m_longestStudentWait = waitTime;
    }
    if(waitTime > 10){//if the student wait time is over ten minutes we increment
      m_studentsOverTen++;
    }
    delete s;
  }

  //calculating window idle time statistics
  m_meanStudentWait = (totalStudentWait/size);

  float totalWindowIdle = 0.0;
  float idle = 0.0;
  for(int i = 0; i < office->getSize(); ++i){
    idle = office->getWindow(i).getIdleTime();
    totalWindowIdle += idle;
    if(idle > m_longestWindowIdle){ // updating longest window idle time
      m_longestWindowIdle = idle;
    }
    if(idle > 5){ // incrementing if the window is idle for over five minutes
      m_windowsIdleOver5++;
    }
  }
  m_meanWindowIdle = (totalWindowIdle/(office->getSize()));

  //printing summary statistics
  cout << "Mean Student Wait: " << m_meanStudentWait << endl;
  cout << "Median Student Wait: " << m_medianStudentWait << endl;
  cout << "Longest Student Wait: " << m_longestStudentWait << endl;
  cout << "Students who waited over ten minutes: " << m_studentsOverTen << endl;
  cout << "Mean Window Idle Time: " << m_meanWindowIdle << endl;
  cout << "Longest Window Idle Time: " << m_longestWindowIdle << endl;
  cout << "Windows idle over five minutes: " << m_windowsIdleOver5 << endl;
}
