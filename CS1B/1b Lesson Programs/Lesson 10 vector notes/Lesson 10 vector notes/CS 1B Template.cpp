// Attached: HW_1a, 1b
// ===================================================
// Program: HW_1a
// ===================================================
// Programmer: Aaron Geesink
// Class: CS 1B ÅE12 pm class
// ===================================================

#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int>numbers;
	vector<int>values(10);

	cout << "Here are the values of the value vector:\n";
	for (int i = 0; i < values.size(); i++)
	{
		cout << values[i] << endl;
	}

	numbers.push_back(1);
	cout << "SIZE:\t" << numbers.size() << endl
		<< "CAPACITY:\t" << numbers.capacity() << endl << endl;

	numbers.push_back(2);
	cout << "SIZE:\t" << numbers.size() << endl
		<< "CAPACITY:\t" << numbers.capacity() << endl << endl;

	numbers.push_back(3);
	cout << "SIZE:\t" << numbers.size() << endl
		<< "CAPACITY:\t" << numbers.capacity() << endl << endl;

	numbers.push_back(4);
	cout << "SIZE:\t" << numbers.size() << endl
		<< "CAPACITY:\t" << numbers.capacity() << endl << endl;

	numbers.push_back(5);
	cout << "SIZE:\t" << numbers.size() << endl
		<< "CAPACITY:\t" << numbers.capacity() << endl << endl;

	numbers.push_back(6);
	cout << "SIZE:\t" << numbers.size() << endl
		<< "CAPACITY:\t" << numbers.capacity() << endl << endl;

	numbers.push_back(7);
	cout << "SIZE:\t" << numbers.size() << endl
		<< "CAPACITY:\t" << numbers.capacity() << endl << endl;

	cout << "Here are the vector values:\n";
	for (int i = 0; i < numbers.size(); i++)
	{
		cout << numbers[i] << endl;
	}
	cout << endl << "Front:\t" << numbers.front() << endl;
	cout << "Back:\t" << numbers.back() << endl << endl;

	numbers.resize(5);

	cout << "Here are the vector values after resize:\n";
	for (int i = 0; i < numbers.size(); i++)
	{
		cout << numbers[i] << endl;
	}

	//numbers.clear();
	cout << endl << "After numbers are cleared:\n";
	cout << "SIZE:\t" << numbers.size() << endl
		<< "CAPACITY:\t" << numbers.capacity() << endl << endl;

	// --------------------------------------------------

	vector<int>::iterator it;

	it = numbers.begin();
	numbers.insert(it + 4, 55);

	cout << "Here are the vector values after insert:\n";
	for (int i = 0; i < numbers.size(); i++)
	{
		cout << numbers[i] << endl;
	}

	system("pause");
	return 0;
}

// ===================================================
/* OUTPUT:

*/
// ===================================================