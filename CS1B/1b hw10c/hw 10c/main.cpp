// Attached: HW_10a, b, c
// ===================================================
// Program: HW_10c
// ===================================================
// Programmer: Aaron Geesink
// Class: CS 1B ÅE12 pm class
// ===================================================

#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

int main()
{
	const int NUM_EMPLOYEES = 5;
	vector<int> hours(5);
	vector<double> wage(5);

	cout << "Enter hours worked and hourly wage of each employee:\n\n";

	for (int i = 0; i < hours.size(); i++)
	{
		cout << "Hours for Employee #" << i + 1 << ":  ";
		cin >> hours[i];
		
		cout << "Wage for Employee #" << i + 1 << ":  ";
		cin >> wage[i];
	}
	
	system("cls");

	cout << fixed << setprecision(2);

	cout << "Gross pay for each employee:\n\n";
	for (int i = 0; i < hours.size(); i++)
	{
		cout << setw(11) << "Employee #" << i + 1 << setw(5) << "$"
			<< setw(7) << wage[i] * hours[i] << endl;
	}

	cout << "\nEmployee #1 hours = " << hours[0] << "\n";
	cout << "Employee #5 hours = " << hours[4] << "\n\n";

	system("pause");
	return 0;
}

// ===================================================
/* OUTPUT:
Enter hours worked and hourly wage of each employee:

Hours for Employee #1:  1
Wage for Employee #1:  1
Hours for Employee #2:  2
Wage for Employee #2:  2
Hours for Employee #3:  3
Wage for Employee #3:  3
Hours for Employee #4:  4
Wage for Employee #4:  4
Hours for Employee #5:  5
Wage for Employee #5:  5

----------------------- SYSTEM CLEAR -----------------

Gross pay for each employee:

 Employee #1    $   1.00
 Employee #2    $   4.00
 Employee #3    $   9.00
 Employee #4    $  16.00
 Employee #5    $  25.00

Employee #1 hours = 1
Employee #5 hours = 5

Press any key to continue . . .
*/
// ===================================================