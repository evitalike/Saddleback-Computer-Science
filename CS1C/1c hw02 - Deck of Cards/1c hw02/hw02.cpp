// ===================================================
// Program: hw 02 - Deck of Cards
// ===================================================
// Programmer: Aaron Geesink
// Class: CS 1C
// ===================================================
// the purpse of this assignment is to practice
// creating classes with private and public data,
// overloaded operators, and slightly complex organization.
// ===================================================

#include "cardDeckClass.h"
#include <iostream>
using namespace std;

int main()
{
	cardDeckClass Deck;
	cardDeckClass unshuffledDeck;
	int numShuffles = 0;

	cout << "Here is the deck before shuffling:\n\n";
	Deck.printDeck();

	Deck.performPerfectShuffle();
	cout << "Here is the deck after shuffling once:\n\n";
	numShuffles++;
	Deck.printDeck();

	cout << "Shufflng the deck until it returns to original configuration\n"
		<< "Uses the equality operator in a while loop:\n\n";
	while (!(Deck == unshuffledDeck))
	{
		Deck.performPerfectShuffle();
		numShuffles++;
	}

	cout << "Total number of shuffles:  " << numShuffles << "\n\n";

	cout << "Here's the deck after " << numShuffles << " Perfect Shuffles:\n\n";
	Deck.printDeck();

	return 0;
}

// ===================================================