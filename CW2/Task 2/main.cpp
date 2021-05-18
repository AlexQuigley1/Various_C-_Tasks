#include <iostream>
#include "Football.h"

int main() {

	// data setup
	Team* leic = new Team("Leicester City");
	Team* mancity = new Team("Manchester City");
	Team* chelsea = new Team("Chelsea");
	Team* noteam = new Team("Not playing in Premier League");

	Goalkeeper* schmeichel = new Goalkeeper("Schmeichel", leic);
	Player* simpson = new Defender("Simpson", leic);
	Player* morgan = new Defender("Morgan", leic);
	Player* huth = new Defender("Huth", noteam);
	Player* fuchs = new Defender("Fuchs", leic);
	Player* mahrez = new Midfielder("Mahrez", mancity);
	Player* drinkwater = new Midfielder("Drinkwater", chelsea);
	Player* kante = new Midfielder("Kante", chelsea);
	Player* albrighton = new Midfielder("Albrighton", leic);
	Player* okazaki = new Attacker("Okazaki", noteam);
	Player* vardy = new Attacker("Vardy", leic);

	// forming my fantasy team
	FantasyTeam champion2016;
	champion2016.addPlayer(schmeichel);
	champion2016.addPlayer(simpson);
	champion2016.addPlayer(morgan);
	champion2016.addPlayer(huth);
	champion2016.addPlayer(fuchs);
	champion2016.addPlayer(mahrez);
	champion2016.addPlayer(drinkwater);
	champion2016.addPlayer(kante);
	champion2016.addPlayer(albrighton);
	champion2016.addPlayer(okazaki);
	champion2016.addPlayer(vardy);

	// update match stats
	leic->addGoalsConceded(1);
	noteam->addGoalsConceded(2);
	schmeichel->addShotsSaved(4);
	huth->addGoalsScored(1);
	mahrez->addGoalsScored();
	mahrez->addAssists();
	vardy->addGoalsScored(2);

	// display scores
	cout << schmeichel->print() << endl;
	cout << huth->print() << endl;
	cout << mahrez->print() << endl;
	cout << vardy->print() << endl;

	cout << "Team score: " << champion2016.getScore() << endl;

	// not bothered with delete's	
}
