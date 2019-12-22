// Attached: HW_1a, 1b
// ===================================================
// Program: HW_1a
// ===================================================
// Programmer: Aaron Geesink
// Class: CS 1B E12 pm class
// ===================================================

#include <iostream>
#include <list>
using namespace std;

int main()
{
	list<int>numbers;

	numbers.push_front(1);
	numbers.push_front(2);
	numbers.push_front(3);

	numbers.push_back(4);
	numbers.push_back(5);
	numbers.push_back(6);

	cout << "SIZE:\t" << numbers.size() << "\n\n";

	cout << "Here is a list of numbers:\n";
	for (list<int>::iterator it = numbers.begin(); it != numbers.end(); it++)
	{
		cout << *it << '\t';
	}
	cout << "\n\n";

	cout << "Here is a list of numbers in reverse:\n";
	for (list<int>::reverse_iterator it = numbers.rbegin(); it != numbers.rend(); it--)
	{
		cout << *it << '\t';
	}
	cout << "\n\n";

	//--------------------------------------------------------------

	cout << "Front:\t" << numbers.front() << endl
		<< "Back:\t" << numbers.back() << "\n"
		<< "Size:\t" << numbers.size() << "\n\n";

	numbers.pop_front();
	cout << "Front after pop_front:\t" << numbers.front() << endl
		<< "Size after pop_front:\t" << numbers.size() << "\n\n";

	

	system("pause");
	return 0;
}

// ===================================================
/* OUTPUT:

*/
// ===================================================