#include <iostream>
#include "FootballTester.h"
#include "Football.h"

FootballTester::FootballTester() : TesterBase() {
}

FootballTester::~FootballTester() {
}

void FootballTester::testAttackerCtor() {
	funcname_ = "FootballTester::testAttackerCtor";

	Team* t = new Team("Example team");
	Player* p = new Attacker("Some attacker", t);
	if (p->getScore() != 0)
		errorOut_("Attacker score not zero initially",1);
	delete p;
	delete t;
	passOut_("Tested the attacker constructor.");
}

void FootballTester::testAttackerAddGoalsScored() {
	funcname_ = "FootballTester::testAttackerAddGoalsScored";

	Team* t = new Team("Example team");
	Player* p = new Attacker("Some attacker", t);
	p->addGoalsScored();
	if (p->getScore() != 4) 
		errorOut_("Attacker score not 4 after 1 goal",1);
	p->addGoalsScored(2);
	if (p->getScore() != 12) 
		errorOut_("Attacker score not 12 after 3 goals",2);
	delete p;
	delete t;

	passOut_("Tested the attacker add goals scored.");
}

void FootballTester::testAttackerAddAssist() {
	funcname_ = "FootballTester::testAttackerAddAssist";

	Team* t = new Team("Example team");
	Player* p = new Attacker("Some attacker", t);
	p->addAssists();
	if (p->getScore() != 3)
		errorOut_("Attacker score not 3 after 1 assist",1);
	p->addAssists(2);
	if (p->getScore() != 9)
		errorOut_("Attacker score not 9 after 3 assists",2);
	delete p;
	delete t;

	passOut_("Tested the attacker add assist.");

}

void FootballTester::testAttackerGetScore() {

	funcname_ = "FootballTester::testAttackerGetScore";

	Team* t = new Team("Example team");
	Player* p = new Attacker("Some attacker", t);
	t->addGoalsConceded(1);
	p->addGoalsScored(7);
	p->addAssists(4);
	if (p->getScore() != 40) 
		errorOut_("Attacker score incorrect",0);
	delete p;
	delete t;

	passOut_("Tested the attacker getscore.");

}

void FootballTester::testAttackerPrint() {
	funcname_ = "FootballTester::testAttackerPrint";

	Team* t = new Team("Example team");
	Player* p = new Attacker("Some attacker", t);
	t->addGoalsConceded(1);
	p->addGoalsScored(7);
	p->addAssists(4);
	string s = "Attacker: Some attacker, Team: Example team\n";
	s += " Goals scored: 7\n";
	s += " Assists: 4\n";
	s += " Goals conceded: 1\n";
	s += " Score: 40";
	cout << "---- Should produce something like this: ----" << endl;
	cout << s << endl;
	cout << "----------- Program printed this: -----------\n";
	string s2 = p->print();
	cout << s2 << endl;
	delete p;
	delete t;
	if (s != s2) errorOut_("Attacker print incorrect",1);
	else passOut_("Tested the attacker print.");
}

void FootballTester::testMidfielderCtor() {
	funcname_ = "FootballTester::testMidfielderCtor";

	Team* t = new Team("Example team");
	Player* p = new Midfielder("Some midfielder", t);
	if (p->getScore() != 1) 
		errorOut_("Midfielder score not 1 initially",1);
	delete p;
	delete t;

	passOut_("Tested the midfielder constructor.");
}

void FootballTester::testMidfielderAddGoalsScored() {
	funcname_ = "FootballTester::testMidfielderAddGoalsScored";

	Team* t = new Team("Example team");
	Player* p = new Midfielder("Some midfielder", t);
	p->addGoalsScored();
	if (p->getScore() != 6) 
		errorOut_("Midfielder score not 6 after 1 goal",1);
	p->addGoalsScored(2);
	if (p->getScore() != 16) 
		errorOut_("Midfielder score not 16 after 3 goals",2);

	delete p;
	delete t;
	passOut_("Tested the midfielder add goals scored.");
}

