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
	TreeNode(T value)
	{
		_value = value;
		_parent = NULL;
		_left = new TreeNode(this);
		_right = new TreeNode(this);
		_color = BLACK;
	};
};



int main()
{
	return 0;
}

