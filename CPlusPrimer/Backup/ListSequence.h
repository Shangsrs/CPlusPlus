#include <iostream>
using namespace std;

template<class T>
class ListSequence
{
	private:
		T *element;
		int size;
		int len;

	public:
		ListSequence(int size = 64);
		ListSequence(T value[],int n);
		~ListSequence();
		bool isEmpty();
		int length();
		T get(int i);
		bool set(int i, T x);
		friend ostream&operator<<(ostream &out,ListSequence<T> &list);
		T operator[](int i);
		void insert(int i,T x);
		void insert(T x);
		bool remove(int i, T &old);
		void clear();

};

template<class T>
ListSequence<T>::ListSequence(int sizet)
{
	size = sizet<64?64:sizet;
	this->element = new T[size];
	len = 0;
}

template<class T>
ListSequence<T>::ListSequence(T value[],int n)
{
	if (n>0)
	{
		this->element=new T(2*n);
		size=2*n;
		for( int i=0;i<n;i++)
			this->element[i]=value[i];
		len = n;
	}
}

template<class T>
ListSequence<T>::~ListSequence()
{
	if(this->element)
		delete[] this->element;
}

template<class T>
bool ListSequence<T>::isEmpty()
{
	return len==0;
}


template<class T>
int ListSequence<T>::length()
{
	return len;
}


template<class T>
T ListSequence<T>::get(int i)
{
	if(i>=0&&i<len)
		return element[i];
	throw "Invalide index i";
}


template<class T>
bool ListSequence<T>::set(int i, T x)
{
	if(i>=0&&i<len)
		element[i] = x;
	throw " Invalide index i";
}


template<class T>
ostream& operator<<(ostream &out,ListSequence<T> &list)
{
	if(list.isEmpty())
	{
		out<<"Empty list";
		return out;
	}
	out<<"( ";
	if(list.length()>0)
	{
		for (int i=0;i<list.length() ;i++ )
		{
			out<<list.get(i)<<" ";
		}
	}
	out<<")";
	return out;
}

template<class T>
T ListSequence<T>::operator[](int i)
{
	return get(i);
}

template<class T>
void ListSequence<T>::insert(int i,T x)
{
	if(len == size)
	{
		T *temp = this->element;
		this->element = new T[size*2];
		for(int j=0;j<len;j++)
		{
			this->element[j] = temp[j];
		}
		size = 2*size;
		delete[] temp;
	}
	if(i<0)
		i=0;
	if(i>len)
		i=len;
	for(int t =len-1;t>=i;t--)
	{
		this->element[t+1] = this->element[t];
	}
	this->element[i] = x;
	len++;
}


template<class T>
void ListSequence<T>::insert(T x)
{
	insert(len,x);
}


template<class T>
bool ListSequence<T>::remove(int i, T &old)
{
	if(len>0 && i>=0 && i<len)
	{
		old = element[i];
		for(int j=i; j<len;j++)
			element[j] = element[j+1];
		len--;
		return true;
	}
	return false;
}


template<class T>
void ListSequence<T>::clear()
{
	this->len = 0;
}

