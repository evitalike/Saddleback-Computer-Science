#ifndef LINKEDLISTSTACK_H
#define LINKEDLISTSTACK_H

#include <iostream>

template <class Type>
class LinkedListStack
{
public:
	LinkedListStack() : top(0) {}
	// default constructor
	// postconditon: top assigned to 0;

	~LinkedListStack();
	// class desructor
	// postcondition: class data destroyed and deallocated

	bool isEmpty() const;
	//returns if the stack is empty
	//postcondition: true if stack empty, else false

	Type pop();
	// returns and deletes the top element of the stack
	// precondition: stack is not empty
	// postcondition: top element returned and deleted

	void push(const Type& val);
	// adds an element to the stack
	// precondition: argument of type Type
	// postcondition: element added to top of the stack

	const Type& topElem();
	// returns the top element of the stack
	// precondition: stack not empty
	// postcondition: top element returned

	void print();
	// prints and pops the elements of the stack
	// postcondition: stack elements printed and deleted

private:
	struct nodeType
	{
		Type info;
		nodeType *link;

		nodeType(const Type& newData, nodeType *nextNode) 
			: info(newData), link(nextNode) {}
	};

	nodeType *top;
};

template <class Type>
inline LinkedListStack<Type>::~LinkedListStack()
{
	while (!isEmpty()) 
	{
		pop();
	}
}

template <class Type>
inline void LinkedListStack<Type>::push(const Type& val)
{
	top = new nodeType(val, top);
}

template <class Type>
inline Type LinkedListStack<Type>::pop()
{
	if (!isEmpty()) 
	{
		nodeType *topNode = top;
		top = top->link;
		Type info = topNode->info;
		delete topNode;
		return info;
	}
}

template <class Type>
inline const Type& LinkedListStack<Type>::topElem()
{
	if (!isEmpty()) 
	{
		return top->info;
	}
}

template <class Type>
inline bool LinkedListStack<Type>::isEmpty() const
{
	if (top == 0) 
	{
		return true;
	}
	else 
	{
		return false;
	}
}

template <class Type>
void LinkedListStack<Type>::print()
{
	while (!isEmpty())
	{
		std::cout << topElem() << "  ";
		pop();
	}
	std::cout << "\n";
}

#endif