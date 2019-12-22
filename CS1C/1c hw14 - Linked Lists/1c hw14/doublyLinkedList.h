#ifndef DOUBLY_LINKED_LIST
#define DOUBLY_LINKED_LIST

#include <iostream>
using namespace std;

template <typename T>
struct node
{
	T data;
	node<T> * next;
	node<T> * back;
};

template <typename T>
class doublyLinkedList
{
public:
	doublyLinkedList();
	// Default constructor

	~doublyLinkedList();
	// Destructor

	doublyLinkedList(const doublyLinkedList & source);
	// Copy constructor

	doublyLinkedList & operator=(const doublyLinkedList & source);
	// Copy assignment

	void insert(T newItem, int position = 1);
	// Insert function
	// Precondition: newItem T and a valid position
	// Postcondition: Inserts a new node into the linked list at the specified position

	void remove(int position = 1);
	// Removes an elements in the list
	// Precondition: position is a valid position in the list
	// Postcondition: Removes the node at position

	void reverse(doublyLinkedList & source);
	// Reads data from source and copies the data to the invoking list in reverse
	// Postcondition: The invoking linked list becomes a reversed version of source

	int size();
	// Postcondition: return count;

	void print();
	// Print function
	// Postcondition: list elements printed to the console

private:
	node<T> * head;
	int count;

};

// Default constructor
template<typename T>
inline doublyLinkedList<T>::doublyLinkedList() : head{nullptr}, count{0}
{}

// Destructor
template<typename T>
inline doublyLinkedList<T>::~doublyLinkedList()
{
	for (int i = 0; i < count; i++)
	{
		remove();
	}
}

// Copy constructor
template<typename T>
inline doublyLinkedList<T>::doublyLinkedList(const doublyLinkedList & source) : head{ nullptr }, count { 0 }
{
	node<T> * temp = source.head;
	for (int i = 0; i < source.count - 1; i++)
	{
		insert(temp->data, i + 1);
		temp = temp->next;
	}
	insert(temp->data, source.count);
}

// Copy assignment
template<typename T>
inline doublyLinkedList<T> & doublyLinkedList<T>::operator=(const doublyLinkedList & source)
{
	for (int i = 0; i < count; i++)
	{
		remove();
	}
	node<T> * temp = source.head;
	for (int i = 0; i < source.count - 1; i++)
	{
		insert(temp->data, i + 1);
		temp = temp->next;
	}
	insert(temp->data, source.count);

	return *this;
}

template<typename T>
inline void doublyLinkedList<T>::insert(T newItem, int position)
{
	if (position - 1 > count || position < 1)
		cout << "error: cannot insert in that position\n";
	// Case 1: If the list is empty
	else if (head == nullptr)
	{
		// Create new node
		node<T> * temp = new node<T>;
		temp->data = newItem;

		// Insert node
		head = temp;
		temp->back = nullptr;
		temp->next = nullptr;
		count++;
	}
	// Case 2: Insert at position 1
	else if (position == 1)
	{
		// Create new node
		node<T> * temp = new node <T>;
		temp->data = newItem;

		//Insert node at position 1
		head->back = temp;
		temp->next = head;
		head = temp;
		temp->back = nullptr;
		count++;
	}
	// Case 3: Insert last in the list
	else if (position > count)
	{
		// Create new node
		node<T> * temp = new node<T>;
		temp->data = newItem;

		// Insert node last in list
		node<T> * iterator = head;
		for (int i = 0; i < position - 2; i++)
		{
			iterator = iterator->next;
		}
		iterator->next = temp;
		temp->back = iterator;
		temp->next = nullptr;
		count++;
	}
	// Case 4: Insert node somewhere in the middle
	else
	{
		// Create new node
		node<T> * temp = new node<T>;
		temp->data = newItem;

		// Insert node in the correct position
		node<T> * itBack = head;
		for (int i = 0; i < position - 2; i++)
		{
			itBack = itBack->next;
		}
		node<T> * itFront = itBack->next;
		itBack->next = temp;
		temp->back = itBack;
		itFront->back = temp;
		temp->next = itFront;
		count++;
	}
}

template<typename T>
inline void doublyLinkedList<T>::remove(int position)
{
	if (position > count || position < 1)
	{
	cout << "error: not a valid node to delete\n";
	}
	// Case 1: delete a list of size 1
	else if (count == 1)
	{
		node<T> * temp = head;
		head = nullptr;
		delete temp;
	}
	// Case 2: delete position 1
	else if (position == 1)
	{
		node<T> * temp = head;
		head = head->next;
		head->back = nullptr;
		delete temp;
		count--;
	}
	// Case 2: Delete last node
	else if (position == count)
	{
		node<T> * itBack = head;
		for (int i = 0; i < position - 2; i++)
		{
			itBack = itBack->next;
		}
		node<T> * itFront = head->next;
		delete itFront;
		itBack->next = nullptr;
		count--;
	}
	// Case 3: Delete a node in the middle
	else
	{
		node<T> * itBack = head;
		for (int i = 0; i < position - 2; i++)
		{
			itBack = itBack->next;
		}
		node<T> * itFront = itBack->next;
		itBack->next = itFront->next;
		itBack = itBack->next;
		itBack->back = itFront->back;
		delete itFront;
		count--;
	}
}

template<typename T>
inline void doublyLinkedList<T>::reverse(doublyLinkedList & source)
{
	node<T> * temp = source.head;
	for (int i = 0; i < source.count - 1; i++)
	{
		insert(temp->data);
		temp = temp->next;
	}
	insert(temp->data);
}

template<typename T>
inline int doublyLinkedList<T>::size()
{
	return count;
}

template<typename T>
inline void doublyLinkedList<T>::print()
{
	node<T> * temp = head;
	for (int i = 0; i < count; i++)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

#endif