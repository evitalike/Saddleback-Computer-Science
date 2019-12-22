#ifndef QUICKSORT_H
#define QUICKSORT_H

// ===================== quick sort =================

// An iterative implementation of quick sort 
#include <stack>
using namespace std;

// A utility function to swap two elements 
void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

/* This function takes last element as pivot, places
  the pivot element at its correct position in sorted
  array, and places all smaller (smaller than pivot)
  to left of pivot and all greater elements to right
  of pivot */
int partition(int arr[], int l, int h, unsigned long int &statements)
{
	++statements;
	int x = arr[h];
	int i = (l - 1);

	for (int j = l; j <= h - 1; j++)
	{
		++statements;
		if (arr[j] <= x)
		{
			++statements;
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[h]);
	return (i + 1);
}

// swaps pivot at end element with pivot at start
// element and calls the partition function 
int partitionFirst(int arr[], int low, int high, unsigned long int &statements)
{
	++statements;

	// Swap A[random] with A[high] 
	swap(arr[low], arr[high]);

	return partition(arr, low, high, statements);
}

// swaps pivot at end element with pivot at middle
// element and calls the partition function 
int partitionMid(int arr[], int low, int high, unsigned long int &statements)
{
	++statements;

	// Swap A[random] with A[high] 
	swap(arr[(low + high) / 2], arr[high]);

	return partition(arr, low, high, statements);
}

// Generates Random Pivot, swaps pivot with 
// end element and calls the partition function 
int partitionRand(int arr[], int low, int high, unsigned long int &statements)
{
	++statements;
	// Generate a random number in between 
	// low .. high 
	srand(time(NULL));
	int random = low + rand() % (high - low);

	// Swap A[random] with A[high] 
	swap(arr[random], arr[high]);

	return partition(arr, low, high, statements);
}

/* A[] --> Array to be sorted,
lo --> Starting index,
hi --> Ending index */
unsigned long int quickSort(int arr[], int lo, int hi, int (*partitionFunc)(int arr[], int l, int h, unsigned long int &statements))
{
	unsigned long int statements = 0;

	++statements;

	stack<int> start;
	stack<int> end;
	start.push(lo);
	end.push(hi);
	int l, r, p;

	while (!start.empty())
	{
		++statements;
		l = start.top();
		r = end.top();
		if (l < r)
		{
			++statements;
			p = partitionFunc(arr, l, r, statements);
			start.pop();
			end.pop();
			start.push(p + 1);
			end.push(r);
			start.push(l);
			end.push(p - 1);
		}
		else
		{
			++statements;
			start.pop();
			end.pop();
		}
	}

	return statements;
}

#endif