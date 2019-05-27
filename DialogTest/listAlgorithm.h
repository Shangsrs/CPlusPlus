#ifndef LIATALGORITHM_H
#define LIATALGORITHM_H

#include "header.h"
#include<QDebug>
class illegalParameterValue
{
public:
    illegalParameterValue():message("Illegal parameter value"){}
	illegalParameterValue(const char* theMessage)
	{
		message = theMessage;
    }
    void outputMessage(){cout<<message<<endl;}

private:
	string message;
};


template<class T>
class LinearList
{
public:
    virtual ~LinearList(){}
	virtual bool empty() const = 0;
	virtual int size() const = 0;
	virtual T& get(int index) const = 0;
	virtual int indexOf(const T& element) const = 0;
	virtual void erase(int index) = 0;
	virtual void insert(int index, const T& element) = 0;

};


template<class T>
struct ChainNode
{
	T _element;
	ChainNode<T> *_next;
	ChainNode()
	{
		this->_element = 0;
		this->_next = NULL;
    }
	ChainNode(const T& element)
	{
		this->_element = element;
		this->_next = NULL;
    }
	ChainNode(const ChainNode<T>& node)
	{
		this->_element = node->_element;
		this->_next = node->_next;
    }
	ChainNode(const T& element,ChainNode<T>* next)
	{
		this->_element = element;
		this->_next = next;
    }
    friend ostream& operator<<(ostream& out,ChainNode<T> &node)
    {
        out<<node->_element<<" next:"<<_next<<endl;
        return out;
    }
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

    bool empty() const {return _size == 0;}
    int size() const {return _size;}
	T& get(int index) const;
//    ChainNode<T>& get(int index) const;
	int indexOf(const T& element) const;
	void erase(int index);
	void insert(int index, const T& element);

	class iterator
	{
	protected:
		ChainNode<T> *_node;
	public:
        iterator(ChainNode<T> *node = NULL){_node = node;}
	};
    iterator begin(){return iterator(_head);}
    iterator end(){return iterator(NULL);}
    iterator begin() const {return iterator(_head);}
    iterator end() const {return iterator(NULL);}
    ChainList<T>* operator->(){return this;}
    ChainList<T>* operator->() const {return this;}
};

template<class T>
ChainList<T>::ChainList(int capacity)
{
	if(capacity<1)
	{
		ostringstream s;
		s<<"Initial capacity = "<<capacity<<" Must be > 0";
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
//	ChainNode<T> *newNode = _head->_next;
    ChainNode<T> *temp = _head;
    while(oldNode != NULL)
    {
        cout<<"oldNode: "<<oldNode<<" _element: "<<oldNode->_element<<endl;
        ChainNode<T> *newNode = new ChainNode<T>(oldNode->_element);
        temp->_next = newNode;
        temp = newNode;
        oldNode = oldNode->_next;
    }
    temp->_next = NULL;
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
    //	newNode->_next = _head;
		_head = newNode;
	}
	else
	{
		for(int i=0;i<index-1;i++)
			node = node->_next;
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
    qDebug()<<"get "<<"_element: "<<&(node->_element)<<" _head:"<<_head<<" size: "<<_size<<" node: "<<&node<<endl;
	return node->_element;
}
/*
template<class T>
ChainNode<T>& ChainList<T>::get(int index) const
{
    if(index <= 0) index = 0;
    if(index >= _size) index = _size;
    ChainNode<T> *node = _head;
    for(int i=0;i<index;i++)
        node = node->_next;
    return node;
}
*/
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

    bool empty() const {return _size == 0;}
    int size() const {return _size;}
    T& get(int index) const;
//    DLinkNode<T>& get(int index) const;
    int indexOf(const T& element) const;
    void erase(int index);
    void insert(int index, const T& element);

    class iterator
    {
    protected:
        DLinkNode<T> *_node;
    public:
        iterator(DLinkNode<T> *node = NULL){_node = node;}
    };
    iterator begin(){return iterator(_head);}
    iterator end(){return iterator(NULL);}
    iterator begin() const {return iterator(_head);}
    iterator end() const {return iterator(NULL);}
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
/*
template<class T>
DLinkNode<T>& DLinkList<T>::get(int index) const
{
    if(index <= 0) index = 0;
    if(index >= _size) index = _size;
    DLinkNode<T> *node = _head;
    for(int i=0;i<index;i++)
        node = node->_right;
    return node;
}
*/
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



#endif




