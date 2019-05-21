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
	BNode* root;
public:
	BNode* minimum(BNode *node);
	BNode* maxminum(BNode *node);
	BNode* successor(BNode *node);
	void insert(T v);
	void delete(BNode *z);
	void transplant(BNode *u, BNode *v);
};

template<class T>
BNode* BinaryTree::minimum(BNode *node)
{
	while(node->left!=NULL)
		node = node->left;
	return node;
}


template<class T>
BNode* BinaryTree::maxminum(BNode *node)
{
	while(node->right!=NULL)
		node = node->right;
	return node;
}

template<class T>
BNode* BinaryTree::successor(BNode *node)
{
	if(node->right != NULL)
		return minimum(node);
	BNode *y=node->parent;
	while(y!=NULL && node == y->right)
	{
		node = y;
		y = y->parent;
	}
	return y;
}


template<class T>
void BinaryTree::insert(BNode *z)
{
	BNode *y = NULL;
	BNode *x = root;
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
void BinaryTree::delete(BNode *z)
{
	if(z == NULL)
		return;
	if(z->left == NULL)
		transplant(z,z->right);
	else if(z->right == NULL)
		transplant(z,z->left);
	else
	{
		BNode *y = minimum(z->right);
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
void BinaryTree::transplant(BNode *u, BNode *v)
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

