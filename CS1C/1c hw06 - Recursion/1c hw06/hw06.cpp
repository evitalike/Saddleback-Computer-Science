// ===================================================
// Program: hw 06 - Recursion
// ===================================================
// Programmer: Aaron Geesink
// Class: CS 1C - 3:00 PM M T W TH
// ===================================================
// The purpose of this program is to demonstrate the use
// of recursive functions by reversing letters between
// two index locations of a character array. A 
// character array of the alphabet is reversed between
// various index locations to demonstrate that the
// recursive function works properly.
// ===================================================

// EXTRA CREDIT INCLUDED
// The difference between the iterative and the recursive approach is
// that the recursive approach has more overhead as it must 
// call the function multiple times, while the recursive
// approach has one process that loops multiple times without
// having to instatiate new variables. They both run until their conditions
// are met, so they are both are valid options for solving problems.

#include <iostream>
#include <cstring>
using namespace std;

void reverse(char word[], int indexStart, int indexEnd);
// function that reverses the letters of a character array between to given index locations.
// postcondition: characters between indexStart and indexEnd are reversed.

void loopReverse(char word[], int indexStart, int indexEnd);
// EC reverse function with a loop instead of recursion
// postcondition: characters between indexStart and indexEnd are reversed.

int main()
{
	char alphabet[27] = "abcdefghijklmnopqrstuvwxyz";
	reverse(alphabet, 11, 18);
	cout << alphabet << endl << endl;

	strcpy(alphabet, "abcdefghijklmnopqrstuvwxyz");
	reverse(alphabet, 4, 22);
	cout << alphabet << endl << endl;

	strcpy(alphabet, "abcdefghijklmnopqrstuvwxyz");
	reverse(alphabet, 0, 25);
	cout << alphabet << endl << endl;

	strcpy(alphabet, "abcdefghijklmnopqrstuvwxyz");
	loopReverse(alphabet, 0, 25);
	cout << "Here's reverse using a loop instead:\n"
		<< alphabet << endl << endl;

	system("pause");
	return 0;
}

// ===================================================

void reverse(char word[], int indexStart, int indexEnd)
{
	if (indexStart >= indexEnd)
		return;
	else
	{
		swap(word[indexStart], word[indexEnd]);
		reverse(word, indexStart + 1, indexEnd - 1);
	}
}

void loopReverse(char word[], int indexStart, int indexEnd)
{
	for (indexStart; !(indexStart >= indexEnd); indexStart++)
	{
		swap(word[indexStart], word[indexEnd]);
		indexEnd--;
	}
}
