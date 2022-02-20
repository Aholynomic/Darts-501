#pragma once
class DartBoard
{
private:

	int singlesCount;
	int doublesCount;
	int treblesCount;
	int bullsCount;

public:

	DartBoard();
	~DartBoard();

	int dartBoard[2][21] = { { 0, 20, 15, 17, 18, 12, 13, 19, 16, 14, 6, 8, 9, 4, 11, 10, 7, 2, 1, 3, 5 },
	{ 0, 18, 17, 19, 13, 20, 10, 16, 11, 12, 15, 14, 5, 6, 9, 2, 8, 3, 4, 7, 1 } }; // dart board numbers

	int throw_single(int); // function for throw single dart score
	int throw_bull_at_start(int); // used for throwing for nearest the bull at 50:50 start of game
	int throw_bull(int); // throw for bull function
	int throw_treble(int, int); // used to throw treble
	int throw_double(int); // used to throw double

	// getters

	int getBulls(void);
	int getSingles(void);
	int getDoubles(void);
	int getTrebles(void);

	// setters

	void setBulls(int);
	void setSingles(int);
	void setDoubles(int);
	void setTrebles(int);
};

