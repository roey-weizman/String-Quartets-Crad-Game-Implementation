
#include "Player.h"


Player::Player(Hand& handp,const string namep,int const type,int const position):Hand(handp),name(namep),type(type),position(position){

}
string  Player:: getName(){
	return Player::name;
}

string Player::toStringToPlayer(){
return name+": "+toString();
}
int Player::getType(){
	return type;
}
Player::~Player(){
}
int Player::getPosition(){
	return position;
}
