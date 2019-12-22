#include "Clock.h"

Clock::Clock()
{
	hrs = 12;
	mins = 0;
	secs = 0;
	pm = true;
}

Clock::Clock(int hrs, int mins, int secs, bool pm)
{
	this->hrs = hrs;
	this->mins = mins;
	this->secs = secs;
	this->pm = true;
}

Clock::~Clock() { }

void Clock::setTime(int hrs, int mins, int secs, bool pm)
{
	this->hrs = hrs;
	this->mins = mins;
	this->secs = secs;
	this->pm = pm;
}

void Clock::incrementSeconds()
{
	secs = secs + 1;
	if (secs == 60)
	{
		mins = mins + 1;
		secs = 0;
		if (mins == 60)
		{
			hrs = hrs + 1;
			mins = 0;
			if (hrs == 12)
				pm = !pm;
			if (hrs == 13)
				hrs = 1;
		}
	}
}

void Clock::incrementMinutes()
{
	mins = mins + 1;
	if (mins == 60)
	{
		hrs = hrs + 1;
		mins = 0;
		if (hrs == 12)
			pm = !pm;
		if (hrs == 13)
			hrs = 1;
	}
}

void Clock::incrementHours()
{
	hrs = hrs + 1;
	if (hrs == 12)
		pm = !pm;
	if (hrs == 13)
		hrs = 1;
}

void Clock::printTime()
{
	cout << setfill('0') << setw(2) << hrs << ':' << setw(2) << mins << ':' << setw(2) << secs << " ";
	if (pm)
		cout << "PM";
	else
		cout << "AM";
}

bool Clock::operator==(const Clock& clock) const
{
	return ((hrs == clock.hrs) && (mins == clock.mins) && (secs == clock.secs) && (pm == clock.pm));
}

bool Clock::operator==(const Clock & clock)
{
	return ((hrs == clock.hrs) && (mins == clock.mins) && (secs == clock.secs) && (pm == clock.pm));
}

bool Clock::operator<(const Clock & clock) const
{
	if (pm != clock.pm)
		return pm < clock.pm;
	if (hrs != clock.hrs)
		return hrs < clock.hrs;
	if (mins != clock.mins)
		return mins < clock.mins;
	if (secs != clock.secs)
		return secs < clock.secs;
	return false;
}

bool Clock::operator<(const Clock & clock)
{
	if (pm != clock.pm)
		return pm < clock.pm;
	if (hrs != clock.hrs)
		return hrs < clock.hrs;
	if (mins != clock.mins)
		return mins < clock.mins;
	if (secs != clock.secs)
		return secs < clock.secs;
	return false;
}

ostream & operator<<(ostream & stream, const Clock & clock)
{
	stream << setfill('0') << setw(2) << clock.hrs << ':' << setw(2) << clock.mins << ':' << setw(2) << clock.secs << " ";
	if (clock.pm)
		stream << "PM";
	else
		stream << "AM";
	return stream;
}
