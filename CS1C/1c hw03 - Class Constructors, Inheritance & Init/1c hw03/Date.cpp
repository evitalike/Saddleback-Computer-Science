//Date.cpp, implementation of data class.

#include "Date.h"

Date::Date() : month{0}, day{0}, year{0}
{ }

Date::Date(int month, int day, int year) : month{month}, day{day}, year{year}
{ }

void Date::setDate(const int month, const int day, const int year)
{
	this->month = month;
	this->day = day;
	this->year = year;
}

ostream & operator<<(ostream & stream, const Date & date)
{
	stream << date.month << '/' << date.day << '/' << date.year;
	return stream;
}
