#pragma once
#include <iostream>
#include <iomanip>
using namespace std;

struct Student
{
	int id;
	char name[30];
	char address[30];
	char city[30];
	char state[30];
	char zip[30];
	char gpa[30];
	Student *next;
};