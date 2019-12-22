#ifndef SL
#define SL

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <ctime>
#include <random>
using namespace std;

class Skip_list
{

public:
	struct Node {
		int key;
		string value;
		// pointers to successor nodes
		vector<Node*> forward;

		Node(int k, const std::string& v, int level) :
			key(k), value(v), forward(level, nullptr)
		{}
	};

	Skip_list();
	~Skip_list();

	// non-modifying member functions

	/*
	It prints the key, value, level
	of each node of the skip list.

	Prints two nodes per line.
	*/
	void print() const;

	/*
	It searches the skip list and
	returns the element corresponding
	to the searchKey; otherwise it returns
	failure, in the form of null pointer.
	*/
	string* find(int searchKey) const;

	// modifying member functions

	/*
	It searches the skip list for elements
	with seachKey, if there is an element
	with that key its value is reassigned to the
	newValue, otherwise it creates and splices
	a new node, of random level.
	*/
	void insert(int searchKey, const string& newValue);

	/*
	It deletes the element containing
	searchKey, if it exists.
	*/
	void erase(int searchKey);

	int size();

	bool empty()
	{
		return (size() == 0);
	}

	// Iterators
	using iterator = Node * ;
	using const_iterator = const string *;
	iterator begin() // points to first element
	{
		if (size() == 0)
			return nullptr;
		return head->forward[0];
	}
	iterator end() // points to one beyond the last element
	{
		if (size() == 0)
			return nullptr;
		return NIL;
	}

	// Function to demonstrate the iterators
	void printKeys()
	{
		for (Node * i = begin(); i != end(); i = i->forward[0])
		{
			cout << i->key << " ";
		}
	}
	// Erase a value pointed to by an iterator
	void erase(iterator p);

	// Find all values with a given key
	void findAll(int key);

private:

	// Generates node levels in the range [1, maxLevel).    
	int randomLevel() const;

	//Returns number of incoming and outgoing pointers
	static int nodeLevel(const Node* v);

	//creates a node on the heap and returns a pointer to it.   
	static Node* makeNode(int key, std::string val, int level);

	// Returns the first node for which node->key < searchKey is false  
	Node* lower_bound(int searchKey) const;

	/*
	* Returns a collection of Pointers to Nodes
	* result[i] hold the last node of level i+1 for which result[i]->key < searchKey is true
	*/
	vector<Node*> predecessors(int searchKey) const;

	// data members 
	const float probability;
	const int maxLevel;
	Node* head; // pointer to first node
	Node* NIL;  // last node
};

#endif