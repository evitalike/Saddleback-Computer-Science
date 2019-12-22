#pragma once
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
	Date(int month, int day, int year);
	~Date();
	void setDate();
	void addDays(int days);
	void displayDate();
};