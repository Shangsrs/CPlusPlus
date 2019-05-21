#include <iostream>
using namespace std;

template<class T>
class Stack
{
private:
	T *data;
	int size;
	int length;
	
public:
	Stack();
	Stack(T* arr,int len);
	~Stack();
	void push(T x);
	T pop();
	int Length();
	bool isEmpty();
	void clear();
	T& get(int i);
	friend ostream& operator<<(ostream &out,Stack<T> &st);
};

template<class T>
Stack<T>::Length()
{
	return length;
}

template<class T>
Stack<T>::Stack()
{
	data = new T[64];
	size = 64;
	length = 0;
}

template<class T>
Stack<T>::Stack(T* arr,int len)
{
	size = 2*len>64?len*2:64;
	data = new T[size];
	length = len;
	for(int i=0;i<len;i++)
	{
		data[i] = arr[i];
	}

}

template<class T>
Stack<T>::~Stack()
{
	if(data)
	{
		delete[] data;
		size = 0;
		length = 0;
	}
}

template<class T>
void Stack<T>::push(T x)
{
	if(length+1>size)
	{
		size = 2*size;
		T* temp = data;
		data = new T[size];
		for(int i=0;i<length;i++)
		{
			data[i] = temp[i];
		}
		delete[] temp;
	}
	data[length] = x;
	length++;
}

template<class T>
T Stack<T>::pop()
{
	if(length>0)
	{
		return data[--length];
	}
	return NULL;
}

template<class T>
bool Stack<T>::isEmpty()
{
	return length==0;
}

template<class T>
void Stack<T>::clear()
{
	length = 0;
}

template<class T>
T& Stack<T>::get(int i)
{
	if(i<=0)
		i=0;
	if(i>=length)
		i=length-1;
	return data[i];
}

template<class T>
ostream& operator<<(ostream &out,Stack<T> &st)
{
	out<<"(";
	for(int i=0;i<st.Length();i++)
	{
		out<<st.get(i)<<"\t";
	}
	out<<")";
	out<<std::endl;
	return out;
}

