// Attached: HW_10a, b, c
// ===================================================
// Program: HW_10b
// ===================================================
// Programmer: Aaron Geesink
// Class: CS 1B ÅE12 pm class
// ===================================================

#include <iostream>
#include <vector>
using namespace std;

void displayVector(vector<int> values);

int main()
{
	vector<int> values;

	values.push_back(1);
	values.push_back(2);
	values.push_back(4);
	values.push_back(9);
	values.push_back(5);
	displayVector(values);

	values.insert(values.begin(), 3);
	displayVector(values);

	values.erase(values.begin());
	displayVector(values);

	values.pop_back();
	displayVector(values);

	cout << "There are " << values.size() << " values.\n\n";

	system("pause");
	return 0;
}

void displayVector(vector<int> values)
{
	cout << "Vector:  ";
	for (int i = 0; i < values.size(); i++)
	{
		cout << values[i] << "  ";
	}
	cout << "\n\n";
}

// ===================================================
/* OUTPUT:
Vector:  1  2  4  9  5

Vector:  3  1  2  4  9  5

Vector:  1  2  4  9  5

Vector:  1  2  4  9

There are 4 values.

Press any key to continue . . .
*/
// ===================================================