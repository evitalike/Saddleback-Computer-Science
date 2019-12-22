#pragma once
#include <string>
#include <iostream>
using namespace std;

class Car
{
private:
	int year = 0;
	string model = "0";
public:
	Car(int year, string model);
	~Car();
	void getInfo(Car & car);
	void showInfo(Car & car);
};