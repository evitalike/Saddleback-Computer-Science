// Attached: HW_1a, 1b
// ===================================================
// Program: HW_1a
// ===================================================
// Programmer: Aaron Geesink
// Class: CS 1B ÅE12 pm class
// ===================================================

#include <iostream>
using namespace std;

const int ROWS = 3;
const int COLS = 4;

void getData(int numArray[][COLS]);
void displayArray(int numArray[][COLS]);

int main()
{
	int numArray[ROWS][COLS] = { 0 };

	getData(numArray);
	displayArray(numArray);

	system("pause");
	return 0;
}

void getData(int numArray[][COLS])
{
	cout << "Enter integers into the 2 - Dimensional array:\n\n";
	for (int row = 0; row < ROWS; row++)
	{
		for (int col = 0; col < COLS; col++)
		{
			cout << "Enter a number:\t";
			cin >> numArray[row][col];
		}
	}
}

void displayArray(int numArray[][COLS])
{
	cout << "Here is the data in the 2-Dimensional array:\n";
	for (int row = 0; row < ROWS; row++)
	{
		for (int col = 0; col < COLS; col++)
		{
			cout << numArray[row][col] << "\t";
		}
		cout << endl;
	}

}

// ===================================================
/* OUTPUT:
Enter integers into the 2 - Dimensional array:

Enter a number: 34
Enter a number: 64
Enter a number: 578
Enter a number: 9
Enter a number: 43
Enter a number: 009
Enter a number: 76
Enter a number: 34
Enter a number: 34
Enter a number: 5
Enter a number: 6
Enter a number: 7
Here is the data in the 2-Dimensional array:
34      64      578     9
43      9       76      34
34      5       6       7
Press any key to continue . . .
*/
// ===================================================