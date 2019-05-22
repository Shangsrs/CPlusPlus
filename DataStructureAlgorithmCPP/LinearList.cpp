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
	void output(ostream& out) const;

	int capacity() const {return _length;};

	iterator begin(){return iterator(_element);};
	iterator end(){return iterator(_element+_size);};

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
			++position;
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
	
};

template<class T>
ArrayList<T>::ArrayList(int initialCapacity)
{
	if(initialCapacity < 1)
	{
		ostringstream s;
		s<<"Initial capacity = "<<initialCapacity<<" must be > 0";
		throw illegalParameterValue(s.str());
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
		throw illegalParameterValue(s.str());
	}
}

template<class T>
T& ArrayList<T>::get(int index) const
{
	checkindex(index);
	return element[index];
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
	checkIndex(index);
	copy(_element+index+1,_element+_size,_element+_index);
//	_element[--_size].~T();
}

int main()
{
	return 0;
}

