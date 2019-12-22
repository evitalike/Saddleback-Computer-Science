// Attached: HW_1a, 1b
// ===================================================
// Program: HW_1a
// ===================================================
// Programmer: Aaron Geesink
// Class: CS 1B ÅE12 pm class
// ===================================================

#include "Book.h";

//bool areEqual(Book &book_1, Book &book_2); not necessary, prototype is in Book.h

int main()
{
	Book b1("Ulysses", 15.00);
	Book b2("Old Man and the Sea", 15.00);
	float totalCost = 0;

	cout << "There are " << Book::getCount() << " Books.\n\n";
	
	if (areEqual(b1, b2))
		cout << "They are the same price." << endl << endl;
	else
		cout << "They are not the same price." << endl << endl;

	cout << "Here is book number 1:\n";
	cout << b1; //overloaded insertion operator

	cout << "Here is book number 2:\n";
	cout << b2; //overloaded insertion operator

	cin >> b1; //overloaded extraction operator

	totalCost = b1 + b2; //the + operator is overloaded, allowing for additional functionality

	cout << "Total cost is $" << totalCost << endl << endl;

	if (b1 == b2) //overloaded eqalutiy operator
	{
		cout << "They have the same title and price.\n\n";
	}
	else
		cout << "They do not have the same title and price.\n\n";

	if (b1 > b2) //overloaded greater than operator
		cout << "Book 1 costs more than book 2\n\n";
	else
		cout << "Book 1 does not cost more than book 2\n\n";

	if (b1 > 20) //Another overloaded greater than operator with float as an argument rather than a Book object.
		cout << "Book 1 costs more than $20\n\n";
	else
		cout << "Book 1 does not cost more than $20\n\n";


	system("pause");
	return 0;
}

// ===================================================
/* OUTPUT:

*/
// ===================================================

bool areEqual(Book & book_1, Book & book_2)
{
	return (book_1.wholesaleCost == book_2.wholesaleCost);
}

ostream & operator<<(ostream & stream, Book & book)
{
	stream << "Title:\t" << book.title << endl
		<< "Cost:\t" << book.wholesaleCost << endl << endl;

	return stream;
}

istream & operator>>(istream & stream, Book & book)
{
	cout << "Title:\t";
	getline(stream, book.title);
	cout << "Cost:\t";
	stream >> book.wholesaleCost;

	return stream;
}
