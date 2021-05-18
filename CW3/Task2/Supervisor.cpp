#include "Supervisor.h"
#include <iostream>
#include <fstream>

using std::cout;
using std::string;

// default constructor
Supervisor::Supervisor() {
}
// value constructor
Supervisor::Supervisor(string iD, int load)  {
    setID(iD);
    setLoad(load);
}

// destructor
Supervisor::~Supervisor() {
}


string Supervisor::getID(){
    return iD_;
}

void Supervisor::setID(string x){
    iD_ = x;
}

int Supervisor::getLoad(){
    return load_;
}

void Supervisor::setLoad(int x){
    load_ = x;
}