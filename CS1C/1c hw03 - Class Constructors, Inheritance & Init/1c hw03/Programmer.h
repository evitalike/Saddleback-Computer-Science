// Programmer.h, specification for Programmer class
// Programmer class inherits from Employee class

#ifndef PROGRAMMER_H
#define PROGRAMMER_H

#include "Employee.h"

class Programmer : public Employee
{
private:
	int department;
	string supervisor;
	int salaryInc;
	bool knowsCpp;
	bool knowsJava;

public:
	Programmer();
	// default Programmer constructor
	// postcondition: Employee default constructor is called.
	// department = 0; supervisor = "0"; salaryInc = 0;
	// knowsCpp = 0; knowsJava = 0;

	Programmer(const int department, const string supervisor, const int salaryInc, const bool knowsCpp, const bool knowsJava, 
		const string name, const string phone, const string job, const int id, const int age,
		const float salary, const char gender, const int hireMonth, const int hireDay, const int hireYear);
	// overloaded Programmer constructor with parameters
	// postcondition: department = department; supervisor = supervisor; salaryinc = salaryInc; knowsCpp = knowsCpp; knowsJava = knowsJava;
	// name = name; phone = phone; job = job; id = id; age = age; salary = salary; gender = gender; hireMonth = hireMonth;
	// hireday = hireDay; hireYear = hireYear;

	void setDepartment(const int department);
	// mutator for department
	// postcondition: department = department;

	void setSupervisor(const string supervisor);
	// mutator for supervisor
	// postcondition: supervisor = supervisor;

	void setSalaryInc(const int salaryInc);
	// mutator for salaryInc
	// postcondition: salaryInc = salaryInc;

	void setKnowsCpp(const bool knowsCpp);
	// mutator for knowsCpp
	// postcondition: knowsCpp = knowsCpp;

	void setKnowsJava(const bool knowsJava);
	// mutator for knowsJava
	// postcondition: knowsJava = knowsJava;

	void setProgrammer(int department, string supervisor, int salaryInc, bool knowsCpp, bool knowsJava,
		string name, string phone, string job, int id, int age, float salary, char gender, int month, int day, int year);
	// mutator for all Programmer member data
	// postcondition: department = department; supervisor = supervisor; salaryinc = salaryInc; knowsCpp = knowsCpp; knowsJava = knowsJava;
	// name = name; phone = phone; job = job; id = id; age = age; salary = salary; gender = gender; hireMonth = hireMonth;
	// hireday = hireDay; hireYear = hireYear;

	friend ostream& operator<<(ostream& stream, const Programmer &programmer);
	// overloaded insertion operator for Programmer class
	// uses the overloaded insertion operator for the Programmer class
	// postcondition: Programmer member data outputted to the stream location.
};

#endif