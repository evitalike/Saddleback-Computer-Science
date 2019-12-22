// Attached: HW_8a, 8b, 8c
// ===================================================
// Program: HW_8a
// ===================================================
// Programmer: Aaron Geesink
// Class: CS 1B ÅE12 pm class
// ===================================================

#include "Bird.h"
#include "Mammal.h"

int main()
{
	Bird bird("pelican", 8.5, "gray");
	Mammal cow("dairy cow", 8.5, "black and white");

	bird.showAnimal();
	cow.showAnimal();

	system("pause");
	return 0;
}

// ===================================================
/* OUTPUT:
Birds are vertebrates in the Aves class.
This pelican has gray feathers and weighs 8.5 pounds.

Mammals are vertebrates in the Mammalia class.
This black and white dairy cow weighs 8.5 pounds.

Press any key to continue . . .
*/
// ===================================================