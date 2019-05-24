#include "../header.h"

class illegalParameterValue
{
public:
	illegalParameterValue():message("Illegal parameter value"){};
	illegalParameterValue(const char* theMessage)
	{
		message = theMessage;
	};
	void outputMessage(){cout<<message<<endl;};

private:
	string message;
};


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

//*******************************
template<class T>
struct ChainNode
{
	T _element;
	ChainNode<T> *_next;
	ChainNode()
	{
		this->_element = 0;
		this->_next = NULL;
	};
	ChainNode(const T& element)
	{
		this->_element = element;
		this->_next = NULL;
	};
	ChainNode(const ChainNode<T>& node)
	{
		this->_element = node->_element;
		this->_next = node->_next;
	};
	ChainNode(const T& element,ChainNode<T>* next)
	{
		this->_element = element;
		this->_next = next;
	};
};

template<class T>
class ChainList : public LinearList<T>
{
protected:
	void checkIndex(int index) const;
	ChainNode<T>* _head;
	int _size;
public:
	ChainList(int capacity = 10);
	ChainList(const ChainList<T>& list);
	~ChainList();

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
		ChainNode<T> *_node;
	public:
		iterator(ChainNode<T> *node = NULL){_node = node;};
	};
	iterator begin(){return iterator(_head);};
	iterator end(){return iterator(NULL);};
	iterator begin() const {return iterator(_head);};
	iterator end() const {return iterator(NULL);};
//	ChainList<T>& operator->(){return *this;};
//	ChainList<T>& operator->() const {return *this;};
};

template<class T>
ChainList<T>::ChainList(int capacity = 10)
{
	if(capacity<1)
	{
		ostringstream s;
		s<<"Initial capacity = "<<capacity<<" Must be > 0";
		throw illegalParameterValue(s.str().c_str());
	}
	_head = NULL;
	_size = 0;
}

template<class T>
ChainList<T>::ChainList(const ChainList<T>& list)
{
	_size = list._size;
	if(_size <= 0)
	{
		_head = NULL;
		_size = 0;
		return;
	}
	ChainNode<T> *oldNode = list._head;
	_head = new ChainNode<T>(oldNode->_element);
	oldNode = oldNode->_next;
	ChainNode<T> *newNode = _head->_next;
	while(oldNode != NULL)
	{
		newNode = new ChainNode<T>(oldNode->_element);
		newNode = newNode->_next;
		oldNode = oldNode->_next;
	}
	newNode->_next = NULL;
}

template<class T>
ChainList<T>::~ChainList()
{
	ChainNode<T> *node = _head;
	while(_head != NULL)
	{
		_head = _head->_next;
		delete node;
		node = _head;
	}
	_size = 0;
}

template<class T>
void ChainList<T>::insert(int index, const T& element)
{
	if(index <= 0) index = 0;
	if(index >= _size) index = _size;
	ChainNode<T> *node = _head;
	ChainNode<T> *newNode = new ChainNode<T>(element);
	if(index == 0)
	{
		newNode->_next = _head;
		_head = newNode;
	}
	else
	{
		for(int i=0;i<index-1;i++)
			node = node->_next;
//		cout<<"newNode = "<<newNode<<" ,newNode->_next = "<<newNode->_next<<endl;
//		cout<<"node = "<<node<<" ,node->next = "<<node->_next<<endl;
		newNode->_next = node->_next;
		node->_next = newNode;
 	}
	_size++;
}


template<class T>
void ChainList<T>::checkIndex(int index) const
{
	if(index <0 || index >= _size)
	{
		ostringstream s;
		s<<"index = "<<index<<" is out of range when size = "<<_size;
		illegalParameterValue(s.str().c_str());
	}
}

template<class T>
T& ChainList<T>::get(int index) const
{	
	if(index <= 0) index = 0;
	if(index >= _size) index = _size;
	ChainNode<T> *node = _head;
	for(int i=0;i<index;i++)
		node = node->_next;
	return node->_element;
}

template<class T>
int ChainList<T>::indexOf(const T& element) const
{
	if(_size <=0 || _head == NULL)
		return -1;
	ChainNode<T> *node = _head;
	int index = 0;
	while(node != NULL && node->_element != element)
	{
		node = node->_next;
		index ++;
	}
	if(node == NULL)
		return -1;
	return index;
	
}

template<class T>
void ChainList<T>::erase(int index)
{
	if(_size <=0 || _head == NULL)
		return;
	if(index <= 0) index = 0;
	if(index >= _size) index = _size-1;
	ChainNode<T> *node = _head;
	ChainNode<T> *deleteNode;
	if(index == 0)
	{
		deleteNode = _head;
		_head = _head->_next;
	}
	else
	{
		for(int i=0;i<index-1;i++)
			node = node->_next;
		deleteNode = node->_next;
		node->_next = deleteNode->_next;
	}
	_size--;
}

template<class T>
void ChainList<T>::output(ostream& out) const
{
	if(_size <=0 || _head == NULL)
		return;
	ChainNode<T> *node = _head;
	while(node != NULL)
	{
		out<<node->_element<<"\t";
		node = node->_next;
	}
}

//****************************************




