#include <iostream>
#include "Registrar.h"

using namespace std;

int main(int argc, char **argv){
  string fileName = "";

  //GenQueue<int> *queue = new GenQueue<int>();
  //queue->insert(4);
  //cout << queue->peak() << endl;

  if(argc > 1){
    fileName = argv[1];
  }else{
    cout << "INVALID USAGE: please enter name of a text file" << endl;
    cout << "USAGE: ./a.out [file name]" << endl;
  }

  delete queue;
  return 0;
}
