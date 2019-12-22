#ifndef DEQUE_H
#define DEQUE_H

#include <iostream>
using namespace std;

// templated node for the Deque class
template <class T>
struct Node
{
	T data;
	Node<T> *prev;
	Node<T> *next;
};

template <class T>
class Deque
{
private:
	Node<T>* front;
	Node<T>* back;
	int size;

public:
	Deque() : front{ NULL }, back{ NULL }, size{ 0 } { };
	// Deque default constructor
	// postcondition: front = NULL; back = NULL; size = 0;

	~Deque();
	// destructor for Deque class
	// postcondition: dynamic front and back data deleted

	void pushFront(T data);
	// function to push data to the front
	// postcondition: new node added, front = new Node;
	// size++;

	void pushBack(T data);
	// function to push data to the back
	// postcondition: new node added, back = new Node;
	// size++;

	void popFront();
	// function to delete data from the front
	// postcondition: front node deleted
	// size--;

	void popBack();
	// function to delete data from the back
	// postcondition: back node deleted
	// size--;

	T getfront();
	// function to return the data of the front node
	// postcondition: return front->data;

	T getback();
	// function to return the data of the back node
	// postcondition: return back->data;

	T getsize();
	// function to return the size of the deque
	// postcondition: return this->size;

	bool isEmpty();
	// postcondition: returns true if deque has no elements
	// otherwise returns false

	void erase();
	// deletes all nodes of the deque
	// postcondition: all nodes deleted
	// size = 0;

	void print();
	// prints the data in each node to the console
	// postcondition: node data printed to the console
};

template<class T>
inline Deque<T>::~Deque()
{
	delete front;
	delete back;
}

template<class T>
inline void Deque<T>::pushFront(T data)
{
	Node<T>* newNode = new Node<T>;
	newNode->data = data;
	
	// If deque is empty 
	if (front == NULL)
		back = front = newNode;

	// else inserts node at the front end 
	else
	{
		newNode->next = front;
		front->prev = newNode;
		front = newNode;
	}

	// Increments count of elements by 1 
	size++;
}

template<class T>
inline void Deque<T>::pushBack(T data)
{
	Node<T>* newNode = new Node<T>;
	newNode->data = data;

	// If deque is empty 
	if (back == NULL)
		front = back = newNode;

	// else inserts node at the back end 
	else
	{
		newNode->prev = back;
		back->next = newNode;
		back = newNode;
	}

	// Increments count of elements by 1 
	size++;
}

template<class T>
inline void Deque<T>::popFront()
{
	// If deque is empty then throw an error string
	if (isEmpty())
		throw "Cannot pop from an empty deque";

	// Deletes the node from the front end and makes 
	// the adjustment in the links 
	else
	{
		Node<T>* temp = front;
		front = front->next;

		// If only one element was present
		if (front == NULL)
			back = NULL;
		else
			front->prev = NULL;

		delete temp;

		// Decrements count of elements by 1 
		size--;
	}
}

template<class T>
inline void Deque<T>::popBack()
{
	// If deque is empty then throw an error string
	if (isEmpty())
		throw "Cannot pop from an empty deque";

	// Deletes the node from the back end and makes 
	// the adjustment in the links 
	else
	{
		Node<T>* temp = back;
		back = back->prev;

		// If only one element was present 
		if (back == NULL)
			front = NULL;
		else
			back->next = NULL;

		delete temp;

		// Decrements count of elements by 1 
		size--;
	}
}

template<class T>
inline T Deque<T>::getfront()
{
	// If deque is empty throws an error string
	if (isEmpty())
		throw "Queue is empty";
	return front->data;
}

template<class T>
inline T Deque<T>::getback()
{
	// If deque is empty throws an error string

	if (isEmpty())
		throw "Queue is empty";
	return back->data;
}

template<class T>
inline T Deque<T>::getsize()
{
	return size;
}

template<class T>
inline bool Deque<T>::isEmpty()
{
	return (front == NULL);
}

template<class T>
inline void Deque<T>::erase()
{
	back = NULL;
	while (front != NULL)
	{
		Node* temp = front;
		front = front->next;
		delete temp;
	}
	size = 0;
}

template<class T>
inline void Deque<T>::print()
{
	Node<T>* temp = front;
	while (temp != back->next)
	{
		cout << temp->data << "  ";
		temp = temp->next;
	}

	cout << '\n';
}

#endif