#ifndef CARD_H_
#define CARD_H_

#include <iostream>

#include <string>

#include <sstream>

using namespace std;

enum Shape {
	Club,
	Diamond,
	Heart,
	Spade
};

enum Figure {
	Jack,
	Queen,
	King,
	Ace
};

class Card {
private:
	Shape shape;
public:
	Card(Shape shape);
	Card(const Card& other);
	virtual string toString() = 0; //Returns the string representation of the card "<value><shape>" exp: "12S" or "QD"
	Shape getShape();
	string getStringShape(int i);
  virtual bool isPure( ) = 0;
   virtual ~Card();
};

class FigureCard : public Card {
private:
	Figure figure;
public:
	FigureCard(Figure figure, Shape shape);
	FigureCard(const FigureCard& other);
	virtual string toString() override;
	Figure getFigure();
	virtual bool  isPure( );
	virtual ~FigureCard();
};

class NumericCard : public Card {
private:
	int number;
public:
	NumericCard(int number, Shape shape);
	NumericCard(int number);
	NumericCard(const NumericCard& other);
	virtual string toString() override;
	int getNumber();
	virtual bool  isPure();
	 virtual ~NumericCard();

};
#endif
