// Attached: HW_1a, 1b
// ===================================================
// Program: HW_1a
// ===================================================
// Programmer: Aaron Geesink
// Class: CS 1B ÅE12 pm class
// ===================================================

#include <iostream>
using namespace std;

int getID();
void searchNumbers(int idNumbers[], const int SIZE, int id);

int main()
{
	const int SIZE = 5;
	int idNumbers[SIZE] = { 12345, 54321, 11223, 33211, 44411 };
	int id = 0;
	char choice = '0';

	do
	{
		id = getID();
		searchNumbers(idNumbers, SIZE, id);

		cout <<"Search for a new number? (Y / N)\t";
		cin >> choice;
		cout << endl;
	} while (toupper(choice) == 'Y');

	system("pause");
	return 0;
}

int getID()
{
	int id = 0;

	cout << "Enter an id number to be searched:\t";
	cin >> id;

	return id;
}

void searchNumbers(int idNumbers[], const int SIZE, int id)
{
	for (int i = 0; i < SIZE; i++)
	{
		if (idNumbers[i] == id)
		{
			cout << "id has been found at index number " << i << "!\n";
			return;
		}
	}
	cout << "The desired number could not be found in the list.\n";
}

// ===================================================
/* OUTPUT:
Enter an id number to be searched:      12345
id has been found at index number 0!
Search for a new number? (Y / N)        y

Enter an id number to be searched:      44411
id has been found at index number 4!
Search for a new number? (Y / N)        y

Enter an id number to be searched:      34567
The desired number could not be found in the list.
Search for a new number? (Y / N)        n

Press any key to continue . . .
*/
// ===================================================


