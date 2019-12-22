// Attached: HW_1a, 1b
// ===================================================
// Program: HW_1a
// ===================================================
// Programmer: Aaron Geesink
// Class: CS 1B ÅE12 pm class
// ===================================================

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	string id;
	string artist;
	string genre;

	fstream file("Music.txt", ios::in);

	cout << "File contents:\n";

	while (!file.eof())
	{
		getline(file, id, '|');
		getline(file, artist, '|');
		getline(file, genre, '|');

		cout << "ID:	" << id << endl;
		cout << "Artist:	" << artist << endl;
		cout << "Genre:	" << genre << endl << endl;
	}

	system("pause");
	return 0;
}


// ===================================================
/* OUTPUT:

*/
// ===================================================