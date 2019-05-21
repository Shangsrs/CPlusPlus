#include <iostream>
#include <string>
#include <queue>

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
	RBNode(T _value)
	{
		value = _value;
		parent = left = right = NULL;
		color = RB_NAME::BLACK;
	};
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
	RBTree():root(NULL){};
	RBNode<T>* minimum(RBNode<T> *node = NULL);
	RBNode<T>* maxminum(RBNode<T> *node = NULL);
	RBNode<T>* successor(RBNode<T> *node);
	void printBRTree(RBNode<T> *node);
	void printBRTree();
	void printLayer();

	void leftRotate(RBNode<T> *node);
	void rightRotate(RBNode<T> *node);
	void insert(RBNode<T> *node);
	void insert(T value);
	void insertFixup(RBNode<T> *node);
	void transplant(RBNode<T> *u,RBNode<T> *v);
	void remove(RBNode<T> *z);
	void remove(T v);
	void deleteFixup(RBNode<T> *node);
};

template<class T>
void RBTree<T>::printLayer()
{
	if(root == NULL)
		return;
	queue<RBNode<T>*> *que = new queue<RBNode<T>*>();
	RBNode<T> *node = NULL;
	que->push(root);
	while(!que->empty())
	{
		node = que->front();
		cout<<"value: "<<node->value<<",color: "<<node->color<<"\t";
		if(node->left != NULL)
			que->push(node->left);
		if(node->right != NULL)
			que->push(node->right);
		que->pop();
	}
	cout<<endl;
}


template<class T>
void RBTree<T>::printBRTree(RBNode<T> *node)
{
	if(node == NULL)
		return;
	printBRTree(node->left);
	cout<<"value: "<<node->value<<",color: "<<node->color<<"\t";
	printBRTree(node->right);
}

template<class T>
void RBTree<T>::printBRTree()
{
	printBRTree(root);
}


template<class T>
RBNode<T>* RBTree<T>::minimum(RBNode<T> *node)
{
	if(node == NULL)
		node = root;
	while(node->left!=NULL)
		node = node->left;
	return node;
}


template<class T>
RBNode<T>* RBTree<T>::maxminum(RBNode<T> *node)
{
	if(node == NULL)
		node = root;
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
void RBTree<T>::insert(T value)
{
	RBNode<T> *node = new RBNode<T>(value);
	insert(node);
}


template<class T>
void RBTree<T>::insert(RBNode<T> *z)
{
//	cout<<"insert"<<endl;
	RBNode<T> *x = root;
	RBNode<T> *y = NULL;
	while(x!=NULL)
	{
		y=x;
		if(z->value < x->value)
			x=x->left;
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
//	cout<<"insert done"<<endl;
}

template<class T>
void RBTree<T>::insertFixup(RBNode<T> *z)
{
	if(z == NULL || z == root)
	{
		root->color = RB_NAME::BLACK;
		return;
	}
	while(z->parent != NULL &&   z->parent->color == RB_NAME::RED)
	{
//		if(z->parent->parent == NULL)
//			break;
		cout<<"insertFixup-->"<<z->value<<" Color: "<<z->color<<endl;
		if(z->parent == z->parent->parent->left)
		{
			RBNode<T> *y = z->parent->parent->right;
			if(y!=NULL && y->color == RB_NAME::RED)
			{
				z->parent->color = RB_NAME::BLACK;
				y->color = RB_NAME::BLACK;
				z->parent->parent->color = RB_NAME::RED;
				z = z->parent->parent;
			}
			else if(z == z->parent->right)
			{
				z = z->parent;
				leftRotate(z);
			}
			if(z!=NULL && z->parent!=NULL)
				z->parent->color = RB_NAME::BLACK;
			if(z!=NULL && z->parent!=NULL && z->parent->parent!=NULL)
			{
				z->parent->parent->color = RB_NAME::RED;
				rightRotate(z->parent->parent);
			}
		}
		else
		{
			RBNode<T> *y = z->parent->parent->left;
			if(y!=NULL && y->color == RB_NAME::RED)
			{
				z->parent->color = RB_NAME::BLACK;
				y->color = RB_NAME::BLACK;
				z->parent->parent->color = RB_NAME::RED;
				z = z->parent->parent;
			}
			else if(z == z->parent->left)
			{
				z = z->parent;
				rightRotate(z);
			}
			if(z!=NULL && z->parent!=NULL)
				z->parent->color = RB_NAME::BLACK;
			if(z!=NULL && z->parent!=NULL && z->parent->parent!=NULL)
			{
				z->parent->parent->color = RB_NAME::RED;
				leftRotate(z->parent->parent);
			}
		}
	}
	root->color = RB_NAME::BLACK;
//	cout<<"insertFixup done"<<endl;
}


template<class T>
void RBTree<T>::transplant(RBNode<T> *u,RBNode<T> *v)
{
	cout<<"transplant "<<u<<" "<<v<<endl;
	if(u == NULL || v == NULL)
		return;
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
	RB_NAME::COLOR yOriginalColor = y->color;
	if(z->left == NULL)
	{
		x = z->right;
		cout<<"Remove node "<<z->value<<endl;
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
//	delete z;
}

template<class T>
void RBTree<T>::remove(T v)
{
	RBNode<T> *node = root;
	while(node!=NULL)
	{
//		cout<<"Remove "<<node->value<<" " <<v<<endl;
		if(node->value == v)
			break;
		else if(node->value < v)
			node = node -> right;
		else 
			node = node -> left;
	}
	if(node != NULL)
		remove(node);
//	cout<<"Remove "<<node<<" " <<v<<endl;
}

template<class T>
void RBTree<T>::deleteFixup(RBNode<T> *x)
{
	if(x==NULL)
		return;
	RBNode<T> *w = NULL;
	cout<<"Delete fixup "<<x->value<<endl;
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
				w->left->color = RB_NAME::BLACK;
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
				w->right->color = RB_NAME::BLACK;
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
	RBTree<int> *rbTree = new RBTree<int>();
	for(int i=0;i<6;i++)
	{
		rbTree->insert(i);
//		rbTree->printBRTree();
		rbTree->printLayer();
		cout<<endl<<endl;
	}
	rbTree->printBRTree();
	cout<<endl;
	cout<<"Min: "<<rbTree->minimum()->value<<endl;
	cout<<"Max: "<<rbTree->maxminum()->value<<endl;
	rbTree->printLayer();
	cout<<endl;
//	rbTree->remove(4);
//	rbTree->printLayer();
	cout<<endl;
	rbTree->printBRTree();
	cout<<endl;
	return 0;
}

