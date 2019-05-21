#include <iostream>
using namespace std;

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

void Merge(int *arr, int mid,int left,int right)
{
	int *temp = new int[right-left+1];
	int i = left;
	int j = mid+1;
	int k = 0;
	while(i<=mid&&j<=right)
	{
		if(arr[i]<arr[j])
			temp[k++]=arr[i++];
		else
			temp[k++]=arr[j++];
	}
	while(i<=mid)
		temp[k++]=arr[i++];
	while(j<=right)
		temp[k++]=arr[j++];
	i=0;
//	k = left
	while(i<k)
		arr[left++]=temp[i++];
//	delete[] temp;
}

//¹é²¢ÅÅĞò
int* MergeSort2(int *arr,int left, int right)
{
	if(left<right)
	{
		int mid = (left+right)/2;
		arr = MergeSort2(arr,left,mid);
		arr = MergeSort2(arr,mid+1,right);
		Merge(arr,mid,left,right);
	}
	return arr;
}

void MergeSort(int *arr,int left, int right)
{
	if(left<right)
	{
		int mid = (left+right)/2;
		MergeSort(arr,left,mid);
		MergeSort(arr,mid+1,right);
		Merge(arr,mid,left,right);
	}
}

int main(int argc, char *argv[])
{
	int len = 30;
	int *arr = new int[len];
	for(int i=0;i<len;i++)
		arr[i] = RandomCreate(10*i+10,100);
	printArray(arr,len);
	MergeSort(arr,0,len-1);
	printArray(arr,len);
	return 0;
}
