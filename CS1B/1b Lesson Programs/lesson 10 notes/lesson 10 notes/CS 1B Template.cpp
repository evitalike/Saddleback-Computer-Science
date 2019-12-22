// Attached: HW_1a, 1b
// ===================================================
// Program: HW_1a
// ===================================================
// Programmer: Aaron Geesink
// Class: CS 1B ÅE12 pm class
// ===================================================

class Something {};

#include <iostream>
using namespace std;

int getDenom();
int divide(int num, int denom);

int main()
{
	int num = 4;
	int denom = 0;
	int result = 0;

	try
	{
		denom = getDenom();
	}
	catch (const char *message)
	{
		cout << message;

		system("pause");
		exit(1);
	}
	cout << "The result is " << result << ".\n\n";
	
	system("pause");
	return 0;
}

int getDenom()
{
	int denom;

	cout << "Enter a denominator:\t";
	cin >> denom;
	
	if (!cin)
	{
		throw "Error. Invalid entry.\n\n";
	}

	return denom;
}

int divide(int num, int denom)
{
	if (denom == 0)
	{
		throw Something();
	}
	return num / denom;
}

// ===================================================
/* OUTPUT:

*/
// ===================================================