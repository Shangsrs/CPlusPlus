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
	std::cout<<std::endl<<std::endl;
}

void Quick(int *arr, int left, int right)
{
	if(left>right)
		return;
	int pos = (left+right)/2;
	pos = right;
	int pivot = arr[pos];
	int i = left, j = right;
	while(i<j)
	{
		while(arr[i]<=pivot && i<j)
			i++;
		while(arr[j]>=pivot && i<j)
			j--;
		int temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
	}
	arr[pos] = arr[i];
	arr[i] = pivot;
	Quick(arr,left,i-1);
	Quick(arr,i+1,right);

}

//¿ìËÙÅÅÐò
void QuickSort(int *arr,int len)
{
	if(arr==NULL && len<=0)
		return;
	Quick(arr, 0,len-1);
}


int main(int argc, char *argv[])
{
	int len = 20;
	std::cout<<"Please enter length::"<<std::endl;
	std::cin>>len;
	if(len>10000)
		len=10000;
	int *arr = new int[len];
	for(int i=0;i<len;i++)
		arr[i] = RandomCreate(10*i+10,len*2);
	printArray(arr,len);
	QuickSort(arr,len);
	printArray(arr,len);
	for(int j=0;j<len-1;j++)
	{
		if(arr[j]>arr[j+1])
			cout<<"Sort Failed"<<endl;
	}
	return 0;
}
