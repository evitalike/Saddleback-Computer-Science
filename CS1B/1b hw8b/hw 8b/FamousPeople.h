#pragma once
#include "Date.h"

class FamousPeople : public Date
{
private:
	string name;
	string quote;
	Date birthDate;

public:
	FamousPeople();
	~FamousPeople();
	void setName(string name);
	void setQuote(string quote);
	void setDate(int month, int day, int year);
	void displayPerson();
	void displayDate();
};