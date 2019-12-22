// ===================================================
// Program: hw 01 - Random Numbers
// ===================================================
// Programmer: Aaron Geesink
// Class: CS 1C - 3:00 PM class
// ===================================================
// TODO: The goal of this program is to review various
// c++ techniques. This program creates a random
// number and performs math operations to it, 
// reads and writes to a file, passes an array to a function
// by reference, and sorts an array of integers.
// ===================================================

#include <iostream>
#include <random>
#include <string>
#include <fstream>
#include <algorithm>
#include <ctime>
using namespace std;

int generateRandomNum();
// this function returns a randomly generated number between 1 and 1000
// Postcondition: returns a random int variable between 1 and 1000

int sumDigits(int num);
// this function sums the the digits of a number less than 1000
// Postcondition: returns int sum = ones + tens + hundreds

int reverseDigits(int num);
// this function reverses the digits of a number less than 1000;
// Postcondition: returns an int of the reverse argument

void readFile();
// this function reads the array located in the resource file "file.txt"
// Postcondition: values in "file.txt" are outputted to the console

void printIntArray(int nums[], const int SIZE);
// this function reads an array of integers to the screen
// Postcondition: int num[] is outputted to the console

int main()
{
	// =================== PART A ========================
	srand(time(NULL));
	int randNum = generateRandomNum();

	cout << "The random number is:  " << randNum << "\n\n";
	cout << "The sum of the number's digits is:  " << sumDigits(randNum) << "\n\n";
	cout << randNum << " times 3 is:  " << randNum * 3 << "\n\n";
	cout << randNum << " in reverse is:  " << reverseDigits(randNum) << "\n\n";

	// =================== PART B ========================
	enum { ZERO, ONE, TWO, THREE };
	int enumNum = ONE;

	typedef const long int constLongInt;
	constLongInt NUMBER = 100;

	string words = "Hello World";


	// =================== PART C ========================
	const int SIZE = 10;
	int intArray[SIZE] = { 0 };

	for (int i = 0; i < SIZE; i++)
	{
		intArray[i] = generateRandomNum();
	}

	// =================== PART D ========================
	int n = sizeof(intArray) / sizeof(intArray[0]);
	sort(intArray, intArray + n);

	cout << "Here is a random array of size " << SIZE << " after being sorted:\n";
	printIntArray(intArray, SIZE);
	cout << endl;

	// =================== PART E ========================
	ofstream fout;

	fout.open("file.txt");
	for (int i = 0; i < n; ++i)
		fout << intArray[i] << endl;
	fout.close();

	// =================== PART F ========================
	cout << "Here is the array read from a file:\n";
	readFile();
	cout << endl;

	// =================== PART G ========================
	cout << "Here is the array read from a function:\n";
	printIntArray(intArray, SIZE);
	cout << endl;

	system("pause");
	return 0;
}

// =============== Function Defintions ==========

int generateRandomNum()
{
	return rand() % 999 + 1;
}

int sumDigits(int num)
{
	int ones;
	int tens;
	int hundreds;
	int sum;

	ones = num % 10;
	tens = (num % 100 - ones) / 10;
	hundreds = (num % 1000 - tens - ones) / 100;

	sum = ones + tens + hundreds;
	return sum;
}

int reverseDigits(int num)
{
	int ones = 0;
	int tens = 0;
	int hundreds = 0;
	int sum = 0;

	ones = num % 10;
	tens = (num % 100 - ones);
	hundreds = (num % 1000 - ones - tens);

	if (num > 99)
	{
		ones = ones * 100;
		hundreds = hundreds / 100;
	}
	else if (num > 9)
	{
		ones = ones * 10;
		tens = tens / 10;
	}

	sum = ones + tens + hundreds;
	return sum;

}

void readFile()
{
	int num = 0;
	ifstream fin;

	fin.open("file.txt");
	while (fin >> num)
	{
		cout << num << endl;
	}

}

void printIntArray(int nums[], const int SIZE)
{
	for (int i = 0; i < SIZE; i++)
	{
		cout << nums[i] << '\n';
	}
}

// ================== OUTPUT ====================
/*
The random number is : 223

The sum of the number's digits is:  7

223 times 3 is : 669

223 in reverse is : 322

Here is a random array of size 10 after being sorted :
45
132
155
386
500
545
656
825
882
996

Here is the array read from a file :
45
132
155
386
500
545
656
825
882
996

Here is the array read from a function :
45
132
155
386
500
545
656
825
882
996
Press any key to continue . . .
*/
// ===================================================