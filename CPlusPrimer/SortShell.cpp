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

void InsertSort(int *arr,int distance, int pos,int len)
{
	for (int i=1;pos+i*distance < len ;i++ )
	{
		int temp = arr[pos+i*distance];
		for(int j=0;j<i;j++)
		{
			if(temp<arr[pos+j*distance])
			{
				for(int m=i;m>j;m--)
					arr[pos+m*distance] = arr[pos+(m-1)*distance];
				arr[pos+j*distance]=temp;
				break;
			}
		}
	}
}


//Shell≈≈–Ú
void ShellSort(int *arr,int len)
{
	if(arr == NULL || len <=1)
		return;
	for(int i = len/2;i>0;i/=2)
	{
		for(int j=0;j<i;j++)
		{
			InsertSort(arr,i,j,len);
//			printArray(arr,len);
		}
	}
}

void InsertSort(int *arr,int distance, int pos)
{
	int temp = arr[pos];
	for (int i=pos%distance;i<pos ; i+=distance)
	{
		if(arr[i]>temp)
		{
			for(int j=pos;j>=i;j-=distance)
			{
				arr[j]=arr[j-distance];
			}
			arr[i]=temp;
			break;
		}
	}
}

void ShellSort2(int *arr,int len)
{
	if(arr == NULL || len <=1)
		return;
	for(int i = len/2;i>0;i/=2)
	{
		for(int j=i;j<len;j++)
		{
			InsertSort(arr,i,j);
		}
	}
}

void InsertSort2(int *arr,int len)
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
	ShellSort2(arr,len);
	printArray(arr,len);
	ShellSort(arr,len);
	printArray(arr,len);
	InsertSort2(arr,len);
	printArray(arr,len);

	return 0;
}
