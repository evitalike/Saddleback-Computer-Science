// Employee.h, implementation of Employee class

#include "Employee.h"

Employee::Employee() : name{ "0" }, phone{ "0" }, job{ "0" }, id{ 0 }, age{ 0 }, salary{ 0.0 }, gender{ '0' }, hireDate{}
{ }

Employee::Employee(const string name, const string phone, const string job, const int id, const int age,
	const float salary, const char gender, const int hireMonth, const int hireDay, const int hireYear)
	: name{ name }, phone{ phone }, job{ job }, id{ id }, age{ age }, salary{ salary }, gender{ gender }, hireDate{ hireMonth, hireDay, hireYear }
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

bool Employee::operator==(const Employee & otherEmployee)
{
	return (this->phone == otherEmployee.phone);
}

void Employee::addAge(int age)
{
	this->age = this->age + age;
	cout << "\n" << age << " years were added to age\n";
}

void Employee::operator+(const int age)
{
	this->age = this->age + age;
	cout << "\n" << age << " years were added to age\n";
}

Employee Employee::operator++()
{
	this->age = this->age + 1;
	cout << "after assignment, pre-increment age becomes:  " << this->age << endl;
	return *this;
}

Employee Employee::operator++(int none)
{
	Employee temp = *this;
	this->age = this->age + 1;
	cout << "after assignment, post-increment age becomes " << this->age << ", while the temp age that is returned is " << temp.age << endl;
	return temp;
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

istream & operator>>(istream & stream, Employee & employee)
{
	cout << "Enter Name:  ";
	getline(stream, employee.name);
	cout << "Enter Id:  ";
	stream >> employee.id;
	cout << "Enter Phone:  ";
	stream.ignore();
	getline(stream, employee.phone);
	cout << "Enter Age:  ";
	stream >> employee.age;
	cout << "Enter Gender:  ";
	stream.ignore();
	stream.get(employee.gender);
	cout << "Enter Job:  ";
	stream.ignore();
	getline(stream, employee.job);
	cout << "Enter Salary:  $";
	stream >> employee.salary;
	stream >> employee.hireDate;

	return stream;
}

bool compareEmployeePhone(Employee & e1, Employee & e2)
{
	return (e1.phone == e2.phone);
}
