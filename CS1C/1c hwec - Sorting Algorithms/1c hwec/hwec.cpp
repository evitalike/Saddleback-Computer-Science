// ===================================================
// Program: hw EC - Sorting Algorithms
// ===================================================
// Programmer: Aaron Geesink
// Class: CS 1C - 3:00 PM M T W TH
// ===================================================


#include <iostream>
#include <chrono>
using namespace std;

const int SIZE = 100;

int comparisons = 0;
int assignments = 0;

void bubbleSort(int list[], int size);
void insertionSort(int list[], int size);
void selectionSort(int array[], int n);

void quickSort(int arr[], int low, int high);
int partition(int arr[], int low, int high);
void swap(int* a, int* b);

int mergeSort(int *input, int size);
void merge_helper(int *input, int left, int right, int *scratch);
int max(int x, int y);

void beforeSort(int list1[], int list2[], int list3[]);
void afterSort(int list1[], int list2[], int list3[]);

int main()
{
	int list1[SIZE];
	int list2[SIZE];
	int list3[SIZE];

	cout << "BubbleSort\n";
	beforeSort(list1, list2, list3);
	auto start = std::chrono::high_resolution_clock::now();
	bubbleSort(list1, SIZE);
	auto finish = std::chrono::high_resolution_clock::now();
	std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(finish - start).count() << " ns\n";
	start = std::chrono::high_resolution_clock::now();
	bubbleSort(list2, SIZE);
	finish = std::chrono::high_resolution_clock::now();
	std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(finish - start).count() << " ns\n";
	start = std::chrono::high_resolution_clock::now();
	bubbleSort(list3, SIZE);
	finish = std::chrono::high_resolution_clock::now();
	std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(finish - start).count() << " ns\n\n";
	afterSort(list1, list2, list3);

	cout << "insertionSort\n";
	beforeSort(list1, list2, list3);
	start = std::chrono::high_resolution_clock::now();
	insertionSort(list1, SIZE);
	finish = std::chrono::high_resolution_clock::now();
	std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(finish - start).count() << " ns\n";
	start = std::chrono::high_resolution_clock::now();
	insertionSort(list2, SIZE);
	finish = std::chrono::high_resolution_clock::now();
	std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(finish - start).count() << " ns\n";
	start = std::chrono::high_resolution_clock::now();
	insertionSort(list3, SIZE);
	finish = std::chrono::high_resolution_clock::now();
	std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(finish - start).count() << " ns\n\n";
	afterSort(list1, list2, list3);

	cout << "selectionSort\n";
	beforeSort(list1, list2, list3);
	start = std::chrono::high_resolution_clock::now();
	selectionSort(list1, SIZE);
	finish = std::chrono::high_resolution_clock::now();
	std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(finish - start).count() << " ns\n";
	start = std::chrono::high_resolution_clock::now();
	selectionSort(list2, SIZE);
	finish = std::chrono::high_resolution_clock::now();
	std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(finish - start).count() << " ns\n";
	start = std::chrono::high_resolution_clock::now();
	selectionSort(list3, SIZE);
	finish = std::chrono::high_resolution_clock::now();
	std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(finish - start).count() << " ns\n\n";
	afterSort(list1, list2, list3);

	cout << "quickSort\n";
	beforeSort(list1, list2, list3);
	start = std::chrono::high_resolution_clock::now();
	quickSort(list1, 0, SIZE);
	finish = std::chrono::high_resolution_clock::now();
	std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(finish - start).count() << " ns\n";
	start = std::chrono::high_resolution_clock::now();
	quickSort(list2, 0, SIZE);
	finish = std::chrono::high_resolution_clock::now();
	std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(finish - start).count() << " ns\n";
	start = std::chrono::high_resolution_clock::now();
	quickSort(list3, 0, SIZE);
	finish = std::chrono::high_resolution_clock::now();
	std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(finish - start).count() << " ns\n\n";
	afterSort(list1, list2, list3);

	cout << "mergeSort\n";
	beforeSort(list1, list2, list3);
	start = std::chrono::high_resolution_clock::now();
	mergeSort(list1, SIZE);
	finish = std::chrono::high_resolution_clock::now();
	std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(finish - start).count() << " ns\n";
	start = std::chrono::high_resolution_clock::now();
	mergeSort(list2, SIZE);
	finish = std::chrono::high_resolution_clock::now();
	std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(finish - start).count() << " ns\n";
	start = std::chrono::high_resolution_clock::now();
	mergeSort(list3, SIZE);
	finish = std::chrono::high_resolution_clock::now();
	std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(finish - start).count() << " ns\n\n";
	afterSort(list1, list2, list3);


	system("pause");
	return 0;
}

// ===================================================

void bubbleSort(int list[], int size)
{
	comparisons = 0;
	assignments = 0;
	for (int x = 0; x < size; x++)
	{
		for (int y = 0; y < size - 1; y++)
		{
			comparisons++;
			if (list[y] > list[y + 1])
			{
				assignments++;
				int temp = list[y + 1];
				list[y + 1] = list[y];
				list[y] = temp;
			}
		}
	}
	cout << "Comparisons: " << comparisons << endl;
	cout << "Assignments: " << comparisons << endl;
}

