#include <iostream>
#include <vector>
using std::cout;
using std::string;

class Project {
public:

	// Default constructor
	Project();

	//Value constructor
	Project(int iD, string supId, int multiplicity, string title);

	//Destructor
	~Project();

	int getID();

	void setID(int iD);

	int getMultiplicity();

	void setMultiplicity(int multiplicity);

	string getSupervisorID();

	void setSupervisorID(string iD);

	string getTitle();

	void setTitle(string Title);

private:
	int iD_;
	string supervisorID_;
	int multiplicity_;
	string title_;
};
