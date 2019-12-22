// ===================================================
// Programmer: Aaron Geesink
// Class: CS 1D
// ===================================================

#include <iostream>
#include <ctime>
#include <random>
#include <string>
#include <algorithm>
using namespace std;

int generateRandomNum();
void printIntVector(vector<int> &nums);
int reverseDigits(int num);
void reverseVector(vector<int> &nums);
int sumDigits(int num);
void sumVector(vector<int> &nums);

void printReverseVector(vector<int> &nums);
void printSumVector(vector<int> &original, vector<int> &reverse);

int SIZE = 15;

int main()
{
	//Description
	cout << "===================================================\n"
		<< "Names: Aaron Geesink and Milo Fisher\n"
		<< "Class: CS1D\n"
		<< "Professor: Lebowitz\n"
		<< "===================================================\n"
		<< "The purpose of this program is to generate 15 random three digits\n"
		<< "And store them all into a integer vector. The also generates the\n"
		<< "Sum of the digits of each vector element as well as the digits of\n"
		<< "The vector in reverse, stores the sums and reverse digits to two new\n"
		<< "vectors, and prints the three vectors to the console.\n"
		<< "===================================================\n\n";


	srand(time(NULL));
	vector<int> numbers(0);

	for (int i = 0; i < SIZE; i++)
	{
		numbers.push_back(generateRandomNum());
	}

	sort(numbers.begin(), numbers.end());
	cout << "Here are the random numbers:\n";
	printIntVector(numbers);

	vector<int> numbersReverse = numbers;
	reverseVector(numbersReverse);
	cout << "\nHere are the random numbers in Reverse:\n";
	printReverseVector(numbersReverse);

	vector<int> numbersSum = numbers;
	sumVector(numbersSum);
	cout << "\nHere are the sums of the random numbers:\n";
	printSumVector(numbers, numbersSum);

	system("pause");
	return 0;
}

// ===================================================

int generateRandomNum()
{
	return rand() % 900 + 100;
}

void printIntVector(vector<int> &nums)
{
	for (int i = 0; i < SIZE; i++)
	{
		cout << nums[i] << '\n';
	}
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

void reverseVector(vector<int> &nums)
{
	for (int i = 0; i < SIZE; i++)
	{
		nums[i] = reverseDigits(nums[i]);
	}
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

void sumVector(vector<int> &nums)
{
	for (int i = 0; i < SIZE; i++)
	{
		nums[i] = sumDigits(nums[i]);
	}
}

void printReverseVector(vector<int>& nums)
{
	for (int i = 0; i < SIZE; i++)
	{
		if (nums[i] < 10)
			cout << "00" << nums[i] << '\n';

		else if (nums[i] < 100)
			cout << "0" << nums[i] << '\n';

		else
			cout << nums[i] << '\n';
	}
}

void printSumVector(vector<int> &original, vector<int> &reverse)
{
	for (int i = 0; i < SIZE; i++)
	{
		cout << "sum of the digits of " << original[i] << " is " << reverse[i] << endl;
	}
}


// ===================================================