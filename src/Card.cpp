
#include "Card.h"


Card::Card(Shape shapeP) : shape(shapeP)
{}

Card::Card(const Card& other) : shape(other.shape)
{}

  Card::~Card(){}

	Shape Card:: getShape(){
return Card::shape;
}



string Card::getStringShape(int i){
	string s1;
	if(i==0)
			s1="C";
		else if(i==1) s1="D";
		else if(i==2) s1="H";
		else s1="S";
	return s1;
}


