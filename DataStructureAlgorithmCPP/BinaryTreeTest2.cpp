#include "../header.h"

template<class T>
struct binaryTreeNode
{
	T _element;
	binaryTreeNode<T> *_left, *_right;
	binaryTreeNode(){_left = _right = NULL;}
	binaryTreeNode(const T& element,binaryTreeNode<T> *left=NULL,binaryTreeNode<T> *right=NULL)
	:_element(element),_left(left),_right(right){}
};

template<class T>
class binaryTree
{
public:
	virtual ~binaryTree(){};
	virtual bool empty() const = 0;
	virtual int size() const = 0;
	virtual void preOrder() = 0;
	virtual void postOrder() = 0;
	virtual void levelOrder() = 0;
};

template<class T>
class linkedBinaryTree : public binaryTree<binaryTreeNode<T>>
{
private:
	binaryTreeNode<T> *_root;
	int _size;
	static void preOrder(binaryTreeNode<T> *t);
	static void inOrder(binaryTreeNode<T> *t);
	static void postOrder(binaryTreeNode<T> *t);
	static int height(binaryTreeNode<T> *t);
	static void insert(binaryTreeNode<T> **c,binaryTreeNode<T> *t);
	static void dispose(binaryTreeNode<T> *t){delete t;}
public:
	linkedBinaryTree():_root(NULL),_size(0){}
	~linkedBinaryTree(){erase();}
	bool empty() const {return _size == 0;}
	int size() const {return _size;}
	void preOrder()
	{
		preOrder(_root);
	}
	void inOrder()
	{
		inOrder(_root);
	}
	void postOrder()
	{
		postOrder(_root);
	}
	void levelOrder();
	void erase()
	{
//		postOrder(dispose);
		_root = NULL;
		_size = 0;
	}
	int height() const {return height(root);}
	void insert(const T& element);
};


template<class T>
void linkedBinaryTree<T>::insert(const T& element)
{
	binaryTreeNode<T> *node  = new binaryTreeNode<T>(element);
	if(_root == NULL)
	{
		_root = node;
		return;
	}
	linkedBinaryTree<T>::insert(&_root,node);  
}

template<class T>
void linkedBinaryTree<T>::insert(binaryTreeNode<T> **c,binaryTreeNode<T> *t)
{
	if(*c == NULL)
		*c = t;
	else if((*c)->_element < t->_element)
		insert(&((*c)->_right),t);
	else
		insert(&((*c)->_left),t);
}

template<class T>
void linkedBinaryTree<T>::preOrder(binaryTreeNode < T > * t)
{
	if(t == NULL)
		return;
	cout<<t->_element<<"\t";
	preOrder(t->_left);
	preOrder(t->_right);
}

template<class T>
void linkedBinaryTree<T>::inOrder(binaryTreeNode < T > * t)
{
	if(t == NULL)
		return;
	inOrder(t->_left);
	cout<<t->_element<<"\t";
	inOrder(t->_right);
}

template<class T>
void linkedBinaryTree<T>::postOrder(binaryTreeNode < T > * t)
{
	if(t == NULL)
		return;
	postOrder(t->_left);
	postOrder(t->_right);
	cout<<t->_element<<"\t";
}

template<class T>
int linkedBinaryTree<T>::height(binaryTreeNode < T > * t)
{
	if(t == NULL)
		return 0;
	int hl = height(t->_left);
	int hr = height(t->_right);
	if(hl > hr)
		return hl+1;
	else
		return hr+1;
}


template<class T>
void linkedBinaryTree<T>::levelOrder()
{
}



int main()
{
	int length = 10;
	linkedBinaryTree<int> *tree = new linkedBinaryTree<int>;
	srand(time(NULL));
	for(int i=0;i<length;i++)
		tree->insert(rand()%10);
	tree->preOrder();	
	cout<<endl;
	tree->inOrder();	
	cout<<endl;
	tree->postOrder();	
	return 0;
}

