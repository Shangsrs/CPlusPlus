#include "Queue.h"
#include "QueueSequenceList.h"
#include "QueueLinkList.h"

//#define type QueueSequenceList<int>
#define type QueueLinkList<int>
//#define type Queue<int>

int RandomCreate(int seed, int area)
{
	srand(seed);
	srand(rand());
	return rand()%area;
}

int main()
{
	type que1;
	que1.printQueue();
	int *arr = new int[10];
	for(int i=0;i<10;i++)
	{
		arr[i] = i;
	}
	type que2(arr,10);
	que2.printQueue();
	std::cout<<que2.dequeue()<<std::endl;
	que2.enqueue(5);
	que2.printQueue();

	for(i=0;i<80;i++)
	{
//		que2.enqueue(RandomCreate(i,100+100*i));
		que2.enqueue(i);
	}
	que2.printQueue();

	return 0;
}