#ifndef ARRAYQUEUE_H
#define ARRAYQUEUE_H

#include <iostream>
using namespace std;

template <typename T>
class ArrayQueue
{
private:
	int size;
	int maxSize;
	int front;
	int back;
	T* elem;

public:
	ArrayQueue(int size);
	// ArrayQueue constructor
	// postcondition: elem = new T[size]; maxSize = size;
	// this->size = 0; front = 0; back = 0;

	~ArrayQueue();
	// ArrayQueue destructor
	// postcondition: delete[] elem; ArrayQueue object deleted

	void enqueue(const T& item);
	// enqueue function adds items to the back of the queue
	// precondition: queue is not full
	// postcondtion: size++; back = back + 1 % maxSize; elem[back] = item;

	T& dequeue();
	// dequeue function deletes items from the front of the queue and returns them by reference.
	// precondition: queue is not empty
	// postcondition: return elem[front]; size--; front = front + 1 % maxSize;

	T getFront();
	// returns front element of the queue.
	// postcondition: return elem[front];

	int getSize();
	// returns the number of elements in the queue
	// postcondtion: return size;

	bool isEmpty();
	// returns true if there are no elements in the queue
	// postcondition: return (size == 0);

	bool isFull();
	// returns true if the array is full
	// postcondition: return (size == maxSize);

	ArrayQueue(const ArrayQueue<T>& source);
	// ArrayQueue copy constructor
	// postcondition: this->elem = source.elem; maxSize = source.maxSize;
	// this->size = sourse.size; front = source.front; back = source.back;

	ArrayQueue<T>& operator=(const ArrayQueue<T> & source);
	// ArrayQueue copy constructor
	// postcondition: this->elem = source.elem; maxSize = source.maxSize;
	// this->size = sourse.size; front = source.front; back = source.back;

	void print();
	// prints the elements in the queue object to the console
	// postcondition: elem's elements outputted to the console.
};

#endif

template<typename T>
inline ArrayQueue<T>::ArrayQueue(int size) : elem{ new T[size] }, maxSize{ size }, size{ 0 }, front{ 0 }, back{ 0 }
{ }

template<typename T>
inline ArrayQueue<T>::~ArrayQueue()
{
	delete[] elem;
}

template<typename T>
inline void ArrayQueue<T>::enqueue(const T& item)
{
	if (isEmpty())
	{
		elem[back] = item;
		size++;
	}

	else if (!isFull())
	{
		back++;
		back = back % maxSize;
		size++;

		elem[back] = item;
	}
	else
		cout << "Cannot add to a full queue.\n";
}

template<typename T>
inline T& ArrayQueue<T>::dequeue()
{
	if (!isEmpty())
	{
		T temp = elem[front];

		front++;
		front = front % maxSize;
		size--;

		return temp;
	}
	else
		cout << "Cannot delete from an empty queue.\n";
}

template<typename T>
inline T ArrayQueue<T>::getFront()
{
	return elem[front];
}

template<typename T>
inline int ArrayQueue<T>::getSize()
{
	return size;
}

template<typename T>
inline bool ArrayQueue<T>::isEmpty()
{
	return (size == 0);
}

template<typename T>
inline bool ArrayQueue<T>::isFull()
{
	return (size == maxSize);
}

template<typename T>
inline ArrayQueue<T>::ArrayQueue(const ArrayQueue<T>& source)
	: elem{ new T[source.size] }, maxSize{ source.maxSize }, size{ source.size }, front{ source.front }, back{ source.back }
{ 
	for (int i = 0; i < size; i++)
	{
		this->elem[i] = source.elem[i];
	}
}

template<typename T>
inline ArrayQueue<T>& ArrayQueue<T>::operator=(const ArrayQueue<T>& source)
{
	maxSize = source.maxSize;
	size = source.size;
	front = source.front;
	back = source.back;

	// copying source to a temp array to allow for self assignment after elem's array is deleted.
	T* temp = new T[source.size];
	for (int i = 0; i < source.size; i++)
	{
		temp[i] = source.elem[i];
	}

	delete[] elem;
	elem = temp;
	delete[] temp;

}

template<typename T>
inline void ArrayQueue<T>::print()
{
	for (int i = 0; i < size; i++)
	{
		cout << elem[(i + front) % maxSize] << " ";
	}
	cout << "\n";
}

