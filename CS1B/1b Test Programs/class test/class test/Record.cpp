#include "Record.h"

Record::Record(int id, std::string first, std::string last, std::string address, std::string city, std::string state)
{
	this->id = id;
	this->first = first;
	this->last = last;
	this->address = address;
	this->city = city;
	this->state = state;
}

Record::Record()
{
}

Record::~Record()
{
}

int Record::getID()
{
	std::cin >> id;
	return id;
}

std::string Record::getFirst()
{
	std::cin >> first;
	return first;
}

std::string Record::getLast()
{
	std::cin >> last;
	return last;
}

std::string Record::getAddress()
{
	std::cin >> address;
	return address;
}

std::string Record::getCity()
{
	std::cin >> city;
	return city;
}

std::string Record::getState()
{
	std::cin >> state;
	return state;
}

void Record::showID(int id)
{
	std::cout << id;
}

void Record::showFirst(std::string first)
{
	std::cout << first;
}

void Record::showLast(std::string last)
{
	std::cout << last;
}

void Record::showAddress(std::string address)
{
	std::cout << address;
}

void Record::showCity(std::string city)
{
	std::cout << city;
}

void Record::showState(std::string state)
{
	std::cout << state;
}
