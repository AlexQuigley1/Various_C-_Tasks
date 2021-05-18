#ifndef TESTERBASE_H_
#define TESTERBASE_H_

#include <string>

class TesterBase {
public:
	TesterBase();
	~TesterBase();
	
	
protected:
	void errorOut_(const std::string& errMsg, unsigned int errBit);
	void passOut_(const std::string& passMsg);

	char error_;
	std::string funcname_;

	static const unsigned int MAX_COORDINATE = 100;

	double randomDouble_(unsigned int max=0);

};

#endif /* TESTERBASE_H_ */
