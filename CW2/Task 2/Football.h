#include <string>
using namespace std;

// Class for a real-life team
class Team {
public:
	// constructor. name is the name of the team.
	// Also should initialise relevant team statistics to 0
	Team(const string& name);

	// destructor
	~Team();

	// Add number of goals conceded by the team by g. If g is omitted,
	// default 1 is assumed.
	void addGoalsConceded(int g = 1);

	int getGoalsConceded() const;

	string getName() const;

private:

	string name_;
	int goalsConceded_;

};

// Class for a footballer
// You must turn this into an abstract class
class Player {
public:

	// Value constructor, specifying the name of the player and
	// the team the player belongs to. 
	// The memory pointed to by t is externally managed and 
	// not owned by this class
	// Also should initialise relevant player statistics to 0
	Player(const string& name, Team* t);

	// Destructor
	virtual ~Player();
	//Virtual so uses each player types destructor

	// Increases the player's number of goals scored by g. 
	// If g is omitted, 1 is assumed
	void addGoalsScored(int g = 1);

	// Increases the player's number of assists by a. 
	// If a is omitted, 1 is assumed
	void addAssists(int a = 1);

	// Returns the score of this player, based on all the individual
	// and team statistics. It is assumed that the caller knows what
	// they are doing and have called the various add..() functions
	// before calling this function.
	virtual int getScore() const;

	// Returns a string that includes the player's name, the position
	// they play (goalkeeper/attacker etc.), the name of
	// the (real-life) team they belong to, all their statistics such
	// as number of goals scored/conceded, assists etc., and the total
	// points scored.
	// Ideally you should print this exactly as described in the test cases
	// but minor formatting differences will be tolerated
	virtual string print() const;


protected:

	string name_;
	int goalsScored_;
	int assists_;
	Team* team_;
};

// Classes for each of the 4 roles
// Most functions are explained in the Player class above

class Attacker : public Player {
public:
	Attacker(const string& name, Team* t);
	~Attacker();
	int getScore() const;
	string print() const;

	// TODO: you can add any private member variables
};

class Midfielder : public Player {
public:
	Midfielder(const string& name, Team* t);
	~Midfielder();
	int getScore() const;
	string print() const;

	// TODO: you can add any private member variables
};

class Defender : public Player {
public:
	Defender(const string& name, Team* t);
	~Defender();
	int getScore() const;
	string print() const;

	// TODO: you can add any private member variables
};

class Goalkeeper : public Player {
public:
	Goalkeeper(const string& name, Team* t);
	~Goalkeeper();
	int getScore() const;
	string print() const;

	// Increase the number of shots saved by this goalkeeper by ss. 
	// If ss is omitted, 1 is assumed
	void addShotsSaved(int ss = 1);

private:
	int shotsSaved_;
};

// Class for a fantasy team
class FantasyTeam {

public:
	// Constructor. Should initialise team to 0 players
	FantasyTeam();

	~FantasyTeam(); // destructor

	// Add p to be part of this fantasy team, returning true if successful.
	// The memory pointed to by p belongs to the caller.
	// The function should check whether the same player (as identified 
	// by pointer equality) is already added, and also if there are
	// already 11 players added. If either is true, return false and
	// do not add the player.
	bool addPlayer(Player* p);

	// Returns the total score of all players in this fantasy team.
	// This should still work if less than 11 players have been added
	// (non-existent players contribute 0 to team score).
	int getScore() const;

private:
	// Member variables: the 11 players
	// You must not change this.
	Player* players[11];
	int playerCount_;
};
