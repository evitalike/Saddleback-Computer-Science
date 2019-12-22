// Attached: HW_1a, 1b
// ===================================================
// Program: HW_1a
// ===================================================
// Programmer: Aaron Geesink
// Class: CS 1B ÅE12 pm class
// ===================================================

#include "Car.h";

void deleteCar(Car *&head);
void insertCar(Car *&head);
void showList(Car *&head);

int main()
{
	Car *head = nullptr;
	int idNum = 0;
	char choice = '0';
	
	do
	{
		cout << "A to insert\n" << "B to show list\n" << "C to delete\n" << "What shall you do:\t";
		cin >> choice;
		cout << endl << "=======================================================" << endl << endl;

		switch (toupper(choice))
		{
		case 'A': insertCar(head);
			break;
		case 'B': showList(head);
			break;
		case 'C': deleteCar(head);
			break;
		default: cout << "Please enter a valid choice\n";
			break;
		}
	} while (true);

	
	showList(head);

	system("pause");
	return 0;
}

void deleteCar(Car *& head)
{
	Car *lead = head;
	Car *follow = head;
	int idNum;

	cout << "Enter the ID of the car to be deleted:\t";
	cin >> idNum;

	while (lead->id != idNum && lead->next != nullptr)
	{
		follow = lead;
		lead = lead->next;
	}

	if (lead == head)
	{
		head = head->next;
		delete lead;
	}
	else if (lead->id == idNum)
	{
		follow->next = lead->next;
		delete lead;
	}
	else
	{
		cout << "id not found in the list\n\n";
	}
}

void insertCar(Car *& head)
{
	char answer = '0';

	do
	{
		Car *temp = new Car;
		
		cout << "Enter the ID:\t";
		cin >> temp->id;
		cout << "Enter the car's model:\t";
		cin.ignore();
		getline(cin, temp->model);

		temp->next = head;
		head = temp;

		cout << "Would you like to add another car? (Y / N)\t";
		cin >> answer;
		cout << endl;
	} while (toupper(answer) == 'Y');
}

void showList(Car *& head)
{
	Car *temp = head;

	cout << "Here is the list of cars:\n";
	while (temp != nullptr)
	{
		cout << "ID:\t" << temp->id << endl;
		cout << "Model:\t" << temp->model << endl << endl;
		temp = temp->next;
	}
}

// ===================================================
/* OUTPUT:

*/
// ===================================================

