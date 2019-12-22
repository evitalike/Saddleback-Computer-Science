// Attached: HW_9a, 9b
// ===================================================
// Program: HW_9a, 9b
// ===================================================
// Programmer: Aaron Geesink
// Class: CS 1B ÅE12 pm class
// ===================================================

#include "Book.h"

int Book::bookCount = 0;

int main()
{



	data1 + data2;

	data1.addNum(Data &data);












	Book b1("0-12345-9", 1990, 12.50);
	Book b2("0-54321-9", 2001, 7.75);
	Book b3;
	double avg;

	cout << "Here is book #1:\n";
	b1.displayBook();

	cout << "Here is book #2:\n";
	b2.displayBook();

	cout << "There are " << b1.getCount() << " books.\n\n";

	if (b1 > b2) 		  // Use this overloaded function:  bool operator>();
		cout << "Book #1 has a higher price.\n\n";
	else
		cout << "Book #1 does not have a higher price.\n\n";
	// ------------------------------
	if (b1 == b2)          // Use this overloaded function: bool operator==();
		cout << "Same price.\n\n";
	else
		cout << "Not the same price.\n\n";
	// ------------------------------
	if (b2 > 10.00)        // Use this overloaded function:  bool operator>();
		cout << "The price is more than $10.00.\n\n";
	else
		cout << "The price is not more than $10.00.\n\n";
	// ---------------
	avg = (b1 + b2) / 2.0;  // Use this overloaded function:  bool operator+();

	cout << "The average book price is " << avg << ".\n\n";
	// ---------------
	if (b1 < 2000)          // Use this overloaded function:  bool operator<();
		cout << "The book was published before 2000.\n\n";
	else
		cout << "The book was not published before 2000.\n\n";
	// ---------------
	cout << b1;             // Use this:  friend ostream& operator<<();
	// ---------------
	cout << "\nEnter Book #3 information.\n";
	cin >> b3; 		    // Use this:  friend istream& operator>>();
		// ---------------
		cout << "\nHere is what you entered for Book #3:\n";
	cout << b3; 		    // Use this:  friend ostream& operator<<();
	// ---------------

	system("pause");
	return 0;
}

// ===================================================
/* OUTPUT:
Here is book #1:
ISBN:   0-12345-9
Year:   1990
Price:  12.5

Here is book #2:
ISBN:   0-54321-9
Year:   2001
Price:  7.75

There are 3 books.

Book #1 has a higher price.

Not the same price.

The price is not more than $10.00.

The average book price is 10.125.

The book was published before 2000.

ISBN:   0-12345-9
Year:   1990
Price:  12.5


Enter Book #3 information.
ISBN:  12345
Year:  2004
Price:  7.8

Here is what you entered for Book #3:
ISBN:   12345
Year:   2004
Price:  7.8

Press any key to continue . . .
*/
// ===================================================