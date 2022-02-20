# include "Score.h"

using namespace std;

Score::Score()
{
	playerPoints = 501;
}

Score::~Score()
{
	
}

// getters

int Score::getPoints()
{
	return playerPoints;
}

// setters

void Score::setPoints(int x)
{
	playerPoints = x;
}


