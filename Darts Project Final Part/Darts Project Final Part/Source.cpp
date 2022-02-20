# include "DartBoard.h"
# include "Game.h"
# include "Player.h"
# include "Score.h"
# include <iostream>
# include <string>
# include <ctime>
# include <cstdlib>
# include <iomanip>

using namespace std;

// global tally variables Joe

double sevenToSix = 0; // 7:6
double sevenToFive = 0; // 7:5
double sevenToFour = 0; // 7:4
double sevenToThree = 0; // 7:3
double sevenToTwo = 0; // 7:2
double sevenToOne = 0; // 7:1
double sevenToZero = 0; // 7:0

// global tally variables Sid

double sixToSeven = 0; // 6:7
double fiveToSeven = 0; // 5:7
double fourToSeven = 0; // 4:7
double threeToSeven = 0; // 3:7
double twoToSeven = 0; // 2:7
double oneToSeven = 0; // 1:7
double zeroToSeven = 0; // 0:7

// prototypes

void outputData();
int findIntendedDart(int playerScore, int percentage);
int main();

int main()
{
	srand(time(0)); // initialise random number generator

	Player p1; // access data to the player class
	Player p2; 
	Game game; // used to access the check score function
	DartBoard dartboardP1; // keeps a tally of singles, doubles, trebles and bull and the types of throw functions
	DartBoard dartboardP2;
	Score p1Score; // keeps data relevant to the players score
	Score p2Score;

	p1.setName("Joe"); // sets the players names
	p2.setName("Sid");
	p1.setSuccess(71); // sets the success rate for each player (Joe - 71, Sid - 73)
	p2.setSuccess(73);

	// p1

	int p1Bull = 0; // used for throw bull for joe at start (2 - bull, 1 - 25 has been hit, 0 - a value between 1 and 20 has been hit)
	int player1Games = 0; int *gameCountP1 = &player1Games; // keeps a track of joe's games for each set. is reset each time a set is completed
	bool p1Turn = true; bool *a = &p1Turn; // this will stop joe from throwing any more darts if he has reached 0 or sid has done so 
	int originalScoreP1 = 0; int *scoreSetP1 = &originalScoreP1; // used to store joe's score before he throws his three darts 
	bool setOriginalP1 = false; bool *originalP1 = &setOriginalP1; // works in conjuction with the variable above. if joe has gone bust or done something 'illegal' then this will activate and allow to set original score
	bool whoGoesFirstP1 = false; bool *p1Turns = &whoGoesFirstP1; // used to alternate the players so if joe wins one game then this will turn false and sid will go first next game since joe was the last person to throw his darts
	int player1Sets = 0; int *setsP1 = &player1Sets; // used to store joe's sets for each match. is reset each time a match is completed (if equal to 7)

	// p2

	int p2Bull = 0; // used for throw bull for sid at start (2 - bull, 1 - 25 has been hit, 0 - a value between 1 and 20 has been hit)
	int player2Games = 0; int *gameCountP2 = &player2Games; // this keeps a track of sid's games for each set. resets each time a sets is completed (if it reaches 3)
	bool p2Turn = true; bool *b = &p2Turn; // stops sid from throwing any more darts if he has reached 0 or if joe has done so
	int originalScoreP2 = 0; int *scoreSetP2 = &originalScoreP2; // used to store sid's score before he throws his three darts
	bool setOriginalP2 = false; bool *originalP2 = &setOriginalP2; // this will allow sid's original score to be the new score as his score has gone bust
	bool whoGoesFirstP2 = false; bool *p2Turns = &whoGoesFirstP2; // used to alternate the players
	int player2Sets = 0; int *setsP2 = &player2Sets; // keeps a track of sid's sets for each match. is reset each time a match is completed (if equal to 7)

	// variables

	int dartScore = 0; int *score = &dartScore; // value that obtains the score from each throw function (single, double, treble and bull)
	int intScore = 0; int *intendedScore = &intScore; // used in the later stages of the game so that the player will throw a double of that score
	int i = 0; // used instead of a for loop to go through 3 darts with each player
	bool throwForBull = true; bool *loop = &throwForBull; // used for throw nearest the bull and if it's false then either sid or joe will go first
	int checkScore = 0; int *check = &checkScore; // obtains the value from passing player score, type of dart and what dart the player is on from check score function
	int intendedDart = 0; int *dart = &intendedDart; // used to find the value that will get the player on score 40 if player score is less than 50 and greater than 40
	char dartChar = ' '; // stores the type of dart needed to pass into check score to ensure if the score is bust or not
	int numberOfMatches = 0; int *matches = &numberOfMatches; // stores the number of matches the player will run (in this case, 10,000) 
	// note:  1 match -> 13 sets (best to 7) -> 5 games (best to 3) 
	int choiceForDart = 0; // casts a random number between 1 and 3 that will determine if the player will throw for treble, double or bull in the high scores

	while (*loop == true) // while this is true
	{
		dartScore = dartboardP1.throw_bull_at_start(p1.getSuccess()); // joe will try to aim for bull
		if (dartScore == 50) // if he succeeds
		{
			p1Bull = 2; // greater chance of going first
		}
		else if (dartScore == 25) // if he missed but hits the outer segment
		{
			p1Bull = 1; // still a good chance of getting first
		}
		else
		{
			p1Bull = 0; // low chance of getting first
		}

		dartScore = dartboardP2.throw_bull_at_start(p2.getSuccess()); // sid will then throw
		if (dartScore == 50)
		{
			p2Bull = 2;
		}
		else if (dartScore == 25)
		{
			p2Bull = 1;
		}
		else
		{
			p2Bull = 0;
		}

		if (p1Bull == p2Bull) // if joe and sid got the same outcome
		{
			*loop = true; // keep going until joe and sid get different outcomes
		}
		else
		{
			if (p1Bull > p2Bull) // if joe got bull or outer segment and sid got lower, joe goes first 
			{
				cout << "Joe will go first." << endl;
				cout << "Sid will follow" << endl;
				whoGoesFirstP1 = true;
				*loop = false; // break the loop
			}
			else // but if sid got bull and joe got outer segment or single, sid goes first
			{
				cout << "Sid will go first." << endl;
				cout << "Joe will follow." << endl;
				whoGoesFirstP2 = true;
				*loop = false; // break the loop
			}
		}
	}

	*matches = 10000; // set matches to 10,000

	cout << "\n";
	cout << "* Please wait a few seconds *" << endl;
	cout << "* Computing " << *matches << " matches *" << endl;
	cout << "\n";

	while (*matches != (p1.getMatches() + p2.getMatches())) // while 10,000 is not equal to joe and sid's won matches then
	{
		if (whoGoesFirstP1 == true && whoGoesFirstP2 == false) // joe will get to go first and sid will follow
		{
			if (p1Turn == true) // if this is true (score hasn't gone bust and sid hasn't got 0)
			{
				if (setOriginalP1 == false) // if joe's score hasn't gone bust then store the score before the 3 darts
				{
					originalScoreP1 = p1Score.getPoints();
				}
				else if (setOriginalP1 == true) // but if it has then set the original score before the 3 darts were thrown
				{
					p1Score.setPoints(originalScoreP1);
					setOriginalP1 = false; // set back to false to avoid errors
				}

				i = 0; // set to 0 to begin 3 darts

				while (i != 3) // while dart counter isn't equal to 3
				{
					i++; // + 1 to dart counter
					p1.setDarts(p1.getDarts() + 1); // add 1 to joe darts
					choiceForDart = rand() % 3 + 1; // decide on type of dart 
					if (p1Score.getPoints() <= 500 && p1Score.getPoints() > 100) // if score is within these ranges (500 - 100)
					{
						if (choiceForDart == 1) // throw treble 20
						{
							dartScore = dartboardP1.throw_treble(20, p1.getSuccess()); // dart score 20 to be trebled, success rate
							dartChar = 't'; // t - treble
						}
						else if (choiceForDart == 2) // throw bull
						{
							dartScore = dartboardP1.throw_bull(p1.getSuccess()); // success rate
							dartChar = 'b'; // b - bull
						}
						else // throw double 20
						{
							dartScore = dartboardP1.throw_double(20); // dart score 20 to be doubled
							dartChar = 'd'; // d - double
						}
					}
					else if (p1Score.getPoints() <= 100) // if score is less than and equal to 100
					{
						if (p1Score.getPoints() >= 50) // if score is greater and equal to 50
						{
							if (p1Score.getPoints() == 100) // if score is 100
							{
								dartScore = dartboardP1.throw_bull(p1.getSuccess()); // throw bull
								dartChar = 'b'; // b - bull
							}
							else if (p1Score.getPoints() == 90 || p1Score.getPoints() == 80 || p1Score.getPoints() == 70) // else if score is 90 or 80 or 70
							{
								dartScore = dartboardP1.throw_treble(20, p1.getSuccess()); // throw treble 20
								dartChar = 't'; // t - treble
							}
							else if (p1Score.getPoints() == 50) // if score is 50
							{
								if (i == 3) // if dart counter for that round is 3 then throw for bull
								{
									dartScore = dartboardP1.throw_bull(p1.getSuccess());
									dartChar = 'b'; // b - bull
								}
								else // deliberately miss to avoid getting score stuck or go for dart score 0
								{
									dartScore = dartboardP1.throw_double(0);
									dartChar = 'd'; // d - doublee
								}
							}
							else if (p1Score.getPoints() == 60) // else if score is equal to 60
							{
								dartScore = dartboardP1.throw_double(20); // throw double 20
								dartChar = 'd'; // d - double
							}
							else // else if score isn't equal to any of these then
							{
								intendedDart = findIntendedDart(p1Score.getPoints(), 10); // pass in player points and 10 (land a score to the next 10 for player (if score is 57 then go for dart score 7 to get player on score 50))
								dartScore = dartboardP1.throw_single(intendedDart); // get the intended dart and throw a single of that intended dart
								dartChar = 's'; // s - single
							}
						}
						else // if score is less than 50
						{
							if (p1Score.getPoints() > 40) // if score is greater than 40 but less than 50 then
							{
								intendedDart = findIntendedDart(p1Score.getPoints(), 10); // pass in player points and int 10 (47 - intendedDart = hopefully score 40)
								dartScore = dartboardP1.throw_single(intendedDart); // throw single intended dart
								dartChar = 's'; // s - single
							}
							else if (p1Score.getPoints() % 2 == 0) // else if score is less than 40 and divisible by 2
							{
								if (i == 3) // if darts counter is equal to 3
								{
									intScore = p1Score.getPoints(); // get the players points
									intScore = intScore / 2; // divide by 2
									dartScore = dartboardP1.throw_double(intScore); // pass that value into throw double function and hopefully get a double of that score
									dartChar = 'd';
								}
								else // else if it isn't then deliberately miss
								{
									dartScore = dartboardP1.throw_double(0);
									dartChar = 'd'; // d - double
								}
							}
							else // else if the score is an odd number then
							{
								intendedDart = findIntendedDart(p1Score.getPoints(), 2); // try find a value that will be to the next 2 (39 would become 38 so player would throw single 1 (39 - 1 = 38))
								dartScore = dartboardP1.throw_single(intendedDart); // throw single intended dart
								dartChar = 's'; // s - single
							}
						}
					}
					else // for intitial throw when score is on 501
					{
						dartScore = dartboardP1.throw_single(rand() % 20 + 1); // throw random number between 1 and 20
						dartChar = 's'; // s - single
					}

					p1Score.setPoints(p1Score.getPoints() - dartScore); // set the new score by taking away score - dart score
					checkScore = game.checkScore(p1Score.getPoints(), dartChar, i); // ensure the score hasn't gone bust and check if it is equal to 0
					if (checkScore == 1) // if joe's score is equal to 0
					{
						p1Turn = false; // end joe's turn
						p2Turn = false; // end sid's turn
						break; // break out of if p1Turn == true
					}
					else if (checkScore == 0) // else if score has gone bust
					{
						setOriginalP1 = true; // set the original score before the player threw their 3 darts
						break; // break out of if p1Turn == true
					}

				}
			}

			if (p2Turn == true) // if score hasn't gone bust or equal to 0 then
			{
				if (setOriginalP2 == false) // if score hasn't gone bust
				{
					originalScoreP2 = p2Score.getPoints(); // store the original score before sid throws the 3 darts
				}
				else if (setOriginalP2 == true) // else if it has then the new score will be what it was before sid threw the 3 darts on the previous set
				{
					p2Score.setPoints(originalScoreP2);
					setOriginalP2 = false; // set to false again
				}

				i = 0;

				while (i != 3)
				{
					i++;
					p2.setDarts(p2.getDarts() + 1); // add 1 to sid's darts
					choiceForDart = rand() % 3 + 1;
					if (p2Score.getPoints() <= 500 && p2Score.getPoints() > 100)
					{
						if (choiceForDart == 1)
						{
							dartScore = dartboardP2.throw_treble(20, p2.getSuccess());
							dartChar = 't';
						}
						else if (choiceForDart == 2)
						{
							dartScore = dartboardP2.throw_bull(p2.getSuccess());
							dartChar = 'b';
						}
						else
						{
							dartScore = dartboardP2.throw_double(20);
							dartChar = 'd';
						}
					}
					else if (p2Score.getPoints() <= 100)
					{
						if (p2Score.getPoints() >= 50)
						{
							if (p2Score.getPoints() == 100)
							{
								dartScore = dartboardP2.throw_bull(p2.getSuccess());
								dartChar = 'b';
							}
							else if (p2Score.getPoints() == 90 || p2Score.getPoints() == 80 || p2Score.getPoints() == 70)
							{
								dartScore = dartboardP2.throw_treble(20, p2.getSuccess());
								dartChar = 't';
							}
							else if (p2Score.getPoints() == 50)
							{
								if (i == 3)
								{
									dartScore = dartboardP2.throw_bull(p2.getSuccess());
									dartChar = 'b';
								}
								else
								{
									dartScore = dartboardP2.throw_double(0);
									dartChar = 'd';
								}
							}
							else if (p2Score.getPoints() == 60)
							{
								dartScore = dartboardP2.throw_double(20);
								dartChar = 'd';
							}
							else
							{
								intendedDart = findIntendedDart(p2Score.getPoints(), 10);
								dartScore = dartboardP2.throw_single(intendedDart);
								dartChar = 's';
							}
						}
						else
						{
							if (p2Score.getPoints() > 40)
							{
								intendedDart = findIntendedDart(p2Score.getPoints(), 10);
								dartScore = dartboardP2.throw_single(intendedDart);
								dartChar = 's';
							}
							else if (p2Score.getPoints() % 2 == 0)
							{
								if (i == 3)
								{
									intScore = p2Score.getPoints();
									intScore = intScore / 2;
									dartScore = dartboardP2.throw_double(intScore);
									dartChar = 'd';
								}
								else
								{
									dartScore = dartboardP2.throw_double(0);
									dartChar = 'd';
								}
							}
							else
							{
								intendedDart = findIntendedDart(p2Score.getPoints(), 2);
								dartScore = dartboardP2.throw_single(intendedDart);
								dartChar = 's';
							}
						}
					}
					else
					{
						dartScore = dartboardP2.throw_single(rand() % 20 + 1);
						dartChar = 's';
					}

					p2Score.setPoints(p2Score.getPoints() - dartScore); // set sid's new score 
					checkScore = game.checkScore(p2Score.getPoints(), dartChar, i); // pass in sid's current score, the type of dart and what dart he is on currently on
					if (checkScore == 1) // if his score has reached 0
					{
						p2Turn = false; // stop sid from throwing any more darts
						p1Turn = false; // as well as joe
						break;
					}
					else if (checkScore == 0) // but if his score has gone bust then set the original score before the 3 darts to be his new score
					{
						setOriginalP2 = true;
						break;
					}

				}
			}

			if (p1Turn == false && p2Turn == false) // if sid and joe have stopped throwing any more darts for that game
			{
				if (p1Score.getPoints() == 0) // if joe's score did equal 0 and not sid's
				{
					p1.setGames(p1.getGames() + 1); // add 1 to joe's overall games
					player1Games++; // add 1 to joe's current games for this set
					p1Score.setPoints(501); // set scores back to 501
					p2Score.setPoints(501);
					p1Turn = true; // let players throw darts again
					p2Turn = true;
					whoGoesFirstP1 = false; // let sid go first next game and joe second
					whoGoesFirstP2 = true;
					if (player1Games == 3) // if joe's games for this set equal 3 (first to three; five games)
					{
						player1Games = 0; // set players current games for this set back to 0
						player2Games = 0;
						p1.setSets(p1.getSets() + 1); // add 1 to joe's overall sets
						player1Sets++; // add 1 to joe's current sets for this match
						if (player1Sets == 7) // if joe's current sets equal to 7 (first to 7 - 13 sets)
						{
							if (player1Sets == 7 && player2Sets == 6) // if joe has achieved 7 sets and sid 6 (7:6)
							{
								sevenToSix++; // add 1 for tally of 7:6
							}
							else if (player1Sets == 7 && player2Sets == 5) // else if joe has achieved 7 and sid 5
							{
								sevenToFive++; // add 1 for tally of 7:5
							}
							else if (player1Sets == 7 && player2Sets == 4) // else if joe 7 and sid 4
							{
								sevenToFour++; // add 1 for tally of 7:4
							}
							else if (player1Sets == 7 && player2Sets == 3) // else if joe 7 and sid 3
							{
								sevenToThree++; // add 1 for tally of 7:3
							}
							else if (player1Sets == 7 && player2Sets == 2) // else if joe 7 and sid 2
							{
								sevenToTwo++; // add 1 for tally of 7:2
							}
							else if (player1Sets == 7 && player2Sets == 1) // else if joe 7 and sid 1
							{
								sevenToOne++; // add 1 for tally of 7:1
							}
							else if (player1Sets == 7 && player2Sets == 0) // else if joe 7 and 0
							{
								sevenToZero++; // add 1 for tally of 7:0
							}

							p1.setMatches(p1.getMatches() + 1); // add 1 to joe's matches
							player1Sets = 0; // reset joe and sid's sets to 7 to continue to the next match
							player2Sets = 0;
						}
					}
				}
				else if (p2Score.getPoints() == 0) // else if sid's score did equal 0 and not joe's
				{
					p2.setGames(p2.getGames() + 1); // add 1 to sid's overall games
					player2Games++; // add 1 to sid's current games for this set
					p1Score.setPoints(501); // set players' score back to 501 to continue next game
					p2Score.setPoints(501);
					p1Turn = true; // allow players' to continue throwing darts
					p2Turn = true;
					whoGoesFirstP1 = true; // let joe go first next game and sid second
					whoGoesFirstP2 = false;
					if (player2Games == 3) // if sid's current games equal 3 (first to 3; 5 games)
					{
						player1Games = 0; // set players current game wins for this set back to 0
						player2Games = 0;
						p2.setSets(p2.getSets() + 1); // add 1 to sid's overall sets
						player2Sets++; // add 1 to sid's current sets
						if (player2Sets == 7) // if sid's current sets is equal to 7
						{
							if (player1Sets == 6 && player2Sets == 7) // if joe's sets equal to 6 and sid's 7 for this match
							{
								sixToSeven++; // add 1 for tally of 6:7
							}
							else if (player1Sets == 5 && player2Sets == 7) // else if joe's sets equal to 5 and sid's 7 for this match
							{
								fiveToSeven++; // add 1 for tally of 5:7
							}
							else if (player1Sets == 4 && player2Sets == 7) // else if joe's sets equal to 4 and sid's 7 for this match
							{
								fourToSeven++; // add 1 for tally of 4:7
							}
							else if (player1Sets == 3 && player2Sets == 7) // else if joe's sets equal to 3 and sid's 7 for this match
							{
								threeToSeven++; // add 1 for tally of 3:7
							}
							else if (player1Sets == 2 && player2Sets == 7) // else if joe 1 and sid 7
							{
								twoToSeven++; // add 1 for tally of 2:7
							}
							else if (player1Sets == 1 && player2Sets == 7) // else if joe's sets equal to 1 and sid's 7 for this match
							{
								oneToSeven++; // add 1 for tally of 1:7
							}
							else if (player1Sets == 0 && player2Sets == 7) // else if joe 0 and sid 7
							{
								zeroToSeven++; // add 1 for tally 0:7
							}

							p2.setMatches(p2.getMatches() + 1); // add 1 to sid's matches
							player1Sets = 0; // set players' matches back to 0 to continue for next match
							player2Sets = 0;
						}
					}
				}
			}
		}
		else if (whoGoesFirstP1 == false && whoGoesFirstP2 == true) // else if sid needs to go first and joe second
		{
			if (p2Turn == true) // sid goes first
			{

				if (setOriginalP2 == false)
				{
					originalScoreP2 = p2Score.getPoints();
				}
				else if (setOriginalP2 == true)
				{
					p2Score.setPoints(originalScoreP2);
					setOriginalP2 = false;
				}

				i = 0;

				while (i != 3)
				{
					i++;
					p2.setDarts(p2.getDarts() + 1);
					choiceForDart = rand() % 3 + 1;
					if (p2Score.getPoints() <= 500 && p2Score.getPoints() > 100)
					{
						if (choiceForDart == 1)
						{
							dartScore = dartboardP2.throw_treble(20, p2.getSuccess());
							dartChar = 't';
						}
						else if (choiceForDart == 2)
						{
							dartScore = dartboardP2.throw_bull(p2.getSuccess());
							dartChar = 'b';
						}
						else
						{
							dartScore = dartboardP2.throw_double(20);
							dartChar = 'd';
						}
					}
					else if (p2Score.getPoints() <= 100)
					{
						if (p2Score.getPoints() >= 50)
						{
							if (p2Score.getPoints() == 100)
							{
								dartScore = dartboardP2.throw_bull(p2.getSuccess());
								dartChar = 'b';
							}
							else if (p2Score.getPoints() == 90 || p2Score.getPoints() == 80 || p2Score.getPoints() == 70)
							{
								dartScore = dartboardP2.throw_treble(20, p2.getSuccess());
								dartChar = 't';
							}
							else if (p2Score.getPoints() == 50)
							{
								if (i == 3)
								{
									dartScore = dartboardP2.throw_bull(p2.getSuccess());
									dartChar = 'b';
								}
								else
								{
									dartScore = dartboardP2.throw_double(0);
									dartChar = 'd';
								}
							}
							else if (p2Score.getPoints() == 60)
							{
								dartScore = dartboardP2.throw_double(20);
								dartChar = 'd';
							}
							else
							{
								intendedDart = findIntendedDart(p2Score.getPoints(), 10);
								dartScore = dartboardP2.throw_single(intendedDart);
								dartChar = 's';
							}
						}
						else
						{
							if (p2Score.getPoints() > 40)
							{
								intendedDart = findIntendedDart(p2Score.getPoints(), 10);
								dartScore = dartboardP2.throw_single(intendedDart);
								dartChar = 's';
							}
							else if (p2Score.getPoints() % 2 == 0)
							{
								if (i == 3)
								{
									intScore = p2Score.getPoints();
									intScore = intScore / 2;
									dartScore = dartboardP2.throw_double(intScore);
									dartChar = 'd';
								}
								else
								{
									dartScore = dartboardP2.throw_double(0);
									dartChar = 'd';
								}
							}
							else
							{
								intendedDart = findIntendedDart(p2Score.getPoints(), 2);
								dartScore = dartboardP2.throw_single(intendedDart);
								dartChar = 's';
							}
						}
					}
					else
					{
						dartScore = dartboardP2.throw_single(rand() % 20 + 1);
						dartChar = 's';
					}

					p2Score.setPoints(p2Score.getPoints() - dartScore);
					checkScore = game.checkScore(p2Score.getPoints(), dartChar, i);
					if (checkScore == 1)
					{
						p2Turn = false;
						p1Turn = false;
						break;
					}
					else if (checkScore == 0)
					{
						setOriginalP2 = true;
						break;
					}

				}

				if (p1Turn == true) // joe goes second
				{
					if (setOriginalP1 == false)
					{
						originalScoreP1 = p1Score.getPoints();
					}
					else if (setOriginalP1 == true)
					{
						p1Score.setPoints(originalScoreP1);
						setOriginalP1 = false;
					}

					i = 0;

					while (i != 3)
					{
						i++;
						p1.setDarts(p1.getDarts() + 1);
						choiceForDart = rand() % 3 + 1;
						if (p1Score.getPoints() <= 500 && p1Score.getPoints() > 100)
						{
							if (choiceForDart == 1)
							{
								dartScore = dartboardP1.throw_treble(20, p1.getSuccess());
								dartChar = 't';
							}
							else if (choiceForDart == 2)
							{
								dartScore = dartboardP1.throw_bull(p1.getSuccess());
								dartChar = 'b';
							}
							else
							{
								dartScore = dartboardP1.throw_double(20);
								dartChar = 'd';
							}
						}
						else if (p1Score.getPoints() <= 100)
						{
							if (p1Score.getPoints() >= 50)
							{
								if (p1Score.getPoints() == 100)
								{
									dartScore = dartboardP1.throw_bull(p1.getSuccess());
									dartChar = 'b';
								}
								else if (p1Score.getPoints() == 90 || p1Score.getPoints() == 80 || p1Score.getPoints() == 70)
								{
									dartScore = dartboardP1.throw_treble(20, p1.getSuccess());
									dartChar = 't';
								}
								else if (p1Score.getPoints() == 50)
								{
									if (i == 3)
									{
										dartScore = dartboardP1.throw_bull(p1.getSuccess());
										dartChar = 'b';
									}
									else
									{
										dartScore = dartboardP1.throw_double(0);
										dartChar = 'd';
									}
								}
								else if (p1Score.getPoints() == 60)
								{
									dartScore = dartboardP1.throw_double(20);
									dartChar = 'd';
								}
								else
								{
									intendedDart = findIntendedDart(p1Score.getPoints(), 10);
									dartScore = dartboardP1.throw_single(intendedDart);
									dartChar = 's';
								}
							}
							else
							{
								if (p1Score.getPoints() > 40)
								{
									intendedDart = findIntendedDart(p1Score.getPoints(), 10);
									dartScore = dartboardP1.throw_single(intendedDart);
									dartChar = 's';
								}
								else if (p1Score.getPoints() % 2 == 0)
								{
									if (i == 3)
									{
										intScore = p1Score.getPoints();
										intScore = intScore / 2;
										dartScore = dartboardP1.throw_double(intScore);
										dartChar = 'd';
									}
									else
									{
										dartScore = dartboardP1.throw_double(0);
										dartChar = 'd';
									}
								}
								else
								{
									intendedDart = findIntendedDart(p1Score.getPoints(), 10);
									dartScore = dartboardP1.throw_single(intendedDart);
									dartChar = 's';
								}
							}
						}
						else
						{
							dartScore = dartboardP1.throw_single(rand() % 20 + 1);
							dartChar = 's';
						}

						p1Score.setPoints(p1Score.getPoints() - dartScore);
						checkScore = game.checkScore(p1Score.getPoints(), dartChar, i);
						if (checkScore == 1)
						{
							p1Turn = false;
							p2Turn = false;
							break;
						}
						else if (checkScore == 0)
						{
							setOriginalP1 = true;
							break;
						}

					}
				}
			}

			if (p1Turn == false && p2Turn == false)
			{
				if (p1Score.getPoints() == 0)
				{
					p1.setGames(p1.getGames() + 1);
					player1Games++;
					p1Score.setPoints(501);
					p2Score.setPoints(501);
					p1Turn = true;
					p2Turn = true;
					whoGoesFirstP1 = false;
					whoGoesFirstP2 = true;
					if (player1Games == 3)
					{
						player1Games = 0;
						player2Games = 0;
						p1.setSets(p1.getSets() + 1);
						player1Sets++;
						if (player1Sets == 7)
						{
							if (player1Sets == 7 && player2Sets == 6)
							{
								sevenToSix++;
							}
							else if (player1Sets == 7 && player2Sets == 5)
							{
								sevenToFive++;
							}
							else if (player1Sets == 7 && player2Sets == 4)
							{
								sevenToFour++;
							}
							else if (player1Sets == 7 && player2Sets == 3)
							{
								sevenToThree++;
							}
							else if (player1Sets == 7 && player2Sets == 2)
							{
								sevenToTwo++;
							}
							else if (player1Sets == 7 && player2Sets == 1)
							{
								sevenToOne++;
							}
							else if (player1Sets == 7 && player2Sets == 0)
							{
								sevenToZero++;
							}

							p1.setMatches(p1.getMatches() + 1);
							player1Sets = 0;
							player2Sets = 0;
						}
					}
				}
				else if (p2Score.getPoints() == 0)
				{
					p2.setGames(p2.getGames() + 1);
					player2Games++;
					p1Score.setPoints(501);
					p2Score.setPoints(501);
					p1Turn = true;
					p2Turn = true;
					whoGoesFirstP1 = true;
					whoGoesFirstP2 = false;
					if (player2Games == 3)
					{
						player1Games = 0;
						player2Games = 0;
						p2.setSets(p2.getSets() + 1);
						player2Sets++;
						if (player2Sets == 7)
						{
							if (player1Sets == 6 && player2Sets == 7)
							{
								sixToSeven++;
							}
							else if (player1Sets == 5 && player2Sets == 7)
							{
								fiveToSeven++;
							}
							else if (player1Sets == 4 && player2Sets == 7)
							{
								fourToSeven++;
							}
							else if (player1Sets == 3 && player2Sets == 7)
							{
								threeToSeven++;
							}
							else if (player1Sets == 2 && player2Sets == 7)
							{
								twoToSeven++;
							}
							else if (player1Sets == 1 && player2Sets == 7)
							{
								oneToSeven++;
							}
							else if (player1Sets == 0 && player2Sets == 7)
							{
								zeroToSeven++;
							}

							p2.setMatches(p2.getMatches() + 1);
							player1Sets = 0;
							player2Sets = 0;
						}
					}
				}
			}
		}
	}

	// display joe and sid's stats after 10,000
	
	// joe

	cout << "\n";
	cout << "\n";
	cout << "G A M E  O V E R !" << endl;
	cout << "\n";
	cout << "\n";
	cout << p1.getName() << endl;
	cout << "\n";
	cout << "Matches won: " << p1.getMatches() << endl;
	cout << "\n";
	cout << "Average darts thrown: " << setprecision(2) << p1.calculateAverage(dartboardP1.getBulls() + dartboardP1.getSingles() + dartboardP1.getTrebles() + dartboardP1.getDoubles()) << endl;
	cout << "\n";
	cout << "Bulls: " << dartboardP1.getBulls() << endl;
	cout << "\n";
	cout << "Singles: " << dartboardP1.getSingles() << endl;
	cout << "\n";
	cout << "Doubles: " << dartboardP1.getDoubles() << endl;
	cout << "\n";
	cout << "Trebles: " << dartboardP1.getTrebles() << endl;
	cout << "\n";
	cout << "Games won: " << p1.getGames() << endl;
	cout << "\n";
	cout << "Sets won: " << p1.getSets() << endl;
	cout << "\n";
	cout << "Darts thrown: " << p1.getDarts() << endl;
	cout << "\n";
	cout << "Success rate: " << p1.getSuccess() << endl;
	cout << "\n";
	cout << "\n";

	// sid

	cout << p2.getName() << endl;
	cout << "\n";
	cout << "Matches won: " << p2.getMatches() << endl;
	cout << "\n";
	cout << "Average darts thrown: " << setprecision(2) << p2.calculateAverage(dartboardP2.getBulls() + dartboardP2.getSingles() + dartboardP2.getTrebles() + dartboardP2.getDoubles()) << endl;
	cout << "\n";
	cout << "Bulls: " << dartboardP2.getBulls() << endl;
	cout << "\n";
	cout << "Singles: " << dartboardP2.getSingles() << endl;
	cout << "\n";
	cout << "Doubles: " << dartboardP2.getDoubles() << endl;
	cout << "\n";
	cout << "Trebles: " << dartboardP2.getTrebles() << endl;
	cout << "\n";
	cout << "Games won: " << p2.getGames() << endl;
	cout << "\n";
	cout << "Sets won: " << p2.getSets() << endl;
	cout << "\n";
	cout << "Darts thrown: " << p2.getDarts() << endl;
	cout << "\n";
	cout << "Success rate: " << p2.getSuccess() << endl;
	cout << "\n";
	cout << "\n";

	outputData(); // output the data after 10,000 matches and show tally's for each set
	getchar();
}

