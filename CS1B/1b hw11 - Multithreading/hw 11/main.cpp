// Attached: HW_1a, 1b
// ===================================================
// Program: HW_1a
// ===================================================
// Programmer: Aaron Geesink
// Class: CS 1B ÅE12 pm class
// ===================================================

#include <ctime>		// ctime is part of the standard library
#include <iostream>
#include <fstream>
#include <cmath>
#include <thread>
using namespace std;

void writeRoots();
void writeSquares();

int main()
{					
	clock_t start;
	clock_t end;
	

	cout << "Starting clock\n\n";
	start = clock();

	cout << "writing 1,000,000 square roots\n\n";
	thread thread1(writeRoots);

	cout << "Writing 1,000,000 squares\n\n";
	thread thread2(writeSquares);

	thread2.join();
	thread1.join();

	end = clock();

	// CLK_TCK is part of <ctime> and returns the time in seconds.
	cout << "Runtime = " << (end - start) / CLK_TCK << " seconds.\n\n";

	system("pause");
	return 0;
}

void writeRoots()
{
	ofstream outfile;
	outfile.open("roots.txt");

	for (int i = 0; i < 1000000; i++)
	{
		outfile << sqrt(i);
	}
	outfile.close();
	cout << "The square roots are ready\n\n";
}

void writeSquares()
{
	ofstream outfile;
	outfile.open("squares.txt");
	for (int i = 0; i < 1000000; i++)
	{
		outfile << (i * i);
	}
	outfile.close();
	cout << "The squares are ready\n\n";
}

// ===================================================
/* OUTPUT without threads:
Starting clock

writing 1,000,000 square roots

The square roots are ready

Writing 1,000,000 squares

The squares are ready

Runtime = 7 seconds.

Press any key to continue . . .
------------------------------------------------------
OUTPUT with threads:
Starting clock

writing 1,000,000 square roots

Writing 1,000,000 squares

The squares are ready

The square roots are ready

Runtime = 5 seconds.

Press any key to continue . . .

*/
// ===================================================

