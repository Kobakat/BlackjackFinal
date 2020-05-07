#include "Player.hpp"

Player::Player()
{
	this->name = "Player";
	this->hand;
	this->handValue = 0;
}

Player::~Player() 
{
	this->name = "";
	this->hand.clear();
	this->handValue = 0;
}

//Draw a card from a deck into the players hand; pops the deck card
std::string Player::Hit(std::vector<Card> * deck) 
{
	this->handValue += deck->back().value;
	this->hand.push_back(deck->back());
	
	std::string output;
	output = this->name + " draws a " + std::to_string(deck->back().value) + deck->back().suit;

	deck->pop_back();
	return output;
}

//Display to console the players hand and total value
std::string Player::DisplayHand() 
{
	std::string output;

	output += this->name + "'s hand is: \n";

	for (int i = 0; i < this->hand.size(); i++) 
	{
		output += std::to_string(this->hand[i].value) + this->hand[i].suit + "\n";
	}
	output += this->name +" value is: " + std::to_string(this->handValue);

	return output;
}