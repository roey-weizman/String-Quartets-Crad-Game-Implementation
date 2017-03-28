#include "Game.h"
#include <fstream>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
void Game::split(const string& str, const string& delim,
		vector<string>& parts) {
	size_t start, end = 0;
	while (end < str.size()) {
		start = end;
		while (start < str.size() && (delim.find(str[start]) != string::npos)) {
			start++;  // skip initial whitespace
		}
		end = start;
		while (end < str.size() && (delim.find(str[end]) == string::npos)) {
			end++; // skip to end of word
		}
		if (end - start != 0) {  // just ignore zero-length strings.
			parts.push_back(string(str, start, end - start));
		}
	}
}
int Game::String2Int(const string& str, int result) {
	std::istringstream ss(str);
	ss.imbue(std::locale::classic());
	ss >> result;
	return result;
}
void Game::printWinner() {
	string s = winner1;
	string e = winner2;
	if (winner1.length() != 0 && winner2.length() != 0) {
		cout << "***** The Winners are: " << s << " and " << e << " *****"
				<< endl;
	} else {
		if (winner1.length() != 0 || winner2.length() != 0)
			cout << "***** The Winner is: " << s << e << " *****" << endl;

	}
}
Game::Game(char* configurationFile) :
		winner1(""), winner2(""), initial(""), numOfTurns(0), players(), deck(), verbalField(
				-1), highNField(0), toAsk(), asker(), asked() {
	bool verbal = false;
	bool deckFile = false;
	bool highN = false;
	vector<string> parts1;
	vector<string> parts2;
	vector<Card*> ofD;
	string delim = " ";
	Deck *deck1 = new Deck(ofD);
	deck = *deck1;
	delete deck1;
	int d = 0;
	std::ifstream filein(configurationFile);

	string line;
	while (!filein.eof()) {
		//	in >> newLine;
		std::getline(filein, line);
		if (line == "" || line.at(0) == '#')
			continue;
		else if (verbal == false) {
			verbalField = String2Int(line.substr(0, 1), verbalField);
			verbal = true;
			continue;
		} else if (highN == false) {
			highNField = String2Int(line.substr(line.find_first_of("\t") + 1),
					highNField);
			highN = true;
			continue;
		} else if (deckFile == false) {
			split(line, delim, parts1);
			if (parts1.size() == ((unsigned int) (highNField + 3) * 4))
				deckFile = true;
			continue;
		} else {
			split(line, delim, parts2);
		}
	}
	std::reverse(parts1.begin(), parts1.end());
	for (unsigned i = 0; i < parts1.size(); i++) {
		string s = parts1[i];
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

			Card* c = new FigureCard(f, e);
			deck.pushBack(c);

		} else {
			
			Card* c = new NumericCard(String2Int(s1, d), e);
			deck.pushBack(c);
		}
	}
	int posCnt = 1;
	for (unsigned int j = 0; j < parts2.size(); j = j + 2) {
		int type = 0;
		Hand *h = new Hand();
		Player* temp;
		type = String2Int(parts2[j + 1], type);
		if (type == 1)
			temp = new PlayerType1(*h, parts2[j], type, posCnt);
		else if (type == 2)
			temp = new PlayerType2(*h, parts2[j], type, posCnt);
		else if (type == 3)
			temp = new PlayerType3(*h, parts2[j], type, posCnt);
		else if (type == 4)
			temp = new PlayerType4(*h, parts2[j], type, posCnt);
		players.push_back(temp);
		posCnt++;
		delete h;
	}
}

Game::Game(const Game& otherGame) :
		winner1(otherGame.winner1), winner2(otherGame.winner2), initial(
				otherGame.initial), numOfTurns(otherGame.numOfTurns),players(), deck(
				otherGame.deck), verbalField(otherGame.verbalField), highNField(
				otherGame.highNField), toAsk(otherGame.toAsk), asker(
				otherGame.asker), asked(otherGame.asked) {
	for (unsigned int j = 0; j < otherGame.players.size(); j++) {
		Hand* h=new Hand(otherGame.players[j]->getMyHand());
		Player* temp;
		if (otherGame.players[j]->getType() == 1)
			temp = new PlayerType1(*h, otherGame.players[j]->getName(),
					otherGame.players[j]->getType(),
					otherGame.players[j]->getPosition());
		else if (otherGame.players[j]->getType() == 2)
			temp = new PlayerType2(*h, otherGame.players[j]->getName(),
					otherGame.players[j]->getType(),
					otherGame.players[j]->getPosition());
		else if (otherGame.players[j]->getType() == 3)
			temp = new PlayerType3(*h, otherGame.players[j]->getName(),
					otherGame.players[j]->getType(),
					otherGame.players[j]->getPosition());
		else if (otherGame.players[j]->getType() == 4)
			temp = new PlayerType4(*h, otherGame.players[j]->getName(),
					otherGame.players[j]->getType(),
					otherGame.players[j]->getPosition());
		players.push_back(temp); delete h;
	}

}
int Game::cardOccourences(Player& p1, Card& c) {
	int i = 0;
	string s1 = c.toString();

	for (unsigned int j = 0; j != p1.getMyHand().size(); j++) {
		Card* curr = p1.getMyHand()[j];
		string s2 = curr->toString();
		if (s1.substr(0, s1.size() - 1) == s2.substr(0, s2.size() - 1))
			i++;
	}
	return i;
}

