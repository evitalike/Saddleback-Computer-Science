// Attached: HW_1a, 1b
// ===================================================
// Program: HW_1a
// ===================================================
// Programmer: Aaron Geesink
// Class: CS 1B ÅE12 pm class
// ===================================================

#include "Auto.h";
#include "Cycle.h";

int main()
{
	Auto myCar(12345, "Kia Rio", 4);
	Cycle cycle(54321, "Kawasaki", true);

	cout << "My car:\n";
	myCar.showVehicle();

	cout << "\n\nCycle:\n";
	cycle.showVehicle();

	system("pause");
	return 0;
}

// ===================================================
/* OUTPUT:

*/
// ===================================================