#include "Player.h"

PlayerType4::PlayerType4(Hand& handp,const string namep,int const type,int const position):Player(handp,namep,type,position),posToAsk(){
	posToAsk=1;
}
int PlayerType4::getType(){
	return 4;
}

 Player* PlayerType4::getThePlayerToAskFrom(vector<Player*> playerList){
	 if (posToAsk == this->getPosition()) {
	 		if((unsigned int)posToAsk==playerList.size()){
	 			posToAsk=2;
	 			return playerList[0];
	 		}else  {int j=posToAsk;
	 			posToAsk=((posToAsk+2)%playerList.size());
	 			if(posToAsk==0)
	 				posToAsk=playerList.size();
	 		return playerList[j];
	 		}
	 	}
	 	else {
	 		if((unsigned int)posToAsk==playerList.size()){
	 			int k =posToAsk-1;
	 			posToAsk=1;
	 			return playerList[k];
	 		}else {int y=posToAsk-1;
	 		posToAsk=posToAsk+1;
	 		return playerList[y];

	 		}

	 	}
	 }
 int PlayerType4::String2Int(const string& str, int result) {
 	std::istringstream ss(str);
 	ss.imbue(std::locale::classic());
 	ss >> result;
 	return result;
 }
 Card* PlayerType4::getTheCardINeed(){
	 Card* c=getMyHand()[0];
	 for (unsigned int i=1; i< getMyHand().size(); i++) {
	 		Card* curr = getMyHand()[i];
	 		if(compare(c,curr))
	 			c=curr;
	 	}
		string s = c->toString();
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

			} else {int d =0;
				c = new NumericCard(String2Int(s1,d), e);
			}

	 return c;
 }
 PlayerType4::~PlayerType4(){

 }


