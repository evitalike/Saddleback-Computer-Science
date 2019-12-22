// ===================================================
// Program: Lab 2 - Recursion
// ===================================================
// Programmer: Aaron Geesink
// Class: CS 1D
// ===================================================
// TODO: WRITE THE PURPOSE OF THIS ASSIGNMENT
// ===================================================

#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool testPalindrome(string palindrome);

int main()
{
	bool result = false;

	vector<string> strings;
	strings.push_back("A man a plan a canal Panama");
	strings.push_back("The rain in Spain");
	strings.push_back("No lemon, no melon");
	strings.push_back("radar");
	strings.push_back("CS1D");
	strings.push_back("Was it a cat I saw ?");
	strings.push_back("Racecar");
	strings.push_back("Saddleback");
	strings.push_back("dad");

	cout << "Testing Palindromes:\n";
	for (int i = strings.size; i < strings.size; i++)
	{
		result = testPalindrome(strings[i]);
		if (result)
			cout << strings[i] << " Is a palindrome\n";
		else
			cout << strings[i] << " Is not a palindrome\n";
	}

	system("pause");
	return 0;
}

// ===================================================

bool testPalindrome(string palindrome)
{
	string result;
	std::remove_copy_if(palindrome.begin(), palindrome.end(),
		std::back_inserter(result), //Store output           
		std::ptr_fun<int, int>(&std::ispunct)
	);

	return false;
}
