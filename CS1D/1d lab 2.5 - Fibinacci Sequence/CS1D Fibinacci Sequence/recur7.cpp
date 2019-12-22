// recur7.cpp
// A recursive function for a function having one parameter that
// generates the nth Fibonacci number.
// f(i+2)=fi+f(i+1)
#include <iostream>
#include <cmath>
using namespace std;
// The full recursive version:
unsigned long Fib1(int n);
int main()
{
	char ans;
	int N;
	do
	{
		cout << "I will display fibonacci numbers 0-N." << endl;
		cout << "Enter an limit, please. Be patient! This recursive"
			<< endl << "Fibonacci routine will take about 17 "
			<< endl << "seconds for N = 45 alone " << endl;
		cin >> N;
		for (int i = 0; i < N; i++)
			cout << Fib1(i) << endl;
		cout << "Y/y to continue, anything else quits" << endl;
		cin >> ans;
	} while ('Y' == ans || 'y' == ans);
}

unsigned long Fib1(int n)
{
	if (n == 0 || n == 1)
		return 1;
	return Fib1(n - 1) + Fib1(n - 2);
}
