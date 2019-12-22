// Attached: HW_2a, 2b, 2c, 2d
// ===================================================
// Program: HW_2a
// ===================================================
// Programmer: Aaron Geesink
// Class: CS 1B ÅE12 pm class
// ===================================================

#include <iostream>
using namespace std;

void displayInfo(int age, char fullName[]);

int main()
{
	char firstName[10] = "Aaron";
	char lastName[10] = { 0 };
	char fullName[20] = { 0 };
	int age = 0;

	cout << "Enter your age:\t";
	cin >> age;
	cin.ignore();

	cout << "Enter the last name:\t";
	cin.getline(lastName, 10);

	strcat_s(fullName, firstName);
	strcat_s(fullName, " ");
	strcat_s(fullName, lastName);

	displayInfo(age, fullName);

	system("pause");
	return 0;
}

void displayInfo(int age, char fullName[])
{
	cout << "Hello " << fullName << ". You are " << age << " years old\n";
}


// ===================================================
/* OUTPUT:
Enter your age: 18
Enter the last name:    Geesink
Hello Aaron Geesink. You are 18 years old
Press any key to continue . . .
*/
// ===================================================

