#include "ListLink.h"

#include <iostream>
using namespace std;

template <class T>
class QueueLinkList
{
private:
	ListLink<T> *data;
	int size;
	int front, tail;
public:
	QueueLinkList();
	QueueLinkList(T *arr,int len);
	~QueueLinkList();
	T dequeue();//出队
	void enqueue(T x);//入队
	bool isEmpty();
	bool isFull();
	void getFront();
	void printQueue();
};


template <class T>
QueueLinkList<T>::QueueLinkList()
{
	size = 64;
	data = new ListLink<T>(size);
	front = tail = 0;
}


template <class T>
QueueLinkList<T>::QueueLinkList(T *arr,int len)
{
	size = 2*len>64?2*len:64;
	data = new ListLink<T>(size);
	front = 0;
	for(int i=0;i<len;i++)
	{
		data->insert(i,arr[i]);
	}
	tail = len-1;

}

template <class T>
QueueLinkList<T>::~QueueLinkList()
{
	delete[] data;
}

template <class T>
bool QueueLinkList<T>::isEmpty()
{
	if(front==tail)
		return true;
	return false;
}

template <class T>
bool QueueLinkList<T>::isFull()
{
	if((tail+1)%size == front)
		return true;
	return false;
}

template <class T>
T QueueLinkList<T>::dequeue()//出队
{
	if(!isEmpty())
	{
		return data->get(front++);
	}
	std::cout<<"Empty QueueLinkList!"<<std::endl;
	return NULL;
}

template <class T>
void QueueLinkList<T>::enqueue(T x)//入队
{
	if(isFull())
	{
		ListLink<T> *temp = data;
		int oldSize = size;
		size = 2*size;
		data = new ListLink<T>(size);
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
void QueueLinkList<T>::printQueue()
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

