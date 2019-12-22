// ===================================================
// Program: hw07 - Pointers & Dynamic Arrays
// ===================================================
// Programmer: Aaron Geesink
// Class: CS 1C - 3:00 PM M T W TH
// ===================================================

// BOTH EXTRA CREDITS INCLUDED
// transaction history at bottom of main
// also see hw07ec.tar for other EC.

#include "ManageInventory.h"
#include <iostream>
using namespace std;

int main()
{
	cout << "Extra Credit included.\n\n";
	ManageInventory inv1(6);
	ManageInventory transactionHistory;

	inv1.addItem("Nike basketball shoes", 22, 145.99);
	inv1.addItem("Under Armour t-shirt", 33, 29.99);
	inv1.addItem("Brooks running shoes", 11, 111.44);
	inv1.addItem("Asics running shoes", 20, 165.88);
	inv1.addItem("Nike shorts", 77, 45.77);

	cout << "Here are the details of the inventory:\n\n";
	inv1.printInventory();

	inv1.purchaseItems(transactionHistory);

	cout << "Here are the details of the inventory:\n\n";
	inv1.printInventory();
	
	ManageInventory inv2(inv1);

	cout << "\n\nHere are the details of the copied inventory:\n\n";
	inv2.printInventory();

	inv1.purchaseItems(transactionHistory);

	cout << "Here is a history of all previous transactions:\n\n";
	transactionHistory.printTransaction();

	ManageInventory transactionHistoryCopy(transactionHistory);
	cout << "Here is a copy of the transaction history:\n\n";
	transactionHistoryCopy.printTransaction();

	system("pause");
	return 0;
}

// ===================================================