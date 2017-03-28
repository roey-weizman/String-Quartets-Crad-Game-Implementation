/*
 * Improved.cpp
 *
 *  Created on: 20 בנוב 2016
 *      Author: roey_w
 */

#include "Improved.h"

Improved::Improved(Card* card): rank(1),improvedCard(card){
}
Improved::Improved(const Improved &other):rank(other.rank),improvedCard(other.improvedCard){

}
Improved& Improved::operator=(const Improved& other){
	if(this==&other)
		return *this;
	Improved* temp=new Improved(other);
	delete improvedCard;
	improvedCard=temp->improvedCard;
	rank=temp->rank;
	return *this;


}
Card* Improved::getImprovedCard(){
	return improvedCard;
}
	int Improved::getRank(){
		return rank;
	}
	void Improved:: rankUp(){
		rank=rank+1;
	}
	Improved::~Improved(){
		delete improvedCard;

	}
