#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <iostream>
#include <string>
using namespace std;

template <class T>
struct node
{
	T data;
	node<T> *left;
	node<T> *right;
};

template <class T>
class BinaryTree
{
public:
	BinaryTree();
	~BinaryTree();

	void insert(T data);
	node<T> *search(T data);
	void inorderPrint();
	void postorderPrint();
	void preorderPrint();
	void breadthFirstPrint();
	void print();

private:
	void destroyTree(node<T> *leaf);
	void insert(T data, node<T> *leaf);
	node<T> *search(T data, node<T> *leaf);
	void inorderPrint(node<T> *leaf);
	void postorderPrint(node<T> *leaf);
	void preorderPrint(node<T> *leaf);
	void breadthFirstPrint(node<T> *leaf);
	void levelPrint(node<T> *leaf, int level);
	int height(node<T> *leaf);
	void print(const string& prefix, node<T>* leaf, bool isLeft);

	node<T> *root;
};

template<class T>
inline BinaryTree<T>::BinaryTree()
{
	root = NULL;
}

template<class T>
inline BinaryTree<T>::~BinaryTree()
{
	destroyTree(root);
}

template<class T>
inline void BinaryTree<T>::destroyTree(node<T> * leaf)
{
	if (leaf != NULL) 
	{
		destroyTree(leaf->left);
		destroyTree(leaf->right);
		delete leaf;
	}
}

template<class T>
inline void BinaryTree<T>::insert(T data)
{
	if (root != NULL)
	{
		insert(data, root);
	}
	else
	{
		root = new node<T>;
		root->data = data;
		root->left = NULL;
		root->right = NULL;
	}
}

template<class T>
inline void BinaryTree<T>::insert(T data, node<T>* leaf)
{
	if (data < leaf->data)
	{
		if (leaf->left != NULL)
		{
			insert(data, leaf->left);
		}
		else
		{
			leaf->left = new node<T>;
			leaf->left->data = data;
			leaf->left->left = NULL;
			leaf->left->right = NULL;
		}
	}
	else if (data >= leaf->data)
	{
		if (leaf->right != NULL)
		{
			insert(data, leaf->right);
		}
		else
		{
			leaf->right = new node<T>;
			leaf->right->data = data;
			leaf->right->right = NULL;
			leaf->right->left = NULL;
		}
	}
}

template<class T>
inline node<T> * BinaryTree<T>::search(T data)
{
	return search(data, root);
}

template<class T>
inline node<T>* BinaryTree<T>::search(T data, node<T>* leaf)
{
	if (leaf != NULL) 
	{
		if (data == leaf->data) 
		{
			return leaf;
		}
		if (data < leaf->data) 
		{
			return search(data, leaf->left);
		}
		else 
		{
			return search(data, leaf->right);
		}
	}
	else 
	{
		return NULL;
	}
}


template<class T>
inline void BinaryTree<T>::inorderPrint()
{
	inorderPrint(root);
	cout << "\n";
}

template<class T>
inline void BinaryTree<T>::inorderPrint(node<T>* leaf)
{
	if (leaf != NULL) 
	{
		inorderPrint(leaf->left);
		cout << leaf->data << ",";
		inorderPrint(leaf->right);
	}
}

template<class T>
inline void BinaryTree<T>::postorderPrint()
{
	postorderPrint(root);
	cout << "\n";
}

template<class T>
inline void BinaryTree<T>::postorderPrint(node<T>* leaf)
{
	if (leaf != NULL) 
	{
		postorderPrint(leaf->left);
		postorderPrint(leaf->right);
		cout << leaf->data << ",";
	}
}

template<class T>
inline void BinaryTree<T>::preorderPrint()
{
	preorderPrint(root);
	cout << "\n";
}

template<class T>
inline void BinaryTree<T>::preorderPrint(node<T>* leaf)
{
	if (leaf != NULL) 
	{
		cout << leaf->data << ",";
		preorderPrint(leaf->left);
		preorderPrint(leaf->right);
	}
}

template<class T>
inline void BinaryTree<T>::breadthFirstPrint()
{
	breadthFirstPrint(root);
	cout << "\n";
}

template<class T>
inline void BinaryTree<T>::print()
{
	print("", root, false);
}

template<class T>
inline void BinaryTree<T>::breadthFirstPrint(node<T>* leaf)
{
	int h = height(leaf);
	for (int i = 1; i <= h; i++)
		levelPrint(leaf, i);
}

template<class T>
inline void BinaryTree<T>::levelPrint(node<T>* leaf, int level)
{
	if (leaf == NULL)
		return;
	if (level == 1)
		cout << leaf->data << " ";
	else if (level > 1)
	{
		levelPrint(leaf->left, level - 1);
		levelPrint(leaf->right, level - 1);
	}
}

template<class T>
inline int BinaryTree<T>::height(node<T>* leaf)
{
	if (leaf == NULL)
		return 0;
	else
	{
		/* compute the height of each subtree */
		int lheight = height(leaf->left);
		int rheight = height(leaf->right);

		/* use the larger one */
		if (lheight > rheight)
			return(lheight + 1);
		else 
			return(rheight + 1);
	}
}

template<class T>
inline void BinaryTree<T>::print(const string & prefix, node<T>* leaf, bool isLeft)
{
	if (leaf != nullptr)
	{
		cout << prefix;

		if (isLeft)
		{
			cout << "„¥„Ÿ„Ÿ ";
		}
		else
		{
			cout << "„¤„Ÿ„Ÿ ";
		}
		//cout << (isLeft ? "„¥„Ÿ„Ÿ " : "„¤„Ÿ„Ÿ ");

		// print the value of the node
		cout << leaf->data << endl;

		// enter the next tree level - left and right branch
		print(prefix + (isLeft ? "„    " : "    "), leaf->right, true);
		print(prefix + (isLeft ? "„    " : "    "), leaf->left, false);
	}
}

#endif