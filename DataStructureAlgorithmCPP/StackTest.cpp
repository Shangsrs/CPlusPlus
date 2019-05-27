#include "listAlgorithm.h"

template<class T>
class Stack
{
public:
	virtual ~Stack(){};
	virtual bool empty() const = 0;
	virtual int size() const = 0;
	virtual T& top() const = 0;
	virtual void pop() = 0;
	virtual void push(const T& element) = 0;
};

template<class T>
class DerivedArrayStack:private ArrayList<T>,public Stack<T>
{
public:
	DerivedArrayStack(int capacity = 10):ArrayList<T>(capacity){};
	bool empty() const {return ArrayList<T>::empty();}
	int size() const {return ArrayList<T>::size();}
	T& top() const
	{
		if(empty())
			throw illegalParameterValue("Empty stack");
		return get(size()-1);
	}
	void pop()
	{
		if(empty())
			throw illegalParameterValue("Empty stack");
		ArrayList<T>::erase(size()-1);
	}
	void push(const T& element)
	{
		ArrayList<T>::insert(size(),element);
	}
};

template<class T>
class ArrayStack : public Stack<T>
{
private:
	int _top;
	int _length;
	T *_stack;
public:
	ArrayStack(int capacity = 10);
	~ArrayStack()
	{
		delete[] _stack;
		_stack = NULL;
		_top = -1;
	}
	bool empty() const {return _top == -1;}
	int size() const {return _top+1;}
	T& top() const
	{
		if(_top==-1)
			throw illegalParameterValue("Empty Stack");
		return _stack[_top];
	}
	void pop()
	{
		if(_top==-1)
			throw illegalParameterValue("Empty Stack");
		_top--;
	}
	void push(const T& element);
};

template<class T>
ArrayStack<T>::ArrayStack(int capacity)
{
	if(capacity<10)
		capacity = 10;
	_length = capacity;
	_stack = new T[_length];
	_top = -1;
}

template<class T>
void ArrayStack<T>::push(const T& element)
{
	if(_top == _length -1)
	{
		T* temp = _stack;
		_stack = new T[_length*2];
		for(int i=0;i<_length;i++)
			_stack[i] = temp[i];
		_length *=2;
		delete temp;
	}
	_stack[++_top] = element;
}

template<class T>
class DerivedLinkStack:private ChainList<T>,public Stack<T>
{
public:
	DerivedLinkStack(int capacity = 10):ChainList<T>(capacity){};
	bool empty() const {return ChainList<T>::empty();}
	int size() const {return ChainList<T>::size();}
	T& top() const
	{
		if(empty())
			throw illegalParameterValue("Empty stack");
		return get(size()-1);
	}
	void pop()
	{
		if(empty())
			throw illegalParameterValue("Empty stack");
		ChainList<T>::erase(size()-1);
	}
	void push(const T& element)
	{
		ChainList<T>::insert(size(),element);
	}
};

template<class T>
class LinkStack : public Stack<T>
{
private:
	int _size;
	ChainNode<T> *_top;
public:
	LinkStack(int capacity = 10):_size(0),_top(NULL){}
	~LinkStack();
	bool empty() const {return _top == NULL;}
	int size() const {return _size;}
	T& top() const
	{
		if(_size == 0)
			throw illegalParameterValue("Empty Stack");
		return _top->_element;
	}
	void pop();
	
	void push(const T& element)
	{
		_top = new ChainNode<T>(element,_top);
		_size++;
	}
};

template<class T>
LinkStack<T>::~LinkStack()
{
	while(_top != NULL)
	{
		ChainNode<T>* next = _top->_next;
		delete _top;
		_top = next;
	}
}

template<class T>
void LinkStack<T>::pop()
{
	if(_size == 0)
		throw illegalParameterValue("Empty stack");
	ChainNode<T> *next = _top->_next;
	delete _top;
	_top = next;
	_size--;
}


int main()
{
	int length = 371;
	LinkStack<int> *st = new LinkStack<int>;
//	DerivedLinkStack<int> *st = new DerivedLinkStack<int>;
	for(int i=0;i<length;i++)
	{
		st->push(i);
	}
	for(int i=0;i<length;i++)
	{
		cout<<st->top()<<"\tempty:";
		st->pop();
		cout<<st->empty()<<"\tsize:"<<st->size()<<endl;
	}
	return 0;
}
