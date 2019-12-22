// ===================================================
// Program:	hwec - Red Black Trees
// ===================================================
// Programmer: Aaron Geesink
// Class: CS 1D - 5:00 PM M W
// ===================================================
// The purpose of this program is to create and display a red-black
// tree like the one in the extra credit we did in class
// ===================================================

#include "redBlackTree.h"
using namespace std;

int compare_int(void* leftp, void* rightp);
void print_tree_helper(node n, int indent);
void print_tree(rbtree t);

int main()
{
	cout << "===================================================\n"
		<< "Program: hwec - Red Black Trees\n"
		<< "===================================================\n"
		<< "Programmer: Aaron Geesink\n"
		<< "Class: CS 1D - 5:00 PM M W\n"
		<< "===================================================\n"
		<< "The purpose of this program is to create and display a red-black\n"
		<< "tree like the one in the extra credit we did in class\n"
		<< "===================================================\n\n";

	RBTree rbt;
	rbtree t = rbt.rbtree_create();

	cout << "Here is the tree after inserting the values:\n\n";

	rbt.rbtree_insert(t, (void*)15, (void*)15, compare_int);
	rbt.rbtree_insert(t, (void*)5, (void*)5, compare_int);
	rbt.rbtree_insert(t, (void*)16, (void*)16, compare_int);
	rbt.rbtree_insert(t, (void*)4, (void*)4, compare_int);
	rbt.rbtree_insert(t, (void*)7, (void*)7, compare_int);
	rbt.rbtree_insert(t, (void*)3, (void*)3, compare_int);

	print_tree(t);

	system("pause");
	return 0;
}

// ===================================================

/*
 * Compare two nodes
 */
int compare_int(void* leftp, void* rightp)
{
	int left = (int)leftp;
	int right = (int)rightp;
	if (left < right)
		return -1;
	else if (left > right)
		return 1;
	else
	{
		assert(left == right);
		return 0;
	}
}
/*
 * Print RBTRee
 */
void print_tree_helper(node n, int indent)
{
	int i;
	if (n == NULL)
	{
		fputs("<empty tree>", stdout);
		return;
	}
	if (n->right != NULL)
	{
		print_tree_helper(n->right, indent + INDENT_STEP);
	}
	for (i = 0; i < indent; i++)
		fputs(" ", stdout);
	if (n->color == BLACK)
		cout << (int)n->key << endl;
	else
		cout << "[" << (int)n->key << "]" << endl;
	if (n->left != NULL)
	{
		print_tree_helper(n->left, indent + INDENT_STEP);
	}
}

void print_tree(rbtree t)
{
	print_tree_helper(t->root, 0);
	puts("");
}