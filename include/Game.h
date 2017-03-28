#ifndef GAME_H_
#define GAME_H_

#include <iostream>
#include <string>
#include "Player.h"
#include "Deck.h"

using namespace std;

class Game {
private:
	string winner1;
	string winner2;
	string initial;
	int numOfTurns;
	vector<Player *> players;  //The list of the players
	Deck deck;
	int verbalField;
	 int highNField;
	 Card* toAsk;
	 string asker,asked;
	//The deck of the game
public:
	Game(char* configurationFile);
	Game(const Game& otherGame);
	Game& operator=(const Game& other);
	void init();
	void play();
	void printState();        //Print the state of the game as described in the assignment.
	void printWinner();       //Print the winner of the game as describe in the assignment.
  void printNumberOfTurns(); //Print the number of played turns at any given time.
  void checkfor4(Player& p,Card& c);
  void takeCardFromOther(Player& p1,Player& p2,Card& c);
  int cardOccourences(Player& p1,Card& c);
  void split(const string& str, const string& delim, vector<string>& parts);
  int String2Int(const string& str, int result);
  void whoAsks();

  virtual ~Game();


};

#endif
