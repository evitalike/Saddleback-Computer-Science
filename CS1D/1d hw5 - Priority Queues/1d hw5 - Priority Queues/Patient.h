#ifndef PATIENT_H
#define PATIENT_H

#include <string>
#include "Clock.h"
using namespace std;

struct Patient
{
	string name;
	int waitTime;
	int treatTime;
	bool lifeThreat;
	Clock threatTime;
	Clock start;

	bool operator<(Patient const& p) const
	{
		if (lifeThreat != p.lifeThreat)
			return lifeThreat < p.lifeThreat;
		if (threatTime < p.threatTime)
			return false;
		if (p.threatTime < threatTime)
			return true;
		if (waitTime != p.waitTime)
			return waitTime < p.waitTime;
		return true;
	}

	Patient() : name{ "" }, waitTime{ 0 }, treatTime{ 0 }, lifeThreat{ false } { }
	Patient(string name, int waitTime, int hour = 0, int minute = 0, bool pm = true)
		: name{ name }, waitTime{ waitTime }, treatTime{ 0 }, lifeThreat{ false }
	{
		if (waitTime == -1)
		{
			lifeThreat = true;
			threatTime.setTime(hour, minute, 0, pm);
		}
	}
};

// comparator used to determine priority of a patient 
// using the waitTime and lifeThreat keys.
// if true is returned, then current patient has priority.
// if false is returned, then other patient has priority.
// patients with lifeThreat set to true have priority.
// if 2 patients with lifeThreat set to true are compared,
// then the patient currently being treated has priority.
struct ComparePatient 
{
	bool operator()(Patient const& p1, Patient const& p2) 
	{
		if (p1.lifeThreat != p2.lifeThreat)
			return p1.lifeThreat < p2.lifeThreat;
		if (p1.threatTime < p2.threatTime)
			return false;
		if (p2.threatTime < p1.threatTime)
			return true;
		if (p1.waitTime != p2.waitTime)
			return p1.waitTime < p2.waitTime;
		return true;
	}
};

#endif