int findIntendedDart(int playerScore, int percentage)
{
	int intendedDart = 0; int *dart = &intendedDart;
	int intScore = 0; int *intendedScore = &intScore;

	intendedDart = 0; // set back to 0 to avoid taking away huge numbers
	intScore = playerScore; // intscore is now equal to player score

	do {
		if (intScore % percentage != 0) // if intscore is not divisible by percentage (percentage could be 2 or 10, i.e. playerscore % 10 == 0)
		{
			intScore--; // decrease the player's score until it has reached a divisible number
			intendedDart++; // increase the intended dart (this will be the dart score the player will aim for)
		}
	} while (intScore % percentage != 0);

	return intendedDart; // return intended dart

}

void outputData() // outputs the required data after 10,000 matches
{
	cout << "Joe : Sid " << "    " << " " << "Frequency" << endl;
	cout << "\n";
	cout << "  7 : 6   " << "    " << "   " << sevenToSix / 100 << " " << endl;
	cout << "  7 : 5   " << "    " << "   " << sevenToFive / 100 << " " << endl;
	cout << "  7 : 4   " << "    " << "   " << sevenToFour / 100 << " " << endl;
	cout << "  7 : 3   " << "    " << "   " << sevenToThree / 100 << " " << endl;
	cout << "  7 : 2   " << "    " << "   " << sevenToTwo / 100 << " " << endl;
	cout << "  7 : 1   " << "    " << "   " << sevenToOne / 100 << " " << endl;
	cout << "  7 : 0   " << "    " << "   " << sevenToZero / 100 << " " << endl;
	cout << "  6 : 7   " << "    " << "   " << sixToSeven / 100 << " " << endl;
	cout << "  5 : 7   " << "    " << "   " << fiveToSeven / 100 << " " << endl;
	cout << "  4 : 7   " << "    " << "   " << fourToSeven / 100 << " " << endl;
	cout << "  3 : 7   " << "    " << "   " << threeToSeven / 100 << " " << endl;
	cout << "  2 : 7   " << "    " << "   " << twoToSeven / 100 << " " << endl;
	cout << "  1 : 7   " << "    " << "   " << oneToSeven / 100 << " " << endl;
	cout << "  0 : 7   " << "    " << "   " << zeroToSeven / 100 << " " << endl;
	cout << "\n";
}

