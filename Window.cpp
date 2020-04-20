/* Anna Greene - 2314663
  Brandon Kleinman - 2291703
  Assignment 4 - Registrar Office Simulation
 */

#include "Window.h"

Window::Window(){
  m_currStudent = NULL;
  m_idleTime = 0;
}

Window::Window(Student* s, int idleTime){
  m_currStudent = s;
  m_idleTime = idleTime;
}

Window::~Window(){
  delete m_currStudent;
}

bool Window::isOpen(){
  return (m_currStudent == NULL);
}

void Window::setStudent(Student* s){//does this make sense?
  m_currStudent = s;
}

void Window::open(){
  m_currStudent = NULL;
}

Student* Window::getStudent(){
  return m_currStudent;
}

void Window::incrementIdleTime(){
  m_idleTime++;
}

float Window::getIdleTime(){
  return m_idleTime;
}
