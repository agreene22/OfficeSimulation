/* Anna Greene - 2314663
  Brandon Kleinman - 2291703
  Assignment 4 - Registrar Office Simulation
  Window class to define methods
 */

#include "Window.h"

// defualt constructor
Window::Window(){
  m_currStudent = NULL;
  m_idleTime = 0;
}

// overloaded constructor
Window::Window(Student* s, int idleTime){
  m_currStudent = s; // setting member variables to values from parameters
  m_idleTime = idleTime;
}

// destructor
Window::~Window(){
  delete m_currStudent; // deleting pointer to current student
}

// isOpen returns a boolean represting if there is a student at the window
bool Window::isOpen(){
  return (m_currStudent == NULL);
}

// setStudent that takes a student as a paremeter
void Window::setStudent(Student* s){
  m_currStudent = s; // sets current student to parameter
}

// Open method opens the window
void Window::open(){
  m_currStudent = NULL; // sets the current student to NULL
}

// getStudent returns a pointer to the student at the window
Student* Window::getStudent(){
  return m_currStudent;
}

// Increments window idle time
void Window::incrementIdleTime(){
  m_idleTime++;
}

// Returns window idle time
float Window::getIdleTime(){
  return m_idleTime;
}
