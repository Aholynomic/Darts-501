# include "Game.h"

using namespace std;

Game::Game()
{
}

Game::~Game()
{
	
}

int Game::checkScore(int currentScore, char dart, int i)
{
	/*

	0 - set score to orginal, give the turn to the next player or start another set
	1 - give the turn to the next player or end that game
	2 - keep going

	*/

	if (currentScore == 0)
	{
		if (dart == 't')
		{
			return 0;
		}
		else if (dart == 'd')
		{
			if (i == 3)
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
		else if (dart == 's')
		{
			return 0;
		}
		else if (dart == 'b')
		{
			if (i == 3)
			{
				return 1;
			}
			else
			{
				return 0;
			}

		}
	}
	else if (currentScore == 1)
	{
		return 0;
	}
	else if (currentScore < 0)
	{
		return 0;
	}
	else
	{
		return 2;
	}
}

