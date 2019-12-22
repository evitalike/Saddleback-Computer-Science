// Employee.h, implementation of Employee class

#include "Employee.h"

Employee::Employee() : name{"0"}, phone{"0"}, job{"0"}, id{0}, age{0}, salary{0.0}, gender{'0'}, hireDate{}
{ }

Employee::Employee(const string name, const string phone, const string job, const int id, const int age,
	const float salary, const char gender, const int hireMonth, const int hireDay, const int hireYear)
	: name{name}, phone{phone}, job{job}, id{id}, age{age}, salary{salary}, gender{gender}, hireDate{hireMonth, hireDay, hireYear}
{ }

void Employee::setName(const string name)
{
	this->name = name;
}

void Employee::setPhone(const string phone)
{
	this->phone = phone;
}

void Employee::setJob(const string job)
{
	this->job = job;
}

void Employee::setId(const int id)
{
	this->id = id;
}

void Employee::setAge(const int age)
{
	this->age = age;
}

void Employee::setSalary(const float salary)
{
	this->salary = salary;
}

void Employee::setGender(const char gender)
{
	this->gender = gender;
}

void Employee::setHireDate(const int month, const int day, const int year)
{
	hireDate.setDate(month, day, year);
}

void Employee::setEmployee(string name, string phone, string job, int id, int age, float salary, char gender, int month, int day, int year)
{
	this->setName(name);
	this->setPhone(phone);
	this->setJob(job);
	this->setId(id);
	this->setAge(age);
	this->setSalary(salary);
	this->setGender(gender);
	this->setHireDate(month, day, year);
}

ostream & operator<<(ostream & stream, const Employee & employee)
{
	stream << "Name:  " << employee.name << '\n'
		<< "Id:  " << employee.id << '\n'
		<< "Phone:  " << employee.phone << '\n'
		<< "Age:  " << employee.age << '\n'
		<< "Gender:  " << employee.gender << '\n'
		<< "Job:  " << employee.job << '\n'
		<< "Salary:  $" << employee.salary << '\n'
		<< "Hire Date:  " << employee.hireDate << "\n";

	return stream;
}