void Game::checkfor4(Player& p, Card& c) {
	int i = cardOccourences(p, c);
	string s1 = c.toString();
	if (i == 4) {

		for (unsigned int j = 0; i > 0 && j != p.getMyHand().size(); j++) {
			Card* curr = p.getMyHand()[j];
			string s2 = curr->toString();
			if (s1.substr(0, s1.size() - 1) == s2.substr(0, s2.size() - 1)) {
				p.removeCard(*curr);
				j = -1;
				i--;  //maybe do delete command curr inside the "if"
			}
		}
	}
}

void Game::takeCardFromOther(Player& p1, Player& p2, Card& c) {
	int j = cardOccourences(p2, c);
	string s1 = c.toString();

	for (unsigned int k = 0; j > 0 && k < p2.getMyHand().size(); k++) {
		Card* curr = p2.getMyHand()[k];
		string s2 = curr->toString();
		if (s1.substr(0, s1.size() - 1) == s2.substr(0, s2.size() - 1)) {
			p1.addCard(*curr);
			p2.removeCard(*curr);
			j--;
			k = -1;
		}
	}
}
void Game::printNumberOfTurns() {
	std::cout << "Number of turns: ";
	std::cout << numOfTurns << endl;

}

void Game::whoAsks() {
	string t = toAsk->toString();
	cout
			<< asker + " asked " + asked + " for the value "
					+ t.substr(0, t.size() - 1) << endl;
}

void Game::printState() {
	cout << deck.toString() << endl;
	vector<Player*>::iterator it = players.begin();
	for (; it != players.end(); it++) {
		Player* curr = *it;
		cout << curr->toStringToPlayer() << endl;
	}

}

void Game::play() {
	bool flag = false;

	initial = deck.toString();
	vector<Player*>::iterator it = players.begin();
	for (; it != players.end(); it++) {
		Player* curr = *it;
		initial = initial + "\n" + curr->toStringToPlayer();

	}
	while (!flag) {
		Card* c;
		for (unsigned int i = 0; i < players.size() && !flag; i++) {
			numOfTurns++;
			Player* curr = players[i];
			Player* otherP = curr->getThePlayerToAskFrom(players);
			c = curr->getTheCardINeed();
			toAsk = c;
			asker = curr->getName();
			asked = otherP->getName();
			if (verbalField == 1) {
				cout << "Turn ";
				cout << numOfTurns << endl;
				printState();
				whoAsks();
				cout << endl;
			}
			if (otherP->IalreadyHave2(*c) == true) {
				int j = cardOccourences(*otherP, *c);
				takeCardFromOther(*curr, *otherP, *c);
				for (int i = 0; i < j; i++) {
					if (!deck.isEmpty()) {
						Card * d = deck.fetchCard();
						otherP->addCard(*d);
						checkfor4(*otherP, *d);
						delete d;
					}
				}
				if (otherP->getMyHand().size() == 0) {
					winner2 = otherP->getName();
					flag = true;
				}
				checkfor4(*curr, *c);
				if (curr->getMyHand().size() == 0) {
					winner1 = curr->getName();
					flag = true;
					break;
				}
			} else if (!deck.isEmpty()) {
				Card * d = deck.fetchCard();
				curr->addCard(*d);
				checkfor4(*curr, *d);
				delete d;
				if (curr->getMyHand().size() == 0) {
					winner1 = curr->getName();
					flag = true;
					break;
				}
			}
		delete toAsk;}

	}

}

void Game::init() {
	vector<Player*>::iterator it = players.begin();
	for (; it != players.end(); it++) {
		Player* curr = *it;
		for (unsigned int j = 7; j > 0; j--) {
			Card* c = deck.fetchCard();
			curr->addCard(*c);
			checkfor4(*curr, *c);
delete c;
		}

	}
}
Game& Game::operator=(const Game& other) {
	Game *temp = new Game(other);

	deck.~Deck();
	toAsk->~Card();
	winner1 = temp->winner1;
	winner2 = temp->winner2;
	initial = temp->initial;
	numOfTurns = temp->numOfTurns;
	players = temp->players;  //The list of the players
	deck = temp->deck;
	verbalField = temp->verbalField;
	highNField = temp->highNField;
	toAsk = temp->toAsk;
	asker = temp->asker;
	asked = temp->asked;
	return *this;

}
Game::~Game() {
	vector<Player*>::iterator it = players.begin();
	for (; it != players.end(); it++) {
		Player* curr = *it;
		delete curr;

	}
	players.clear();
	deck.~Deck();
	delete toAsk;
}

