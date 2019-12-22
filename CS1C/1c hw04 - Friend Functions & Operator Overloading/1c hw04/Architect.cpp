// Architect.cpp, implementation for Architect class
// Architect class inherits from Employee class

#include "Architect.h"
#include <iostream>
using namespace std;

Architect::Architect() : department{ 0 }, supervisor{ "0" }, salaryInc{ 0 }, yearsExperience{ 0 }, Employee()
{ }

Architect::Architect(const int department, const string supervisor, const int salaryInc, const int yearsExperience,
	const string name, const string phone, const string job, const int id, const int age,
	const float salary, const char gender, const int hireMonth, const int hireDay, const int hireYear)
	: department{ department }, supervisor{ supervisor }, salaryInc{ salaryInc }, yearsExperience{ yearsExperience },
	Employee{ name, phone, job, id, age, salary, gender, hireMonth, hireDay, hireYear }
{ }

void Architect::setDepartment(const int department)
{
	this->department = department;
}

void Architect::setSupervisor(const string supervisor)
{
	this->supervisor = supervisor;
}

void Architect::setSalaryInc(const int salaryInc)
{
	this->salaryInc = salaryInc;
}

void Architect::setYearsExperience(const int yearsExperience)
{
	this->yearsExperience = yearsExperience;
}

void Architect::setArchitect(int department, string supervisor, int salaryInc, int yearExperience,
	string name, string phone, string job, int id, int age, float salary, char gender, int month, int day, int year)
{
	this->setEmployee(name, phone, job, id, age, salary, gender, month, day, year);
	this->setDepartment(department);
	this->setSupervisor(supervisor);
	this->setSalaryInc(salaryInc);
	this->setYearsExperience(yearExperience);
}

ostream & operator<<(ostream & stream, const Architect & architect)
{
	stream << Employee(architect)
		<< "Department:  " << architect.department << '\n'
		<< "Supervisor:  " << architect.supervisor << '\n'
		<< "Raise %:  " << architect.salaryInc << '\n'
		<< "Years Experience:  " << architect.yearsExperience << '\n';

	return stream;
}
