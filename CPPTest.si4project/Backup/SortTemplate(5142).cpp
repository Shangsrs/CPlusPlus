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

template<class T>
void sort(T *arr, int length)
{
	if(arr==NULL || length <= 0)
		return;
//	selectSort(arr, length);
//	insertSort(arr, length);
//	bubbleSort(arr, length);
//	shellSort(arr, length);
//	mergeSort(arr,0,length-1);
	mergeSort(arr,length);
}
//Select Sort
template<class T>
void selectSort(T *arr, int length)
{
	for(int i=0;i<length;i++)
	{
		int max = 0;
		for(int j=0;j<length-i;j++)
		{
			if(arr[j]>arr[max])
			{
				max = j;
			}
		}
		T temp = arr[max];
		arr[max] = arr[length-i-1];
		arr[length-i-1] = temp;
	}
}

//Insert Sort
template<class T>
void insertSort(T *arr, int length)
{
	for(int i=0; i<length; i++)
	{
		int pos = i;
		while(pos-1>=0 && arr[pos-1]>arr[pos])
		{
			T temp = arr[pos];
			arr[pos] = arr[pos-1];
			arr[pos-1] = temp;
			pos--;
		}
	}
}
//Bubble Sort
template<class T>
void bubbleSort(T *arr, int length)
{
	for(int i=0;i<length;i++)
	{
		for(int j=0;j<length-i-1;j++)
		{
			if(arr[j]>arr[j+1])
			{
				T temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
}


//Shell Function
template<class T>
void shell(T *arr, int distance, int length)
{
	for(int i=distance;i<length;i++)
	{
		int pos = i;
		while(pos-distance>=0 && arr[pos-distance]>arr[pos])
		{
			T temp = arr[pos];
			arr[pos] = arr[pos-distance];
			arr[pos-distance] = temp;
			pos--;
		}
	}
}

//Shell Sort
template<class T>
void shellSort(T *arr, int length)
{
	for(int i=length/2;i>0;i=i/2)
	{
		shell(arr,i,length);
	}
}
//Merge Sort
template<class T>
void merge(T *arr, int left, int mid, int right)
{
//	if(right<=left)
//		return;
	int i = left, j = mid+1, m = 0;
	T *temp = new T[right-left+1];
	while(i<=mid && j <=right)
	{
		if(arr[i]>arr[j])
			temp[m++] = arr[j++];
		else
			temp[m++] = arr[i++];
	}
	while(i<=mid)
		temp[m++] = arr[i++];
	while(j<=right)
		temp[m++] = arr[j++];
	i = left;
	m = 0;
	while(i<=right)
		arr[i++] = temp[m++];
	delete temp;
}

template<class T>
void mergeSort(T *arr, int left, int right)
{
	if(right<=left)
		return;
	int mid = (right+left)/2;
	mergeSort(arr,left, mid);
	mergeSort(arr,mid+1,right);
	merge(arr,left,mid,right);
}

template<class T>
void mergeSort(T *arr, int length)
{
	if(arr == NULL && length <=1)
		return;
	int i=0;
	for(i=2;i<length;i*=2)
	{
		int j=0;
		while(j<length)
		{
			if(j+i <= length)
			{
				int mid = (j+j+i-1)/2;
				merge(arr,j,mid,j+i-1);
				j+=i;
			}
			else
			{
				int mid = (j + length -1)/2;
				merge(arr,j,mid,length-1);
				break;
			}
		}
		printArray(arr,length);
	}
}

//QuickSort

//Heap Sort

//Base Sort

//Bucket Sort

//Count Sort

//BinaryTree Sort

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
	sort<int>(arr,length);
	printArray(arr,length);
	for(int i=1;i<length;i++)
	{
		if(arr[i-1]>arr[i])
			std::cout<<"Sort Failed : "<<i<<std::endl;
	}
	return 0;
}
