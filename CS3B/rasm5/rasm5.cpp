/*	rasm5.cpp 
	Programmed by: Aaron Geesink
	Barnett CS3B 3PM Class */

#include <iostream>
#include <fstream>
#include <ctime>
#include "bubbleSort.h"
using namespace std;

extern "C" void aBubbleSort(int a[], int length);

#define SIZE 200000

int main()
{
	int choice = 0;
	int cSeconds = 0;
	int aSeconds = 0;
	int numbers[SIZE];
	//int sorted[SIZE];

	clock_t start;
	clock_t end;

	fstream file;
	
	while (choice != 4)
	{
		system("clear");

		cout << "               RASM5 C vs Assembly\n"
			<< "              File Element Count: " << SIZE << '\n'
			<< "------------------------------------------------\n"
			<< "C        Bubblesort Time: " << cSeconds << " secs\n"
			<< "Assembly Bubblesort Time: " << aSeconds << " secs\n"
			<< "------------------------------------------------\n"
			<< "<1> Load input file (integers)\n"
			<< "<2> Sort using C Bubblesort algorithm\n"
			<< "<3> Sort using Assembly Bubblesort algorithm\n"
			<< "<4> Quit\n\n";


		cout << "Please enter you choice: ";
		cin >> choice;

		// load data from file
		if (choice == 1)
		{
			file.open("input.txt");

			for (int i = 0; i < SIZE; i++)
			{
				file >> numbers[i];
				//cout << numbers[i] << endl;
			}

			file.close();
			cout << "\nPress any key to continue";
			cin.ignore().get();
		}
		// sort using c function
		else if (choice == 2)
		{

			file.open("output_c.txt");

			// sort the array using c and time it
			start = clock();
			BubbleSort(numbers, SIZE);
			end = clock();
			cSeconds = (end - start) / 1000000.0;

			// write to output_c
			for (int i = 0; i < SIZE; i++)
			{
				file << numbers[i] << '\n';
			}

			file.close();
			cout << "\nPress any key to continue";
			cin.ignore().get();
		}
		// sort using assembly function
		else if (choice == 3)
		{

			file.open("output_a.txt");

			// sort the array using assembly and time it
			start = clock();
			aBubbleSort(numbers, SIZE);
			end = clock();
			aSeconds = (end - start) / 1000000.0;

			// write to output_a
			for (int i = 0; i < SIZE; i++)
			{
				file << numbers[i] << '\n';
			}

			file.close();
			cout << "\nPress any key to continue";
			cin.ignore().get();
		}
		else if (choice == 4)
		{
			cout << "\nGoodbye!\n";
		}
		else
		{
			cout << "\nPlease enter a valid choice\n";
			cout << "Press any key to continue";
			cin.ignore().get();
		}
	}

	return 0;
}
