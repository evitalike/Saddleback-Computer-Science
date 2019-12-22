#ifndef RADIXSORT_H
#define RADIXSORT_H


#include <string>
#include <iostream>
#include <string>
using namespace std;

// ===================== radix sort =================

size_t getMax(string arr[], int n)
{
	size_t max = arr[0].size();
	for (int i = 1; i < n; i++)
	{
		if (arr[i].size() > max)
			max = arr[i].size();
	}
	return max;
}

void countSort(string a[], int size, size_t k)
{
	string *b = NULL; int *c = NULL;
	b = new string[size];
	c = new int[257];

	for (int i = 0; i < 257; i++)
	{
		c[i] = 0;
		//cout << c[i] << "\n";
	}
	for (int j = 0; j < size; j++)
	{
		c[k < a[j].size() ? (int)(unsigned char)a[j][k] + 1 : 0]++;            //a[j] is a string
		//cout << c[a[j]] << endl;
	}

	for (int f = 1; f < 257; f++)
	{
		c[f] += c[f - 1];
	}

	for (int r = size - 1; r >= 0; r--)
	{
		b[c[k < a[r].size() ? (int)(unsigned char)a[r][k] + 1 : 0] - 1] = a[r];
		c[k < a[r].size() ? (int)(unsigned char)a[r][k] + 1 : 0]--;
	}

	for (int l = 0; l < size; l++)
	{
		a[l] = b[l];
	}

	// avoid memory leak
	delete[] b;
	delete[] c;
}


void radixSort(string b[], int r) 
{
	size_t max = getMax(b, r);
	// size_t is unsigned, so avoid using digit >= 0, which is always true
	for (size_t digit = max; digit > 0; digit--)
	{ 
		cout << "\nPass " << max - digit + 1 << ": ";
		countSort(b, r, digit - 1);
		for (size_t i = 0; i < r; i++)
		{
			cout << b[i].c_str() << " ";
		}
	}
}

#endif