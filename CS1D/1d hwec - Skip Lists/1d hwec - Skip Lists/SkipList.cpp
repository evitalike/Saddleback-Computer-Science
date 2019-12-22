#include "SkipList.h"

//==============================================================================
// Class Skip_list member implementations

Skip_list::Skip_list() : probability(0.50), maxLevel(6)
{
	int headKey = std::numeric_limits<int>::min();
	head = new Node(headKey, "head", maxLevel);

	int nilKey = std::numeric_limits<int>::max();
	NIL = new Node(nilKey, "NIL", maxLevel);

	fill(head->forward.begin(), head->forward.end(), NIL);
}

Skip_list::~Skip_list() {
	auto node = head;
	while (node->forward[0]) {
		auto tmp = node;
		node = node->forward[0];
		delete tmp;
	}
	delete node;
}

string* Skip_list::find(int searchKey) const {
	string* res{};
	if (auto x = lower_bound(searchKey)) {
		if (x->key == searchKey && x != NIL) {
			res = &(x->value);
		}
	}
	return res;
}

void Skip_list::print() const {
	Node* list = head->forward[0];
	unsigned int currentMaximum = nodeLevel(head);

	for (int i = 1; i < currentMaximum; i++)
	{
		cout << "Level " << i - 1 << ":\n";
		Node* list = head->forward[0];
		while (list != NIL)
		{
			if (nodeLevel(list) >= i && list->forward[0]->value != "NIL")
			{
				cout << "Key: " << list->forward[0]->key
					<< " --> Value: " << setfill(' ') << setw(14) << left << list->forward[0]->value;
				cout << "\n";
			}
			list = list->forward[0];
		}
		cout << "\n";
	}
}

void Skip_list::insert(int searchKey, const string& newValue)
{
	auto preds = predecessors(searchKey);

	// create new node
	cout << "Key " << searchKey << ": ";
	const int newNodeLevel = randomLevel();
	auto newNodePtr = makeNode(searchKey, newValue, newNodeLevel);

	// connect pointers of predecessors and new node to respective successors
	for (int i = 0; i < newNodeLevel; ++i) {
		newNodePtr->forward[i] = preds[i]->forward[i];
		preds[i]->forward[i] = newNodePtr;
	}
}


void Skip_list::erase(int searchKey)
{
	auto preds = predecessors(searchKey);

	//check if the node exists
	auto node = preds[0]->forward[0];
	if (node->key != searchKey || node == NIL) {
		return;
	}

	// update pointers and delete node 
	for (size_t i = 0; i < nodeLevel(node); ++i) {
		preds[i]->forward[i] = node->forward[i];
	}
	delete node;
}

void Skip_list::erase(iterator p)
{
	auto preds = predecessors(p->key);

	//check if the node exists
	auto node = preds[0]->forward[0];
	if (node->key != p->key || node == NIL) {
		return;
	}

	// update pointers and delete node 
	for (size_t i = 0; i < nodeLevel(node); ++i) {
		preds[i]->forward[i] = node->forward[i];
	}
	delete node;
}

//###### private member functions ######
int Skip_list::nodeLevel(const Node* v) {
	return v->forward.size();
}

Skip_list::Node* Skip_list::makeNode(int key, std::string val, int level) {
	return new Node(key, val, level);
}

void Skip_list::findAll(int key)
{
	Node* list = head->forward[0];
	while (list != NIL)
	{
		if (list->key == key)
		{
			cout << list->key << " " << list->value << "\n";
		}
		list = list->forward[0];
	}
}

int Skip_list::randomLevel() const 
{
	rand();
	rand();
	int v = 1;
	int count = 0;
	while (((double)std::rand() / RAND_MAX) < probability && v < maxLevel)
	{
		v++;
		count++;
	}
	cout << "Num random rolls: " << count << "\n";
	return v;
}

Skip_list::Node* Skip_list::lower_bound(int searchKey) const {
	Node* x = head;

	for (unsigned int i = nodeLevel(head); i-- > 0;) {
		while (x->forward[i]->key < searchKey) {
			x = x->forward[i];
		}
	}
	return x->forward[0];
}

vector<Skip_list::Node*> Skip_list::predecessors(int searchKey) const
{
	vector<Node*> result(nodeLevel(head), nullptr);
	Node* x = head;

	for (unsigned int i = nodeLevel(head); i-- > 0;)
	{
		while (x->forward[i]->key < searchKey)
		{
			x = x->forward[i];
		}
		result[i] = x;
	}
	return result;
}

int Skip_list::size()
{
	Node* list = head->forward[0];
	int size = 0;
	while (list != NIL)
	{
		list = list->forward[0];
		size++;
	}
	return size - 1;
}
