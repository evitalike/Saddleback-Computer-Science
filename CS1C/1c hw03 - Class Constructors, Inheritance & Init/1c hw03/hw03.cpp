// ===================================================
// Program: hw 03 - Class Constructors, Inheritance & Init
// ===================================================
// Programmer: Aaron Geesink
// Class: CS 1C - 3:00 PM M T W TH
// ===================================================
// The purpose of this program is to demonstrate
// the usage of default and overloaded class constructors,
// create a class that inherits from a base class,
// create a member initialization list, and
// demonstrate the composition of one class as member data
// within another. This program uses the Employee class,
// which contains information about a cs1c employee,
// as well as a Programmer and Architect class,
// which extend the employee class through inheritance
// to provide more information on the employee.
// ===================================================

#include "Employee.h"
#include "Architect.h"
#include "Programmer.h"

int main()
{
	Employee e1;
	Employee e2("Joe Bob", "888-888-8888", "Therapist", 12345, 42, 100000.00, 'M', 12, 25, 1999);

	Architect a1;
	Architect a2(1234567, "Big Boss", 4, 12, "Millard Filmore", "777-867-5309", "architect", 56473, 45, 56737.00, 'M', 3, 6, 1999);

	Programmer p1;
	Programmer p2(8765432, "Big Boss", 8, true, false, "Mary Sue", "666-444-2222", "programmer", 19876, 40, 12737.00, 'F', 4, 7, 2000);

	cout << "==================================\n"
		<< "BEFORE setting values:\n\n"
		<< "Employees:\n\n"
		<< e1 << '\n'
		<< e2 << '\n'
		<< "Architects:\n\n"
		<< a1 << '\n'
		<< a2 << '\n'
		<< "Programmers:\n\n"
		<< p1 << '\n'
		<< p2 << "\n\n\n";
	
	//these 3 class Setters use a setter for each data member within the function body
	e1.setEmployee("Billy Smith", "999-999-9999", "Skydiver", 99999, 99, 9999, 'M', 9, 9, 1999);
	a1.setArchitect(4444444, "Pants Man", 4, 4, "Sally Sandwich", "444-444-4444", "Architect", 44444, 44, 444444, 'F', 4, 4, 1994);
	p1.setProgrammer(2222222, "Pants Man", 2, true, true, "Dastardly Daniel", "222-222-2222", "Programmer", 22222, 22, 220220, 'M', 2, 2, 1922);

	cout << "==================================\n"
		<< "AFTER setting values with mutator functions:\n\n"
		<< "Employees:\n\n"
		<< e1 << '\n'
		<< e2 << '\n'
		<< "Architects:\n\n"
		<< a1 << '\n'
		<< a2 << '\n'
		<< "Programmers:\n\n"
		<< p1 << '\n'
		<< p2 << "\n\n";


	system("pause");
	return 0;
}

// ===================================================