#include "PriorityQueueTest.h"
#include "../header.h"



//Priority Queue test
int main()
{
	int length = 20;
	cout<<"Please enter a number:"<<endl;
	cin>>length;
	cout<<endl;
//	MaxHeap<int> *heap = new MaxHeap<int>;
	MinHeap<int> *heap = new MinHeap<int>;
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

