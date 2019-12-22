// Attached: HW_4
// ===================================================
// Program: HW_4
// ===================================================
// Programmer: Aaron Geesink
// Class: CS 1B ÅE12 pm class
// ===================================================

#include "Student.h";

void addStudent(Student *&head);
void showList(Student *&head);

// ===================================================

int main()
{
	Student *head = nullptr;
	char choice = '\0';

	do
	{
		addStudent(head);

		cout << "Display all records Y/N?\t";
		cin >> choice;
		if (toupper(choice) == 'Y')
		{
			system("cls");
			showList(head);
		}

		cout << "\nDo again Y/N?\t";
		cin >> choice;
	} while (toupper(choice) == 'Y');


	system("pause");
	return 0;
}

// ===================================================

void addStudent(Student *& head)
{
	cout << "Enter a student record (-1 to quit) :\n\n";

	do
	{
		Student *temp = new Student;

		cout << right << setw(10) << "ID:\t";
		cin >> temp->id;
		if (temp->id == -1)
		{
			delete temp;
			return;
		}

		cout << setw(10) << "Name:\t";
		cin.ignore();
		cin.getline(temp->name, 30);

		cout << setw(10) << "Address:\t";
		cin.getline(temp->address, 30);

		cout << setw(10) << "City:\t";
		cin.getline(temp->city, 30);

		cout << setw(10) << "State:\t";
		cin.getline(temp->state, 30);

		cout << setw(10) << "Zip:\t";
		cin.getline(temp->zip, 30);

		cout << setw(10) << "GPA:\t";
		cin.getline(temp->gpa, 30);
		cout << endl;

		temp->next = head;
		head = temp;
	} while (true);
}

// ===================================================

void showList(Student *& head)
{
	Student *temp = head;

	do
	{
		cout << right << setw(10) << "ID:" << setw(30) << temp->id << endl;
		cout << setw(10) << "Name:" << setw(30) << temp->name << endl;
		cout << setw(10) << "Address:" << setw(30) << temp->address << endl;
		cout << setw(10) << "City:" << setw(30) << temp->city << endl;
		cout << setw(10) << "State:" << setw(30) << temp->state << endl;
		cout << setw(10) << "Zip:" << setw(30) << temp->zip << endl;
		cout << setw(10) << "GPA:" << setw(30) << temp->gpa << endl << endl;

		temp = temp->next;
	} while (temp != nullptr);
}

// ===================================================
/* OUTPUT:
Enter a student record (-1 to quit) :

	  ID:       100
	Name:       bob bill
 Address:       yeet street
	City:       RMS
   State:       CA
	 Zip:       99999
	 GPA:       4.0

	  ID:       101
	Name:       Bill bob
 Address:       Mamma mia lane
	City:       colorado
   State:       NV
	 Zip:       23567
	 GPA:       2.3

	  ID:       -1
Display all records Y/N?        y

---------------------- CLEAR -------------------------

	   ID:                           101
	 Name:                      Bill bob
  Address:                Mamma mia lane
	 City:                      colorado
	State:                            NV
	  Zip:                         23567
	  GPA:                           2.3

	   ID:                           100
	 Name:                      bob bill
  Address:                   yeet street
	 City:                           RMS
	State:                            CA
	  Zip:                         99999
	  GPA:                           4.0

Do again Y/N?   n
Press any key to continue . . .
*/
// ===================================================