void FootballTester::testMidfielderAddAssist() {
	funcname_ = "FootballTester::testMidfielderAddAssist";

	Team* t = new Team("Example team");
	Player* p = new Midfielder("Some midfielder", t);
	p->addAssists();
	if (p->getScore() != 4)
		errorOut_("Midfielder score not 4 after 1 assist",1);
	p->addAssists(2);
	if (p->getScore() != 10)
		errorOut_("Midfielder score not 10 after 3 assists",2);
	delete p;
	delete t;

	passOut_("Tested the midfielder add assist.");

}

void FootballTester::testMidfielderGetScore() {

	funcname_ = "FootballTester::testMidfielderGetScore";

	Team* t = new Team("Example team");
	Player* p = new Midfielder("Some midfielder", t);
	p->addGoalsScored(4);
	p->addAssists(6);
	if (p->getScore() != 39)
		errorOut_("Midfielder score incorrect",0);
	t->addGoalsConceded(1);
	if (p->getScore() != 38)
		errorOut_("Midfielder score incorrect",1);

	delete p;
	delete t;

	passOut_("Tested the midfielder getscore.");

}

void FootballTester::testMidfielderPrint() {
	funcname_ = "FootballTester::testMidfielderPrint";

	Team* t = new Team("Example team");
	Player* p = new Midfielder("Some midfielder", t);
	p->addGoalsScored(4);
	p->addAssists(6);
	string s = "Midfielder: Some midfielder, Team: Example team\n";
	s += " Goals scored: 4\n";
	s += " Assists: 6\n";
	s += " Goals conceded: 0\n";
	s += " Score: 39";
	cout << "---- Should produce something like this: ----" << endl;
	cout << s << endl;
	cout << "----------- Program printed this: -----------\n";
	string s2 = p->print();
	cout << s2 << endl;
	delete p;
	delete t;
	if (s != s2) errorOut_("Midfielder print incorrect",1);
	else passOut_("Tested the midfielder print.");
	
}

void FootballTester::testDefenderCtor() {
	funcname_ = "FootballTester::testDefenderCtor";

	Team* t = new Team("Example team");
	Player* p = new Defender("Some defender", t);
	if (p->getScore() != 4) 
		errorOut_("Defender score not 4 initially",1);
	delete p;
	delete t;
	passOut_("Tested the defender constructor.");

}

void FootballTester::testDefenderAddGoalsScored() {
	funcname_ = "FootballTester::testDefenderAddGoalsScored";

	Team* t = new Team("Example team");
	Player* p = new Defender("Some defender", t);
	p->addGoalsScored();
	if (p->getScore() != 10) 
		errorOut_("Defender score not 10 after 1 goal",1);
	p->addGoalsScored(2);
	if (p->getScore() != 22) 
		errorOut_("Defender score not 22 after 3 goals",2);

	delete p;
	delete t;
	passOut_("Tested the defender add goals scored.");
}

void FootballTester::testDefenderAddAssist() {
	funcname_ = "FootballTester::testDefenderAddAssist";

	Team* t = new Team("Example team");
	Player* p = new Defender("Some defender", t);
	p->addAssists();
	if (p->getScore() != 7)
		errorOut_("Defender score not 7 after 1 assist",1);
	p->addAssists(2);
	if (p->getScore() != 13)
		errorOut_("Defender score not 13 after 3 assists",2);
	delete p;
	delete t;

	passOut_("Tested the defender add assist.");

}

void FootballTester::testDefenderGetScore() {
	funcname_ = "FootballTester::testDefenderGetScore";

	Team* t = new Team("Example team");
	Player* p = new Defender("Some defender", t);
	p->addGoalsScored(1);
	p->addAssists(2);
	if (p->getScore() != 16) 
		errorOut_("Defender score incorrect",0);
	t->addGoalsConceded();
	if (p->getScore() != 12) 
		errorOut_("Defender score incorrect",1);
	t->addGoalsConceded(8);
	if (p->getScore() != 8) 
		errorOut_("Defender score incorrect",2);

	delete p;
	delete t;

	passOut_("Tested the defender getscore.");

}

