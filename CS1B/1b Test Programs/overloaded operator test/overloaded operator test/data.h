#pragma once
#include <iostream>
using namespace std;

class Data
{
private:
	int num;
public:
	Data();
	Data(int num);
	~Data();
	int operator+(Data &data);
	int operator+(int num);

	friend ostream& operator<<(ostream &stream, Data &data);
	friend void showNum(Data &data);
};