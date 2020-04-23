/* Anna Greene - 2314663
  Brandon Kleinman - 2291703
  Assignment 4 - Registrar Office Simulation
 */

#include "Registrar.h"
#include <vector>

using namespace std;


class Simulation{
public:
  Simulation();//constructor
  ~Simulation();//destructor

  void Run(string fileName);//this function runs the simulation
  void Calculate();//this function calculates summary statistics

private://member variables
  float m_meanStudentWait;
  float m_medianStudentWait;
  float m_longestStudentWait;
  float m_studentsOverTen;
  float m_meanWindowIdle;
  float m_longestWindowIdle;
  float m_windowsIdleOver5;
  List<Student>* queue;
  DoublyLinkedList<Student>* helpedStudents;
  Registrar* office;
};
