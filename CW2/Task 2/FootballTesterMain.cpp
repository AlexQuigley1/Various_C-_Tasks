#include <iostream>
#include <string>

#include "FootballTester.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main(int argc, char* argv[]) {

	while (argc > 1) {
		switch (argv[--argc][0]) {
		case 'a':
		{
			FootballTester t;
			t.testAttackerCtor();
		}
		break;
		case 'b':
		{
			FootballTester t;
			t.testAttackerAddGoalsScored();
		}
		break;
		case 'c':
		{
			FootballTester t;
			t.testAttackerAddAssist();
		}
		break;
		case 'd':
		{
			FootballTester t;
			t.testAttackerGetScore();
		}
		break;
		case 'e':
		{
			FootballTester t;
			t.testAttackerPrint();
		}
		break;
		case 'f':
		{
			FootballTester t;
			t.testMidfielderCtor();
		}
		break;
		case 'g':
		{
			FootballTester t;
			t.testMidfielderAddGoalsScored();
		}
		break;
		case 'h':
		{
			FootballTester t;
			t.testMidfielderAddAssist();
		}
		break;
		case 'i':
		{
			FootballTester t;
			t.testMidfielderGetScore();
		}
		break;
		case 'j':
		{
			FootballTester t;
			t.testMidfielderPrint();
		}
		break;
		case 'k':
		{
			FootballTester t;
			t.testDefenderCtor();
		}
		break;
		case 'l':
		{
			FootballTester t;
			t.testDefenderAddGoalsScored();
		}
		break;
		case 'm':
		{
			FootballTester t;
			t.testDefenderAddAssist();
		}
		break;
		case 'n':
		{
			FootballTester t;
			t.testDefenderGetScore();
		}
		break;
		case 'o':
		{
			FootballTester t;
			t.testDefenderPrint();
		}
		break;
		case 'p':
		{
			FootballTester t;
			t.testGoalkeeperCtor();
		}
		break;
		case 'q':
		{
			FootballTester t;
			t.testGoalkeeperAddGoalsScored();
		}
		break;
		case 'r':
		{
			FootballTester t;
			t.testGoalkeeperAddAssist();
		}
		break;
		case 's':
		{
			FootballTester t;
			t.testGoalkeeperAddShotsSaved();
		}
		break;
		case 't':
		{
			FootballTester t;
			t.testGoalkeeperGetScore();
		}
		break;
		case 'u':
		{
			FootballTester t;
			t.testGoalkeeperPrint();
		}
		break;
		case 'v':
		{
			FootballTester t;
			t.testFantasyTeamAddPlayer();
		}
		break;
		case 'w':
		{
			FootballTester t;
			t.testFantasyTeamGetScore();
		}
		break;
		default:
		{
			cout<<"Options are a -- w."<<endl;
		}
		break;
       	}
	}

	return 0;
}

