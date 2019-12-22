// ===================================================
// Program: hw 13 - Exception Handling
// ===================================================
// Programmer: Aaron Geesink
// Class: CS 1C - 3:00 PM M T W TH
// ===================================================

#include "ArrayQueue.h"
#include "QueueException.h"
#include <string>
#include <cassert>

int main()
{
	ArrayQueue<int> intQueue(3);

	try
	{
		cout << "Adding 4 elements to a 3 element queue:\n";
		intQueue.enqueue(1);
		intQueue.enqueue(2);
		intQueue.enqueue(3);
		// throw is found within the enqueue function.
		intQueue.enqueue(4);
	}
	catch (QueueException & exception)
	{
		std::cerr << "An array exception occurred (" << exception.what() << ")\n\n";
	}

	cout << "Here is the queue after exception handling:\n";
	intQueue.print();

	try
	{
		cout << "\ndeleting 4 elements from a queue with 3 elements:\n";
		intQueue.dequeue();
		intQueue.dequeue();
		intQueue.dequeue();
		// throw is found within the dequeue function.
		intQueue.dequeue();
	}
	catch (QueueException & exception)
	{
		std::cerr << "An array exception occurred (" << exception.what() << ")\n\n";
	}

	cout << "Here is the queue after exception handling (Note: nothing will happen):\n";
	intQueue.print();

	bool assertBool = true;

	cout << "Testing an assertion that passes\n";
	assert(assertBool);
	cout << "Assertion has passed.\n\n";

	assertBool = false;
	cout << "Testing an assertion that fails. (Note: program will abort.)\n";
	assert(assertBool);
	// the next line will not run.
	cout << "Assertion has passed.\n\n";

	system("pause");
	return 0;
}

// ===================================================