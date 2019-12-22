// Attached: HW_5b
// ===================================================
// Program: HW_5b
// ===================================================
// Programmer: Aaron Geesink
// Class: CS 1B ÅE12 pm class
// ===================================================

#include <iostream>
using namespace std;

void showEvens(int values[], const int SIZE, int index, int count);

int main()
{
	const int SIZE = 10;
	int values[SIZE] = { 2, 5, 7 ,8, 12, 14, 17, 18, 22, 23, };

	showEvens(values, SIZE, 0, 0);
	cout << endl;

	system("pause");
	return 0;
}

void showEvens(int values[], const int SIZE, int index, int count)
{
	if (index == SIZE)
	{
		cout << "Here are the " << count << " even numbers:\n";
		return;
	}
	else if (values[index] % 2 == 0)
	{
		showEvens(values, SIZE, index + 1, count + 1);
		cout << values[index] << '\t';
	}
	else
		showEvens(values, SIZE, index + 1, count);
}

// ===================================================
/* OUTPUT:
Here are the 6 even numbers:
22      18      14      12      8       2
Press any key to continue . . .
*/
// ===================================================

