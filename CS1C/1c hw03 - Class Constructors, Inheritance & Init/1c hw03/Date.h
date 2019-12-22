//Data.h, specification for the date class.

#ifndef DATE_H
#define DATE_H

#include <iostream>
using namespace std;

class Date
{
private:
	int month;
	int day;
	int year;

public:
	Date();
	// Date Default constructor
	// Postcondition: month = 0; day = 0;
	// year = 0;

	Date(int month, int day, int year);
	// Date overloaded constructor with parameters
	// postcondition: this->month = month;
	// this->day = day; this->year = year;

	void setDate(const int month, const int day, const int year);
	// Function to set the date according to paramaters.
	// postcondition: this->month = month;
	// this->day = day; this->year = year;

	friend ostream& operator<<(ostream& stream, const Date& date);
	// overloaded insertion operator to output Date to the stream location.
	// postcondition: Date object member data is outputted to the stream location.
};

#endif