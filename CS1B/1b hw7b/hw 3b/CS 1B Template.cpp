// Attached: HW_7a, 7b
// ===================================================
// Program: HW_7b
// ===================================================
// Programmer: Aaron Geesink
// Class: CS 1B ÅE12 pm class
// ===================================================

#include "ClockType.h";

int main()
{
	ClockType myClock;
	ClockType yourClock;
	ClockType myOtherClock(0, 0, 0);

	myClock.setTime(3, 30, 0);
	yourClock.setTime(10, 0, 15);

	cout << "The time on my clock is: ";
	myClock.printTime();

	cout << "\n\nThe time on your clock is: ";
	yourClock.printTime();

	if (myClock.areTimesEqual(yourClock))
		cout << "\n\nThe times of my clock and your clock are equal.";
	else
		cout << "\n\nThe times of my clock and your clock are not equal.";

	cout << "\n\nThe time on my other clock is: ";
	myOtherClock.printTime();

	cout << "\n\nI am going to add 1 minute, 1 second, and 1 hour to my other clock.";

	myOtherClock.incrementMinutes();
	myOtherClock.incrementSeconds();
	myOtherClock.incrementHours();

	cout << "\n\nThe time on my other clock is: ";
	myOtherClock.printTime();
	cout << endl << endl;

	system("pause");
	return 0;
}

// ===================================================
/* OUTPUT:
The time on my clock is: 03:30:00

The time on your clock is: 10:00:15

The times of my clock and your clock are not equal.

The time on my other clock is: 00:00:00

I am going to add 1 minute, 1 second, and 1 hour to my other clock.

The time on my other clock is: 01:01:01

Press any key to continue . . .
*/
// ===================================================