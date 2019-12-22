// ===================================================
// Program: Assignment 3 - Queues and Deques
// ===================================================
// Programmer: Aaron Geesink
// Class: CS 1D - 5:00 PM M W
// ===================================================
// This program demonstrates the enqueue and dequeue functions
// of a custom queue class that utilizes a circular array to 
// store its data for Parts A and B, as well as the push and
// pop functions of a custom node based deque class for parts C and D.
// ===================================================

#include <iostream>
#include <string>
#include "ArrayQueue.h"
#include "Deque.h"
using namespace std;

int main()
{
	cout << "===================================================\n"
		<< "Program: Assignment 3 - Queues and Deques\n"
		<< "===================================================\n"
		<< "Programmer: Aaron Geesink\n"
		<< "Class: CS 1D - 5:00 PM M W\n"
		<< "===================================================\n"
		<< "This program demonstrates the enqueue and dequeue functions\n"
		<< "of a custom queue class that utilizes a circular array to\n"
		<< "store its data for Parts A and B, as well as the push and\n"
		<< "pop functions of a custom node based deque class for parts C and D.\n"
		<< "===================================================\n\n";

	// data initialization for the containers used in the program
	string names[7] = { "Mark", "Alan", "Jennifer", "Sonny", "Eric", "JoAnn", "Bill" };
	double doubles[6] = { 983.3, 44.44, 888.55, 99.99, 123.123, 8.445 };
	const int SIZE = 10;

	ArrayQueue<string> nameQueue(SIZE);
	ArrayQueue<double> doubleQueue(SIZE);

	Deque<string> nameDeque;
	Deque<double> doubleDeque;

	for (int i = 0; i < 7; i++)
	{
		nameQueue.enqueue(names[i]);
		nameDeque.pushFront(names[i]);
	}

	for (int i = 0; i < 6; i++)
	{
		doubleQueue.enqueue(doubles[i]);
		doubleDeque.pushFront(doubles[i]);
	}

	cout << "Part A: Data from the custom name and double queues:\n";
	nameQueue.print();
	doubleQueue.print();

	//deleing 99.99 and Sonny from the double and name stack
	nameQueue.dequeue();
	nameQueue.dequeue();
	nameQueue.dequeue();
	nameQueue.dequeue();

	doubleQueue.dequeue();
	doubleQueue.dequeue();
	doubleQueue.dequeue();
	doubleQueue.dequeue();

	cout << "\nPart B: Data from the custom name and double queues After 99.99 and Sonny are deleted:\n";
	nameQueue.print();
	doubleQueue.print();

	cout << "\nPart C: Data from the custom name and double deques:\n";
	nameDeque.print();
	doubleDeque.print();

	//deleting 99.99 and Sonny from the double and name stack
	nameDeque.popFront();
	nameDeque.popFront();
	nameDeque.popFront();
	nameDeque.popFront();

	doubleDeque.popBack();
	doubleDeque.popBack();
	doubleDeque.popBack();
	doubleDeque.popBack();

	cout << "\nPart D: Data from the custom name and double deques After 99.99 and Sonny are deleted:\n";
	nameDeque.print();
	doubleDeque.print();

	cout << endl;
	system("pause");
	return 0;
}

// ===================================================