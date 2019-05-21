#include "header.h"

#ifndef RB_TREE_H_
#define RB_TREE_H_

template<class T>
class RedBlackTree;

template<class T>
class RedBlackNode;

template<class T>
class RedBlackTree
{
public:
	RedBlackTree(const T & negInf);
	~RedBlackTree();

	enum {RED,BLACK};	//利用枚举表示两种颜色

	typedef RedBlackNode<T> Node;

	bool isEmpty() const;
	void makeEmpty();

	bool find(const T & x) const;

	void insert(const T & x);
	
//private:
	Node *header;	//头节点
	Node *nullNode;	//空节点

	Node *current;
	Node *parent;	//父节点
	Node *grand;	//祖父节点
	Node *great;	//曾祖父节点
//////////////
	void printBRTree(Node *node);
	void printBRTree();
	void printLayer();
////////////
	void reclaimMemory(Node *t) const;

	void rotateWithLeftChild(Node * &k2) const;
	void rotateWithRightChild(Node * &k1) const;
	void doubleRotateWithLeftChild(Node * &k3) const;
	void doubleRotateWithRightChild(Node * &k1) const;

	void handleReorient(const T &item);
	RedBlackNode<T> * rotate(const T & item, Node *theParent) const;
};
//红黑树节点
template<class T>
class RedBlackNode
{
public:
	T		element;
	RedBlackNode	*left;
	RedBlackNode	*right;
	int				color;

	RedBlackNode(const T & theElement = T(),
		RedBlackNode *lt = NULL,
		RedBlackNode *rt = NULL,
		int c = RedBlackTree<T>::BLACK)
		:element(theElement), left(lt), right(rt), color(c){}

	friend class RedBlackTree<T>;	//将红黑树作为友元类用于操作私有对象
};

////////////////
template<class T>
void RedBlackTree<T>::printLayer()
{
	cout<<"Print Layout"<<endl;
	if(header == NULL)
		return;
	queue<Node*> *que = new queue<Node*>();
	Node *node = NULL;
	que->push(header);
	while(!que->empty())
	{
		node = que->front();
		cout<<"value: "<<node->element<<",color: "<<node->color<<"\t";
		if(node->left != NULL)
			que->push(node->left);
		if(node->right != NULL)
			que->push(node->right);
		que->pop();
	}
	cout<<endl;
}


template<class T>
void RedBlackTree<T>::printBRTree(Node *node)
{
	if(node == NULL)
		return;
	printBRTree(node->left);
	cout<<"value: "<<node->element<<",color: "<<node->color<<"\t";
	printBRTree(node->right);
}

template<class T>
void RedBlackTree<T>::printBRTree()
{
	printBRTree(header);
}
///////////////////
template<class T>
RedBlackTree<T>::RedBlackTree(const T & negInf)
{
	nullNode = new Node();
	nullNode->left = nullNode->right = nullNode;

	header = new Node(negInf);
	header->left = header->right = nullNode;	//左右孩子都指向空节点
}

template<class T>
RedBlackTree<T>::~RedBlackTree()
{
	delete nullNode;
	delete header;
}

//向红黑树中插入数据，在插入过程中需要实现自动平衡
template<class T>
void RedBlackTree<T>::insert(const T & x)
{
	current = parent = grand = header;
	nullNode->element = x;

	while (current->element != x)	//不能插入相同的数据
	{
		great = grand; grand = parent; parent = current;	//旧的元素往上升一辈
		current = x < current->element ? current->left : current->right;	//向下搜寻

		//1.如果当前节点的左右儿子都是红色，需要进行处理
		if (current->left->color == RED && current->right->color == RED)
			handleReorient(x);
	}

	if (current != nullNode)
		throw "element repeat!";

	current = new Node(x, nullNode, nullNode);
	if (x < parent->element)
		parent->left = current;
	else
		parent->right = current;

	//对于新插入节点也要进行处理
	handleReorient(x);
}

//向右旋转
template<class T>
void RedBlackTree<T>::rotateWithLeftChild(Node * &k2) const
{
	Node *k1 = k2->left;
	//横向移动
	k2->left = k1->right;
	//上升和下降
	k1->right = k2;
	k2 = k1;
}
//向左旋转
template<class T>
void RedBlackTree<T>::rotateWithRightChild(Node * &k1) const
{
	Node *k2 = k1->right;
	k1->right = k2->left;
	k2->left = k1;
	k1 = k2;
}
//向右双旋转
template<class T>
void RedBlackTree<T>::doubleRotateWithLeftChild(Node * &k3) const
{
	rotateWithRightChild(k3->left);
	rotateWithLeftChild(k3);
}

