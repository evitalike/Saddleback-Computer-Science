// Attached: HW_1a, 1b
// ===================================================
// Program: HW_1a
// ===================================================
// Programmer: Aaron Geesink
// Class: CS 1B ÅE12 pm class
// ===================================================

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	const int SIZE = 30;
	char n1[SIZE] = "Tom";
	char n2[SIZE] = "Brenda";
	char n3[SIZE] = "Ken Ben";

	fstream file("data.bin", ios::out | ios::in | ios::binary);
	if (file.fail())
	{
		cout << "Error\n";
		exit(1);
	}

	//file.read(n1, sizeof(n1));
	//cout << "Name #1:  " << n1 << endl << endl;

	//file.write(n1, sizeof(n1));
	//file.write(n2, sizeof(n2));
	//file.write(n3, sizeof(n3));

	//file.seekg(2 * sizeof(n3), ios::beg);
	//file.read(n3, sizeof(n3));
	//cout << n3 << endl;

	//file.seekp(sizeof(n1), ios::beg);

	file.seekp(0, ios::end);
	file.write(n1, sizeof(n1));

	//file.write(n2, sizeof(n2));


	file.close();

	system("pause");
	return 0;
}

// ===================================================
/* OUTPUT:

*/
// ===================================================