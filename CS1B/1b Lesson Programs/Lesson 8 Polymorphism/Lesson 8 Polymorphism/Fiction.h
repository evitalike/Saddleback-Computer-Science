#include "Book.h"

class Fiction : public Book
{
public:
	Fiction(string title, float wholesaleCost) : Book(title, wholesaleCost)
	{

	}
	// --------------------
	~Fiction() {}
};