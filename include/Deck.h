#ifndef DECK_H_
#define DECK_H_

#include <iostream>
#include <vector>
#include "Card.h"

using namespace std;

class Deck {
private:
	vector<Card*> deck;
public:
	Deck(vector<Card*> newDeck);
	Deck(const Deck& otherDeck);
	Deck();
	Card* fetchCard();   //Returns the top card of the deck and remove it rom the deck
	int getNumberOfCards(); // Get the number of cards in the deck
	string toString(); // Return the cards in top-to-bottom order in a single line, cards are separated by a space ex: "12S QD AS 3H"
	bool isEmpty();
	vector<Card*> getMyDeck();
	 virtual ~Deck();
	 void pushBack(Card* c);
	 int String2Int(const string& str, int result);
};

#endif
