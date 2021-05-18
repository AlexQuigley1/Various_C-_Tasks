#include "Project.h"
#include <iostream>
using std::cout;
using std::string;

// default constructor
Project::Project() {
}
// value constructor
Project::Project(int iD, string supId, int multiplicity, string title)  {
    setID(iD);
    setSupervisorID(supId);
    setMultiplicity(multiplicity);
    setTitle(title);
}

// destructor
Project::~Project() {
}

int Project::getID(){
    return iD_;
}

void Project::setID(int x){
    iD_ = x;
}

string Project::getSupervisorID(){
    return supervisorID_;
}

void Project::setSupervisorID(string x){
    supervisorID_ = x;
}

int Project::getMultiplicity(){
    return multiplicity_;
}

void Project::setMultiplicity(int x){
    multiplicity_ = x;
}

string Project::getTitle(){
    return title_;
}

void Project::setTitle(string x){
    title_ = x;
}
