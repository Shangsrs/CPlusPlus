#include <iostream>
using namespace std;

namespace RB_NAME
{
	enum COLOR{RED,BLACK};
};

template<class T>
struct RBNode
{
	RBNode<T> *parent;
	RBNode<T> *left;
	RBNode<T> *right;
	T value;
	RB_NAME::COLOR color;	
	//Tail Node
	RBNode(RBNode<T> *node)
	{
		value = 0;
		parent = node;
		left = right = NULL;
		color = RB_NAME::BLACK;
	};
	//Node
	RBNode(RBNode<T> *node,T value)
	{
		value = value;
		parent = node;
		left = NULL;
		color = RB_NAME::BLACK;
	};
};


template<class T>
class RBTree
{
private:
	RBNode<T> *root;

public:
	RBNode<T>* minimum(RBNode<T> *node);
	RBNode<T>* maxminum(RBNode<T> *node);
	RBNode<T>* successor(RBNode<T> *node);

	void leftRotate(RBNode<T> *node);
	void rightRotate(RBNode<T> *node);
	void insert(RBNode<T> *node);
	void insertFixup(RBNode<T> *node);
	void transplant(RBNode<T> *u,RBNode<T> *v);
	void remove(RBNode<T> *z);
	void remove(T v);
	void deleteFixup(RBNode<T> *node);
};

template<class T>
RBNode<T>* RBTree<T>::minimum(RBNode<T> *node)
{
	while(node->left!=NULL)
		node = node->left;
	return node;
}


template<class T>
RBNode<T>* RBTree<T>::maxminum(RBNode<T> *node)
{
	while(node->right!=NULL)
		node = node->right;
	return node;
}

template<class T>
RBNode<T>* RBTree<T>::successor(RBNode<T> *node)
{
	if(node->right != NULL)
		return minimum(node);
	RBNode<T> *y=node->parent;
	while(y!=NULL && node == y->right)
	{
		node = y;
		y = y->parent;
	}
	return y;
}


template<class T>
void RBTree<T>::leftRotate(RBNode<T> *x)
{
	if(x==NULL || x->right==NULL)
		return;
	RBNode<T> *y = x->right;
//1
	x->right = y->left;
	if(y->left!=NULL)
		y->left->parent = x;
//2
	y->parent = x->parent;
	if(x->parent == NULL)
		root=y;
	else if(x==x->parent->left)
		x->parent->left = y;
	else
		x->parent->right = y;
//3
	x->parent = y;
	y->left = x;
		
}

template<class T>
void RBTree<T>::rightRotate(RBNode<T> *y)
{
	if(y == NULL || y->left == NULL)
		return;
	RBNode<T> *x = y->left;
//1
	y->left = x->right;
	if(x->right != NULL)
		x->right->parent = y;
//2
	x->parent = y->parent;
	if(y->parent==NULL)
		root = x;
	else if(y == y->parent->left)
		y->parent->left = x;
	else 
		y->parent->right = x;
//3
	x->left = y;
	y->parent = x;
}

template<class T>
void RBTree<T>::insert(RBNode<T> *z)
{
	RBNode<T> *x = root;
	RBNode<T> *y = NULL;
	while(x!=NULL)
	{
		y=x;
		if(z->value < x->value)
			x=x->left
		else
			x=x->right;
	}
	z->parent = y;
	if(y == NULL)
		root = z;
	else if(z->value<y->value)
		y->left = z;
	else
		y->right = z;
	z->left=z->right = NULL;
	z->color = RB_NAME::RED;
	insertFixup(z);
	
}

