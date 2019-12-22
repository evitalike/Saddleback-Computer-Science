// Attached: HW_6a, 6b, 6c, 6d, 6e
// ===================================================
// Program: HW_6d, 6e
// ===================================================
// Programmer: Aaron Geesink
// Class: CS 1B ÅE12 pm class
// ===================================================

#include "Cat.h";

int main()
{
	Cat cat;
	fstream file;
	
	file.open("critters.bin", ios::app | ios::binary);
	cout << "Enter 3 cat records.\n";

	for (int i = 0; i < 3; i++)
	{
		cout << "Enter information about a cat:\n";

		cout << "NAME:\t";
		cin.getline(cat.name, 20);

		cout << "AGE:\t";
		cin >> cat.age;
		cin.ignore();

		file.write(reinterpret_cast<char *>(&cat), sizeof(cat));
	}
	
	cout << "Record written to file.\n\n";

	cout << "Enter one more cat\n";
	cout << "NAME:\t";
	cin.getline(cat.name, 20);

	cout << "AGE:\t";
	cin >> cat.age;

	file.write(reinterpret_cast<char *>(&cat), sizeof(cat));
	file.close();
	
	cout << "\nHere is a list of all cats:\n";
	file.open("critters.bin", ios::in | ios::binary);

	for (int i = 0; i < 4; i++)
	{
		file.seekg(sizeof(Cat)*i, ios::beg);
		file.read(reinterpret_cast<char *>(&cat), sizeof(cat));

		cout << left << setw(10) << cat.name;
		cout << cat.age << endl;
	}
	file.close();

	system("pause");
	return 0;
}

// ===================================================
/* OUTPUT:
Enter 3 cat records.
Enter information about a cat:
NAME:   fluffy
AGE:    3
Enter information about a cat:
NAME:   bob
AGE:    4
Enter information about a cat:
NAME:   jannet
AGE:    5
Record written to file.

Enter one more cat
NAME:   jerry
AGE:    6

Here is a list of all cats:
fluffy    3
bob       4
jannet    5
jerry     6
Press any key to continue . . .
*/
// ===================================================