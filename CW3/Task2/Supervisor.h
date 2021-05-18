#include <iostream>
#include <vector>
using std::cout;
using std::string;

class Supervisor {
public:

	// Default constructor
	Supervisor();

	//Value constructor
	Supervisor(string iD, int load);

	//Destructor
	~Supervisor();

	string getID();

	void setID(string iD);

	int getLoad();

	void setLoad(int x);

private:
	string iD_;
	int load_;
};
