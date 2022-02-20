#include "Player.h"

Player::Player()
{
	dartsThrown = 0;
	gamesWon = 0;
	setsWon = 0;
	matchesWon = 0;
}

Player::~Player()
{
	
}

double Player::calculateAverage(int x) // returns average dart throws for each player
{
	double average = (double)dartsThrown / x;
	return average;
}

// getters

string Player::getName(void)
{
	return playerName;
}

int Player::getSuccess(void)
{
	return successRate;
}

int Player::getDarts(void)
{
	return dartsThrown;
}

int Player::getGames(void)
{
	return gamesWon;
}

int Player::getSets(void)
{
	return setsWon;
}

int Player::getMatches(void)
{
	return matchesWon;
}

// setters

void Player::setName(string t)
{
	playerName = t;
}

void Player::setSuccess(int t)
{
	successRate = t;
}

void Player::setDarts(int x)
{
	dartsThrown = x;
}

void Player::setGames(int x)
{
	gamesWon = x;
}

void Player::setSets(int x)
{
	setsWon = x;
}

void Player::setMatches(int x)
{
	matchesWon = x;
}
