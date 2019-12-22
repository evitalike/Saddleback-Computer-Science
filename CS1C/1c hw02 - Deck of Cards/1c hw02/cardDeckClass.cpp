#include "cardDeckClass.h"
#include <string>
#include <iostream>
using namespace std;

const int SUIT_SIZE = 4;
const int RANK_SIZE = 13;

string suitString[SUIT_SIZE] = 
{
	"Clubs",
	"Diamonds",
	"Hearts", 
	"Spades" 
};

string rankString[RANK_SIZE] =
{
	"Ace",
	"King",
	"Queen",
	"Jack",
	"Ten",
	"Nine",
	"Eight",
	"Seven",
	"Six",
	"Five",
	"Four",
	"Three",
	"Two",
};

cardDeckClass::cardDeckClass(void)
{
	int cardNum = 0;

	//nested for loop to instantiate all ranks AND suits for a deck of cards
	for (int suit = CLUBS; suit <= SPADES; ++suit)
	{
		for (int rank = ACE; rank <= TWO; ++rank)
		{
			cardDeck[cardNum].suit = suitType(suit);
			cardDeck[cardNum].rank = rankType(rank);

			cardNum++;
		}
	}
}

void cardDeckClass::performPerfectShuffle(void)
{
	const int HALF_DECK_SIZE = DECK_SIZE / 2;

	cardType halfDeck1[HALF_DECK_SIZE];
	cardType halfDeck2[HALF_DECK_SIZE];

	int cardNum;
	int deckNum;

	for (cardNum = 0; cardNum < HALF_DECK_SIZE; cardNum++)
	{
		halfDeck1[cardNum] = cardDeck[cardNum];
		halfDeck2[cardNum] = cardDeck[cardNum + HALF_DECK_SIZE];
	}

	deckNum = 0;

	for (cardNum = 0; cardNum < HALF_DECK_SIZE; cardNum++)
	{
		cardDeck[deckNum] = halfDeck1[cardNum];
		deckNum++;
		cardDeck[deckNum] = halfDeck2[cardNum];
		deckNum++;
	}

	cout << "The deck has been shuffled.\n\n";
}

void cardDeckClass::printDeck(void)
{
	for (int cardNum = 0; cardNum < DECK_SIZE; cardNum++)
	{
		cout << rankString[cardDeck[cardNum].rank] << " of " << suitString[cardDeck[cardNum].suit] << '\n';
		//cout << cardDeck[cardNum].rank << " of " << cardDeck[cardNum].suit << '\n';
	}
	cout << '\n';
}

bool cardDeckClass::operator==(cardDeckClass& otherDeck)
{
	int cardNum;

	for (cardNum = 0; cardNum < DECK_SIZE; cardNum++)
	{
		//return false if any location in the decks are not equal
		if ((this->cardDeck[cardNum].suit != otherDeck.cardDeck[cardNum].suit)
			|| (this->cardDeck[cardNum].rank != otherDeck.cardDeck[cardNum].rank))
		{
			return false;
		}
	}
	//if both the decks are the same, return true;
	return true;
}