//向左双旋转
template<class T>
void RedBlackTree<T>::doubleRotateWithRightChild(Node * &k1) const
{
	rotateWithLeftChild(k1->right);
	rotateWithRightChild(k1);
}

//根据红黑规则调整红黑树
template<class T>
void RedBlackTree<T>::handleReorient(const T &item)
{
	//变色
	//1.对于有两个红色子节点的节点进行变色处理
	current->color = RED;
	current->left->color = BLACK;
	current->right->color = BLACK;

	//2.当前节点的父节点为红色
	if (parent->color == RED)
	{
		//爷爷颜色变红
		grand->color = RED;
		//进行旋转处理
		//判断如果是内部孙子就有两次旋转，外部孙子一次旋转
		if (item < grand->element != item < parent->element)
			parent = rotate(item, grand);
		current = rotate(item, great);
		//旋转之后把当前节点变黑
		current->color = BLACK;
	}
	//根节点必须黑色
	header->right->color = BLACK;
}

//根据内容自动判断旋转方向：
//左子树向右转->LL
//左子树向左转->LR
//右子树向右转->RL
//右子树向左转->RR
//参数1：当前节点数据，参数2：祖父节点（应比当前item大两辈）
template<class T>
RedBlackNode<T> * RedBlackTree<T>::rotate(const T & item, Node *theParent) const
{
	if (item < theParent->element)	//左子树
	{
		//如果item小于theParent->left->element,证明item是左子孙，要向右转
		item < theParent->left->element ?
			rotateWithLeftChild(theParent->left) :
			rotateWithRightChild(theParent->left);

		return theParent->left;
	}
	else	//右子树
	{
		item < theParent->right->element ?
			rotateWithLeftChild(theParent->right) :
			rotateWithRightChild(theParent->right);

		return theParent->right;
	}
}
//判断红黑树是否为空
template<class T>
bool RedBlackTree<T>::isEmpty() const
{
	return header->right == nullNode;
}

//清空红黑树
template<class T>
void RedBlackTree<T>::makeEmpty()
{
	reclaimMemory(header->right);
	header->right = nullNode;
}

template<class T>
void RedBlackTree<T>::reclaimMemory(Node *t) const
{
	//递归清除
	//t等于t->left时证明到底了停止递归（都是nullNode）
	if (t != t->left)
	{
		reclaimMemory(t->left);
		reclaimMemory(t->right);
		delete t;
	}
}

//清空红黑树
template<class T>
bool RedBlackTree<T>::find(const T & x) const
{
	nullNode->element = x;

	Node *curr = header->right;

	while (1)
	{
		if (x < curr->element)
			curr = curr->left;
		else if (x>curr->element)
			curr = curr->right;
		else if (curr != nullNode)
			return true;
		else
			return false;
	}
}

#endif


//RB_Tree.cpp
//红黑树实现
int main1()
{
	const int NEG_INF = -99999;
	//使用一个很大的负数作为头指针的值
	RedBlackTree<int> t(NEG_INF);
	t.insert(50);
	t.insert(40);
	t.insert(30);
	t.insert(20);

	//如果不是红黑树，上面的输入会退化为链表，下面是验证过程
	cout << "First Layer	:" << t.header->right->element << endl;
	cout << "Second Layer	:" << t.header->right->left->element << " " << t.header->right->right->element << endl;
	cout << "Third Layer	:" << t.header->right->left->left->element << endl;
	//查找数据
	cout << (t.find(20) ? "Find" : "Not find") << endl;
	//清空数据
	cout << t.isEmpty() << endl;
	t.makeEmpty();
	cout << t.isEmpty() << endl;

	system("pause");
	return 0;
}

int main()
{
	RedBlackTree<int> *rbTree = new RedBlackTree<int>(-99999);
	for(int i=0;i<10;i++)
	{
		rbTree->insert(i);
		cout<<"Tree"<<endl;
//		rbTree->printBRTree();
//		cout<<endl<<endl;
	}
//	cout<<"Min: "<<rbTree->minimum()->value<<endl;
//	cout<<"Max: "<<rbTree->maxminum()->value<<endl;
	rbTree->printLayer();
//	rbTree->remove(4);
//	rbTree->printLayer();
	return 0;
}


