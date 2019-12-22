#ifndef MERGESORT_H
#define MERGESORT_H

// Merges two subarrays of arr[]. 
// First subarray is arr[l..m] 
// Second subarray is arr[m+1..r] 
void merge(int arr[], int l, int m, int r, int &statements)
{
	++statements;
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	/* create temp arrays */
	int *L = new int[n1];
	int *R = new int[n2];

	/* Copy data to temp arrays L[] and R[] */
	for (i = 0; i < n1; i++)
	{
		++statements;
		L[i] = arr[l + i];
	}
	for (j = 0; j < n2; j++)
	{
		++statements;
		R[j] = arr[m + 1 + j];
	}

	/* Merge the temp arrays back into arr[l..r]*/
	i = 0; // Initial index of first subarray 
	j = 0; // Initial index of second subarray 
	k = l; // Initial index of merged subarray 
	while (i < n1 && j < n2)
	{
		++statements;

		if (L[i] <= R[j])
		{
			++statements;
			arr[k] = L[i];
			i++;
		}
		else
		{
			++statements;
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	/* Copy the remaining elements of L[], if there
	   are any */
	while (i < n1)
	{
		++statements;
		arr[k] = L[i];
		i++;
		k++;
	}

	/* Copy the remaining elements of R[], if there
	   are any */
	while (j < n2)
	{
		++statements;
		arr[k] = R[j];
		j++;
		k++;
	}

	delete[] L;
	delete[] R;
}

/* l is for left index and r is right index of the
   sub-array of arr to be sorted */
int mergeSort(int arr[], int l, int r)
{
	int statements = 0;

	++statements;

	if (l < r)
	{
		++statements;
		// Same as (l+r)/2, but avoids overflow for 
		// large l and h 
		int m = l + (r - l) / 2;

		// Sort first and second halves 
		statements += mergeSort(arr, l, m);
		statements += mergeSort(arr, m + 1, r);

		merge(arr, l, m, r, statements);
	}
	return statements;
}

#endif