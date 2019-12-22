// Attached: HW_5a, 5b
// ===================================================
// Program: HW_5a
// ===================================================
// Programmer: Aaron Geesink
// Class: CS 1B ÅE12 pm class
// ===================================================

#include <iostream>
using namespace std;

void decToBinary(int num);

int main()
{
	int num = 0;

	cout << "Enter a non-negative integer value:\t";
	cin >> num;
	cout << "Decimal " << num ;
	decToBinary(num);

	cout << "\n\n";

	system("pause");
	return 0;
}

void decToBinary(int num)
{
	if (num < 0)
	{
		cout << " = Invalid entry";
		return;
	}
	else if (num == 0)
	{
		cout << " = Binary ";
		return;
	}
	else if (num % 2 == 1)
	{
		decToBinary(num / 2);
		cout << "1";
	}
	else
	{
		decToBinary(num / 2);
		cout << "0";
	}
}

// ===================================================
/* OUTPUT:
Enter a non-negative integer value:     128
Decimal 128 = Binary 10000000

Press any key to continue . . .

------------------------------------------------------

Enter a non-negative integer value:     19
Decimal 19 = Binary 10011

Press any key to continue . . .

------------------------------------------------------

Enter a non-negative integer value:     -1
Decimal -1 = Invalid entry

Press any key to continue . . .

*/
// ===================================================


