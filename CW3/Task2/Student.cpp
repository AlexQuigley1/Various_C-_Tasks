#include "Student.h"
#include <iostream>
#include <vector>
using std::cout;
using std::string;
using std::vector;

// default constructor
Student::Student() {
}
// value constructor
Student::Student(string iD, vector <int> choices)  {
    choices_ = choices;
    setID(iD);
}

// destructor
Student::~Student() {
}

vector<int> Student::getChoices()  {
    return choices_;
}

string Student::getID(){
    return iD_;
}

void Student::setID(string x){
    iD_ = x;
}

int Student::getProject(){
    return chosenProject_;
}

void Student::setProject(int x){
    chosenProject_ = x;
}

int Student::getScore(){
    return score_;
}

void Student::setScore(int x){
    score_ = x;
}