template<class T>
void RBTree<T>::insertFixup(RBNode<T> *z)
{
	while(z->parent->color == RB_NAME::RED)
	{
		if(z->parent == z->parent->parent->left)
		{
			RBNode<T> *y = z->parent->parent->right;
			if(y->color == RB_NAME::RED)
			{
				z->parent->color = RB_NAME::BLACK;
				y->color = RB_NAME::BLACK;
				z->parent->parent->color = RB_NAME::RED;
				z = z->parent->parent
			}
			else if(z == z->parent->right)
			{
				z = z->parent;
				leftRotate(z);
			}
			z->parent->color = RB_NAME::BLACK;
			z->parent->parent->color = RB_NAME::RED;
			rightRotate(z->parent->parent);
		}
		else
		{
			RBNode<T> *y = z->parent->parent->left;
			if(y->color == RB_NAME::RED)
			{
				z->parent->color = RB_NAME::BLACK;
				y->color = RB_NAME::BLACK;
				z->parent->parent->color = RB_NAME::RED;
				z = z->parent->parent
			}
			else if(z == z->parent->left)
			{
				z = z->parent;
				rightRotate(z);
			}
			z->parent->color = RB_NAME::BLACK;
			z->parent->parent->color = RB_NAME::RED;
			leftRotate(z->parent->parent);
		}
	}
}


template<class T>
void RBTree<T>::transplant(RBNode<T> *u,RBNode<T> *v)
{
	if(u->parent == NULL)
		root = v;
	else if(u == u->parent->left)
		u->parent->left = v;
	else
		u->parent->right = v;
	if(v==NULL)
		v->parent = u->parent;
}

template<class T>
void RBTree<T>::remove(RBNode<T> *z)
{
	if(z == NULL)
		return;
	RBNode<T> *y = z;
	RBNode<T> *x = NULL;
	COLOR yOriginalColor = y->color;
	if(z->left == NULL)
	{
		x = z->right;
		transplant(z,z->right);
	}
	else if(z->right == NULL)
	{
		x = z->left;
		transplant(z,z->left);
	}
	else
	{
		y = minimum(z->right);
		yOriginalColor = y->color;
		x = y->right;
		if(y->parent == z)
			x->parent = y;
		else
		{
			transplant(y,y->right);
			y->right->parent = y;
		}
		transplant(z,y);
		y->left = z->left;
		y->left->parent = y;
		y->color = z->color;			
	}
	if(yOriginalColor == RB_NAME::BLACK)
		deleteFixup(x);
	delete z;
}

template<class T>
void RBTree<T>::remove(T v)
{
	RBNode<T> *node = root;
	while(node!=NULL)
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
void RBTree<T>::deleteFixup(RBNode<T> *x)
{
	RBNode<T> *w = NULL;
	while(x != root && x->color == RB_NAME::BLACK)
	{
		if(x == x->parent->left)
		{
			w = x->parent->right;
			if(w->color == RB_NAME::RED)
			{
				w->color = RB_NAME::BLACK;
				x->parent->color = RB_NAME::RED;
				leftRotate(x->parent);
				w = x->parent->right;
			}
			if(w->left->color == RB_NAME::BLACK && w->right->color == RB_NAME::BLACK)
			{
				w->color = RB_NAME::RED;
				x = x->parent;
			}
			else if(w->right->color == RB_NAME::BLACK)
			{
				w->left->color == RB_NAME::BLACK;
				w->color = RB_NAME::RED;
				rightRotate(w);
				w = x->parent->right;
			}
			w->color = x->parent->color;
			x->parent->color = RB_NAME::BLACK;
			w->right->color = RB_NAME::BLACK;
			leftRotate(x->parent);
			x = root;
		}
		else
		{
			w = x->parent->left;
			if(w->color == RB_NAME::RED)
			{
				w->color = RB_NAME::BLACK;
				x->parent->color = RB_NAME::RED;
				rightRotate(x->parent);
				w = x->parent->left;
			}
			if(w->right->color == RB_NAME::BLACK && w->left->color == RB_NAME::BLACK)
			{
				w->color = RB_NAME::RED;
				x = x->parent;
			}
			else if(w->left->color == RB_NAME::BLACK)
			{
				w->right->color == RB_NAME::BLACK;
				w->color = RB_NAME::RED;
				leftRotate(w);
				w = x->parent->left;
			}
			w->color = x->parent->color;
			x->parent->color = RB_NAME::BLACK;
			w->left->color = RB_NAME::BLACK;
			rightRotate(x->parent);
			x = root;
		}
	}
	x->color = RB_NAME::BLACK;
}



int main()
{
	return 0;
}

