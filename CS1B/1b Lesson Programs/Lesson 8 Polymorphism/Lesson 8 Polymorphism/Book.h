#include <iostream>
#include <string>
using namespace std;

#ifndef BOOK_H
#define BOOK_H

class Book
{
protected:
	string title;
	float wholesaleCost;
public:
	Book(string title, float wholesaleCost)
	{
		this->title = title;
		this->wholesaleCost = wholesaleCost;
	}
	// --------------
	virtual ~Book() {}
	// --------------
	virtual float calcRetail()
	{
		return 1.5 * wholesaleCost;
	}
};
#endif