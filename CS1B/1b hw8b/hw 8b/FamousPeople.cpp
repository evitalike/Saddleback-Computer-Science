#include "FamousPeople.h"

FamousPeople::FamousPeople() : Date()
{
	name = "";
	quote = "";
}

FamousPeople::~FamousPeople()
{
}

void FamousPeople::setName(string name)
{
	this->name = name;
}

void FamousPeople::setQuote(string quote)
{
	this->quote = quote;
}

void FamousPeople::setDate(int month, int day, int year)
{
	birthDate.setDate(month, day, year);
}

void FamousPeople::displayPerson()
{
	cout << "Name:\t" << name << '\n'
		<< "Birth Date:\t";
	birthDate.displayDate();
	cout << "\nQuotation:\n" << quote << "\n\n";
}

void FamousPeople::displayDate()
{
	birthDate.displayDate();
}
