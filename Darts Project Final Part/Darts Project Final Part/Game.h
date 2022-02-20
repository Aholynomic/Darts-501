# pragma once

class Game
{
public:
	Game();
	~Game();

	int checkScore(int, char, int); // check score function ensures a players score hasn't gone bust or if it has reached 0 that they should stop throwing darts
};


