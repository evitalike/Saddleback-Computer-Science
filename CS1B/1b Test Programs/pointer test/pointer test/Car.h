#pragma once
#include <iostream>
#include <string>
using namespace std;

struct Car
{
	int id;
	string model;
	Car *next;
};