#include "Date.h"

Date::Date()
{
	month = 0;
	day = 0;
	year = 0;
}

Date::Date(int month, int day, int year)
{
	this->month = month;
	this->day = day;
	this->year = year;
}

Date::~Date()
{
}

void Date::setDate()
{
	cout << "Month:\t";
	cin >> month;
	cout << "Day:\t";
	cin >> day;
	cout << "Year:\t";
	cin >> year;
}


// I could achieve addDays with 2 while loops, but this works fine so i'll leave it.
void Date::addDays(int days)
{
	day = days + day;

	if ((day > 30) && (day % 30 != 0))
	{
		month = month + (day / 30);
		while (day > 30)
			day = day - 30;
	}
	else if ((day > 30) && (day % 30 == 0))
	{
		month = month + (day / 30) - 1;
		while (day > 30)
			day = day - 30;
	}

	if ((month > 12) && (month % 12 != 0))
	{
		year = year + (month / 12);
		while (month > 12)
			month = month - 12;
	}
	else if ((month > 12) && (month % 12 == 0))
	{
		month = month + (day / 12) - 1;
		while (day > 12)
			day = day - 12;
	}
}

void Date::displayDate()
{
	cout << month << '/' << day << '/' << year << endl;
}
