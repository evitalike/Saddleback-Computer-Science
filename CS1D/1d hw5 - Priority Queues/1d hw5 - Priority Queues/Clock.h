#pragma once
#include <iostream>
#include <iomanip>
using namespace std;

class Clock
{
private:
	int hrs;
	int mins;
	int secs;
	bool pm;
public:
	Clock();
	Clock(int hrs, int mins, int secs, bool pm);
	~Clock();
	void setTime(int hrs, int mins, int secs, bool pm);
	void incrementSeconds();
	void incrementMinutes();
	void incrementHours();
	void printTime();

	bool operator==(const Clock& clock) const;
	bool operator==(const Clock& clock);
	bool operator<(const Clock& clock) const;
	bool operator<(const Clock& clock);

	friend ostream& operator<<(ostream& stream, const Clock& clock);
};