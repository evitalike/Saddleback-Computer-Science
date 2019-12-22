#include "ClockType.h"

ClockType::ClockType()
{
	hrs = 0;
	mins = 0;
	secs = 0;
}

ClockType::ClockType(int hrs, int mins, int secs)
{
	this->hrs = hrs;
	this->mins = mins;
	this->secs = secs;
}

ClockType::~ClockType()
{
}

void ClockType::setTime(int hrs, int mins, int secs)
{
	this->hrs = hrs;
	this->mins = mins;
	this->secs = secs;
}

void ClockType::incrementSeconds()
{
	secs = secs + 1;
	if (secs == 60)
	{
		mins = mins + 1;
		secs = 0;
	}
}

void ClockType::incrementMinutes()
{
	mins = mins + 1;
	if (mins == 60)
	{
		hrs = hrs + 1;
		mins = 0;
	}
}

void ClockType::incrementHours()
{
	hrs = hrs + 1;
}

void ClockType::printTime()
{
	cout << setfill('0') << setw(2) << hrs << ':' << setw(2) << mins << ':' << setw(2) << secs;
}

bool ClockType::areTimesEqual(ClockType clock)
{
	if ((hrs == clock.hrs) && (mins == clock.mins) && (secs == clock.secs))
		return true;
	else
		return false;
}
