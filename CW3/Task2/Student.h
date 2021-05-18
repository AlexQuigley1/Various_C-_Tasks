#include <iostream>
#include <vector>
using std::cout;
using std::string;
using std::vector;

class Student {
public:

	// Default constructor
	Student();

	//Value constructor
	Student(string iD, vector <int> choices);

	//Destructor
	~Student();

	vector<int> getChoices();

	string getID();

	void setID(string iD);

	int getProject();

	void setProject(int project);

	int getScore();

	void setScore(int project);

private:
	vector <int> choices_;
	string iD_;
	int chosenProject_;
	int score_;
};
