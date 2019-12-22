// Attached: HW_10a, b, c
// ===================================================
// Program: HW_10a
// ===================================================
// Programmer: Aaron Geesink
// Class: CS 1B ÅE12 pm class
// ===================================================

#include "algorithm.h";

int main()
{
	cout << "The greater value of 1 and 2 = " << max(1, 2);

	cout << "\n\nThe greater value of 2 and 1 = " << max(2, 1);

	cout << "\n\nThe greater value of 'a' and 'z' = " << max('a', 'z');

	cout << "\n\nThe greater value of 3.14 and 2.72 = " << max(3.14, 2.72);

	cout << "\n\nThe greater value of 6 and 6 = ";
	max(6, 6); 
	cout << "\n\n";

	system("pause");
	return 0;
}

// ===================================================
/* OUTPUT:
The greater value of 1 and 2 = 2

The greater value of 2 and 1 = 2

The greater value of 'a' and 'z' = z

The greater value of 3.14 and 2.72 = 3.14

The greater value of 6 and 6 = neither

Press any key to continue . . .
*/
// ===================================================