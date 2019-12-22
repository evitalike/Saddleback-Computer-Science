// Attached: HW_1a, 1b
// ===================================================
// Program: HW_1a
// ===================================================
// Programmer: Aaron Geesink
// Class: CS 1B ÅE12 pm class
// ===================================================

#include "Vehicle.h";

void insertVehicle(Vehicle *&head);
void deleteVehicle(Vehicle *&head);
void showList(Vehicle *&head);

int main()
{
	Vehicle *head = nullptr;
	char choice = '0';

	do
	{
		cout << "A to insert vehicle\n"
			<< "B to delete vehicle\n"
			<< "C to show list\n"
			<< "D to stop the program\n"
			<< "Choose your option:\t";
		cin >> choice;
		cout << endl << "===============================" << endl;
		switch (toupper(choice))
		{
			case 'A': insertVehicle(head);
				break;
			case 'B': deleteVehicle(head);
				break;
			case 'C': showList(head);
				break;
			case 'D': exit(0);
				break;
			default: cout << "Enter a valid choice";
				break;
		}
	} while (true);
	

	system("pause");
	return 0;
}

void insertVehicle(Vehicle *& head)
{
	char choice = '0';

	do {

		Vehicle *temp = new Vehicle;

		cout << "Enter the Vehicle info:\n";

		cout << "ID:\t";
		cin >> temp->id;

		cout << "model:\t";
		cin.ignore();
		getline(cin, temp->model);

		cout << "year:\t";
		cin >> temp->year;

		temp->next = head;
		head = temp;

		cout << "do it again? (Y / N):  ";
		cin >> choice;
		cout << endl;
	} while (toupper(choice) == 'Y');

}

void deleteVehicle(Vehicle *& head)
{
	Vehicle *lead = head;
	Vehicle *follow = head;
	int id = 0;

	cout << "Enter the id of the vehicle to be deleted:\t";
	cin >> id;

	while ((lead->id != id) && (lead->next != nullptr))
	{
		follow = lead;
		lead = lead->next;
	}
	
	if (lead->id != id)
		cout << "No vehicle with an id of " << id << " was found on the list\n\n";

	else if (follow == head)
	{
		head = head->next;
		delete lead;
	}

	else if (lead->id == id)
	{
		follow->next = lead->next;
		delete lead;
	}
}

void showList(Vehicle *& head)
{
	Vehicle *temp = head;

	while (temp != nullptr)
	{
		cout << "ID:\t" << temp->id << endl
			<< "model:\t" << temp->model << endl
			<< "year:\t" << temp->year << endl << endl;

		temp = temp->next;
	}

}

// ===================================================
/* OUTPUT:

*/
// ===================================================

