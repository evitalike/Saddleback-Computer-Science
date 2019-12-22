// ManageInventory class specification

#include "hw07.h"
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;
using namespace hw07;

const int MAX_SIZE = 50;

class ManageInventory
{
public:
	ManageInventory();
	// Instantiates a ManageInventory object with an amount of items equal to MAX_SIZE
	// postcondition: size = MAX_SIZE; count = 0; p_pInventoryItems = new Item*[size];

	ManageInventory(int size);
	// Instantiates a ManageInventory object with an amount of items equal to the size argument
	// postcondition: this->size = size; count = 0; p_pInventoryItems = new Item*[size];

	ManageInventory(ManageInventory & otherInv);
	// Instantiates a ManageInventory object that is a copy of anotther ManageInventory object
	// postcondition: this->size = otherInv.size; count = 0; this->p_pInventoryItems == otherInv.p_pInventoryItems;

	void printInventory();
	// Prints all items of an inventory to the console
	// postcondition: name, quantity, and cost of each items outputted to the console.

	void printTransaction();
	// Prints items purchased into a receipt
	// postcondition: receipt printed to the console.

	void purchaseItems(ManageInventory & transactionHistory);
	// asks the user to input the items they would like to purchase from the inventory and the quantity they would
	// like to purchase, then the quantities of the inventory are updated and a receipt is printed to the console.
	// postcondition: quantity of purchased items is subtracted from p_pInventoryItems. receipt print to console.

	~ManageInventory();
	// Extra Credit
	// Destructor for destroying the ManageInventory's dyanmic arrays to prevent memory leak
	// postcondition: ManageInventory object is destroyed.

	void addItem(string name, int quantity, float cost);
	// Extra Credit
	// adds a new item to p_pInventoryItems if size has not been reached.
	// postcondition: new Item struct add to p_pInventory, does nothing if count == size.

private:
	int size{ MAX_SIZE }; // the maximum number of items allowed
	int count; // the current number of items
	Item ** p_pInventoryItems; // dynamic array that points to dynamically created Item structs
};