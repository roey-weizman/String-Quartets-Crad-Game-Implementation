#include "Card.h"


/*Constructors*/
NumericCard::NumericCard(int number, Shape shape) : Card(shape),number(number){

}
NumericCard::NumericCard(const NumericCard& other) : Card(other) ,number(other.number){
}

 /*Functions*/
int NumericCard:: getNumber() {
	return number;
}
 string NumericCard::toString(){
	string s1=getStringShape(getShape());
	int j =getNumber(); string s2;
	stringstream convert;
	convert << j; s2=convert.str();
	 return s2+s1;
}
 bool NumericCard:: isPure(){
 	return false;
 }

 NumericCard::~NumericCard(){};
