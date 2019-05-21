#include <iostream>
using namespace std;

int length = 45;
int RandomCreate(int seed, int area)
{
	srand(seed);
	srand(rand());
	srand(rand());
	srand(rand());
	return rand()%area;
}

void printArray(int*arr, int len = 10)
{
	for(int i=0;i<len;i++)
	{
		std::cout<<arr[i]<<"\t";
	}
	std::cout<<std::endl;
}

//向下调整
void downAdjust(int *arr, int parent, int length)
{
	if(length<=1)
		return;
	int child = 2*parent + 1;
	int temp = arr[parent];
	while(child < length)
	{
		if(child + 1 < length && arr[child+1] > arr[child])
			child = child +1 1;
		if(temp > arr[child])
			break;
		arr[parent] = arr[child];
		parent = child;
		child = 2*parent + 1;
	}
	arr[parent] = temp;
}

//堆排序
void HeapSort(int *arr,int len)
{
	for(int i=(len-2)/2; i>=0; i--)
	{
		downAdjust(arr,i,len);
	}
	for(i=1;i<len;i++)
	{
		int temp = arr[0];
		arr[0] = arr[len-i];
		arr[len-i] = temp;
		downAdjust(arr,0,len-i);
	}
}

int main(int argc, char *argv[])
{
	int len = 10;
	std::cout<<"Please enter length:";
	std::cin>>len;
	if(len>10000)
		len=10000;
	int *arr = new int[len];
	for(int i=0;i<len;i++)
		arr[i] = RandomCreate(10*i+10,len*10);
	printArray(arr,len);
	HeapSort(arr,len);
	printArray(arr,len);
	for(int j=0;j<len-1;j++)
	{
		if(arr[j]>arr[j+1])
			cout<<"Sort Failed: "<<j<<endl;
	}
	return 0;
}
