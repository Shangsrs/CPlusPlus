#include <iostream>
using namespace std;

template<class T>
class listNode
{
private:
	T value;
	listNode *nextNode;
public:
	listNode(){this->nextNode = NULL;};
	listNode(T data)
	{
		value = data;
		this->nextNode = NULL;
	}
	listNode(T data,listNode *node)
	{
		value = data;
		node->nextNode = this;
		this->nextNode = NULL;
	};
	~listNode(){};
	listNode* next(){return this->nextNode;};
	void setNext(listNode *node)
	{
		this->nextNode = node;
	}
	T getValue(){return this->value;};
	void setValue(T data){this->value = data;};
};

template<class T>
struct linkNode
{
	listNode<T> *m_pre, *m_curr, *m_next;
};

template<class T>
class ListLink
{
private:
	linkNode<T> *linkNode;
	listNode<T> *head;
public:
	ListLink();
	ListLink(T node);
	ListLink(T arr[],int);
	~ListLink();
	bool isEmpty();
	int length();
	T get(int i);
	bool set(int i, T x);
	friend ostream& operator<<(ostream &out,ListLink<T> &list);
	T operator[](int i);
	void insert(int i,T x);
	void insert(T x);
	bool remove(int i, T &old);
	void clear();
	T next();
	bool hasNext();
	listNode<T>* getHead(){return head;};
	void setHead(listNode<T> *node){head=node;};
};

template<class T>
ListLink<T>::ListLink()
{
	head = NULL;
	linkNode->m_curr = head;
}

template<class T>
ListLink<T>::ListLink(T data)
{
	head = new listNode<T>(data);
	linkNode->m_curr = head;
}

template<class T>
ListLink<T>::ListLink(T arr[],int len)
{
	if(len<=0)
	{
		head = NULL;
	}
	else
	{
		head = new listNode<T>();
		head->setValue(arr[0]);
		listNode<T> *currentNode = head;
		for(int i=1; i<len; i++)
		{
			listNode<T> *newNode = new listNode<T>(arr[i],currentNode);
			currentNode = newNode;
		}
	}
	linkNode->m_curr = head;
}


template<class T>
ListLink<T>::~ListLink()
{
	clear();
}


template<class T>
bool ListLink<T>::isEmpty()
{
	if(head)
		return true;
	return false;
}


template<class T>
T ListLink<T>::next()
{
	if(hasNext())
	{
		linkNode->m_pre = linkNode->m_curr;
		linkNode->m_curr = linkNode->m_curr->next();
		return linkNode->m_pre->getValue();
	}
}

template<class T>
bool ListLink<T>::hasNext()
{
	if(linkNode->m_curr->next()!=NULL)
		return true;
	return false;
}


template<class T>
int ListLink<T>::length()
{
	int i=0;
	listNode<T> *curr = head;
	while(curr)
	{
		i++;
		curr = curr->next();
	}
	return i;
}


template<class T>
T ListLink<T>::get(int i)
{
	listNode<T> *curr = head;
	for(;i>0;i--)
	{
		if(curr)
			curr = curr->next();
		else
		{
			std::cout<<"Bad index"<<std::endl;
			return NULL;
		}
	}
	return curr->getValue();
}


template<class T>
bool ListLink<T>::set(int i, T x)
{
	listNode<T> *curr = head;
	for(;i>0;i--)
	{
		if(curr)
			curr = curr->next();
		else
		{
			std::cout<<"Bad index"<<std::endl;
			return false;
		}
	}
	curr->setValue(x);
	return true;
}


template<class T>
ostream&operator<<(ostream &out,ListLink<T> &list)
{
	out<<"(";
	listNode<T> *curr = list.getHead();
	while(curr)
	{
		out<<curr->getValue()<<" ";
		curr = curr->next();
	}
	out<<")"<<std::endl;
	return out;
}

template<class T>
T ListLink<T>::operator[](int i)
{
	return list->get(i);
}


template<class T>
void ListLink<T>::insert(int i,T x)
{
	listNode<T> *newNode = new listNode<T>(x);
	if(i==0)
	{
		newNode->setNext(head);
		head=newNode;
		return;
	}

	listNode<T> *curr = head;
	for(;i>1;i--)
	{
		if(curr)
		{
			curr = curr->next();
		}
		else
		{
			std::cout<<"Bad index"<<std::endl;
			return;
		}
	}
	newNode->setNext(curr->next());
	curr->setNext(newNode);
	return;
}


template<class T>
void ListLink<T>::insert(T x)
{
	insert(this->length(),x);
}


template<class T>
bool ListLink<T>::remove(int i, T &old)
{
	listNode<T> *curr = head, *pre;
	if(i==0)
	{
		old = curr->getValue();
		head=curr->next();
		delete curr;
		return true;
	}

	for(;i>0;i--)
	{
		if(curr)
		{
			pre = curr;
			curr = curr->next();
		}
		else
		{
			std::cout<<"Bad index"<<std::endl;
			return false;
		}
	}
	pre->setNext(curr->next());
	old = curr->getValue();
	delete curr;
	return true;
}


template<class T>
void ListLink<T>::clear()
{
	listNode<T> *curr = head;
	listNode<T> *temp;
	while(curr)
	{
		temp = curr;
		curr = curr->next();
		delete temp;
	}
}