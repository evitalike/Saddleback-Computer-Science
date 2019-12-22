// ===================================================
// Program: hw 12 - Templates (Queues)
// ===================================================
// Programmer: Aaron Geesink
// Class: CS 1C - 3:00 PM M T W TH
// ===================================================

#include "ArrayQueue.h"
#include <string>
using namespace std;

int main()
{
	ArrayQueue<int> intQueue(7);
	ArrayQueue<double> doubleQueue(7);
	ArrayQueue<string> stringQueue(7);

	cout << "Adding 6 elements to each queue:\n";

	intQueue.enqueue(1);
	intQueue.enqueue(2);
	intQueue.enqueue(3);
	intQueue.enqueue(4);
	intQueue.enqueue(5);
	intQueue.enqueue(6);

	doubleQueue.enqueue(1.1);
	doubleQueue.enqueue(2.2);
	doubleQueue.enqueue(3.3);
	doubleQueue.enqueue(4.4);
	doubleQueue.enqueue(5.5);
	doubleQueue.enqueue(6.6);

	stringQueue.enqueue("one");
	stringQueue.enqueue("two");
	stringQueue.enqueue("three");
	stringQueue.enqueue("four");
	stringQueue.enqueue("five");
	stringQueue.enqueue("six");

	intQueue.print();
	doubleQueue.print();
	stringQueue.print();

	cout << "\nDeleting 4 elements from each queue:";

	intQueue.dequeue();
	intQueue.dequeue();
	intQueue.dequeue();
	intQueue.dequeue();

	doubleQueue.dequeue();
	doubleQueue.dequeue();
	doubleQueue.dequeue();
	doubleQueue.dequeue();

	stringQueue.dequeue();
	stringQueue.dequeue();
	stringQueue.dequeue();
	stringQueue.dequeue();

	cout << endl;
	intQueue.print();
	doubleQueue.print();
	stringQueue.print();

	cout << "\nAdding 5 elements to each queue:";

	intQueue.enqueue(7);
	intQueue.enqueue(8);
	intQueue.enqueue(9);
	intQueue.enqueue(10);
	intQueue.enqueue(11);

	doubleQueue.enqueue(7.7);
	doubleQueue.enqueue(8.8);
	doubleQueue.enqueue(9.9);
	doubleQueue.enqueue(10.10);
	doubleQueue.enqueue(11.11);

	stringQueue.enqueue("seven");
	stringQueue.enqueue("eight");
	stringQueue.enqueue("nine");
	stringQueue.enqueue("ten");
	stringQueue.enqueue("eleven");

	cout << endl;
	intQueue.print();
	doubleQueue.print();
	stringQueue.print();

	cout << "\nDeleting 3 elements from each queue:";

	intQueue.dequeue();
	intQueue.dequeue();
	intQueue.dequeue();

	doubleQueue.dequeue();
	doubleQueue.dequeue();
	doubleQueue.dequeue();

	stringQueue.dequeue();
	stringQueue.dequeue();
	stringQueue.dequeue();

	cout << endl;
	intQueue.print();
	doubleQueue.print();
	stringQueue.print();

	cout << "\nAdding to a full queue:\n";
	intQueue.enqueue(12);
	intQueue.enqueue(13);
	intQueue.enqueue(14);
	intQueue.print();
	intQueue.enqueue(15);

	cout << "\nRemoving from an empty queue:\n";
	doubleQueue.dequeue();
	doubleQueue.dequeue();
	doubleQueue.dequeue();
	doubleQueue.dequeue();
	doubleQueue.dequeue();

	cout << "\nTesting Front method:\n";
	cout << stringQueue.getFront() << endl;

	cout << "\nOutputting elements of array copied with copy constructor:\n";
	ArrayQueue<int> intQCopy(intQueue);
	intQCopy.print();

	cout << "\nOutputting elements of array copied with copy assignment:\n";
	ArrayQueue<string> stringQCopy = stringQueue;
	stringQCopy.print();


	system("pause");
	return 0;
}

// ===================================================