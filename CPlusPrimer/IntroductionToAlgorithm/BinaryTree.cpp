#include<iostream>
using namespace std;

template <class T>
struct Node
{
	T value;
	Node<T> *left;
	Node<T> *right;
	Node(T data = 0)
	{
		value = data;
		left = right = NULL;
	};
};

template<class T>
class BinaryTree
{
private:
	Node<T> *root;
public:
	BinaryTree();
	BinaryTree(T *arr, int length);
	~BinaryTree();
	void preOrder();
	void inOrder();
	void postOrder();
	void insert(T data);
	bool remove(T data);
	Node<T>* min();
	Node<T>* max();
	Node<T>* search(T data);
//	int maxDepth();
//	int minDepth();
	void preOrder(Node<T> *node );
	void inOrder(Node<T> *node );
	void postOrder(Node<T> *node );
	void insert(Node<T> **node, T data );
	Node<T>* search(Node<T> *node , T data);
	int maxDepth(Node<T> *node );
	int minDepth(Node<T> *node );
	int maxDepth();
	int minDepth();
};


template<class T>
BinaryTree<T>::BinaryTree()
{
	root = NULL;
}

template<class T>
BinaryTree<T>::BinaryTree(T *arr, int length)
{
	if(arr==NULL || length<=0)
		root = NULL;
	else
	{
		root = new Node<T>(arr[0]);
		for(int i=1;i<length;i++)
		{
			insert(arr[i]);
		}
	}
}

template<class T>
BinaryTree<T>::~BinaryTree()
{
}

template<class T>
void BinaryTree<T>::preOrder(Node<T> *node)
{
	if(node==NULL)
		return;
	cout<<node->value<<"\t";
	preOrder(node->left);
	preOrder(node->right);
}

template<class T>
void BinaryTree<T>::inOrder(Node<T> *node)
{
	if(node==NULL)
		return;
	inOrder(node->left);
	cout<<node->value<<"\t";
	inOrder(node->right);
}

template<class T>
void BinaryTree<T>::postOrder(Node<T> *node)
{
	if(node==NULL)
		return;
	postOrder(node->left);
	postOrder(node->right);
	cout<<node->value<<"\t";
}

template<class T>
void BinaryTree<T>::insert(Node<T> **node, T data)
{
	if((*node) == NULL)
	{
		*node = new Node<T>(data);
		return;
	}
	if(data < (*node)->value)
		insert(&(*node)->left,data);
	else
		insert(&(*node)->right,data);	
}

template<class T>
Node<T>* BinaryTree<T>::search(Node<T> *node, T data)
{
	if(node == NULL)
		return NULL;
	if(node->value == data)
		return node;
	if(node->value < data)
		return search(node->right,data);
	return search(node->left, data);
}

template<class T>
void BinaryTree<T>::preOrder()
{
	std::cout<<std::endl;
	preOrder(root);
	std::cout<<std::endl;
}

template<class T>
void BinaryTree<T>::inOrder()
{
	std::cout<<std::endl;
	inOrder(root);
	std::cout<<std::endl;
}

template<class T>
void BinaryTree<T>::postOrder()
{
	std::cout<<std::endl;
	postOrder(root);
	std::cout<<std::endl;
}

template<class T>
void BinaryTree<T>::insert(T data)
{
	insert(&root,data);
}

template<class T>
bool BinaryTree<T>::remove(T data)
{
	remove(root,data);
}

template<class T>
Node<T>* BinaryTree<T>::min()
{
	Node<T> *node = root;
	while(node->left != NULL)
		node = node->left;
	return node;
}

template<class T>
Node<T>* BinaryTree<T>::max()
{
	Node<T> *node = root;
	while(node->right != NULL)
		node = node->right;
	return node;
}

template<class T>
Node<T>* BinaryTree<T>::search(T data)
{
	return search(root,data);
}

int RandomCreate(int seed, int area)
{
	srand(seed);
	srand(rand());
	srand(rand());
	srand(rand());
	return rand()%area;
}



template<class T>
int BinaryTree<T>::maxDepth(Node<T> *node)
{
	if(node==NULL)
		return 0;
	int left = maxDepth(node->left);
	int right = maxDepth(node->right);
	
	return left>right?left:right+1;
}



template<class T>
int BinaryTree<T>::minDepth(Node<T> *node)
{
	return 0;
}

template<class T>
int BinaryTree<T>::maxDepth()
{
	return maxDepth(root);
}

template<class T>
int BinaryTree<T>::minDepth()
{
	return minDepth(root);
}



int main()
{
	int len = 10;
	std::cout<<"Please enter length:";
	std::cin>>len;
	if(len>10000)
		len=10000;
	int *arr = new int[len];
	for(int i=0;i<len;i++)
		arr[i] = RandomCreate(10*i+10,len*10);
	BinaryTree<int> *bt = new BinaryTree<int>(arr,len);
	bt->inOrder();
	bt->postOrder();
	bt->preOrder();
	std::cout<<"Max: "<<bt->max()->value<<endl;
	cout<<"Min: "<<bt->min()->value<<endl;
	cout<<"Max Depth: "<<bt->maxDepth()<<endl;

	return 0;
}

