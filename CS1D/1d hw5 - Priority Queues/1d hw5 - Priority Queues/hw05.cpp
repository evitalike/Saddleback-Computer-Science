// ===================================================
// Program: Assignment 5 - Priority Queues
// ===================================================
// Programmer: Aaron Geesink
// Class: CS 1D - 5:00 PM M W
// ===================================================
// The Purpose of this Assignment is to demonstrate
// The use of a priority queue to simulate treating
// patients in an afternoon at a hospital. Part 1 uses a
// custom heap based priority queue to handle the patients,
// and part two uses the STL priority queue with a comparator for patients.
// ===================================================

#include <iostream>
#include <queue>
#include <iomanip>
#include "Patient.h"
#include "Clock.h"
#include "PriorityQueue.h"
using namespace std;

int main()
{
	cout << "===================================================\n"
		<< "Program: Assignment 5 - Priority Queues\n"
		<< "===================================================\n"
		<< "Programmer: Aaron Geesink\n"
		<< "Class: CS 1D - 5:00 PM M W\n"
		<< "==================================================="
		<< "\nThe Purpose of this Assignment is to demonstrate"
		<< "\nThe use of a priority queue to simulate treating"
		<< "\npatients in an afternoon at a hospital. Part 1 uses a"
		<< "\ncustom heap based priority queue to handle the patients,"
		<< "\nand part two uses the STL priority queue with a comparator for patients."
		<< "\n===================================================\n\n";

	// -----------------------Data setup------------------------------------

	// setting up patient data
	vector<Patient> patients;
	Patient patient;
	Patient urgent;
	// clock starts at 12:00:00 PM
	Clock time(12, 0, 0, true);

	// Critical patients have a waiting time of -1
	patients.push_back(Patient("Bob Bleeding", 6));
	patients.push_back(Patient("Frank Feelingbad", 3));
	patients.push_back(Patient("Cathy Coughing", 5));
	patients.push_back(Patient("Paula Pain", 4));
	patients.push_back(Patient("Alice Ailment", 7));
	patients.push_back(Patient("Irene Ill", 1));
	patients.push_back(Patient("Tom Temperature", 8));
	patients.push_back(Patient("Sam Sneezing", -1, 1, 34, true));
	patients.push_back(Patient("Sid Sickly", -1, 2, 12, true));

	// ================================== Part 1 ==================================
	cout << "============== Part 1: Custom Priority Queue ===========\n";
	PriorityQueue<Patient> patientQueue1;
	PriorityQueue<Patient> urgentQueue1;

	// All patients are sorted onto the priority queue 
	// based on their wait time and urgency
	for (int i = 0; i < patients.size(); i++)
	{
		if (patients[i].waitTime < 0)
			urgentQueue1.push(patients[i]);
		else
			patientQueue1.push(patients[i]);
	}

	if (!patientQueue1.empty())
		patient = patientQueue1.top();
	if (!urgentQueue1.empty())
		urgent = urgentQueue1.top();

	// Driver to treat patients after being put onto the priority queue.
	while (!patientQueue1.empty())
	{
		
		// put an urgent patient on the top of the queue if they become life threatening
		if (urgent.threatTime == time)
		{
			patientQueue1.pop();
			patientQueue1.push(patient);
			patientQueue1.push(urgent);
			patient = urgent;
			patient.start = time;

			urgentQueue1.pop();
			if (!urgentQueue1.empty())
				urgent = urgentQueue1.top();
		}

		// take a patient off of the queue once they reach 25 minutes
		if (patient.treatTime == 25)
		{
			// display the patient details to the console
			cout << setfill(' ') << setw(16) << patient.name << " - Start: " << patient.start 
				<< " - End: " << time << endl;

			patientQueue1.pop();
			if (!patientQueue1.empty())
			{
				patient = patientQueue1.top();
				if (patient.treatTime == 0)
					patient.start = time;
			}
		}

		// increment the patient's total time treated as well as the time of the clock
		patient.treatTime = patient.treatTime + 1;
		time.incrementMinutes();
	}

	// ================================== Part 2 ==================================
	cout << "\n============== Part 2: STL Priority Queue ==============\n";

	priority_queue<Patient, vector<Patient>, ComparePatient> patientQueue2;
	priority_queue<Patient, vector<Patient>, ComparePatient> urgentQueue2;
	time.setTime(12, 0, 0, true);

	// All patients are sorted onto the priority queue 
	// based on their wait time and urgency
	for (int i = 0; i < patients.size(); i++)
	{
		if (patients[i].waitTime < 0)
			urgentQueue2.push(patients[i]);
		else
			patientQueue2.push(patients[i]);
	}

	if (!patientQueue2.empty())
		patient = patientQueue2.top();
	if (!urgentQueue2.empty())
		urgent = urgentQueue2.top();

	// Driver to treat patients after being put onto the priority queue.
	while (!patientQueue2.empty())
	{

		// put an urgent patient on the top of the queue if they become life threatening
		if (urgent.threatTime == time)
		{
			patientQueue2.pop();
			patientQueue2.push(patient);
			patientQueue2.push(urgent);
			patient = urgent;
			patient.start = time;

			urgentQueue2.pop();
			if (!urgentQueue2.empty())
				urgent = urgentQueue2.top();
		}

		// take a patient off of the queue once they reach 25 minutes
		if (patient.treatTime == 25)
		{
			// display the patient details to the console
			cout << setfill(' ') << setw(16) << patient.name << " - Start: " << patient.start
				<< " - End: " << time << endl;

			patientQueue2.pop();
			if (!patientQueue2.empty())
			{
				patient = patientQueue2.top();
				if (patient.treatTime == 0)
					patient.start = time;
			}
		}

		// increment the patient's total time treated as well as the time of the clock
		patient.treatTime = patient.treatTime + 1;
		time.incrementMinutes();
	}

	system("pause");
	return 0;
}

// ===================================================