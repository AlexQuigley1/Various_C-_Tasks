#include <iostream>
#include <sstream>
#include <vector>
#include <fstream>
#include "Student.h"
#include "Supervisor.h"
#include "Project.h"
#include <memory>
using namespace std;

int main(int argc, char* argv[]) {
	//create vectors to save data from files into
	vector <Supervisor> supervisorVec_;
	vector <Project> projectVec_;
	vector <Student> studentVec_;

	//Dealing with Supervisor file
	const string SupervisorIN_FILENAME = argv[1];
	ifstream supervisorIn(SupervisorIN_FILENAME.c_str());
	const char SupervisorDELIMITER = ' ';
	string supervisorID = "";
	int load = -1;
	// Priming read for one data set
	getline(supervisorIn, supervisorID, SupervisorDELIMITER);
	supervisorIn >> load;
	supervisorIn.ignore(INT32_MAX, '\n');
	while (supervisorIn){
		//create student to add to vector
		Supervisor tempSupervisor(supervisorID, load);
		supervisorVec_.push_back(tempSupervisor);
		// Read the next data set
		getline(supervisorIn, supervisorID, SupervisorDELIMITER);
		supervisorIn >> load;
		supervisorIn.ignore(INT32_MAX, '\n');
	}

	//Dealing with Project file
	const string ProjectIN_FILENAME = argv[2];
	ifstream projectIn(ProjectIN_FILENAME.c_str());
	const char ProjectDELIMITER = ' ';
	int projID = -1;
	string supID = "";
	string title = "";
	int multiplicity = -1;
	// Priming read for one data set
	projectIn >> projID;
	projectIn.ignore(INT32_MAX, ' ');
	getline(projectIn, supID, ProjectDELIMITER);
	projectIn >> multiplicity;
	projectIn.ignore(INT32_MAX, ' ');
	getline(projectIn, title, '\n');
	while (projectIn){

		//create project to add to vector
		Project tempProject(projID, supID, multiplicity, title);
		projectVec_.push_back(tempProject);

		// Read the next data set
		projectIn >> projID;
		projectIn.ignore(INT32_MAX, ' ');
		getline(projectIn, supID, ProjectDELIMITER);
		projectIn >> multiplicity;
		projectIn.ignore(INT32_MAX, ' ');
		getline(projectIn, title, '\n');
	}

	//Dealing with Student file
	const string StudentIN_FILENAME = argv[3];
	ifstream studentIn(StudentIN_FILENAME.c_str());
	const char StudentDELIMITER = ' ';
	string studentID = "";
	int first = -1;
	int second = -1;
	int third = -1;
	int fourth = -1;

	// Priming read for one data set
	getline(studentIn, studentID, StudentDELIMITER);
	studentIn >> first;
	studentIn >> second;
	studentIn >> third;
	studentIn >> fourth;
	studentIn.ignore(INT32_MAX, '\n');
	while (studentIn){
		//create student to add to vector
		vector<int> choices = {first, second, third, fourth};
		Student tempStudent(studentID, choices);
		studentVec_.push_back(tempStudent);
		// Read the next data set
		getline(studentIn, studentID, StudentDELIMITER);
		studentIn >> first;
		studentIn >> second;
		studentIn >> third;
		studentIn >> fourth;
		studentIn.ignore(INT32_MAX, '\n');
	}

	//loop through student vector and allocate projects
	for (int i = 0; i<studentVec_.size(); i++){
		Student currentStudent_ = studentVec_.at(i);
		//set bool to know if student has found project
		bool foundChoice_ = false;
		string studentId_ = currentStudent_.getID();
		vector <int> choices_ = currentStudent_.getChoices();

		//loop through students choices
		for(int x = 0; x<4; x++){
			int currentChoice_ = choices_.at(x);
			//find project by id from currentChoice_
			for(auto proj_ = projectVec_.begin(); proj_ != projectVec_.end(); proj_++){
				if(proj_->getID()==currentChoice_){
					//find supervisor by id from projects supervisor 
					for(auto sup_ = supervisorVec_.begin(); sup_ != supervisorVec_.end(); sup_++){
						if(sup_->getID()==proj_->getSupervisorID()){
							//get load and multiplicity
							int load_ = sup_->getLoad();
							int multiplicity_ = proj_->getMultiplicity();
							if(load_>0 && multiplicity_>0){
								//get score based on choice
								int score_ = 0;
								switch(x){
									case 0:
										score_ = 4;
										break;
									case 1:
										score_ = 3;
										break;
									case 2:
										score_ = 2;
										break;
									case 3:
										score_ = 1;
										break;
								}
								//udpate as student has found choice
								foundChoice_ = true;
								//update student so it knows chosen project
								studentVec_.at(i).setProject(proj_->getID());
								studentVec_.at(i).setScore(score_);
								//update project and supervisor load/multiplicity as one space has been taken up
								proj_->setMultiplicity(proj_->getMultiplicity()-1);
								sup_->setLoad(sup_->getLoad()-1);

								//leave loop
								break;
							}
							if(foundChoice_ == false){
								studentVec_.at(i).setProject(0);
								studentVec_.at(i).setScore(0);
							}
						}
						if(foundChoice_ == true) break;
					}
				}
				if(foundChoice_ == true) break;
			}
			if(foundChoice_ == true) break;
		}
	}
//open output file
ofstream outputFile;
outputFile.open("alloc.txt");
//intialise score count
int totalScore_=0;
	//loop through students adding to file and counting score
	for (int i = 0; i<studentVec_.size(); i++){
		outputFile<< studentVec_.at(i).getID() << " " << studentVec_.at(i).getProject()<<"\n";
		totalScore_+=studentVec_.at(i).getScore();
	}
	outputFile << totalScore_;
	//close file
	outputFile.close();
	//print completion of program
	cout<<"Allocation complete\n";

}

