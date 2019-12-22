#pragma once
#include <string>
#include <iostream>
using namespace std;

class Book
{
private:
	string title;
	float wholesaleCost;
	static int bookCount;
public:
	Book(string title, float wholesaleCost);
	Book();
	~Book();
	void showBook();
	static int getCount();
	friend bool areEqual(Book & book_1, Book & book_2);

	float operator+(Book &book);
	bool operator==(Book &book);
	bool operator>(Book &book);
	bool operator>(float value);

	friend ostream& operator<<(ostream &stream, Book &book);
	friend istream& operator>>(istream &stream, Book &book);
};