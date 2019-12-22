//Employee.h, specification for the Employee class

#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "Date.h"
#include <string>
using namespace std;

class Employee
{
private:
	string name;
	string phone;
	string job;
	int id;
	int age;
	float salary;
	char gender;
	Date hireDate; // Date class object composition

public:
	Employee();
	// Employee Default constructor
	// Postcondition: Date default constructor assigns hireDate,
	// name = "0"; phone = "0"; job = "0"; id = 0; age = 0;
	// salary = 0.0; gender = '0';

	Employee(const string name, const string phone, const string job, const int id, const int age,
		const float salary, const char gender, const int hireMonth, const int hireDay, const int hireYear);
	// Employee overloaded constructor with parameters
	// Postcondition: Date overloaded constructor assigns hireDate,
	// name = name; phone = phone; job = job; id = id; age = age;
	// salary = salary; gender = gender;

	void setName(const string name);
	// mutator for name
	// postcondition: this->name = name;

	void setPhone(const string phone);
	// mutator for phone
	// postcondition: this->phone = phone;

	void setJob(const string job);
	// mutator for job
	// postcondition: this->job = job;

	void setId(const int id);
	// mutator for id
	// postcondition: this->id = id;

	void setAge(const int age);
	// mutator for age
	// postcondition: this->age = age;

	void setSalary(const float salary);
	// mutator for salary
	// postcondition: this->salary = salary;

	void setGender(const char gender);
	// mutator for gender
	// postcondition: this->gender = gender;

	void setHireDate(const int month, const int day, const int year);
	// mutator for hireDate
	// postcondition: calls the setDate mutator the Date class
	// month = month; day = day; year = year;

	void setEmployee(string name, string phone, string job, int id, int age, float salary, char gender, int month, int day, int year);
	// mutator for all of the employee member data
	// postcondition: this->name = name; this->phone = phone; this->job = job; this->id = id; this->age = age; this->salary = salary;
	// this->gender = gender; this->month = month; this->day = day; this->year = year;

	friend ostream& operator<<(ostream& stream, const Employee &employee);
	// overloaded insertion operator to output Employee to the stream location.
	// postcondition: Employee object member data is outputted to the stream location.

	friend istream& operator>>(istream& stream, Employee &employee);
	// overloaded extraction operator to read user imput
	// postcondition: Employee object member data is read from the stream location

	friend bool compareEmployeePhone(Employee &e1, Employee &e2);
	// function to compare the phone number of 2 employee objects
	// postcondition: returns e1.phone == e2.phone

	bool operator ==(const Employee & otherEmployee);
	// overloaded comparison operator to compare the phone number of 2 employee objects
	// postcondition: returns this->phone == otherEmployee.phone

	void addAge(const int age);
	// adds an employee age by the integer argument.
	// postcondition: this->age = this->age + age;

	void operator +(const int age);
	// overlodaed addition operator that adds an employee age by the integer argument.
	// postcondition: this->age = this->age + age;

	Employee operator ++();
	// overlodaed pre-increment operator that adds an employee age by 1
	// postcondition: returns the object with this->age = this->age 1

	Employee operator ++(int temp);
	// overlodaed post-increment operator that adds an employee age by 1 but returns the original age
	// postcondition: this->age = this->age + 1; returns temp copy of original employee data.
};

#endif