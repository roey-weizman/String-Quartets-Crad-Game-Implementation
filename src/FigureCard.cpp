#include "Card.h"

/*Constructors*/
FigureCard::FigureCard(Figure figure, Shape shape) : Card(shape),figure(figure){

}
FigureCard::FigureCard(const FigureCard& other) : Card(other) ,figure(other.figure){
}
Figure J =Jack;
Figure Q=Queen;
Figure K=King;
Figure A=Ace;

/*Functions*/
 string FigureCard:: toString() {
	 string s1=getStringShape(getShape());
	 if (FigureCard:: figure == J)
		return "J"+s1;
	else if (FigureCard::figure == Q)
		return "Q"+s1;
	else if (FigureCard::figure  == K)
		return "K"+s1;
	else
		return "A"+s1;

}
Figure FigureCard:: getFigure() {
	return (figure);
}
bool FigureCard:: isPure(){
	return true;
}
FigureCard::~FigureCard(){};
