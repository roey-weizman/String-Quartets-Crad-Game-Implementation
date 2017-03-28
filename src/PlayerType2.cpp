#include "Player.h"

PlayerType2::PlayerType2(Hand& handp,const string namep,int const type,int const position):Player(handp,namep,type,position),myList(){
}
int PlayerType2::getType(){
	return 2;
}
int PlayerType2::String2Int(const string& str, int result) {
	std::istringstream ss(str);
	ss.imbue(std::locale::classic());
	ss >> result;
	return result;
}
bool PlayerType2:: findAndUpdate(Card& myCard){
	bool flag=false; string s1= myCard.toString();
 	for (unsigned int i=0; i< myList.size()&&flag==false; i++) {

		 		string s2=myList[i]->getImprovedCard()->toString();
		 		if(s1.substr(0,s1.size()-1)== s2.substr(0,s2.size()-1)){
		 			myList[i]->rankUp(); return true;
		 		}

		 	  }
		 	return false;
}
void PlayerType2:: buildList(){
	vector<Improved*>::iterator it = myList.begin();
				 	for (; it != myList.end(); it++) {
				 		Improved* curr = *it;
				 		delete curr;
				 	}myList.clear();
				 	for (unsigned int i=0; i< getMyHand().size(); i++) {
			 		if(findAndUpdate(*getMyHand()[i])==false){
			 			string s = getMyHand()[i]->toString();
			 			string s1 = s.substr(0, s.size() - 1);
			 			string s2 = s.substr(s.size() - 1, 1);
			 			Card* c;
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
			 				int d=String2Int(s1,d);
			 				c = new NumericCard(d, e);
			 			}
			 			Improved* a=new Improved(c);
			 			myList.push_back(a);
			 	  }
				 	}}
/*to return the a pointer to the card that appeared the most in the player's hand */
Card* PlayerType2:: getTheCardINeed(){
	buildList();
	int min = getNumberOfCards()+1;
	Card* c;
	int d=0;
	for (unsigned int i=0; i< myList.size(); i++) {
		if (min > myList[i]->getRank()) {
			min = myList[i]->getRank();
			c = myList[i]->getImprovedCard();
		}
		else if (min == myList[i]->getRank()) {
			bool flag = compare(c, myList[i]->getImprovedCard());
			if (flag == true)
				c = myList[i]->getImprovedCard();
		}
	}

	string s = c->toString();
		string s1 = s.substr(0, s.size() - 1);
		string s2 = s.substr(s.size() - 1, 1);
		Card* ans;
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

			ans = new FigureCard(f, e);

		} else {
			
			ans= new NumericCard(String2Int(s1,d), e);
		}


	return ans;
}
Player* PlayerType2::getThePlayerToAskFrom(vector<Player*> playerList ){//for player1 the one with most cards
	Player* ans;
	string s=getName();
	int max=0; int currPos=0;
	vector<Player*>::iterator it = playerList.begin();
	for (; it !=playerList.end(); it++) {
		Player* curr = *it;
		if (curr->getName()!=s&&curr->getNumberOfCards() >max) {
			max=curr->getNumberOfCards() ;
			ans=curr;currPos=curr->getPosition();}
		if((curr->getName()!=s&&curr->getNumberOfCards() ==max&&curr->getPosition()>currPos))
			ans=curr;currPos=curr->getPosition();
		}


return ans;
}
PlayerType2::~PlayerType2(){
	vector<Improved*>::iterator it = myList.begin();
			 	for (; it != myList.end(); it++) {
			 		Improved* curr = *it;
			 		delete curr;
			 	  }
}
