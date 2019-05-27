#include "../header.h"

template<class T>
class LinearList
{
public:
	virtual ~LinearList(){};
	virtual bool empty() const = 0;
	virtual int size() const = 0;
	virtual T& get(int index) const = 0;
	virtual int indexOf(const T& element) const = 0;
	virtual void erase(int index) = 0;
	virtual void insert(int index, const T& element) = 0;
	virtual void output(ostream& out) const = 0;
};

template<class T>
ostream& operator<<(ostream& out,const LinearList<T> &list)
{
	list.output(out);
	return out;
}

template<class T>
struct DLinkNode
{
	T _element;
	DLinkNode<T> *_left;
	DLinkNode<T> *_right;
	DLinkNode()
	{
		this->_element = 0;
		this->_left = this;
		this->_right = this;
	};
	DLinkNode(const T& element)
	{
		this->_element = element;
		this->_left = this;
		this->_right = this;
	};
	DLinkNode(const DLinkNode<T>& node)
	{
		this->_element = node->_element;
		this->_left = node->_left;
		this->_right = node->_right;
		node->_left->_right = this;
		node->_left = this;
	};
	DLinkNode(const T& element,DLinkNode<T>* node)
	{
		this->_element = element;
		this->_right = node->_right;
		this->_left = node;
		node->_right->_left = this;
		node->_right = this;
		
	};
};

template<class T>
class DLinkList : public LinearList<T>
{
protected:
	DLinkNode<T>* _head;
	int _size;
public:
	DLinkList(int capacity = 10);
	DLinkList(const DLinkList<T>& list);
	~DLinkList();

	bool empty() const {return _size == 0;};
	int size() const {return _size;};
	T& get(int index) const;
	int indexOf(const T& element) const;
	void erase(int index);
	void insert(int index, const T& element);
	void output(ostream& out) const;
	class iterator
	{
	protected:
		DLinkNode<T> *_node;
	public:
		iterator(DLinkNode<T> *node = NULL){_node = node;};
	};
	iterator begin(){return iterator(_head);};
	iterator end(){return iterator(NULL);};
	iterator begin() const {return iterator(_head);};
	iterator end() const {return iterator(NULL);};
//	DLinkList<T>& operator->(){return *this;};
//	DLinkList<T>& operator->() const {return *this;};
};

template<class T>
DLinkList<T>::DLinkList(int capacity)
{
	if(capacity<1)
		capacity = 0;
	_head = NULL;
	_size = 0;
}

template<class T>
DLinkList<T>::DLinkList(const DLinkList<T>& list)
{
	_size = list._size;
	if(_size <= 0)
	{
		_head = NULL;
		_size = 0;
		return;
	}
	_head = new DLinkNode<T>(list._head->_element);
	DLinkNode<T> *oldNode = list._head->_right;
	DLinkNode<T> *newNode = new DLinkNode<T>(oldNode->_element,_head);
	oldNode = oldNode->_right;
	newNode = newNode->_right;
	while(oldNode != list._head)
	{
		newNode = new DLinkNode<T>(oldNode->_element,newNode);
		newNode = newNode->_right;
		oldNode = oldNode->_right;
	}
}

template<class T>
DLinkList<T>::~DLinkList()
{
	DLinkNode<T> *node = _head->_right;
	while(node != _head)
	{
		DLinkNode<T> *temp = node->_right;
		delete node;
		node = temp;
	}
	delete _head;
	_head = NULL;
	_size = 0;
}

template<class T>
void DLinkList<T>::insert(int index, const T& element)
{
	if(index <= 0) index = 0;
	if(index >= _size) index = _size;
	if(index == 0)
	{
		if(_head == NULL)
			_head = new DLinkNode<T>(element);
		else
		{
			DLinkNode<T> *newNode = new DLinkNode<T>(element,_head->_left);
			_head = newNode;
		}
	}
	else
	{
		DLinkNode<T> *node = _head;
		for(int i=0;i<index-1;i++)
			node = node->_right;
		new DLinkNode<T>(element,node);
 	}
	_size++;
}


template<class T>
T& DLinkList<T>::get(int index) const
{	
	if(index <= 0) index = 0;
	if(index >= _size) index = _size;
	DLinkNode<T> *node = _head;
	for(int i=0;i<index;i++)
		node = node->_right;
	return node->_element;
}

template<class T>
int DLinkList<T>::indexOf(const T& element) const
{
	if(_size <=0 || _head == NULL)
		return -1;
	DLinkNode<T> *node = _head;
	if(node->_element == element)
		return 0;
	int index = 0;
	node = node->_right;
	while(node != _head && node->_element != element)
	{
		node = node->_right;
		index ++;
	}
	if(node == _head)
		return -1;
	return index;
	
}

template<class T>
void DLinkList<T>::erase(int index)
{
	if(_size <=0 || _head == NULL)
		return;
	if(index <= 0) index = 0;
	if(index >= _size) index = _size-1;
	DLinkNode<T> *node = _head;
	DLinkNode<T> *deleteNode;
	if(index == 0)
	{
		deleteNode = _head;
		_head = _head->_right;
	}
	else
	{
		for(int i=0;i<index-1;i++)
			node = node->_right;
		deleteNode = node->_right;
	}
	deleteNode->_left->_right = deleteNode->_right;
	deleteNode->_right->_left = deleteNode->_left;
	delete deleteNode;
	_size--;
}

template<class T>
void DLinkList<T>::output(ostream& out) const
{
	if(_size <=0 || _head == NULL)
		return;
	DLinkNode<T> *node = _head;
	out<<node->_element<<"\t";
	node = node->_right;
	while(node != _head)
	{
		out<<node->_element<<"\t";
		node = node->_right;
	}
}


int main()
{
	DLinkList<int> *chainList = new DLinkList<int>;
	int length = 20;
	cout<<"Please enter a number:";
	cin>>length;
	cout<<endl;
	for(int i=0;i<length;i++)
		chainList->insert(i,i);
	cout<<*chainList<<endl;
	chainList->erase(15);
	cout<<*chainList<<endl;
	DLinkList<int> chainList2=*chainList;
	cout<<chainList2<<endl;
	return 0;
}



