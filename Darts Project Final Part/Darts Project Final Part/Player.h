#pragma once
#include <string>
#include <iostream>

using namespace std;

class Player
{
private:

	string playerName;
	int dartsThrown;
	int gamesWon;
	int successRate;
	int setsWon;
	int matchesWon;

public:
	Player();
	~Player();

	double calculateAverage(int);

	// getters

	string getName(void);
	int getSuccess(void);
	int getDarts(void);
	int getGames(void);
	int getSets(void);
	int getMatches(void);

	// setters

	void setName(string);
	void setSuccess(int);
	void setDarts(int);
	void setGames(int);
	void setSets(int);
	void setMatches(int);
};

