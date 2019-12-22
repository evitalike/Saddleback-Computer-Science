// ===================================================
// Program: hw 05 - STL Vectors
// ===================================================
// Programmer: Aaron Geesink
// Class: CS 1C - 3:00 PM M T W TH
// ===================================================
// The purpose of this program is to explore
// the functionalities of STL vectors by creating
// a simple random number generator for a lotto game
// using the <vector> class.
// ===================================================

/* 
QUESTIONS:
1. STL, or Standard Template Library, is a set of template classes that
provided a wide range of functionalities, including algortithms, iterations,
and dynamic container classes. A vector is a dynamic template container class that
uses a single array to store it's data. It can resize whenever elements are added or subtracted from the array
by creating a new array and copying the data to it.

2. After a vector's construction,  the functions reserve, resize, push_back, pop_back, emplace, emplace_back, and shrink_to_fit
all change the size of a vector after it's construction.

3. The STL array container acts like a built in array container, but with some additional functions added to it,
such as a function to obtain its own size as well as well as a front and back function that can obtain the front and back elements.
It differs from a vector because it is not dynamic and cannot grow or shrink in size.

4. The vector member function resize changes a vector's size and capacity to a value by adding or removing elements until it is the correct size.
The reserve function can only increase the capacity of a vector and will not remove elements if the specified capacity is less than the current capacity.

5. For a container, begin() returns the beginning position of the container, while end() returns the position after the last position in the container.
These two functions are used for iterating through a container.

6. Vector push_back() example:
        vector<int> v1{ 2, 2 }; 
        v1.push_back(2); 

		// Vector becomes {2, 2, 2}

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <ctime>
using namespace std;

vector<int> Lotto(int spots, int winners);
// precondition: 2 int arguments
// postcondition: Returns an array of size winSpots that contains random numbers
// from a range of 1 to int spots with no duplicates.


void print(vector<int> numbers);
// Precondition: A vector of type int.
// Postcondition: outputs the vector to the console

int main()
{
	srand(time(NULL));

	vector<int> winners;
	winners = Lotto(51, 6);
	
	cout << "Winners are:\n";
	print(winners);
	cout << '\n';

	system("pause");
	return 0;
}

// ===================================================

vector<int> Lotto(int spots, int winners)
{
	vector<int> numbers;
	for (int i = 1; i < spots + 1; i++)
	{
		numbers.push_back(i);
	}

	random_shuffle(numbers.begin(), numbers.end());

	for (int i = 0; i < spots - winners; i++)
	{
		numbers.pop_back();
	}

	sort(numbers.begin(), numbers.end());

	return numbers;
}

void print(vector<int> numbers)
{
	for (int i = 0; i < numbers.size(); i++)
	{
		cout << numbers[i] << ' ';
	}
}
