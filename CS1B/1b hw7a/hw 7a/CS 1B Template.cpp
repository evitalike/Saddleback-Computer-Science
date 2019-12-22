// Attached: HW_7a, 7b
// ===================================================
// Program: HW_7a
// ===================================================
// Programmer: Aaron Geesink
// Class: CS 1B ÅE12 pm class
// ===================================================

#include "Date.h";

int main()
{
	Date today(3, 12, 2019);
	Date payDay;

	cout << "Enter the date of Payday:\n";
	payDay.setDate();

	cout << "Today is ";
	today.displayDate();

	cout << "Payday is ";
	payDay.displayDate();

	payDay.addDays(7);

	cout << "\nPayday seven days later is ";
	payDay.displayDate();

	system("pause");
	return 0;
}

// ===================================================
/* OUTPUT:
Enter the date of Payday:
Month:  12
Day:    28
Year:   2019
Today is 3/12/2019
Payday is 12/28/2019

Payday seven days later is 1/5/2020
Press any key to continue . . .
*/
// ===================================================