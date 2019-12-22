// Attached: HW_1a, 1b
// ===================================================
// Program: HW_1a
// ===================================================
// Programmer: Aaron Geesink
// Class: CS 1B ÅE12 pm class
// ===================================================

#include "Textbook.h"
#include "Fiction.h"

void displayRetail(Book &book);

int main()
{
	Textbook textbook("C++", 10.);
	Fiction fiction("Godzilla", 10.);

	cout << "Textbook:\n";
	displayRetail(textbook);

	cout << "\nFiction:\n";
	displayRetail(fiction);

	return 0;
}
// --------------------
void displayRetail(Book &book)
{
	cout << "Retail Price:  $" << book.calcRetail() << endl << endl;
}

// ===================================================
/* OUTPUT:

*/
// ===================================================