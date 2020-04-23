/* Anna Greene - 2314663
  Brandon Kleinman - 2291703
  Assignment 4 - Registrar Office Simulation
  Main file to implement simulation class
 */

#include <iostream>
#include "Simulation.h"

using namespace std;

int main(int argc, char **argv){
  string fileName = "";

  Simulation* sim; // creating pointer to simulation
  if(argc > 1){
    fileName = argv[1];

    sim = new Simulation(); // initializing new instance of simulation
    sim->Run(fileName); // calling run and calculate methods
    sim->Calculate();


  }else{ // if no file is provided error check
   cout << "INVALID USAGE: please enter name of a text file" << endl;
   cout << "USAGE: ./a.out [file name]" << endl;
  }


  return 0;
}
