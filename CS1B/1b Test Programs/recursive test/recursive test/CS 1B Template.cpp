// Attached: HW_1a, 1b
// ===================================================
// Program: HW_1a
// ===================================================
// Programmer: Aaron Geesink
// Class: CS 1B ÅE12 pm class
// ===================================================

#include <iostream>
#include <ctime>
using namespace std;

int factorial(int n);
long int fib(int n);

int main()
{
	int n = 45;
	clock_t start;
	clock_t end;

	start = clock();
	cout << factorial(n) << endl;
	end = clock();
	cout << "Factorial took " << (end - start) / CLK_TCK << " seconds.\n";

	start = clock();
	cout << fib(n) << endl;
	end = clock();
	cout << "fib took " << (end - start) / CLK_TCK << " seconds.\n";


	system("pause");
	return 0;
}

int factorial(int n)
{
	if (n < 2)
		return 1;
	
	return n * factorial(n - 1);

	return 0;
}

long int fib(int n)
{
	if (n == 1 || n == 2)
		return 1;

	return fib(n - 1) + fib(n - 2);
}

// ===================================================
/* OUTPUT:

*/
// ===================================================