#pragma once

#include <string>
using namespace std;

struct Student
{
	int id;
	string name;
	Student *next;
};