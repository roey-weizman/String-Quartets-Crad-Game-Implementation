
#include <algorithm>

#include "Deck.h"

/*Constructors*/
Deck::Deck():deck(){

}
Deck::Deck(vector<Card*> newDeck):deck(){
	Card*c;
	int d=0;
	for (unsigned int i = 0; i < newDeck.size(); i++) {

		string s = newDeck[i]->toString();
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
			c = new NumericCard(String2Int(s1,d), e);}

		deck.push_back(c);
	}}

int Deck::String2Int(const string& str, int result) {
	std::istringstream ss(str);
	ss.imbue(std::locale::classic());
	ss >> result;
	return result;
}
Deck::Deck(const Deck& otherDeck):deck(){
	Card*c;
	int d=0;
	for (unsigned int i = 0; i < otherDeck.deck.size(); i++) {

		string s = otherDeck.deck[i]->toString();
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
			c = new NumericCard(String2Int(s1,d), e);}

		deck.push_back(c);
	}}




/*Functions*/
Card* Deck::fetchCard() {
	Card* temp= deck.back();
	deck.pop_back();
	return temp; }
int Deck::getNumberOfCards(){
	return Deck::deck.size();
}
string Deck::toString(){
	string ans="Deck: ";
	for(int i=deck.size()-1;i>=0;i--) {
		ans=ans+(deck[i])->toString()+" ";
	}
	return ans;
}

bool Deck::isEmpty(){
	return deck.size()==0;
}
vector<Card*> Deck::getMyDeck(){
	return deck;
}

Deck::~Deck() {
	vector<Card*>::iterator it = deck.begin();
	for (; it != deck.end(); it++) {
		Card* curr = *it;
		delete curr;
	  }
	deck.clear();
}
void Deck::pushBack(Card* c){
	deck.push_back(c);

}


