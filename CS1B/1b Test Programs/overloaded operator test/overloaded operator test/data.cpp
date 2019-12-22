#include "data.h"

Data::Data()
{
	num = 0;
}

Data::Data(int num)
{
	this->num = num;
}

Data::~Data()
{
}

int Data::operator+(Data & data)
{
	return num + data.num;
}

int Data::operator+(int num)
{
	return this->num + num;
}

ostream & operator<<(ostream & stream, Data & data)
{
	stream << data.num;

	return stream;
}
