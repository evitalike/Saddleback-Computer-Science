// Architect.h, specification for Architect class
// Architect class inherits from Employee class

#ifndef ARCHITECH_H
#define ARCHITECT_H

#include "Employee.h"

class Architect : public Employee
{
private:
	int department;
	string supervisor;
	int salaryInc;
	int yearsExperience;

public:
	Architect();
	// default Architect constructor
	// postcondition: Employee default constructor is called,
	// department = 0; supervisor = "0"; salaryInc = 0;
	// yearExperience = 0;

	Architect(const int department, const string supervisor, const int salaryInc, const int yearsExperience,
		const string name, const string phone, const string job, const int id, const int age,
		const float salary, const char gender, const int hireMonth, const int hireDay, const int hireYear);
	// overloaded Architect constructor with parameters
	// postcondition: department = department; supervisor = supervisor; salaryinc = salaryInc; yearExperience = yearsExperience;
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

	void setYearsExperience(const int yearsExperience);
	// mutator for yearExperience
	// postcondition: yearsExperience = yearsExperience;

	void setArchitect(int department, string supervisor, int salaryInc, int yearExperience,
		string name, string phone, string job, int id, int age, float salary, char gender, int month, int day, int year);
	// mutator for all Architect member data
	// postcondition: department = department; supervisor = supervisor; salaryinc = salaryInc; yearExperience = yearsExperience;
	// name = name; phone = phone; job = job; id = id; age = age; salary = salary; gender = gender; hireMonth = hireMonth;
	// hireday = hireDay; hireYear = hireYear;

	friend ostream& operator<<(ostream& stream, const Architect& architect);
	// overloaded insertion operator for Architect class
	// uses the overloaded insertion operator for the Employee class
	// postcondition: Architect member data outputted to the stream location.
};

#endif