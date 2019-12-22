// Attached: HW_8a, 8b, 8c
// ===================================================
// Program: HW_8b
// ===================================================
// Programmer: Aaron Geesink
// Class: CS 1B ÅE12 pm class
// ===================================================

#include "FamousPeople.h";

void setPerson(FamousPeople & person);

int main()
{
	FamousPeople p1;
	FamousPeople p2;
	FamousPeople p3;

	cout << "Enter the first famous person:\t";
	setPerson(p1);

	cout << "Enter the second famous person:\t";
	cin.ignore();
	setPerson(p2);

	cout << "Enter the third famous person:\t";
	cin.ignore();
	setPerson(p3);

	cout << "Here are the famous people:\n\n";

	p1.displayPerson();
	p2.displayPerson();
	p3.displayPerson();
	
	system("pause");
	return 0;
}

void setPerson(FamousPeople & person)
{
	string temp = "";
	int month = 0;
	int day = 0;
	int year = 0;

	getline(cin, temp);
	person.setName(temp);

	cout << "\nEnter the quotation:\n";
	getline(cin, temp);
	person.setQuote(temp);

	cout << "\nEnter the birth date:\n"
		<< "Month:\t";
	cin >> month;
	cout << "Day:\t";
	cin >> day;
	cout << "Year:\t";
	cin >> year;
	person.setDate(month, day, year);
	
	system("cls");
}

// ===================================================
/* OUTPUT:
Enter the first famous person:  Aaron Geesink

Enter the quotation:
I'm a radical dude.

Enter the birth date:
Month:  7
Day:    25
Year:   2000

======================= CLEAR ========================

Enter the second famous person: Garrett Geesink

Enter the quotation:
I'm slightly less radical than Aaron

Enter the birth date:
Month:  7
Day:    25
Year:   2000

======================= CLEAR ========================

Enter the third famous person:  DaVinci

Enter the quotation:
I have from an early age abjured the use of meat, and the time will come when men such as I will look upon the murder of animals as they now look upon the murder of men.

Enter the birth date:
Month:  4
Day:    15
Year:   1452

======================= CLEAR ========================

Here are the famous people:

Name:   Aaron Geesink
Birth Date:     7/25/2000
Quotation:
I'm a radical dude.

Name:   Garrett Geesink
Birth Date:     7/25/2000
Quotation:
I'm slightly less radical than Aaron

Name:   DaVinci
Birth Date:     4/15/1452
Quotation:
I have from an early age abjured the use of meat, and the time will come when men such as I will look upon the murder of animals as they now look upon the murder of men.

Press any key to continue . . .
*/
// ===================================================