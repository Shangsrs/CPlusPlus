#include "listAlgorithm.h"

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
	ChainNode(const T& element,ChainNode<T>* next)
	{
		this->_element = element;
		this->_next = next;
	};
};

template<class T>
class Chain : public LinearList<T>
{
protected:
	void checkIndex(int index) const;
	ChainNode<T>* _head;
	int _size;
public:
	Chain(int capacity = 10);
	Chain(const Chain<T>& list);
	~Chain();

	bool empty() const {return _size == 0;};
	int size() const {return _size;};
	T& get(int index) const;
	int indexOf(const T& element) const;
	void erase(int index,const T& element);
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
};

template<class T>
Chain<T>::Chain(int capacity = 10)
{
}

template<class T>
Chain<T>::Chain(const Chain<T>& list)
{
}

template<class T>
Chain<T>::~Chain()

{
}

template<class T>
T& Chain<T>::get(int index) const
{
}

template<class T>
int Chain<T>::indexOf(const T& element) const
{
}

template<class T>
void Chain<T>::erase(int index,const T& element)
{
}

template<class T>
void Chain<T>::output(ostream& out) const
{
}


int main()
{
	return 0;
}
