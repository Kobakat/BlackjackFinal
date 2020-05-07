#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <ctime>
#include <string>
#include "Card.hpp"
#include "Player.hpp"


//Returns a vector of 52 cards randomly shuffled
std::vector<Card> GenerateDeck() 
{
	std::vector<Card> newDeck;

	for (int i = 0; i < 13; i++)
	{
		for (int j = 0; j < 4; j++) 
		{
			Card newCard;
			switch (j) 
			{
				case 0:
					newCard.suit = " of Clubs";
					break;
				case 1:
					newCard.suit = " of Spades";
					break;
				case 2:
					newCard.suit = " of Hearts";
					break;
				case 3:
					newCard.suit = " of Diamonds";
					break;
			}
			newCard.value = i + 1;
			if (newCard.value > 10) 
			{
				newCard.value = 10;
			}

			newDeck.push_back(newCard);
		}
	}
	
	for (int i = 0; i < 52; i++) 
	{
		int j = i + std::rand() % (52-i);
		std::swap(newDeck[i], newDeck[j]);
	}
	return newDeck;
}

std::string Prompt() 
{
	return "Enter 'h' to hit or any other key to stay: ";
}

int main() 
{
	Player player;
	player.name = "Player";
	Player dealer;
	dealer.name = "Dealer";
	srand(time(0));


	std::vector<Card> deck = GenerateDeck();

	std::cout << player.Hit(&deck) << std::endl;
	std::cout << player.Hit(&deck) << std::endl;
	std::cout << dealer.Hit(&deck) << std::endl;
	std::cout << dealer.Hit(&deck) << std::endl;
	std::cout << std::endl;
	std::cout << "Press enter to continue" << std::endl;
	std::cin.get();
	std::cout << player.DisplayHand() << std::endl;

	char reloop;

	std::cout << Prompt();
	std::cin >> reloop;

	while (reloop == 'h' && player.handValue < 21) 
	{
		std::cout << "\n";
		std::cout << player.Hit(&deck) << std::endl;

		if (player.handValue == 21)
		{
			std::cout << "\n";
			std::cout << "You got a hand of 21, you win!";
			return 0;
		}

		else if (player.handValue > 21)
		{
			std::cout << "\n";
			std::cout << "You drew a hand over 21, you bust!";
			return 0;
		}

		std::cout << player.DisplayHand() << std::endl;
		std::cout << Prompt();
		std::cin >> reloop;
	}

	std::cout << "\n";
	std::cout << "The dealer will now begin to draw, Press enter to continue";
	std::cin.get();
	std::cin.get();
	while (dealer.handValue <= 16) 
	{
		std::cout << "\n";
		std::cout << dealer.Hit(&deck) << std::endl;
		std::cout << "\n";
		std::cout << dealer.DisplayHand() << std::endl;
		std::cout << "Press enter to continue" << std::endl;
		std::cin.get();
	}

	if (dealer.handValue > 21) 
	{
		std::cout << "\n";
		std::cout << "The dealer busts, you win!";
		return 0;
	}

	else if (dealer.handValue < player.handValue) 
	{
		std::cout << "\n";
		std::cout << "You drew a better hand than the dealer, you win!";
		return 0;
	}

	else if (dealer.handValue > player.handValue)
	{
		std::cout << "\n";
		std::cout << "The dealer drew a better hand than you, you lose!";
		return 0;
	}

	else 
	{
		std::cout << "\n";
		std::cout << "You two drew an equal hand, the dealer wins by default.";
		return 0;
	}

	return 0;
}