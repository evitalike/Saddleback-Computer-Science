// Attached: HW_1a, 1b, 1c, 1d
// ===================================================
// Program: HW_1a
// ===================================================
// Programmer: Aaron Geesink
// Class: CS 1B ÅE12 pm class
// ===================================================

#include <iostream>
#include <iomanip>
using namespace std;

float getSaleAmt();
float calcCommission(float amount);
float calcPay(float commission);
void displayPay(float amount, float commission, float pay);


int main()
{
	float amount = 0;
	float commission = 0;
	float pay = 0;
	char choice = '0';

	do
	{
		amount = getSaleAmt();
		commission = calcCommission(amount);
		pay = calcPay(commission);
	
		displayPay(amount, commission, pay);
		cout << "Do it again ? (Y / N)\t";
		cin >> choice;
		cout << endl;
	} while (toupper(choice) == 'Y');

	system("pause");
	return 0;
}

float getSaleAmt()
{
	float amount = 0;

	std::cout << "Enter the monthly sales amount:\t";
	std::cin >> amount;

	return amount;
}

float calcCommission(float amount)
{
	if (amount > 50000)
		return amount * 0.02;
	else if (amount > 25000)
		return amount * 0.015;
	else
		return 0;
}

float calcPay(float commission)
{
	return 2500 + commission;
}

void displayPay(float amount, float commission, float pay)
{
	char choice = '0';

	cout << fixed << setprecision(2) << setw(23) << left << "Monthly Sales :" << right << "$ " << amount << endl
		<< setw(23) << left << "Commission :" << right << "$ " << commission << endl
		<< setw(23) << left << "Base Pay :" << right << "$ 2500.00" << endl
		<< setw(23) << left << "Pay :" << right << "$ " << pay << endl;
}

// ===================================================
/* OUTPUT:
Enter the monthly sales amount: 60000
Monthly Sales :        $ 60000.00
Commission :           $ 1200.00
Base Pay :             $ 2500.00
Pay :                  $ 3700.00
Do it again ? (Y / N)   y

Enter the monthly sales amount: 30000
Monthly Sales :        $ 30000.00
Commission :           $ 450.00
Base Pay :             $ 2500.00
Pay :                  $ 2950.00
Do it again ? (Y / N)   n
Press any key to continue . . .
*/
// ===================================================


