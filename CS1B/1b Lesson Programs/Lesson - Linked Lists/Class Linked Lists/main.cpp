// Attached: HW_1a, 1b
// ===================================================
// Program: HW_1a
// ===================================================
// Programmer: Aaron Geesink
// Class: CS 1B ÅE12 pm class
// ===================================================

#include <iostream>
#include "StudentList.h"
using namespace std;

int main()
{
	char answer = 'Y';
	StudentList list;

	while (answer == 'Y')
	{
		list.insertStudent();
		
		cout << "Enter another student? (Y / N):";
		cin >> answer;
	}

	system("pause");
	return 0;
}

// ===================================================
/* OUTPUT:

*/
// ===================================================