/* Please note: even though it says IMPLEMENT ME, in some cases
   the implementation can be empty. In fact, you may wish to remove
   some of the functions entirely
*/
#include "Football.h"
#include <iostream>

// -------------- Team --------------------

Team::Team(const string& name) {
	//Initialise variables to 0 and give a name
	name_ = name;
	goalsConceded_ = 0;
}

void Team::addGoalsConceded(int g) {
	//adds g to goalsConceded (counter)
	goalsConceded_ += g;
}

Team::~Team() {
	//no pointers to delete 
}

int Team::getGoalsConceded() const{
	//return goalsConceded counter
	return goalsConceded_;
}

string Team::getName() const{
	//return name of the team
	return name_;
}

// -------------- Player ------------------

Player::Player(const string& name, Team* t) {
	//Initialise Player variables to 0, name_ to name, link *team_ with *t
	name_ = name;
	goalsScored_ = 0;
	assists_ = 0;
	team_ = t;
}

// don't remove this even if you want to make the destructor pure virtual
Player::~Player() {
	//Virtual destructor so not used
}

void Player::addGoalsScored(int g) {
	//adds g to goalsScored (counter)
	goalsScored_ += g;
}

void Player::addAssists(int a) {
	//adds a to assists (counter)
	assists_ += a;
}

int Player::getScore() const {
	//virtual method so never inside
}

string Player::print() const {
	//virtual method so never inside
	string removeMe = "";
	return removeMe;
}

// -------------- Attacker ------------------

Attacker::Attacker(const string& name, Team* t):Player(name, t)  {
	//Calls Player constructor with name and t
}

Attacker::~Attacker() {
	//Sets *Team team_ to nullptr
	team_ = nullptr;
}

int Attacker::getScore() const {
	//Initialise a score variable
	int score_ = 0;
	//Calculate score based on goalsScored_ and assists_
	score_ += 4 * goalsScored_;
	score_ += 3 * assists_;
	//return calculated score
	return score_;
}

string Attacker::print() const {
	//Initialise string variable
	string s;
	//add to string the required player statistics
	s += "Attacker: " + name_ + ", ";
	s += "Team: " + (*team_).getName() + "\n";
	s += " Goals scored: " + to_string(goalsScored_) + "\n";
	s += " Assists: " + to_string(assists_) + "\n";
	s += " Goals conceded: " + to_string((*team_).getGoalsConceded()) + "\n";
	s += " Score: " + to_string(getScore());
	//return created string
	return s;
}

// -------------- Midfielder ------------------

Midfielder::Midfielder(const string& name, Team* t):Player(name, t)  {
	//Calls Player constructor with name and t
}

Midfielder::~Midfielder() {
	//Sets *Team team_ to nullptr
	team_ = nullptr;
}

int Midfielder::getScore() const {
	//Initialise a score variable
	int score_ = 0;
	//Calculate score based on goalsScored_ and assists_
	score_ += 5 * goalsScored_;
	score_ += 3 * assists_;
	//Calculate if goalsConceded is 0
	if ((*team_).getGoalsConceded() == 0) score_ += 1;
	//return calculated score
	return score_;
}

string Midfielder::print() const {
	//Initialise string variable
	string s;
	//add to string the required player statistics
	s += "Midfielder: " + name_ + ", ";
	s += "Team: " + (*team_).getName() + "\n";
	s += " Goals scored: " + to_string(goalsScored_) + "\n";
	s += " Assists: " + to_string(assists_) + "\n";
	s += " Goals conceded: " + to_string((*team_).getGoalsConceded()) + "\n";
	s += " Score: " + to_string(getScore());
	//return created string
	return s;
}

// -------------- Defender ------------------

Defender::Defender(const string& name, Team* t):Player(name, t)  {
	//Calls Player constructor with name and t
}

Defender::~Defender() {
	//Sets *Team team_ to nullptr
	team_ = nullptr;
}

int Defender::getScore() const {
	//Initialise a score variable
	int score_ = 0;
	//Calculate score based on goalsScored_ and assists_
	score_ += 6 * goalsScored_;
	score_ += 3 * assists_;
	//Calculate if goalsConceded is 0
	if ((*team_).getGoalsConceded() == 0) score_ += 4;
	else score_ -= (*team_).getGoalsConceded()/2;
	//return calculated score
	return score_;
}

string Defender::print() const {
	//Initialise string variable
	string s;
	//add to string the required player statistics
	s += "Defender: " + name_ + ", ";
	s += "Team: " + (*team_).getName() + "\n";
	s += " Goals scored: " + to_string(goalsScored_) + "\n";
	s += " Assists: " + to_string(assists_) + "\n";
	s += " Goals conceded: " + to_string((*team_).getGoalsConceded()) + "\n";
	s += " Score: " + to_string(getScore());
	//return created string
	return s;
}

// -------------- Goalkeeper ------------------

Goalkeeper::Goalkeeper(const string& name, Team* t):Player(name, t) {
	//Calls Player constructor with name and t
	//Initialise shotsSaved_ to 0
	shotsSaved_ = 0;
}

Goalkeeper::~Goalkeeper() {
	//Sets *Team team_ to nullptr
	team_ = nullptr;
}

void Goalkeeper::addShotsSaved(int ss) {
	shotsSaved_ += ss;
}

int Goalkeeper::getScore() const {
	//Initialise a score variable
	int score_ = 0;
	//Calculate score based on goalsScored_ and assists_
	score_ += 6 * goalsScored_;
	score_ += 3 * assists_;
	score_ += shotsSaved_/3;
	//Calculate if goalsConceded is 0 or a multiple of 2
	if ((*team_).getGoalsConceded() == 0) score_ += 4;
	else score_ -= (*team_).getGoalsConceded()/2;
	//return calculated score
	return score_;
}

string Goalkeeper::print() const {
	//Initialise string variable
	string s;
	//add to string the required player statistics
	s += "Goalkeeper: " + name_ + ", ";
	s += "Team: " + (*team_).getName() + "\n";
	s += " Goals scored: " + to_string(goalsScored_) + "\n";
	s += " Assists: " + to_string(assists_) + "\n";
	s += " Goals conceded: " + to_string((*team_).getGoalsConceded()) + "\n";
	s += " Shots saved: " + to_string(shotsSaved_) + "\n";
	s += " Score: " + to_string(getScore());
	//return created string
	return s;
}

// -------------- FantasyTeam ------------------

FantasyTeam::FantasyTeam() {
	//Initialise to 0
	playerCount_ = 0;
}

FantasyTeam::~FantasyTeam() {
	//No pointers to deconstuct
}

bool FantasyTeam::addPlayer(Player* p) {

	//Check if there are 11 players already
	if (playerCount_ == 11) return false;

	//loop to check if the player is already a part of fantasy team
	for (int i = 0; i < 11; i++){
		if (p == players[i]) return false;
}

	//add player to fantasy team
	players[playerCount_] = p;
	//increase player count
	playerCount_ += 1;
	
	return true;
}

int FantasyTeam::getScore() const {
	//Initiliase score variable
	int score_ = 0;
	//go through fantasy team getting each players score and adding to score_
	for (int i = 0; i < playerCount_; i++) score_ += (*players[i]).getScore();
	//return calculated value
	return score_;
}
