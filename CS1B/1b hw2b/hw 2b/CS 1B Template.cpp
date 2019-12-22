// Attached: HW_2a, 2b, 2c, 2d
// ===================================================
// Program: HW_2b
// ===================================================
// Programmer: Aaron Geesink
// Class: CS 1B ÅE12 pm class
// ===================================================

#include <iostream>
using namespace std;

void getInfo(char street[], char city[], char state[], char zip[]);
void displayAddress(char address[]);

int main()
{
	char street[30] = { 0 };
	char city[20] = { 0 };
	char state[3] = { 0 };
	char zip[6] = { 0 };
	char address[60] = { 0 };
	char choice = '0';

	do
	{
		getInfo(street, city, state, zip);

		strcat_s(address, street);
		strcat_s(address, ", ");
		strcat_s(address, city);
		strcat_s(address, ", ");
		strcat_s(address, state);
		strcat_s(address, ", ");
		strcat_s(address, zip);

		displayAddress(address);

		cout << "Do you want to run the program again (Y / N)?\t";
		cin >> choice;
	} while (toupper(choice) == 'Y');

	system("pause");
	return 0;
}

void getInfo(char street[], char city[], char state[], char zip[])
{
	cout << "Enter your street address :\t";
	cin.getline(street, 30);
	cout << "Enter your city :\t";
	cin.getline(city, 20);
	cout << "Enter your state(2 digits) :\t";
	cin.getline(state, 3);
	cout << "Enter your 5 - digit zip code :\t";
	cin.getline(zip, 6);
	cout << endl;
}

void displayAddress(char address[])
{
	cout << "Your full address is:\n"
		<< "\t" << address << endl;
}

// ===================================================
/* OUTPUT:
Enter your street address :     7737 Mill Run
Enter your city :       Higgity Swiggity
Enter your state(2 digits) :    CA
Enter your 5 - digit zip code : 98989

Your full address is:
		7737 Mill Run, Higgity Swiggity, CA, 98989
Do you want to run the program again (Y / N)?   n
Press any key to continue . . .
*/
// ===================================================


