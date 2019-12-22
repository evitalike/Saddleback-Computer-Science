// Attached: HW_1a, 1b, 1c, 1d
// ===================================================
// Program: HW_1c
// ===================================================
// Programmer: Aaron Geesink
// Class: CS 1B ÅE12 pm class
// ===================================================

#include <iostream>
using namespace std;

void getTemps(float temps[]);
float calcAvg(float temps[]);
void displayAvg(float avg);

int main()
{
	const int SIZE = 3;
	float temps[SIZE] = { 0 };
	float avg = 0;

	getTemps(temps);
	avg = calcAvg(temps);
	displayAvg(avg);

	system("pause");
	return 0;
}

void getTemps(float temps[])
{
	cout << "Enter temperatures of 3 cities.\n";
	cout << "#1:\t";
	cin >> temps[0];
	cout << "#2:\t";
	cin >> temps[1];
	cout << "#3:\t";
	cin >> temps[2];
}

float calcAvg(float temps[])
{
	float avg = (temps[0] + temps[1] + temps[2]) / 3;
	return avg;
}

void displayAvg(float avg)
{
	cout << "The average temperature is " << avg << " degrees.\n";
}

// ===================================================
/* OUTPUT:
Enter temperatures of 3 cities.
#1:     55.0
#2:     67.4
#3:     35.6
The average temperature is 52.6667 degrees.
Press any key to continue . . .
*/
// ===================================================