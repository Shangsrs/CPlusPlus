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
		std::cout<<arr[i]<<" ";
	}
	std::cout<<std::endl;
}


//Ã°ÅİÅÅĞò
void BubbleSort(int *arr,int len)
{
	if(arr == NULL || len <=1)
		return;
	bool flag = false;
	for(int i=0;i<len;i++)
	{
		for(int j=0;j<len-i;j++)
		{
			if(arr[j]>arr[j+1])
			{
				flag = true;
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1]=temp;
			}
		}
		if(!flag)
			break;
	}
}


int main(int argc, char *argv[])
{
	int len = 30;
	int *arr = new int[len];
	for(int i=0;i<len;i++)
		arr[i] = RandomCreate(10*i+10,100);
	printArray(arr,len);
	BubbleSort(arr,len);
	printArray(arr,len);
	BubbleSort(arr,len);
	printArray(arr,len);
	
	return 0;
}
