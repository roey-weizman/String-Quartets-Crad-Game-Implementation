#include "Hand.h"
#include "Deck.h"
#include <algorithm>

Hand::Hand(vector<Card*> newHand) :myHand() {
	Card*c;
	int d=0;
	for (unsigned int i = 0; i < newHand.size(); i++) {

		string s = newHand[i]->toString();
		string s1 = s.substr(0, s.size() - 1);
		string s2 = s.substr(s.size() - 1, 1);
		bool isFig = false;
		Shape e;
		Figure f;
		if (s2 == "C")
			e = Club;
		else if (s2 == "H")
			e = Heart;
		else if (s2 == "S")
			e = Spade;
		else if (s2 == "D")
			e = Diamond;
		if (s1 == "J") {
			f = Jack;
			isFig = true;
		} else if (s1 == "Q") {
			f = Queen;
			isFig = true;
		} else if (s1 == "K") {
			f = King;
			isFig = true;
		} else if (s1 == "A") {
			f = Ace;
			isFig = true;
		}
		if (isFig) {

			c = new FigureCard(f, e);

		} else {
			c = new NumericCard(String2Int(s1,d), e);
		}
		myHand.push_back(c);
	}
}
Hand::Hand(const Hand& otherHand) :myHand() {
	Card*c;
	int d=0;
	for (unsigned int i = 0; i < otherHand.myHand.size(); i++) {

		string s = otherHand.myHand[i]->toString();
		string s1 = s.substr(0, s.size() - 1);
		string s2 = s.substr(s.size() - 1, 1);
		bool isFig = false;
		Shape e;
		Figure f;
		if (s2 == "C")
			e = Club;
		else if (s2 == "H")
			e = Heart;
		else if (s2 == "S")
			e = Spade;
		else if (s2 == "D")
			e = Diamond;
		if (s1 == "J") {
			f = Jack;
			isFig = true;
		} else if (s1 == "Q") {
			f = Queen;
			isFig = true;
		} else if (s1 == "K") {
			f = King;
			isFig = true;
		} else if (s1 == "A") {
			f = Ace;
			isFig = true;
		}
		if (isFig) {

			c = new FigureCard(f, e);

		} else {

			c = new NumericCard(String2Int(s1,d), e);
		}
		myHand.push_back(c);
	}
}

int Hand::String2Int(const string& str, int result) {
	std::istringstream ss(str);
	ss.imbue(std::locale::classic());
	ss >> result;
	return result;
}


Hand::Hand() :
		myHand() {
}

bool Hand::IalreadyHave(Card &card) {
	unsigned int i = 0;
	while (i < Hand::myHand.size()) {
		if (Hand::myHand[i]->toString() == card.toString())
			return true;
		i++;
	}
	return false;
}

bool Hand::IalreadyHave2(Card &card) {
	unsigned int i = 0;
	while (i < Hand::myHand.size()) {
		string s1 = Hand::myHand[i]->toString();
		string s2 = card.toString();
		if (s1.substr(0, s1.size() - 1) == s2.substr(0, s2.size() - 1))
			return true;
		i++;
	}
	return false;
}
vector<Card*> Hand::getMyHand() {
	return myHand;
}

void Hand::findAndDeleteCard(Card& card) { //call just if the card exists in myHand
	unsigned int i = 0;
	while (i < myHand.size()) {
		if (myHand[i]->toString() == card.toString()) { //maybe &
			Card *curr=myHand[i];
			delete curr;
			myHand.erase(myHand.begin() + i);
			return;
		}
		i++;
	}
}

bool Hand::addCard(Card &card) {
	if (IalreadyHave(card))
		return false;
	Card * c;
	int d=0;
	string s = card.toString();
	string s1 = s.substr(0, s.size() - 1);
	string s2 = s.substr(s.size() - 1, 1);
	bool isFig = false;
	Shape e;
	Figure f;
	if (s2 == "C")
		e = Club;
	else if (s2 == "H")
		e = Heart;
	else if (s2 == "S")
		e = Spade;
	else if (s2 == "D")
		e = Diamond;
	if (s1 == "J") {
		f = Jack;
		isFig = true;
	} else if (s1 == "Q") {
		f = Queen;
		isFig = true;
	} else if (s1 == "K") {
		f = King;
		isFig = true;
	} else if (s1 == "A") {
		f = Ace;
		isFig = true;
	}
	if (isFig) {

		c = new FigureCard(f, e);

	} else {
		
		c = new NumericCard(String2Int(s1,d), e);
	}
	myHand.push_back(c);

	sort(myHand.begin(), myHand.end(), compare);
	return true;
}
bool Hand::removeCard(Card& card) {
	if (IalreadyHave2(card)) {
		findAndDeleteCard(card);
		return true;
	} else
		return false;
}

int Hand::getNumberOfCards() {
	return myHand.size();
}
bool Hand::compare(Card* a, Card* b) {
	if (a->isPure() == true && b->isPure() == true) { //both of type figure
		if (((FigureCard*) a)->getFigure() > ((FigureCard*) b)->getFigure()
				|| ((((FigureCard*) a)->getFigure()
						== ((FigureCard*) b)->getFigure())
						&& (a->getShape() > b->getShape())))
			return true;
		else
			return false;
	} else if (a->isPure() == false && b->isPure() == false) { //both numeric
		if (((NumericCard*) a)->getNumber() > ((NumericCard*) b)->getNumber()
				|| ((((NumericCard*) a)->getNumber()
						== ((NumericCard*) b)->getNumber())
						&& (a->getShape() > b->getShape())))
			return true;
		else
			return false;
	} else if (a->isPure() == true && b->isPure() == false) { //a figure , b numeric
		return true;
	} else
		return false;
}

string Hand::toString() {
	sort(myHand.begin(), myHand.end(), compare);
	string ans = "";
	for (int i = myHand.size() - 1; i >= 0; i--) {
		ans = ans + (myHand[i])->toString() + " ";
	}
	return ans;
}
bool Hand::isEmpty() {
	if (myHand.size() == 0)
		return true;
	return false;
}
Hand::~Hand() {
	vector<Card*>::iterator it = myHand.begin();
	for (; it != myHand.end(); it++) {
		Card* curr = *it;
		delete curr;
	}
	myHand.clear();

}

