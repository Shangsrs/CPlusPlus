#include <iostream>
using namespace std;

template<class T>
struct TreeNode
{
	TreeNode<T> *parent;
	TreeNode<T> *left;
	TreeNode<T> *right;
	T value;
	enum COLOR{RED,BLACK};
	COLOR color;	
};

int main()
{
	return 0;
}

