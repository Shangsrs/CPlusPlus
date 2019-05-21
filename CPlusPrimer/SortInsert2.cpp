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


typedef bool (*func)(int &t1, int &t2);
//²åÈëÅÅĞò
void InsertSort(int *arr,int len)
{
	if(arr == NULL || len <=1)
		return;
	for(int i=1;i<len;i++)
	{
		int element = arr[i];
		for(int j=0;j<i;j++)
		{
			if(element < arr[j])
			{
				for(int m=i;m>j;m--)
					arr[m]=arr[m-1];
				arr[j] = element;
				break;
			}
		}
	}
}


int main(int argc, char *argv[])
{
	int len = 30;
	int *arr = new int[len];
	for(int i=0;i<len;i++)
		arr[i] = RandomCreate(10*i+10,100);
	printArray(arr,len);
	InsertSort(arr,len);
	printArray(arr,len);
	
	return 0;
}