void FootballTester::testDefenderPrint() {
	funcname_ = "FootballTester::testDefenderPrint";

	Team* t = new Team("Example team");
	Player* p = new Defender("Some defender", t);
	p->addGoalsScored(1);
	p->addAssists(2);
	t->addGoalsConceded(9);
	string s = "Defender: Some defender, Team: Example team\n";
	s += " Goals scored: 1\n";
	s += " Assists: 2\n";
	s += " Goals conceded: 9\n";
	s += " Score: 8";
	cout << "---- Should produce something like this: ----" << endl;
	cout << s << endl;
	cout << "----------- Program printed this: -----------\n";
	string s2 = p->print();
	cout << s2 << endl;
	delete p;
	delete t;
	if (s != s2) errorOut_("Defender print incorrect",1);
	else passOut_("Tested the defender print.");
}

void FootballTester::testGoalkeeperCtor() {
	funcname_ = "FootballTester::testGoalkeeperCtor";

	Team* t = new Team("Example team");
	 Player* p = new Goalkeeper("Some goalkeeper", t);
	 if (p->getScore() != 4) 
	 	errorOut_("Goalkeeper score not 4 initially",1);
	 delete p;
	 delete t;
	passOut_("Tested the goalkeeper constructor.");
}

void FootballTester::testGoalkeeperAddGoalsScored() {
	funcname_ = "FootballTester::testGoalkeeperAddGoalsScored";

	Team* t = new Team("Example team");
	Player* p = new Goalkeeper("Some goalkeeper", t);
	p->addGoalsScored();
	if (p->getScore() != 10) 
		errorOut_("Goalkeeper score not 10 after 1 goal",1);
	p->addGoalsScored(2);
	if (p->getScore() != 22) 
		errorOut_("Goalkeeper score not 22 after 3 goals",2);

	delete p;
	delete t;
	passOut_("Tested the goalkeeper add goals scored.");
}

void FootballTester::testGoalkeeperAddAssist() {
	funcname_ = "FootballTester::testGoalkeeperAddAssist";

	Team* t = new Team("Example team");
	Player* p = new Goalkeeper("Some goalkeeper", t);
	p->addAssists();
	if (p->getScore() != 7)
		errorOut_("Goalkeeper score not 7 after 1 assist",1);
	p->addAssists(2);
	if (p->getScore() != 13)
		errorOut_("Goalkeeper score not 13 after 3 assists",2);
	delete p;
	delete t;

	passOut_("Tested the goalkeeper add assist.");

}

void FootballTester::testGoalkeeperAddShotsSaved() {
	funcname_ = "FootballTester::testGoalkeeperAddShotsSaved";

	Team* t = new Team("Example team");
	Goalkeeper* p = new Goalkeeper("Some goalkeeper", t);
	p->addShotsSaved();
	if (p->getScore() != 4)
		errorOut_("Goalkeeper score not 6 after 1 save",1);
	p->addShotsSaved(2);
	if (p->getScore() != 5)
		errorOut_("Goalkeeper score not 7 after 3 saves",2);
	delete p;
	delete t;

	passOut_("Tested the goalkeeper add shots saved.");
}

void FootballTester::testGoalkeeperGetScore() {

	funcname_ = "FootballTester::testGoalkeeperGetScore";

	Team* t = new Team("Example team");
	Goalkeeper* p = new Goalkeeper("Some goalkeeper", t);
	p->addGoalsScored(1);
	p->addAssists(1);
	p->addShotsSaved(11);
	if (p->getScore() != 16)
		errorOut_("Goalkeeper score incorrect",0);
	t->addGoalsConceded();
	if (p->getScore() != 12)
		errorOut_("Goalkeeper score incorrect",1);
	t->addGoalsConceded(8);
	if (p->getScore() != 8)
		errorOut_("Goalkeeper score incorrect",2);
	delete p;
	delete t;

	passOut_("Tested the goalkeeper getscore.");

}

void FootballTester::testGoalkeeperPrint() {
	funcname_ = "FootballTester::testGoalkeeperPrint";

	Team* t = new Team("Example team");
	Goalkeeper* p = new Goalkeeper("Some goalkeeper", t);
	p->addGoalsScored(1);
	p->addAssists(1);
	p->addShotsSaved(11);
	t->addGoalsConceded(9);
	string s = "Goalkeeper: Some goalkeeper, Team: Example team\n";
	s += " Goals scored: 1\n";
	s += " Assists: 1\n";
	s += " Goals conceded: 9\n";
	s += " Shots saved: 11\n";
	s += " Score: 8";
	cout << "---- Should produce something like this: ----" << endl;
	cout << s << endl;
	cout << "----------- Program printed this: -----------\n";
	string s2 = p->print();
	cout << s2 << endl;
	delete p;
	delete t;
	if (s != s2) errorOut_("Goalkeeper print incorrect",1);
	else passOut_("Tested the goalkeeper print.");

}

