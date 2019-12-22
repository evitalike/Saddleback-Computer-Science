// Programmer.cpp, implementation for Programmer class
// Programmer class inherits from Employee class

#include "Programmer.h"

Programmer::Programmer() : department{ 0 }, supervisor{ "0" }, salaryInc{ 0 }, knowsCpp{ 0 }, knowsJava{ 0 }, Employee()
{ }

Programmer::Programmer(const int department, const string supervisor, const int salaryInc, const bool knowsCpp, const bool knowsJava, 
	const string name, const string phone, const string job, const int id, const int age,
	const float salary, const char gender, const int hireMonth, const int hireDay, const int hireYear)
	: department{ department }, supervisor{ supervisor }, salaryInc{ salaryInc }, knowsCpp{ knowsCpp }, knowsJava{ knowsJava },
	Employee{ name, phone, job, id, age, salary, gender, hireMonth, hireDay, hireYear }
{ }

void Programmer::setDepartment(const int department)
{
	this->department = department;
}

void Programmer::setSupervisor(const string supervisor)
{
	this->supervisor = supervisor;
}

void Programmer::setSalaryInc(const int salaryInc)
{
	this->salaryInc = salaryInc;
}

void Programmer::setKnowsCpp(const bool knowsCpp)
{
	this->knowsCpp = knowsCpp;
}

void Programmer::setKnowsJava(const bool knowsJava)
{
	this->knowsJava = knowsJava;
}

void Programmer::setProgrammer(int department, string supervisor, int salaryInc, bool knowsCpp, bool knowsJava,
	string name, string phone, string job, int id, int age, float salary, char gender, int month, int day, int year)
{
	this->setEmployee(name, phone, job, id, age, salary, gender, month, day, year);
	this->setDepartment(department);
	this->setSupervisor(supervisor);
	this->setSalaryInc(salaryInc);
	this->setKnowsCpp(knowsCpp);
	this->setKnowsJava(knowsJava);
}

ostream & operator<<(ostream & stream, const Programmer & programmer)
{
	stream << Employee(programmer)
		<< "Department:  " << programmer.department << '\n'
		<< "Supervisor:  " << programmer.supervisor << '\n'
		<< "Raise %:  " << programmer.salaryInc << '\n'

		<< "C++ Knowledge:  ";
	if (programmer.knowsCpp)
		stream << "Yes\n";
	else
		stream << "No\n";

	stream << "Java Knowledge:  ";
	if (programmer.knowsJava)
		stream << "Yes\n";
	else
		stream << "No\n";

	return stream;
}
