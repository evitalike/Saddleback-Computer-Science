// ManageInventory class Implementaion

#include "ManageInventory.h"

ManageInventory::ManageInventory() : count{ 0 }, p_pInventoryItems{ new Item*[size] } 
{ 
	for (int i = 0; i < size; i++)
	{
		p_pInventoryItems[i] = NULL;
	}
}

ManageInventory::ManageInventory(int size) : size{ size }, count{ 0 }, p_pInventoryItems{ new Item*[size] } 
{ 
	for (int i = 0; i < size; i++)
	{
		p_pInventoryItems[i] = NULL;
	}
}

ManageInventory::ManageInventory(ManageInventory & otherInv) 
	: count{ 0 }, size {otherInv.size}, p_pInventoryItems{ new Item*[size] }
{
	for (int i = 0; i < size; i++)
	{
		p_pInventoryItems[i] = NULL;
	}

	for (int i = 0; i < otherInv.count; i++)
	{
		this->addItem(otherInv.p_pInventoryItems[i]->name, otherInv.p_pInventoryItems[i]->quantity, otherInv.p_pInventoryItems[i]->cost);
	}
}

void ManageInventory::printInventory()
{
	for (int i = 0; i < count; i++)
	{
		cout << "Item Number " << i + 1 << ":\n"
			<< "name:  " << p_pInventoryItems[i]->name << "\n"
			<< "quantity:  " << p_pInventoryItems[i]->quantity << "\n"
			<< "cost:  $" << p_pInventoryItems[i]->cost << "\n\n";
	}
}

void ManageInventory::printTransaction()
{
	for (int i = 0; i < count; i++)
	{
		cout << p_pInventoryItems[i]->name << " x " << p_pInventoryItems[i]->quantity << "   $" << p_pInventoryItems[i]->cost << endl;
	}
}

void ManageInventory::purchaseItems(ManageInventory & transactionHistory)
{
	float total = 0.0;
	int itemNum;
	int quant;
	char choice = '0';

	cout << "Here is the inventory:\n";
	for (int i = 0; i < count; i++)
	{
		cout << i + 1 << ". " << p_pInventoryItems[i]->name << " ($" << p_pInventoryItems[i]->cost << ")\n\n";
	}

	ManageInventory receipt;

	do
	{
		cout << "Enter the item number of what you want to purchase:  ";
		cin >> itemNum;
		cout << "Enter quantity to purchase:  ";
		cin >> quant;
		
		total = total + p_pInventoryItems[itemNum - 1]->cost * quant;
		receipt.addItem(p_pInventoryItems[itemNum - 1]->name, quant, p_pInventoryItems[itemNum - 1]->cost * quant);
		transactionHistory.addItem(p_pInventoryItems[itemNum - 1]->name, quant, p_pInventoryItems[itemNum - 1]->cost * quant);

		p_pInventoryItems[itemNum - 1]->quantity = p_pInventoryItems[itemNum - 1]->quantity - quant;

		cout << "Purchase another item? (Y/N):  ";

		cin.ignore();
		cin.get(choice);
		cout << '\n';
	} while (toupper(choice) == 'Y');


	cout << "Here is you receipt:\n";
	receipt.printTransaction();
	cout << "Total Price:  $" << total << endl;
	cout << fixed << setprecision(2) << "Total with 8.25% tax:  $" << (total + total * 0.0825) << "\n\n";
}

ManageInventory::~ManageInventory()
{
	
	for (int i = 0; i < count; i++)
	{
		delete p_pInventoryItems[i];
	}
	
	delete[] p_pInventoryItems;
}

void ManageInventory::addItem(string name, int quantity, float cost)
{
	if (count < size)
	{
		p_pInventoryItems[count] = new Item{ name, quantity, cost };
		count++;
	}
	else
		cout << "Inventory is already at max size.";
}