void FootballTester::testFantasyTeamAddPlayer() {

	funcname_ = "FootballTester::testFantasyTeamAddPlayer";

	Team* t1 = new Team("t1");
	Team* t2 = new Team("t2");

	Player* p1 = new Goalkeeper("p1", t1);
	Player* p2 = new Defender("p2", t1);
	Player* p3 = new Defender("p3", t1);
	Player* p4 = new Defender("p4", t1);
	Player* p5 = new Midfielder("p5", t1);
	Player* p6 = new Midfielder("p6", t1);
	Player* p8 = new Attacker("p8", t1);

	Player* q2 = new Defender("q2", t2);
	Player* q5 = new Midfielder("q5", t2);
	Player* q6 = new Midfielder("q6", t2);
	Player* q8 = new Attacker("q8", t2);
	Player* q9 = new Attacker("q9", t2);

	// forming my fantasy team
	FantasyTeam myteam;
	if (!myteam.addPlayer(p1)) errorOut_("addPlayer incorrectly returned false",1);
	if (!myteam.addPlayer(p2)) errorOut_("addPlayer incorrectly returned false",1);
	if (!myteam.addPlayer(p3)) errorOut_("addPlayer incorrectly returned false",1);
	if (!myteam.addPlayer(p4)) errorOut_("addPlayer incorrectly returned false",1);
	if (!myteam.addPlayer(q2)) errorOut_("addPlayer incorrectly returned false",1);
	if (!myteam.addPlayer(p5)) errorOut_("addPlayer incorrectly returned false",1);
	if (!myteam.addPlayer(p6)) errorOut_("addPlayer incorrectly returned false",1);
	if (!myteam.addPlayer(q5)) errorOut_("addPlayer incorrectly returned false",1);
	if (!myteam.addPlayer(q6)) errorOut_("addPlayer incorrectly returned false",1);
	if (myteam.addPlayer(p5)) errorOut_("addPlayer allowed adding player twice",2);
	if (!myteam.addPlayer(p8)) errorOut_("addPlayer incorrectly returned false",1);
	if (!myteam.addPlayer(q8)) errorOut_("addPlayer incorrectly returned false",1);
	if (myteam.addPlayer(q9)) errorOut_("addPlayer allowed adding 12th player",3);

	delete t1; delete t2;
	delete p1; delete p2; delete p3; delete p4; delete p5; delete p6;
	delete p8; delete q2; delete q5; delete q6; delete q8; delete q9;

	passOut_("Tested the FantasyTeam addplayer");

}

void FootballTester::testFantasyTeamGetScore() {

	funcname_ = "FootballTester::testFantasyTeamGetScore";

	Team* t1 = new Team("t1");
	Goalkeeper* p1 = new Goalkeeper("p1", t1);
	Player* p2 = new Defender("p2", t1);
	Player* p3 = new Defender("p3", t1);
	Player* p4 = new Midfielder("p4", t1);
	Player* p5 = new Midfielder("p5", t1);
	Player* p6 = new Attacker("p6", t1);

	FantasyTeam myteam;
	myteam.addPlayer(p1);
	myteam.addPlayer(p2);
	myteam.addPlayer(p3);
	myteam.addPlayer(p4);
	myteam.addPlayer(p5);
	myteam.addPlayer(p6);

	t1->addGoalsConceded(3);
	p1->addShotsSaved(7);
	p2->addAssists();
	p3->addGoalsScored();
	p4->addAssists(2);
	p5->addGoalsScored();
	p6->addGoalsScored(2);
	if (myteam.getScore() != 27) errorOut_("FantasyTeam getscore incorrect",1);
	delete t1; 
	delete p1; delete p2; delete p3; delete p4; delete p5; delete p6;

	passOut_("Tested the FantasyTeam getScore");

}
