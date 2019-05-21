#include "Stack.h"
#include "StackSeqList.h"
#include "StackLinkList.h"

//#define type Stack<int>
//#define type StackSequence<int>
#define type StackLink<int>

int RandomCreate(int seed, int area)
{
	srand(seed);
	srand(rand());
	return rand()%area;
}

//#define type StackSequence<int>
//#define type int>

int main(int argc, char *argv[])
{
	int *arr = new int[10];
	for(int i=0;i<10;i++)
	{
		arr[i] = i;
	}

	type *st1 = new type;
	std::cout<<*st1;
	st1->pop();
	std::cout<<*st1;
	type *st2 = new type(arr,10);
	std::cout<<*st2;
	st2->pop();
	std::cout<<*st2;
	st2->clear();
	std::cout<<*st2;
	for (i=0;i<5 ;i++)
	{
		st2->push(RandomCreate(i,100+i*100));
	}
	std::cout<<*st2;

	while(!st2->isEmpty())
	{
		std::cout<<st2->pop()<<std::endl;
		std::cout<<*st2;
	}

	return 0;
}
