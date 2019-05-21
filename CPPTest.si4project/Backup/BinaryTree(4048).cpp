#include "header.h"

template<class T>
struct BNode
{
	BNode *parent;
	BNode *left;
	BNode *right;
	T value;
};

template<class T>
class BinaryTree
{
	BNode<T>* root;
public:
	BNode<T>* minimum(BNode<T> *node);
	BNode<T>* maxminum(BNode<T> *node);
	BNode<T>* successor(BNode<T> *node);
	void insert(T v);
	void remove(BNode<T> *z);
	void remove(T v);
	void transplant(BNode<T> *u, BNode<T> *v);
};

template<class T>
BNode<T>* BinaryTree::minimum(BNode<T> *node)
{
	while(node->left!=NULL)
		node = node->left;
	return node;
}


template<class T>
BNode<T>* BinaryTree::maxminum(BNode<T> *node)
{
	while(node->right!=NULL)
		node = node->right;
	return node;
}

template<class T>
BNode<T>* BinaryTree::successor(BNode<T> *node)
{
	if(node->right != NULL)
		return minimum(node);
	BNode<T> *y=node->parent;
	while(y!=NULL && node == y->right)
	{
		node = y;
		y = y->parent;
	}
	return y;
}


template<class T>
void BinaryTree::insert(BNode<T> *z)
{
	BNode<T> *y = NULL;
	BNode<T> *x = root;
	while(x!=NULL)
	{
		y = x;
		if(z->value < x->value)
			x = x->left;
		else
			x = x->right;			
	}
	z->parent = y;
	if(y==NULL)
		root = x;
	else if(z->value < y->value)
		y->left = z;
	else
		y->right = z;	
}


template<class T>
void BinaryTree::remove(BNode<T> *z)
{
	if(z == NULL)
		return;
	if(z->left == NULL)
		transplant(z,z->right);
	else if(z->right == NULL)
		transplant(z,z->left);
	else
	{
		BNode<T> *y = minimum(z->right);
		if(y->parent != z)
		{
			transplant(y,y->right);
			y->right = z->right;
			y->right->parent = y;
		}
		transplant(z,y);
		y->left = z->left;
		y->left->parent = y;
	}
	delete z;
}

template<class T>
void BinaryTree::remove(T v)
{
	BNode<T> *node = root;
	while(node != NULL)
	{
		if(node->value == v)
			break;
		else if(node->value < v)
			node = node->left;
		else 
			node = node ->right;
	}
	if(node != NULL)
		remove(node);
}


template<class T>
void BinaryTree::transplant(BNode<T> *u, BNode<T> *v)
{
	if(u->parent == NULL)
		root = v;
	else if(u == u->parent->left)
		u->parent->left = v;
	else 
		u->parent->right = v;
	if(v != NULL)
		v->parent = u->parent;
}

int main()
{
	return 0;
}

