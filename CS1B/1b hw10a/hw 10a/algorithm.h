#pragma once
#include <iostream>
#include <string>
using namespace std;

template <typename T>
T max(T num1, T num2);

template <typename T>
T max(T num1, T num2)
{
	if (num1 > num2)
		return num1;
	else if (num1 < num2)
		return num2;
	else
		cout << "neither";
}