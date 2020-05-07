#include "Card.hpp"

Card::Card() 
{
	this->value = 1;
	this->suit = "Clubs";
}
Card::~Card()
{
	this->value = 0;
	this->suit = "";
}