#include <iostream>
using namespace std;


template<class T>
struct TreeNode
{
	TreeNode<T> *_parent;
	TreeNode<T> *_left;
	TreeNode<T> *_right;
	T _value;
	enum COLOR{RED,BLACK};
	COLOR _color;	
	//Tail Node
	TreeNode(TreeNode *node)
	{
		_value = 0;
		_parent = node;
		_left = _right = NULL;
		_color = BLACK;
	};
	//Node
	TreeNode(TreeNode *node,T value)
	{
		_value = value;
		_parent = node;
		_left = new TreeNode(this);
		_right = new TreeNode(this);
		_color = BLACK;
	};
};


template<class T>
class BinaryTree
{
private:
	TreeNode<T> *root;

public:
	void leftRotate(TreeNode<T> *node);
	void rightRotate(TreeNode<T> *node);
	void insert(TreeNode<T> *node);
	void insertFixup(TreeNode<T> *node);
	
};

template<class T>
void BinaryTree::leftRotate(TreeNode<T> *x)
{
	if(x==NULL || x->_right==NULL)
		return;
	TreeNode<T> *y = x->_right;
//1
	x->_right = y->_left;
	if(y->_left!=NULL)
		y->_left->_parent = x;
//2
	y->_parent = x->_parent;
	if(x->_parent == NULL)
		root=y;
	else if(x==x->_parent->_left)
		x->_parent->_left = y;
	else
		x->_parent->_right = y;
//3
	x->_parent = y;
	y->_left = x;
		
}

template<class T>
void BinaryTree::rightRotate(TreeNode<T> *y)
{
	if(y == NULL || y->_left == NULL)
		return;
	TreeNode<T> *x = y->_left;
//1
	y->_left = x->_right;
	if(x->_right != NULL)
		x->_right->_parent = y;
//2
	x->_parent = y->_parent;
	if(y->_parent==NULL)
		root = x;
	else if(y == y->_parent->_left)
		y->_parent->_left = x;
	else 
		y->_parent->_right = x;
//3
	x->_left = y;
	y->_parent = x;
}

template<class T>
void BinaryTree::insert(TreeNode<T> *z)
{
	TreeNode<T> *x = root;
	TreeNode<T> *y = NULL;
	while(x!=NULL)
	{
		y=x;
		if(z->_value < x->_value)
			x=x->_left
		else
			x=x->_right;
	}
	z->_parent = y;
	if(y == NULL)
		root = z;
	else if(z->_value<y->_value)
		y->_left = z;
	else
		y->_right = z;
	z->_left=z->_right = NULL;
	z->_color = RED;
	insertFixup(z);
	
}

template<class T>
void BinaryTree::insertFixup(TreeNode<T> *z)
{
	while(z->_parent->_color == RED)
	{
		if(z->_parent == z->_parent->_parent->_left)
		{
			TreeNode<T> *y = z->_parent->_parent->_right;
			if(y->_color == RED)
			{
				z->_parent->_color = BLACK;
				y->_color = BLACK;
				z->_parent->_parent->_color = RED;
				z = z->_parent->_parent
			}
			else if(z == z->_parent->_right)
			{
				z = z->_parent;
				leftRotate(z);
			}
			z->_parent->_color = BLACK;
			z->_parent->_parent->_color = RED;
			rightRotate(z->_parent->_parent);
		}
		else
		{
			TreeNode<T> *y = z->_parent->_parent->_left;
			if(y->_color == RED)
			{
				z->_parent->_color = BLACK;
				y->_color = BLACK;
				z->_parent->_parent->_color = RED;
				z = z->_parent->_parent
			}
			else if(z == z->_parent->_left)
			{
				z = z->_parent;
				rightRotate(z);
			}
			z->_parent->_color = BLACK;
			z->_parent->_parent->_color = RED;
			leftRotate(z->_parent->_parent);
		}
	}
}


int main()
{
	return 0;
}

