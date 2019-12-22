// Attached: HW_6a, 6b, 6c, 6d, 6e
// ===================================================
// Program: HW_6a, 6b, 6c
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
	fstream dataFile;
	fstream resultsFile;
	int temp = 0;

	dataFile.open("data.txt", ios::in);
	resultsFile.open("results.txt", ios::out);

	if (dataFile.fail())
	{
		cout << "Error opening file!";
		system("pause");
		exit(1);
	}

	cout << "Here are the numbers in the file:\n";

	while (!dataFile.eof())
	{
		dataFile >> temp;
		resultsFile << temp << '\n';
		cout << temp << endl;
	}

	dataFile.close();
	resultsFile.close();
	resultsFile.open("results.txt", ios::out | ios::app);

	cout << "Enter 3 more numbers:\n";

	for (int i = 0; i < 3; i++)
	{
		cin >> temp;
		resultsFile << temp << endl;
	}


	cout << "The data has been written to results.txt.\n\n";

	resultsFile.close();

	system("pause");
	return 0;
}

// ===================================================
/* OUTPUT:
Here are the numbers in the file:
3
4
5
Enter 3 more numbers:
8
9
10
The data has been written to results.txt.

Press any key to continue . . .
*/
// ===================================================