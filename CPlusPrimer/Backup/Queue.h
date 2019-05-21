#include <iostream>
using namespace std;

template <class T>
class Queue
{
private:
	T *data;
	int size;
	int front, tail;
public:
	Queue();
	Queue(T *arr,int len);
	~Queue();
	T dequeue();//出队
	void enqueue(T x);//入队
	bool isEmpty();
	bool isFull();
	void getFront();
	void printQueue();
};


template <class T>
Queue<T>::Queue()
{
	size = 64;
	data = new T[size];
	front = tail = 0;
}


template <class T>
Queue<T>::Queue(T *arr,int len)
{
	size = 2*len>64?2*len:64;
	data = new T[size];
	front = 0;
	for(int i=0;i<len;i++)
	{
		data[i]=arr[i];
	}
	tail = len-1;

}

template <class T>
Queue<T>::~Queue()
{
	delete[] data;
}

template <class T>
bool Queue<T>::isEmpty()
{
	if(front==tail)
		return true;
	return false;
}

template <class T>
bool Queue<T>::isFull()
{
	if((tail+2)%size == front)
		return true;
	return false;
}

template <class T>
T Queue<T>::dequeue()//出队
{
	if(!isEmpty())
	{
		return data[front++];
	}
	std::cout<<"Empty queue!"<<std::endl;
	return NULL;
}

template <class T>
void Queue<T>::enqueue(T x)//入队
{
	if(isFull())
	{
		T *temp = data;
		size = 2*size;
		data = new T[size];
		int i=0;
		while((front%size)!=tail)
		{
			data[i++] = temp[front++];
		}
		data[i++] = temp[tail];
		data[i] = x;
		front = 0;
		tail = i;
		delete[] temp;
		return;
	}
	data[++tail] = x;

}


template <class T>
void Queue<T>::printQueue()
{
	int index = front;
	std::cout<<"(";
	while((index%size)!=tail)
	{
		std::cout<<data[index++]<<"\t";
	}
	if(!this->isEmpty())
	{
		std::cout<<data[tail]<<"\t";
	}
	std::cout<<")"<<std::endl;
}

