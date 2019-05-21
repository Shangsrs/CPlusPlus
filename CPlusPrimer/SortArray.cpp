#include <iostream>
using namespace std;

int RandomCreate(int seed, int area)
{
	srand(seed);
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
//Ñ¡ÔñÅÅÐò
template<class T>
void SelectSort(T *arr,int len,func f1)
{
	for(int i=0;i<len;i++)
	{
		int min = i;
		int start = i;
		for(int j=i+1;j<len;j++)
		{
			if(f1(arr[min],arr[j]))
			{
				min = j;
			}
		}
		if(start!=min)
		{
			T temp = arr[start];
			arr[start] = arr[min];
			arr[min] = temp;
		}
	}
}

bool CompareInt(int &a,int &b)
{
	return a>b;
}


template<class T>
void InsertSort(T *arr,len,func f)
{

}


int main(int argc, char *argv[])
{
	int len = 10;
	int *arr = new int[len];
	for(int i=0;i<len;i++)
		arr[i] = RandomCreate(10*i+10,100);
	printArray(arr,len);
	SelectSort<int>(arr,len,CompareInt);
	printArray(arr,len);
	
	return 0;
}
