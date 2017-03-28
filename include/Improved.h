/*
 * Improved.h
 *
 *  Created on: 20 בנוב 2016
 *      Author: roey_w
 */

#ifndef IMPROVED_H_
#define IMPROVED_H_
#include "Card.h"
class Improved {
private:
	int rank;
	Card* improvedCard;
public:
	Improved(Card* card);
	Improved(const Improved &other);
	Improved& operator=(const Improved& other);
	Card* getImprovedCard();
	int getRank();
	void rankUp();
	virtual ~Improved();
};

#endif /* IMPROVED_H_ */
