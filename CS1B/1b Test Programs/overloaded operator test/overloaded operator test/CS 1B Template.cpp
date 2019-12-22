// Attached: HW_1a, 1b
// ===================================================
// Program: HW_1a
// ===================================================
// Programmer: Aaron Geesink
// Class: CS 1B ÅE12 pm class
// ===================================================

#include <iostream>
#include "data.h"
using namespace std;

int main()
{
	Data d1(1);
	Data d2(2);

	cout << 1 + 3 << endl;
	cout << d1 + d2 << endl;
	cout << d1 + 4 << endl;

	cout << d1 << endl;
	showNum(d2);

	system("pause");
	return 0;
}

// ===================================================
/* OUTPUT:

*/
// ===================================================

void showNum(Data & data)
{
	cout << data.num << endl;
}
