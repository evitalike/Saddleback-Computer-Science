#include "Book.h"

class Textbook : public Book
{
public:
	Textbook(string title, float wholesaleCost) : Book(title, wholesaleCost)
	{

	}
	// --------------------
	~Textbook() {}
	// --------------------
	virtual float calcRetail()
	{
		return 2 * wholesaleCost;
	}
};