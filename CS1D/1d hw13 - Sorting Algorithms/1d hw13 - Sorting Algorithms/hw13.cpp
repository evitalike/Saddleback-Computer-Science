// ===================================================
// Program: Assignment 13 - Sorting Algortithms
// ===================================================
// Programmer: Aaron Geesink
// Class: CS 1D - 5:00 PM M W
// ===================================================
// The purpose of this assignment is to analyze the 
// number of executions necesarry fo the merge sort, heap sort
// and quicksort algorithms. The number of executions are counted and
// then displayed to the console for use in Big O analysis.
// Part 3 displays the use of a radix sort to sort 10 strings
// of characters in alphabetical order.
// ===================================================

#include <iostream>
#include <random>
#include <iomanip>
#include "quickSort.h"
#include "heapSort.h"
#include "mergeSort.h"
#include "radixSort.h"
using namespace std;

void shuffleArray(int arr[], int n);
void reverseArray(int arr[], int n);
void orderedArray(int arr[], int n);
void printArray(int arr[], int n);

int main()
{
	cout << "===================================================\n"
		<< "Program: Program: Assignment 13 - Sorting Algortithms\n"
		<< "===================================================\n"
		<< "Programmer: Aaron Geesink\n"
		<< "Class: CS 1D - 5:00 PM M W\n"
		<< "===================================================\n"
		<< "The purpose of this assignment is to analyze the" 
		<< "\nnumber of executions necesarry fo the merge sort, heap sort"
		<< "\nand quicksort algorithms. The number of executions are counted and"
		<< "\nthen displayed to the console for use in Big O analysis."
		<< "\nPart 3 displays the use of a radix sort to sort 10 strings"
		<< "\nof characters in alphabetical order."
		<< "\n===================================================\n\n";

	const int SIZE1 = 5000;
	const int SIZE2 = 10000;
	const int SIZE3 = 50000;
	const int SIZE4 = 75000;
	int array1[SIZE1];
	int array2[SIZE2];
	int array3[SIZE3];
	int array4[SIZE4];

	cout << "\n=========== Part 1: Quicksort ===========\n";

	orderedArray(array1, SIZE1);
	orderedArray(array2, SIZE2);
	orderedArray(array3, SIZE3);
	
	cout << "Ordered Arrays before sorting:\n";
	printArray(array1, 5);
	printArray(array2, 5);
	printArray(array3, 5);

	cout << "\nAlready ordered - number of statements needed to sort:\n";
	cout << setw(10) << "Size(N)" << setw(15) << "First Pivot" << setw(15) << "Random Pivot" << setw(15) << "Middle Pivot\n"
		<< setw(10) << "5000" << setw(15) << quickSort(array1, 0, SIZE1 - 1, partitionFirst);
	orderedArray(array1, SIZE1);
	cout << setw(15) << quickSort(array1, 0, SIZE1 - 1, partitionRand);
	orderedArray(array1, SIZE1);
	cout << setw(15) << quickSort(array1, 0, SIZE1 - 1, partitionMid) << endl;

	cout << setw(10) << "10,000" << setw(15) << quickSort(array2, 0, SIZE2 - 1, partitionFirst);
	orderedArray(array2, SIZE2);
	cout << setw(15) << quickSort(array2, 0, SIZE2 - 1, partitionRand);
	orderedArray(array2, SIZE2);
	cout << setw(15) << quickSort(array2, 0, SIZE2 - 1, partitionMid) << endl;

	cout << setw(10) << "50,000" << setw(15) << quickSort(array3, 0, SIZE3 - 1, partitionFirst);
	orderedArray(array3, SIZE3);
	cout << setw(15) << quickSort(array3, 0, SIZE3 - 1, partitionRand);
	orderedArray(array3, SIZE3);
	cout << setw(15) << quickSort(array3, 0, SIZE3 - 1, partitionMid) << endl;

	cout << "\nOrdered Arrays after sorting:\n";
	printArray(array1, 5);
	printArray(array2, 5);
	printArray(array3, 5);

	cout << "\n=======================\n";

	reverseArray(array1, SIZE1);
	reverseArray(array2, SIZE2);
	reverseArray(array3, SIZE3);

	cout << "\nReverse Ordered Arrays before sorting:\n";
	printArray(array1, 5);
	printArray(array2, 5);
	printArray(array3, 5);

	cout << "\nReverse ordered - number of statements needed to sort:\n";
	cout << setw(10) << "Size(N)" << setw(15) << "First Pivot" << setw(15) << "Random Pivot" << setw(15) << "Middle Pivot\n"
		<< setw(10) << "5000" << setw(15) << quickSort(array1, 0, SIZE1 - 1, partitionFirst);
	reverseArray(array1, SIZE1);
	cout << setw(15) << quickSort(array1, 0, SIZE1 - 1, partitionRand);
	reverseArray(array1, SIZE1);
	cout << setw(15) << quickSort(array1, 0, SIZE1 - 1, partitionMid) << endl;

	cout << setw(10) << "10,000" << setw(15) << quickSort(array2, 0, SIZE2 - 1, partitionFirst);
	reverseArray(array2, SIZE2);
	cout << setw(15) << quickSort(array2, 0, SIZE2 - 1, partitionRand);
	reverseArray(array2, SIZE2);
	cout << setw(15) << quickSort(array2, 0, SIZE2 - 1, partitionMid) << endl;

	cout << setw(10) << "50,000" << setw(15) << quickSort(array3, 0, SIZE3 - 1, partitionFirst);
	reverseArray(array3, SIZE3);
	cout << setw(15) << quickSort(array3, 0, SIZE3 - 1, partitionRand);
	reverseArray(array3, SIZE3);
	cout << setw(15) << quickSort(array3, 0, SIZE3 - 1, partitionMid) << endl;

	cout << "\nReverse Ordered Arrays after sorting:\n";
	printArray(array1, 5);
	printArray(array2, 5);
	printArray(array3, 5);

	cout << "\n=======================\n";

	shuffleArray(array1, SIZE1);
	shuffleArray(array2, SIZE2);
	shuffleArray(array3, SIZE3);

	cout << "\nRandomly Ordered Arrays before sorting:\n";
	printArray(array1, 5);
	printArray(array2, 5);
	printArray(array3, 5);

	cout << "\nRandomly ordered - number of statements needed to sort:\n";
	cout << setw(10) << "Size(N)" << setw(15) << "First Pivot" << setw(15) << "Random Pivot" << setw(15) << "Middle Pivot\n"
		<< setw(10) << "5000" << setw(15) << quickSort(array1, 0, SIZE1 - 1, partitionFirst);
	shuffleArray(array1, SIZE1);
	cout << setw(15) << quickSort(array1, 0, SIZE1 - 1, partitionRand);
	shuffleArray(array1, SIZE1);
	cout << setw(15) << quickSort(array1, 0, SIZE1 - 1, partitionMid) << endl;

	cout << setw(10) << "10,000" << setw(15) << quickSort(array2, 0, SIZE2 - 1, partitionFirst);
	shuffleArray(array2, SIZE2);
	cout << setw(15) << quickSort(array2, 0, SIZE2 - 1, partitionRand);
	shuffleArray(array2, SIZE2);
	cout << setw(15) << quickSort(array2, 0, SIZE2 - 1, partitionMid) << endl;

	cout << setw(10) << "50,000" << setw(15) << quickSort(array3, 0, SIZE3 - 1, partitionFirst);
	shuffleArray(array3, SIZE3);
	cout << setw(15) << quickSort(array3, 0, SIZE3 - 1, partitionRand);
	shuffleArray(array3, SIZE3);
	cout << setw(15) << quickSort(array3, 0, SIZE3 - 1, partitionMid) << endl;

	cout << "\nRandomly Ordered Arrays after sorting:\n";
	printArray(array1, 5);
	printArray(array2, 5);
	printArray(array3, 5);

	cout << "\n=========== Part 2: Heap/Merge Sort ===========\n";

	orderedArray(array3, SIZE3);
	orderedArray(array4, SIZE4);

	cout << "Ordered Arrays before sorting:\n";
	printArray(array3, 5);
	printArray(array4, 5);

	cout << "\nAlready ordered - number of statements needed to sort:\n";
	cout << setw(15) << "Algorithm" << setw(15) << "50000" << setw(15) << "75000\n"
		<< setw(15) << "Merge Sort" << setw(15) << mergeSort(array3, 0, SIZE3 - 1) 
		<< setw(15) << mergeSort(array4, 0, SIZE4 - 1) << endl;

	orderedArray(array3, SIZE3);
	cout << setw(15) << "Heap Sort" << setw(15) << heapSort(array3, SIZE3);
	orderedArray(array4, SIZE4);
	cout << setw(15) << setw(15) << heapSort(array4, SIZE4) << endl;

	cout << "\nOrdered Arrays after sorting:\n";
	printArray(array3, 5);
	printArray(array4, 5);

	cout << "\n=======================\n";

	reverseArray(array3, SIZE3);
	reverseArray(array4, SIZE4);

	cout << "Reverse Ordered Arrays before sorting:\n";
	printArray(array3, 5);
	printArray(array4, 5);

	cout << "\nReverse ordered - number of statements needed to sort:\n";
	cout << setw(15) << "Algorithm" << setw(15) << "50000" << setw(15) << "75000\n"
		<< setw(15) << "Merge Sort" << setw(15) << mergeSort(array3, 0, SIZE3 - 1)
		<< setw(15) << mergeSort(array4, 0, SIZE4 - 1) << endl;

	reverseArray(array3, SIZE3);
	cout << setw(15) << "Heap Sort" << setw(15) << heapSort(array3, SIZE3);
	reverseArray(array4, SIZE4);
	cout << setw(15) << setw(15) << heapSort(array4, SIZE4) << endl;

	cout << "\nOrdered Arrays after sorting:\n";
	printArray(array3, 5);
	printArray(array4, 5);

	cout << "\n=======================\n";

	shuffleArray(array3, SIZE3);
	shuffleArray(array4, SIZE4);

	cout << "Random Arrays before sorting:\n";
	printArray(array3, 5);
	printArray(array4, 5);

	cout << "\nRandomly ordered - number of statements needed to sort:\n";
	cout << setw(15) << "Algorithm" << setw(15) << "50000" << setw(15) << "75000\n"
		<< setw(15) << "Merge Sort" << setw(15) << mergeSort(array3, 0, SIZE3 - 1)
		<< setw(15) << mergeSort(array4, 0, SIZE4 - 1) << endl;

	shuffleArray(array3, SIZE3);
	cout << setw(15) << "Heap Sort" << setw(15) << heapSort(array3, SIZE3);
	shuffleArray(array4, SIZE4);
	cout << setw(15) << setw(15) << heapSort(array4, SIZE4) << endl;

	cout << "\nRandom Arrays after sorting:\n";
	printArray(array3, 5);
	printArray(array4, 5);

	cout << "\n=========== Part 3: Radix sort ===========\n";
	string data[] = 
	{
		"acdes", "asdsd", "ksjtr", "kerpt", "absqa", "zabaa", "rkdsb", "qqqqq", "kdfaa", "zedsd"
	};
	puts("before sorting:");
	for (size_t i = 0; i < sizeof(data) / sizeof(data[0]); i++) 
	{
		cout << data[i] << "  ";
	}
	cout << endl;
	radixSort(data, (int)(sizeof(data) / sizeof(data[0])));
	puts("\n\nafter sorting:");
	for (size_t i = 0; i < sizeof(data) / sizeof(data[0]); i++) 
	{
		cout << data[i] << "  ";
	}
	cout << endl;
	system("pause");
	return 0;
}



// ===================================================

// Shuffle array 
void shuffleArray(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = i + 1;
	}

	srand(time(NULL));
	int seed = n % rand();

	// Shuffling our array 
	shuffle(arr, arr + n,
		default_random_engine(seed));
}

void reverseArray(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = n - i;
	}
}

void orderedArray(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = i + 1;
	}
}

// A utility function to print contents of arr 
void printArray(int arr[], int n)
{
	for (int i = 0; i < n; ++i)
		cout << arr[i] << " ";
	cout << "\n";
}