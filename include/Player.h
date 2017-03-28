#ifndef PLAYER_H_
#define PLAYER_H_

#include <iostream>
#include <Hand.h>
#include "Improved.h"
using namespace std;

class Player : public Hand {
private:
	const string name;
	int const type;
	int const position;
public:
	string getName();   //Returns the name of the player
	Player(Hand& handp,const string namep,int const type,int const position);
	string toStringToPlayer();
	int getType();
	int getPosition();
	virtual Card* getTheCardINeed()=0;
	virtual Player* getThePlayerToAskFrom(vector<Player*> playerList)=0;
	virtual ~Player();
};
class PlayerType1 : public Player {  //For strategy 1
private:
	vector<Improved*> myList;
public:
	PlayerType1(Hand& handp,const string namep,int const type,int const position);
	int getType();
	virtual Card* getTheCardINeed() override;
	bool findAndUpdate(Card& myCard);
	void  buildList();
	virtual Player* getThePlayerToAskFrom(vector<Player*> playerList) override;
	virtual ~PlayerType1();
	int String2Int(const string& str, int result) ;

};

class PlayerType2 : public Player {  //For strategy 2
private:
	vector<Improved*> myList;
public:
	PlayerType2(Hand& handp,const string namep,int const type,int const position);
	int getType();
	virtual Card* getTheCardINeed() override;
	bool findAndUpdate(Card& myCard);
	void buildList();
	virtual Player* getThePlayerToAskFrom(vector<Player*> playerList) override;
	virtual ~PlayerType2();
	int String2Int(const string& str, int result) ;
	};


class PlayerType3 : public Player {  //For strategy 3
private:
	int posToAsk;
public:
	int getType();
	PlayerType3(Hand& handp,const string namep,int const type,int const position);
	virtual Player* getThePlayerToAskFrom(vector<Player*> playerList) override;
	virtual Card* getTheCardINeed() override;
	virtual ~PlayerType3();
	int String2Int(const string& str, int result);

};

class PlayerType4 : public Player {  //For strategy 4
private:
	int posToAsk;
public:
	int getType();
	PlayerType4(Hand& handp,const string namep,int const type,int const position);
	virtual Player* getThePlayerToAskFrom(vector<Player*> playerList) override;
	virtual Card* getTheCardINeed() override;
	virtual ~PlayerType4();
	int String2Int(const string& str, int result);
};

#endif
