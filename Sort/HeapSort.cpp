#include <iostream>
using namespace std;

int randomCreate(int seed, int range)
{
	srand(seed);
	srand(rand());
	srand(rand())	;
	return rand()%range;
}

void printArray(int *arr, int len)
{
	for(int i=0;i<len;i++)
		cout<<*arr++<<'\t';
	cout<<endl<<endl;
}

void downAdjust(int *arr, int parent,int length)
{
	int child = 2*parent +1;
	int temp = arr[parent];
	while(child<length)
	{
		if(child+1<length && arr[child+1]>arr[child])
			child = child +1;
		if(temp > arr[child])
			break;
		arr[parent]=arr[child];
		parent = child;
		child = 2*parent+1;
	}
	arr[parent] = temp;
}

void heapSort(int *arr, int len)
{
	if(arr==NULL || len<1)
		return;
	for(int i=(len-2)/2;i>=0;i--)
	{
		downAdjust(arr,i,len);
	}
	printArray(arr,len);
	for(int i=0;i<len;i++)
	{
		int temp = arr[0];
		arr[0]=arr[len-1-i];
		arr[len-1-i]=temp;
		downAdjust(arr,0,len-1-i);
	}
}

int main()
{
	int length = 10;
	std::cout<<"Please enter a number:";
	std::cin>>length;
	std::cout<<std::endl;
	int *arr = new int[length];
	if(!arr)
		cout<<"Allocate Err"<<endl;
	for(int i=0;i<length;i++)
	{
		arr[i] = randomCreate(10*i+10,length*4);
	}
	printArray(arr,length);
	heapSort(arr,length);
	printArray(arr,length);
	for(int i=1;i<length;i++)
	{
		if(arr[i-1]>arr[i])
			std::cout<<"Sort Failed: "<<i<<std::endl;
	}
	return 0;
}