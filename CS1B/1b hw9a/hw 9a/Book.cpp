#include "Book.h"

Book::Book()
{
	isbn = "";
	year = 0;
	price = 0.0;
	bookCount++;
}

Book::Book(string isbn, int year, double price)
{
	this->isbn = isbn;
	this->year = year;
	this->price = price;
	bookCount++;
}

Book::~Book()
{
	bookCount--;
}

void Book::displayBook()
{
	cout << "ISBN:\t" << isbn << endl
		<< "Year:\t" << year << endl
		<< "Price:\t" << price << endl << endl;
}

int Book::getCount()
{
	return bookCount;
}

bool Book::operator>(Book & book)
{
	return (price > book.price);
}

bool Book::operator==(Book & book)
{
	return (price == book.price);
}

bool Book::operator>(double price)
{
	return (this->price > price);
}

double Book::operator+(Book & book)
{
	return price + book.price;
}

bool Book::operator<(int year)
{
	return (this->year < year);
}

ostream & operator<<(ostream & stream, Book & book)
{
	stream << "ISBN:\t" << book.isbn << endl
		<< "Year:\t" << book.year << endl
		<< "Price:\t" << book.price << endl << endl;

	return stream;
}

istream& operator>>(istream& stream, Book& book)
{
	cout << "ISBN:  ";
	stream >> book.isbn;
	cout << "Year:  ";
	stream >> book.year;
	cout << "Price:  ";
	stream >> book.price;

	return stream;
}
