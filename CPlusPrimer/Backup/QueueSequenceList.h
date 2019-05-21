#include "ListSequence.h"

#include <iostream>
using namespace std;

template <class T>
class QueueSequenceList
{
private:
	ListSequence<T> *data;
	int size;
	int front, tail;
public:
	QueueSequenceList();
	QueueSequenceList(T *arr,int len);
	~QueueSequenceList();
	T dequeue();//出队
	void enqueue(T x);//入队
	bool isEmpty();
	bool isFull();
	void getFront();
	void printQueue();
};


template <class T>
QueueSequenceList<T>::QueueSequenceList()
{
	size = 64;
	data = new ListSequence<T>(size);
	front = tail = 0;
}


template <class T>
QueueSequenceList<T>::QueueSequenceList(T *arr,int len)
{
	size = 2*len>64?2*len:64;
	data = new ListSequence<T>(size);
	front = 0;
	for(int i=0;i<len;i++)
	{
		data->insert(i,arr[i]);
	}
	tail = len-1;

}

template <class T>
QueueSequenceList<T>::~QueueSequenceList()
{
	delete[] data;
}

template <class T>
bool QueueSequenceList<T>::isEmpty()
{
	if(front==tail)
		return true;
	return false;
}

template <class T>
bool QueueSequenceList<T>::isFull()
{
	if((tail+1)%size == front)
		return true;
	return false;
}

template <class T>
T QueueSequenceList<T>::dequeue()//出队
{
	if(!isEmpty())
	{
		return data->get(front++);
	}
	std::cout<<"Empty QueueSequenceList!"<<std::endl;
	return NULL;
}

template <class T>
void QueueSequenceList<T>::enqueue(T x)//入队
{
	if(isFull())
	{
		ListSequence<T> *temp = data;
		int oldSize = size;
		size = 2*size;
		data = new ListSequence<T>(size);
		int i=0;
		while(((front)%oldSize)!=tail)
		{
			data->insert(i++, temp->get(front++));
		}
		data->insert(i++, temp->get(tail));
		data->insert(i, x);
		front = 0;
		tail = i;
		delete[] temp;
		return;
	}
	tail++;
	tail = tail%size;
	data->insert(tail,  x);

}


template <class T>
void QueueSequenceList<T>::printQueue()
{
	int index = front;
	std::cout<<"(";
	while((index%size)!=tail)
	{
		std::cout<<data->get(index++)<<"\t";
	}
	if(!this->isEmpty())
	{
		std::cout<<data->get(tail)<<"\t";
	}
	std::cout<<")"<<std::endl;
}

