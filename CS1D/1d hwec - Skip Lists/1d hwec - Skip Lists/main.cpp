// ===================================================
// Program: Extra Credit - Skip Lists
// ===================================================
// Programmer: Aaron Geesink
// Class: CS 1D - 5 PM class
// ===================================================
/* The purpose of this assignment is to demonstrate the use
of randomly generated skip lists to generate a dictionary.
the program makes use of a skip list with a 50% chance for
a value to be inserted at any given level of the list, and
can have up to five levels. */
// ===================================================

#include "SkipList.h"
using namespace std;

int main()
{
	Skip_list sl;

	// There is a 50% chance for a value to move up a level.
	// The first time it fails a probabilty roll, the highest
	// level of the value is the total number of successful rolls
	cout << "Inserting values and testing Random numbers:\n";
	sl.insert(18, "Laguna Niguel");
	sl.insert(41, "Mission Viejo");
	sl.insert(22, "San Clemente");
	sl.insert(44, "Irvine");
	sl.erase(41);
	sl.erase(42);
	sl.insert(58, "Lake Forest");
	sl.insert(32, "San Diego");
	sl.insert(49, "Anaheim");
	sl.erase(58);
	sl.insert(31, "Los Angeles");
	sl.insert(17, "Orange");
	sl.insert(72, "Palm Springs");
	sl.insert(41, "Riverside");
	sl.erase(72);
	sl.insert(19, "Brea");
	sl.insert(60, "Santa Ana");
	sl.insert(35, "Tustin");
	sl.insert(103, "Oceanside");
	sl.insert(11, "La Jolla");
	sl.insert(18, "Del Mar");
	sl.insert(22, "Aliso Viejo");
	sl.insert(49, "Laguna Beach");
	sl.erase(41);
	sl.insert(42, "Vista");
	sl.insert(49, "San Diego");
	sl.insert(99, "San Juan");
	sl.insert(29, "Dana Point");
	sl.insert(88, "El Segundo");
	sl.insert(41, "San Clemente");
	sl.insert(62, "Laguna Hills");

	cout << "\nDictionary contents:\n";
	sl.print();

	cout << "\nfunction tests:\n";
	cout << "===Find function===\n"
		<< "The value for key 99 is " << *sl.find(99);

	cout << "\n\n===FindAll function===\n"
		<< "Finding all values with the key 22:\n";
	sl.findAll(22);

	cout << "\n===size function===\n"
		<< "Number of items in list: " << sl.size() << "\n\n";

	cout << "===empty function===\n";
	if (sl.empty() == false)
		cout << "The list is not empty\n\n";
	else
		cout << "The list is empty\n\n";

	cout << "===Begin and End iterators===\n"
		<< "Here are the keys in the list:\n";
	sl.printKeys();

	cout << "\n\n===erase function===\n"
		<< "Here are the keys after erasing key 11:\n";
	sl.erase(sl.begin());
	sl.printKeys();

	cout << "\n\n";
	system("pause");
	return 0;
}