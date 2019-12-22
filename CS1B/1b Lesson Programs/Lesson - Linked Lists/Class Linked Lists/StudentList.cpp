#pragma once
#include "StudentList.h"
#include <iostream>
using namespace std;

StudentList::StudentList()
{
	head = nullptr;
}

StudentList::~StudentList()
{
}

void StudentList::insertStudent()
{
	Student *temp = new Student;

	cout << "ID:  ";
	cin >> temp->id;
	cin.ignore();
	cout << "Name:  ";
	getline(cin, temp->name);

}

void StudentList::deleteStudent()
{
}

void StudentList::showList()
{
	Student *temp = head;

	while (temp != nullptr)
	{
		cout << "ID:  " << temp->id << endl
			<< "name:  " << temp->name << endl << endl;
	}
}
