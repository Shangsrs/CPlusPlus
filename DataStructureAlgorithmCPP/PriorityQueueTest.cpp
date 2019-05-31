#include "../header.h"

template<class T>
class maxPriorityQueue
{
public:
	virtual ~maxPriorityQueue(){}
	virtual bool empty() const = 0;
	virtual int size() const = 0;
	virtual const T& top() = 0;
	virtual void pop() = 0;
	virtual void push(const T& element) = 0;
	
};

template<class T>
class MaxHeap : public maxPriorityQueue<T>
{
private:
	T *_heap;
	int _length;
	int _size;
public:
	~MaxHeap()
	{
		delete[] _heap;
		_heap = NULL;
		_length = 0;
		_size = 0;
	}
	MaxHeap(int length = 10)
	{
		if(length<=10)
			length = 10;
		_length = length;
		_size = 0;
		_heap = new T[length];
	}
	bool empty() const {return _size == 0;}
	int size() const {return _size;}
	const T& top() 
	{
		if(_size<=0)
			throw illegalParameterValue("Empty Heap");
		return _heap[0];
	}
	void pop();
	void push(const T& element);
	void initArray(T *arr, int length);
};


template<class T>
void MaxHeap<T>::push(const T & element)
{
	if(_size == _length-1)
	{
		T* temp = new T[_length*2];
		for(int i=0;i<_size;i++)
			temp[i] = _heap[i];
		delete[] _heap;
		_heap = temp;
		_length *=2;
	}
	int currNode = _size++;
	while(currNode != 0 && _heap[(currNode-1)/2] < element)
	{
		_heap[currNode] = _heap[(currNode-1)/2];
		currNode = (currNode-1)/2;
	}
	_heap[currNode] = element;
}

template<class T>
void MaxHeap<T>::pop()
{
	if(_size <= 0)
		throw illegalParameterValue("Empty Heap");
	_heap[0] = _heap[--_size];
	int currNode = 0;
	int childNode = 2*currNode + 1;
	while(childNode < _size)
	{
		if(childNode+1 < _size && _heap[childNode +1] > _heap[childNode])
			childNode = childNode +1;
		if(_heap[currNode] > _heap[childNode])
			break;
		T temp = _heap[currNode];
		_heap[currNode] = _heap[childNode];
		_heap[childNode] = temp;
		currNode = childNode;
		childNode = currNode*2 + 1;
	}
}

template<class T>
void MaxHeap<T>::initArray(T * arr, int length)
{
//	for(int i=0;i<length;i++)
//		push(arr[i]);
	int parent = 0;
	int child = 2*parent+1;
	for(int i=0;i<length;i++)
	{
		
	}
}


int main()
{
	int length = 20;
	cout<<"Please enter a number:"<<endl;
	cin>>length;
	cout<<endl;
	MaxHeap<int> *heap = new MaxHeap<int>;
	srand(time(NULL));
	for(int i=0;i<length;i++)
		heap->push(rand()%1000);
	for(int i=0;i<length;i++)
	{
		cout<<heap->top()<<"\t";
		heap->pop();
	}
//	delete heap;
	cout<<endl<<"End"<<endl;

	int *arr = new int[length];	
	for(int i=0;i<length;i++)
		arr[i] = rand()%1000;
	heap->initArray(arr,length);
	cout<<endl<<endl;
	for(int i=0;i<length;i++)
	{
		cout<<heap->top()<<"\t";
		heap->pop();
	}
	return 0;
}

