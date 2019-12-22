// ===================================================
// Program: hw 04 - Friend Functions & Operator Overloading
// ===================================================
// Programmer: Aaron Geesink
// Class: CS 1C - 3:00 PM M T W TH
// ===================================================
// The purpose of this program is to demonstrate usage of 
// friends functions of a class as well as the overloading
// of operators, including the extraction and insertion operators
// so that they may be used with user defined classes.
// in this case, employee objects were able to be compared
// using the equality operator, added using the addition
// operator, outputted to the console with the insertion operator,
// and changed by the user using the extraction operator.
// ===================================================

// EXTRA CREDIT AT THE BOTTOM

#include "Employee.h"
#include "Architect.h"
#include "Programmer.h"

int main()
{
	Employee employee("Joe Bob", "888-888-8888", "Therapist", 12345, 42, 100000.00, 'M', 12, 25, 1999);
	Programmer programmer(8765432, "Big Boss", 8, true, false, "Mary Sue", "666-444-2222", "programmer", 19876, 40, 12737.00, 'F', 4, 7, 2000);

	cout << "Here are the two employee's information:\n";
	cout << employee << endl;
	cout << programmer << endl;


	cout << "Comparing the employee phone numbers:\n";
	if (compareEmployeePhone(employee, programmer))
		cout << "The Phone Numbers for the two employee's are the same.\n\n";
	else
		cout << "The Phone Numbers for the two employee's are different.\n\n";


	employee.setPhone("666-444-2222");
	cout << "Joe Bob's phone has been set to 666-444-2222\n"
		<< "Comparing the employee phone numbers again:\n";
	if (compareEmployeePhone(employee, programmer))
		cout << "The Phone Numbers for the two employee's are the same.\n\n";
	else
		cout << "The Phone Numbers for the two employee's are different.\n\n";


	cout << "Now testing the phone numbers with overloaded equality operator:\n";
	if (employee == programmer)
		cout << "The Phone Numbers for the two employee's are the same.\n\n";
	else
		cout << "The Phone Numbers for the two employee's are different.\n\n";


	employee.setPhone("777-777-7777");
	cout << "Joe Bob's phone has been set to 777-777-7777\n"
		<< "Comparing the employee phone numbers again:\n";
	if (employee == programmer)
		cout << "The Phone Numbers for the two employee's are the same.\n\n";
	else
		cout << "The Phone Numbers for the two employee's are different.\n\n";
	
	cout << "adding age to Joe Bob by three:\n";
	employee.addAge(3);
	cout << employee << endl;

	cout << "adding age to Joe Bob by 2 using overloaded addition operator:\n";
	employee + 2;
	cout << employee << endl;

	cout << "Changing Joe Bob's data using overloaded insertion operator:\n";
	cin >> employee;

	cout << "\nHere is the new data:\n";
	cout << employee << endl;


	cout << "EXTRA CREDIT:\n"
		<< "Adding to employee's age using the pre-increment operator:\n";
	cout << ++employee << endl;

	cout << "Now Adding to employee's age using the post-increment operator:\n";
	cout << employee++ << endl;

	cout << "And Here is the age after the post increment resolves:\n";
	cout << employee;

	// The post-increment operator has more overhead because it must instantiate a temp
	// variable to be returned on top of the normal assignment of the variables.

	system("pause");
	return 0;
}

// ===================================================