// Attached: HW_1a, 1b, 1c, 1d
// ===================================================
// Program: HW_1b
// ===================================================
// Programmer: Aaron Geesink
// Class: CS 1B ÅE12 pm class
// ===================================================

#include <iostream>
using namespace std;

void getTemps(float &temp1, float &temp2, float &temp3);
float calcAvg(float temp1, float temp2, float temp3);
void displayAvg(float avg);

int main()
{
	float temp1 = 0;
	float temp2 = 0;
	float temp3 = 0;
	float avg = 0;

	getTemps(temp1, temp2, temp3);
	avg = calcAvg(temp1, temp2, temp3);
	displayAvg(avg);

	system("pause");
	return 0;
}

void getTemps(float & temp1, float & temp2, float & temp3)
{
	cout << "Enter temperatures of 3 cities.\n";
	cout << "#1:\t";
	cin >> temp1;
	cout << "#2:\t";
	cin >> temp2;
	cout << "#3:\t";
	cin >> temp3;
}

float calcAvg(float temp1, float temp2, float temp3)
{
	float avg = (temp1 + temp2 + temp3) / 3;
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
#2:     71.5
#3:     68.0
The average temperature is 64.8333 degrees.
Press any key to continue . . .
*/
// ===================================================