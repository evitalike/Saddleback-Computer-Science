#ifndef HEAPSORT_H
#define HEAPSORT_H

// C++ program for implementation of Heap Sort 

// To heapify a subtree rooted with node i which is 
// an index in arr[]. n is size of heap 
void heapify(int arr[], int n, int i, int &statements)
{
	++statements;
	int largest = i; // Initialize largest as root 
	int l = 2 * i + 1; // left = 2*i + 1 
	int r = 2 * i + 2; // right = 2*i + 2 

	// If left child is larger than root 
	if (l < n && arr[l] > arr[largest])
	{
		++statements;
		largest = l;
	}

	// If right child is larger than largest so far 
	if (r < n && arr[r] > arr[largest])
	{
		++statements;
		largest = r;
	}

	// If largest is not root 
	if (largest != i)
	{
		++statements;
		swap(arr[i], arr[largest]);

		// Recursively heapify the affected sub-tree 
		heapify(arr, n, largest, statements);
	}
}

// main function to do heap sort 
int heapSort(int arr[], int n)
{
	int statements = 0;
	++statements;

	// Build heap (rearrange array) 
	for (int i = n / 2 - 1; i >= 0; i--)
	{
		++statements;
		heapify(arr, n, i, statements);
	}

	// One by one extract an element from heap 
	for (int i = n - 1; i >= 0; i--)
	{
		++statements;
		// Move current root to end 
		swap(arr[0], arr[i]);

		// call max heapify on the reduced heap 
		heapify(arr, i, 0, statements);
	}
	return statements;
}

#endif