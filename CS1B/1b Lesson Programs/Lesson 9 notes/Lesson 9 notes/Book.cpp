#include "Book.h"

int Book::bookCount = 0;

Book::Book(string title, float wholesaleCost)
{
	this->title = title;
	this->wholesaleCost = wholesaleCost;
	bookCount++;
}

Book::Book()
{
	title = "";
	wholesaleCost = 0;
	bookCount++;
}

Book::~Book()
{
	bookCount--;
}

void Book::showBook()
{
	cout << "Title:\t" << title << endl
		<< "Cost\t" << wholesaleCost << endl;
}

int Book::getCount()
{
	return bookCount;
}

float Book::operator+(Book & book)
{
	return wholesaleCost + book.wholesaleCost;
}

bool Book::operator==(Book & book)
{
	if ((title == book.title) && (wholesaleCost == book.wholesaleCost))
		return true;
	else
		return false;
}

bool Book::operator>(Book & book)
{
	return wholesaleCost > book.wholesaleCost;
}

bool Book::operator>(float value)
{
	return (wholesaleCost > value);
}
