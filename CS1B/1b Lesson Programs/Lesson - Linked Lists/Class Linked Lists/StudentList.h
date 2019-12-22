#pragma once
#include "Student.h"

class StudentList
{
private:
	Student *head;
public:
	StudentList();
	~StudentList();
	void insertStudent();
	void deleteStudent();
	void showList();
};