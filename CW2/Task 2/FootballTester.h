#ifndef FOOTBALLTESTER_H_
#define FOOTBALLTESTER_H_

#include "TesterBase.h"

class FootballTester : public TesterBase {
public:
	FootballTester();
	~FootballTester();

	// Please note that, despite their names, these test functions do not
	// just test the corresponding method; there are dependencies on 
	// other methods. For example to pass testAttackerAddGoalsScored()
	// you will need to at least partially implement Attacker::getScore()
	// as well.

	void testAttackerCtor(); // 1 mark
	void testAttackerAddGoalsScored(); // 1.5 marks
	void testAttackerAddAssist(); // 1.5 marks
	void testAttackerGetScore(); // 1.5 marks
	void testAttackerPrint(); // 1 mark

	void testMidfielderCtor(); // 1 mark
	void testMidfielderAddGoalsScored(); // 1.5 marks
	void testMidfielderAddAssist(); // 1.5 marks
	void testMidfielderGetScore(); // 1.5 marks
	void testMidfielderPrint(); // 1 mark

	void testDefenderCtor(); // 1 mark
	void testDefenderAddGoalsScored(); // 1.5 marks
	void testDefenderAddAssist(); // 1.5 marks
	void testDefenderGetScore(); // 1.5 marks
	void testDefenderPrint(); // 1 mark

	void testGoalkeeperCtor(); // 1 mark
	void testGoalkeeperAddGoalsScored(); // 1.5 marks
	void testGoalkeeperAddAssist(); // 1.5 marks
	void testGoalkeeperAddShotsSaved(); // 1.5 marks
	void testGoalkeeperGetScore(); // 1.5 marks
	void testGoalkeeperPrint(); // 1 mark

	void testFantasyTeamAddPlayer(); // 1.5 marks
	void testFantasyTeamGetScore(); // 1 mark
};

#endif /* FOOTBALLTESTER_H_ */
