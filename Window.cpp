#include "Window.h"

Window::Window(){
  studentOccupy = NULL;
  m_idleTime = 0;
}

Window::Window(Student* s, int idleTime){
  studentOccupy = s;
  m_idleTime = idleTime
}

Window::~Window(){
  delete s;
}

bool Window::isOpen(){
  return (studentOccupy == NULL);
}

void Window::setStudent(Student* s){
  studentOccupy = s;
}

void Window::open(){
  studentOccupy = NULL;
}
