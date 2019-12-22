#pragma once
#include <string>
#include <iostream>
using namespace std;

class Book
{
private:
	string isbn;
	int year;
	double price;
	static int bookCount;
public:
	Book();
	Book(string isbn, int year, double price);
	~Book();
	void displayBook();
	int getCount();

	bool operator>(Book &book);
	bool operator==(Book &book);
	bool operator>(double price);
	double operator+(Book &book);
	bool operator<(int year);
	friend ostream& operator<<(ostream &stream, Book &book);
	friend istream& operator>>(istream &stream, Book &book);

};