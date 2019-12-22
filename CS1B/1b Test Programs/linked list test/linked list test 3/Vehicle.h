#pragma once
#include <string>
#include <iostream>
using namespace std;

struct Vehicle
{
	int id;
	int year;
	string model;
	Vehicle *next;
};
