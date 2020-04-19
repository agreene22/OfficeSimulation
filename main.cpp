#include <iostream>
#include "Simulation.h"

using namespace std;

int main(int argc, char **argv){
  string fileName = "";

  //GenQueue<int> *queue = new GenQueue<int>();
  //queue->insert(4);
  //cout << queue->peak() << endl;

  if(argc > 1){
    fileName = argv[1];

    Simulation* sim = new Simulation();
    sim->Run(fileName);
    cout << "here" << endl;
    sim->Calculate();

    delete sim;
  }else{
    cout << "INVALID USAGE: please enter name of a text file" << endl;
    cout << "USAGE: ./a.out [file name]" << endl;
  }

  return 0;
}
