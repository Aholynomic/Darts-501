# include "DartBoard.h"
# include <ctime>
# include <iostream>

using namespace std;

DartBoard::DartBoard()
{
	singlesCount = 0;
	doublesCount = 0;
	treblesCount = 0;
	bullsCount = 0;
}

DartBoard::~DartBoard()
{
	
}

int DartBoard::throw_bull(int success)
{
	int throwPercentage = rand() % 100;

	if (throwPercentage < (success - 20))
	{
		bullsCount++;
		return 50;
	}
	else if (throwPercentage < 85)
	{
		singlesCount++;
		return 25;
	}
	else
	{
		singlesCount++;
		return rand() % 20 + 1;
	}
}

int DartBoard::throw_bull_at_start(int success)
{
	int throwPercentage = rand() % 100;

	if (throwPercentage < (success - 20))
	{
		return 50;
	}
	else if (throwPercentage < 85)
	{
		return 25;
	}
	else
	{
		return rand() % 20 + 1;
	}
}

int DartBoard::throw_double(int score)
{
	int throwPercentage = rand() % 100;

	if (throwPercentage < 80)
	{
		doublesCount++;
		return 2 * score;
	}
	else if (throwPercentage < 85)
	{
		return 0;
	}
	else if (throwPercentage < 90)
	{
		singlesCount++;
		return score;
	}
	else if (throwPercentage < 93)
	{
		doublesCount++;
		return 2 * dartBoard[0][score];
	}
	else if (throwPercentage < 96)
	{
		doublesCount++;
		return 2 * dartBoard[1][score];
	}
	else if (throwPercentage < 98)
	{
		singlesCount++;
		return dartBoard[0][score];
	}
	else
	{
		singlesCount++;
		return dartBoard[1][score];
	}
}

int DartBoard::throw_single(int score)
{
	int throwPercentage = rand() % 100 + 1;

	if (score == 25)
	{
		if (throwPercentage < 80)
		{
			singlesCount++;
			return 25;
		}
		else if (throwPercentage < 90)
		{
			bullsCount++;
			return 50;
		}
		else
		{
			singlesCount++;
			return rand() % 20 + 1;
		}
	}
	else
	{
		if (throwPercentage < 88)
		{
			singlesCount++;
			return score;
		}
		else if (throwPercentage < 92)
		{
			singlesCount++;
			return dartBoard[0][score];
		}
		else if (throwPercentage < 96)
		{
			singlesCount++;
			return dartBoard[1][score];
		}
		else if (throwPercentage < 98)
		{
			treblesCount++;
			return 3 * score;
		}
		else
		{
			doublesCount++;
			return 2 * score;
		}
	}
}

int DartBoard::throw_treble(int score, int success)
{
	int throwPercentage = rand() % 100 + 1;

	if (throwPercentage < success)
	{
		treblesCount++;
		return 3 * score;
	}
	else if (throwPercentage < 90)
	{
		singlesCount++;
		return score;
	}
	else if (throwPercentage < 93)
	{
		treblesCount++;
		return 3 * dartBoard[0][score];
	}
	else if (throwPercentage < 96)
	{
		treblesCount++;
		return 3 * dartBoard[1][score];
	}
	else if (throwPercentage < 98)
	{
		singlesCount++;
		return dartBoard[0][score];
	}
	else
	{
		singlesCount++;
		return dartBoard[1][score];
	}
}

// getters

int DartBoard::getSingles()
{
	return singlesCount;
}

int DartBoard::getDoubles()
{
	return doublesCount;
}

int DartBoard::getBulls()
{
	return bullsCount;
}

int DartBoard::getTrebles()
{
	return treblesCount;
}

// setters

void DartBoard::setBulls(int x)
{
	bullsCount = x;
}

void DartBoard::setSingles(int x)
{
	singlesCount = x;
}

void DartBoard::setDoubles(int x)
{
	doublesCount = x;
}

void DartBoard::setTrebles(int x)
{
	treblesCount = x;
}
