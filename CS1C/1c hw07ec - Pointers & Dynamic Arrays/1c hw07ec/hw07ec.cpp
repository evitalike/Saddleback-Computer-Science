// ===================================================
// Program: hw07 - Pointers & Dynamic Arrays
// ===================================================
// Programmer: Aaron Geesink
// Class: CS 1C - 3:00 PM M T W TH
// ===================================================

// BOTH EXTRA CREDITS INCLUDED
// see manageInventory.cpp for destructor.
// also see hw07.tar for transaction history EC

#include "ManageInventory.h"
#include <iostream>
using namespace std;

int main()
{
	cout << "Extra Credit #2 main file.\n\n";

	ManageInventory inventory(3);

	cout << "Before adding items:\n";
	inventory.addItem("Item 1", 10, 10.00);
	inventory.printInventory();

	cout << "After adding items:\n";

	inventory.addItem("Item 2", 20, 20.00);
	inventory.addItem("Item 3", 30, 30.00);
	inventory.printInventory();

	system("pause");
	return 0;
}

// ===================================================