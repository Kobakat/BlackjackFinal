#ifndef Player_H
#define Player_H
#include "Card.hpp"
#include <stdlib.h>
#include <vector>


class Player
{
public:
	
	std::string name;
	std::vector<Card> hand;
	int handValue;

	Player();
	~Player();
	std::string Hit(std::vector<Card> * deck);
	std::string DisplayHand();

};

#endif