#pragma once
#ifndef HAND_H_
#define HAND_H_

#include <iostream>
#include <vector>
#include "Card.h"

using namespace std;

class Hand {
private:
	vector<Card*> myHand;
public:
	Hand(vector<Card*> newHand);
	Hand(const Hand& otherHand);
	Hand();
	bool addCard(Card &card);
	bool removeCard(Card &card);
	int getNumberOfCards(); // Get the number of cards in hand
	string toString(); // Return a list of the cards, separated by space, in one line,
	//in a sorted order, ex: "2S 5D 10H"
	bool IalreadyHave(Card &card);
	bool IalreadyHave2(Card &card);
	vector<Card*> getMyHand();
	void findAndDeleteCard(Card& card);
	static bool compare(Card* a,Card* b);
	bool isEmpty();
	int String2Int(const string& str, int result);
	virtual ~Hand();

};

#endif
