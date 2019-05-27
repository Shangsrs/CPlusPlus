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


template<class T>
class ArrayList : public LinearList<T>
{
protected:
	void checkIndex(int index) const;
	T *_element;
	int _length;
	int _size;
public:
	ArrayList(int initialCapacity = 10);
	ArrayList(const ArrayList<T>& arr);
	~ArrayList() {delete[] _element;};

	bool empty() const {return _size == 0;};
	int size() const {return _size;};
	T& get(int index) const;
	int indexOf(const T & element) const;
	void erase(int index);
	void insert(int index, const T & element);
	void output(ostream& out) const ;

	int capacity() const {return _length;};


	class iterator
	{
	protected:
		T* _position;
	public:
		typedef bidirectional_iterator_tag iterator_category;
		typedef T value_type;
		typedef ptrdiff_t difference_type;
		typedef T* pointer;
		typedef T& reference;

		iterator(T* position = 0){_position = position;};
		T& operator *() const {return *_position;};
		T* operator->() const {return &*_position;};
		iterator& operator++() {++_position; return *this;};
		iterator operator++(int)
		{
			iterator old = *this;
			++_position;
			return old;
		};
		iterator& operator--(){--_position;return *this;};
		iterator operator--(int)
		{
			iterator old = *this;
			--_position;
			return old;
		};
		bool operator!=(const iterator right) const
		{
			return _position != right._position;
		};
		bool operator==(const iterator right) const
		{
			return _position == right._position;
		};
	};
	iterator begin(){return iterator(_element);};
	iterator end(){return iterator(_element+_size);};
	iterator begin() const {return iterator(_element);} ;
	iterator end() const {return iterator(_element+_size);} ;
	
};

template<class T>
ArrayList<T>::ArrayList(int initialCapacity)
{
	if(initialCapacity < 1)
	{
		ostringstream s;
		s<<"Initial capacity = "<<initialCapacity<<" must be > 0";
		throw illegalParameterValue(s.str().c_str());
	}
	_length = initialCapacity;
	_element = new T[_length];
	_size = 0;
}

template<class T>
ArrayList<T>::ArrayList(const ArrayList<T>& arr)
{
	_length = arr->_length;
	_size = arr._size;
	_emement = new T[_length];
	copy(arr._element,arr._element+_size,_element);
}

template<class T>
void ArrayList<T>::checkIndex(int index) const
{
	if(index < 0 || index >= _size)
	{
		ostringstream s;
		s<<"index = "<<index<<" size = "<<_size;
		throw illegalParameterValue(s.str().c_str());
	}
}

template<class T>
T& ArrayList<T>::get(int index) const
{
//	checkIndex(index);
	if(index<=0) index = 0;
	if(index>=_size) index = _size-1;
	return _element[index];
}

template<class T>
int ArrayList<T>::indexOf(const T& element) const
{
	int index = (int) (find(_element,_element+_size,element)-_element);
	if(index == _size)
		return -1;
	else
		return index;
}

template<class T>
void ArrayList<T>::erase(int index)
{
//	checkIndex(index);
	if(_size <=0)return;
	if(index<=0) index = 0;
	if(index>=_size) index = _size-1;
	copy(_element+index+1,_element+_size,_element+index);
	_size--;
//	_element[--_size].~T();
}
template<class T>
void ArrayList<T>::insert(int index,const T& element)
{
/*	if(index<0 || index >_size)
	{
		ostringstream s;
		s<<"index = "<<index<<" size = "<<_size;
		throw illegalParameterValue(s.str().c_str());
	}*/
	if(index <= 0) index = 0;
	if(index >= _size) index = _size;
	if(_size == _length)
	{
		T* temp = _element;
		_element = new T[_length*2];
		copy(temp,temp+_size,_element);
		_length *=2;
		delete[] temp;
	}
	copy_backward(_element+index,_element+_size,_element+_size+1);
	_element[index]=element;
	_size ++;
}


template<class T>
void ArrayList<T>::output(ostream& out) const 
{
	for( ArrayList<T>::iterator it = begin();it != end();it++)
		out<<*it<<"\t";
	out<<endl;
}


template<class T>
class vectorList : public LinearList<T>
{
protected:
	void checkIndex(int index) const;
	vector<T>* _element;
public:
	vectorList(int capacity = 10);
	vectorList(const vectorList<T>&);
	~vectorList(){delete _element;};

	bool empty() const {return _element->empty();};
	int size() const {return (int)_element->size();};
	T& get(int index) const;
	int indexOf(const T& element) const;
	void erase(int index);
	void insert(int index, const T& element);
	void output(ostream& out) const;
	int capacity() const {return (int) _element->capacity();};
	typedef typename vector<T>::iterator iterator;
	iterator begin(){return _element->begin();};
	iterator end(){return _element->end();};
	iterator begin() const {return _element->begin();};
	iterator end() const {return _element->end();};
};


template<class T>
vectorList<T>::vectorList(int capacity)
{
	if(capacity<1)
	{
		ostringstream s;
		s<<"Initial capacity = "<<capacity<<" Must be > 0";
		throw illegalParameterValue(s.str().c_str());
	}
	_element = new vector<T>;
	_element->reserve(capacity);
}

template<class T>
vectorList<T>::vectorList(const vectorList<T>& list)
{
	_element = new vector<T>(*list._element);
}

template<class T>
void vectorList<T>::checkIndex(int index) const
{
	if(index < 0 || index >= size())
	{
		ostringstream s;
		s<<"index = "<<index<<" size = "<<size();
		throw illegalParameterValue(s.str().c_str());
	}
}


template<class T>
void vectorList<T>::erase(int index)
{
	if(index < 0 || index >= size())
	{
		ostringstream s;
		s<<"index = "<<index<<" size = "<<size();
		throw illegalParameterValue(s.str().c_str());
	}
}

template<class T>
void vectorList<T>::insert(int index,const T& element)
{
/*	if(index<0 || index>size())
	{
		ostringstream s;
		s<<"Index = "<<index<<" size = "<<size();
		throw illegalParameterValue(s.str().c_str());
	}*/
	if(size() <=0)return;
	if(index<=0) index = 0;
	if(index>=size()) index = size();
	_element->insert(_element->begin()+index,element);
}

template<class T>
T& vectorList<T>::get(int index) const
{
//	checkIndex(index);
	if(index<=0) index = 0;
	if(index>=size()) index = size()-1;
	return _element->at(index);
}

template<class T>
int vectorList<T>::indexOf(const T& element) const
{
	return 0;
}

template<class T>
void vectorList<T>::output(ostream& out) const
{

}


