#pragma once
#include <iostream>
#include <iomanip>
using namespace std;

class ClockType
{
private:
	int hrs;
	int mins;
	int secs;
public:
	ClockType();
	ClockType(int hrs, int mins, int secs);
	~ClockType();
	void setTime(int hrs, int mins, int secs);
	void incrementSeconds();
	void incrementMinutes();
	void incrementHours();
	void printTime();
	bool areTimesEqual(ClockType clock);
};