#ifndef CARD_DECK_CLASS_H
#define CARD_DECK_CLASS_H

class cardDeckClass
{
public:
	cardDeckClass(void);
		// Default constructor
		// The deck is sorted into a unshuffled array of cards
		// Postcondition: values in cardDeck[DECK_SIZE] are assigned
		// in order of an unshuffled array of cards;

	void performPerfectShuffle(void);
		// a cardDeckClass object is perfect shuffled
		// postCOndition: perfect shuffled cardDeckClass

	void printDeck(void);
		// the rank and suit of a cardDeckClass object are ouputted to the console.
		// Postcondition: cardDeckClass Deck[DECK_SIZE} values outputted to the console.

	bool operator==(cardDeckClass& otherDeck);
		// overloaded equality operator to compare to cardDeckClass objects
		// Postcondition: bool result of comparison.

private:
	typedef enum
	{
		CLUBS,
		DIAMONDS,
		HEARTS,
		SPADES
	} suitType;


	typedef enum
	{
		ACE,
		KING,
		QUEEN,
		JACK,
		TEN,
		NINE,
		EIGHT,
		SEVEN,
		SIX,
		FIVE,
		FOUR,
		THREE,
		TWO,
	} rankType;

	typedef struct
	{
		rankType rank;
		suitType suit;
	} cardType;

	enum { DECK_SIZE = 52 };

	cardType cardDeck[DECK_SIZE]; // a cardType array to store cards as a deck
};

#endif