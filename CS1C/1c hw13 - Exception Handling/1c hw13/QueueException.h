#ifndef QUEUEEXXECPTION_H
#define QUEUEEXXECPTION_H

// QueueException class for handling Exceptions in the ArrayQueue class.

#include <iostream>
#include <exception>
#include <string>

class QueueException
{
private:
	std::string error;

public:
	QueueException(std::string error)
		: error{ error }
	{ }
	// constructor for QueueException
	// postcondition: this-error = error;

	const char* what() 
	{ 
		return error.c_str();
	}
	// accessor function for the error string
	// postcondition: return error;
};

#endif