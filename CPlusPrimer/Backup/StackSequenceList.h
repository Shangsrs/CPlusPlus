#include <iostream>
#include "SequenceList.h"
using namespace std;

template<class T>
class StackSequenceList
{
private:
	SeqList<T> *data;
	int size;
	int length;
	
public:
	StackSequenceList();
	StackSequenceList(T* arr,int len);
	~StackSequenceList();
	void push(T x);
	T pop();
	int Length();
	bool isEmpty();
	void clear();
	T get(int i);
	friend ostream& operator<<(ostream &out,StackSequenceList<T> &st);
};

template<class T>
StackSequenceList<T>::Length()
{
	return length;
}

template<class T>
StackSequenceList<T>::StackSequenceList()
{
	data = new SeqList<T>(64);
	size = 64;
	length = 0;
}

template<class T>
StackSequenceList<T>::StackSequenceList(T* arr,int len)
{
	size = 2*len>64?len*2:64;
	data = new SeqList<T>(size);
	length = len;
	for(int i=0;i<len;i++)
	{
		data->insert(i,arr[i]);
	}

}

template<class T>
StackSequenceList<T>::~StackSequenceList()
{
	if(data)
	{
		delete[] data;
		size = 0;
		length = 0;
	}
}

template<class T>
void StackSequenceList<T>::push(T x)
{
	if(length+1>size)
	{
		size = 2*size;
		SeqList<T>* temp = data;
		data = new SeqList<T>(size);
		for(int i=0;i<length;i++)
		{
			data->insert(i, temp->get(i));
		}
		delete[] temp;
	}
	data->insert(length,x);
	length++;
}

template<class T>
T StackSequenceList<T>::pop()
{
	if(length>0)
	{
		return data->get(--length);
	}
	return NULL;
}

template<class T>
bool StackSequenceList<T>::isEmpty()
{
	return length==0;
}

template<class T>
void StackSequenceList<T>::clear()
{
	length = 0;
}

template<class T>
T StackSequenceList<T>::get(int i)
{
	if(i<=0)
		i=0;
	if(i>=length)
		i=length-1;
	return data->get(i);
}

template<class T>
ostream& operator<<(ostream &out,StackSequenceList<T> &st)
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