void insertionSort(int list[], int size)
{
	comparisons = 0;
	assignments = 0;
	int j;
	int temp;
	for (int i = 0; i < size; i++)
	{
		comparisons++;
		j = i;
		while (j > 0 && list[j] < list[j - 1])
		{
			assignments++;
			temp = list[j];
			list[j] = list[j - 1];
			list[j - 1] = temp;
			j--;
		}
	}
	cout << "Comparisons: " << comparisons << endl;
	cout << "Assignments: " << comparisons << endl;
}

void selectionSort(int array[], int n)
{
	comparisons = 0;
	assignments = 0;
	for (int x = 0; x < n; x++)
	{
		int min = x;
		for (int y = x; y < n; y++)
		{
			comparisons++;
			if (array[min] > array[y])
			{
				assignments++;
				min = y;
			}
		}
		int temp = array[x];
		array[x] = array[min];
		array[min] = temp;
	}
	cout << "Comparisons: " << comparisons << endl;
	cout << "Assignments: " << comparisons << endl;
}

void quickSort(int arr[], int low, int high)
{
	comparisons = 0;
	assignments = 0;
	if (low < high)
	{
		comparisons++;
		int pi = partition(arr, low, high);
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}

}

int partition(int arr[], int low, int high)
{
	int pivot = arr[high];
	int i = (low - 1);

	for (int j = low; j <= high - 1; j++)
	{
		if (arr[j] <= pivot)
		{
			assignments++;
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
	cout << "Comparisons: " << comparisons << endl;
	cout << "Assignments: " << comparisons << endl;
}

void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

int mergeSort(int * input, int size)
{
	comparisons = 0;
	assignments = 0;
	int *scratch = (int *)malloc(size * sizeof(int));

	if (scratch != NULL)
	{
		comparisons++;
		merge_helper(input, 0, size, scratch);
		free(scratch);
		return 1;
	}
	else
	{

		return 0;
	}
}

void merge_helper(int *input, int left, int right, int *scratch)
{
	if (right == left + 1)
	{
		return;
	}
	else
	{
		int i = 0;
		int length = right - left;
		int midpoint_distance = length / 2;
		int l = left, r = left + midpoint_distance;

		merge_helper(input, left, left + midpoint_distance, scratch);
		merge_helper(input, left + midpoint_distance, right, scratch);

		for (i = 0; i < length; i++)
		{
			if (i < left + midpoint_distance && (r == right || max(input[1], input[r]) == input[1]))
			{
				assignments++;
				scratch[i] = input[l];
				l++;
			}
			else
			{
				scratch[i] = input[r];
				r++;
			}
		}
		for (i = left; i < right; i++)
		{
			input[i] = scratch[i - left];
		}
	}
}

int max(int x, int y)
{

	if (x > y)
	{
		return x;
	}
	else
	{
		return y;
	}

}

void beforeSort(int list1[], int list2[], int list3[])
{
	cout << "Before sort:" << endl;

	for (int i = 0; i < SIZE; i++)
	{
		list1[i] = i + 1;
		list2[i] = 100 - i;
		list3[i] = i + 1;
	}

	for (int z = 1; z < 50; z++)
	{
		int x = rand() % 100 + 1;
		int y = rand() % 100 + 1;
		if (x != y)
		{
			int temp = list3[x];
			list3[x] = list3[y];
			list3[y] = temp;
		}
	}
	
	cout << "list 1:\n";
	for (int i = 0; i < 10; i++)
		cout << list1[i] << ' ';
	cout << endl;
	for (int i = 90; i < 100; i++)
		cout << list1[i] << ' ';
	cout << endl;

	cout << "list 2:\n";
	for (int i = 0; i < 10; i++)
		cout << list2[i] << ' ';
	cout << endl;
	for (int i = 90; i < 100; i++)
		cout << list2[i] << ' ';
	cout << endl;

	cout << "list 3:\n";
	for (int i = 0; i < 10; i++)
		cout << list3[i] << ' ';
	cout << endl;
	for (int i = 90; i < 100; i++)
		cout << list3[i] << ' ';
	cout << endl << endl;
}

void afterSort(int list1[], int list2[], int list3[])
{
	cout << "After sort:" << endl;
	cout << "list 1:\n";
	for (int i = 0; i < 10; i++)
		cout << list1[i] << ' ';
	cout << endl;
	for (int i = 90; i < 100; i++)
		cout << list1[i] << ' ';
	cout << "\n";

	cout << "list 2:\n";
	for (int i = 0; i < 10; i++)
		cout << list2[i] << ' ';
	cout << endl;
	for (int i = 90; i < 100; i++)
		cout << list2[i] << ' ';
	cout << "\n";

	cout << "list 3:\n";
	for (int i = 0; i < 10; i++)
		cout << list3[i] << ' ';
	cout << endl;
	for (int i = 90; i < 100; i++)
		cout << list3[i] << ' ';
	cout << "\n\n";
}
