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

void quickSort(int *arr, int left, int right)
{
	if(left>=right)
		return;
	int pivot = arr[left];
	int i=left, j=right;
	while(i<j)
	{
		while(arr[j]>=pivot && i<j) j--;
		while(arr[i]<=pivot && i<j) i++;
		int temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
	}
	arr[left] = arr[i];
	arr[i] = pivot;	
	quickSort(arr,left, i-1);
	quickSort(arr,i+1,right);
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
		arr[i] = randomCreate(10*i+10,length*10);
	}
	printArray(arr,length);
	quickSort(arr,0,length-1);
	printArray(arr,length);
	for(int i=1;i<length;i++)
	{
		if(arr[i-1]>arr[i])
			std::cout<<"Sort Failed!"<<std::endl;
	}
	return 0;
}