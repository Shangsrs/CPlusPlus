#include <iostream>
#include <time.h>
#include <stack>
using namespace std;


int randomCreate(int seed, int range)
{
	srand(seed);
	srand(rand());
	srand(rand())	;
	return rand()%range;
}

int randomCreate(int range)
{
	srand(time(NULL));
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
//	mergeSort(arr,length);
//	quickSort(arr,0,length-1);
//	countSort(arr,length);
	binaryTreeSort(arr,length);
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
	int left=0,right=0,mid=0;
	for(int i=1;i<length;i+=i)
	{
		left=0;mid=left+i-1;right=mid+i;
		while(right<length)
		{
			merge(arr,left,mid,right);
			left=right+1;
			mid=left+i-1;
			right=mid+i;
		}
		if(mid<length && left<length)
			merge(arr,left,mid,length-1);
//		if(right >= length && left<length)
//			merge(arr,left,(left+length-1)/2+1,length-1);
	}
}


template<class T>
void mergeSort(T *arr, int length,int test,int test2)
{
	if(arr == NULL && length <=1)
		return;
	int i=0;
	int mid = 0;
	int j=0;
	for(i=2;i<length;i*=2)
	{
		j=0;
		while(j<length)
		{
			if(j+i <= length)
			{
				mid = (j+j+i-1)/2;
				merge(arr,j,mid,j+i-1);
				j+=i;
			}
			else
			{
				mid = (j + length -1)/2;
				merge(arr,j,mid,length-1);
				break;
			}
		}
		printArray(arr,length);
	}
	std::cout<<i<<std::endl;
	if(i>length && i/2 <length)
	{
		merge(arr,0,i/2-1,length-1);
	}
}

template<class T>
int partition(T *arr, int left, int right)
{
	T temp = arr[right];
	int i = left-1;
	for(int j=left;j<=right-1;j++)
	{
		if(arr[j]<=temp)
		{
			i++;
			T te = arr[i];
			arr[i] = arr[j];
			arr[j] = te;
		}
	}
	arr[right] = arr[i+1];
	arr[i+1] = temp;
	return i+1;
}


//QuickSort
template<class T>
void quickSort(T *arr, int left,int right)
{
	if(left<right)
	{
		int q = partition(arr,left,right);
		quickSort(arr,left,q-1);
		quickSort(arr,q+1,right);
	}
}

//Heap Sort
template<class T>
void heapSort(T *arr, int length)
{
}

//Base Sort
template<class T>
void baseSort(T *arr, int length)
{
}

//Bucket Sort
template<class T>
void bucketSort(T *arr, int length)
{
}

//Count Sort
template<class T>
void countSort(T *arr, int length)
{
	if(arr == NULL || length<= 1)
		return;
	T max = arr[0];
	T min = arr[0];
	int i = 0;
	while(i<length)
	{
		if(arr[i]>max)
			max = arr[i];
		if(arr[i]<min)
			min=arr[i];
		i++;
	}
	T *pos = new T[max-min+1];
	for(i=0;i<max-min+1;i++)
		pos[i]=0;
	for(i=0;i<length;i++)
		pos[arr[i]-min]++;
//	printArray(pos,max-min+1);
	for(i=1;i<=max-min;i++)
		pos[i]+=pos[i-1];
//	printArray(pos,max-min+1);
	T *newArr = new T[length];
//	std::cout<<min<<" "<<max<<std::endl;
	for(i=length-1;i>=0;i--)
	{
		newArr[pos[arr[i]-min]-1]=arr[i];
		pos[arr[i]-min]--;
//		std::cout<<arr[i]-min<<" ";
	}
//	printArray(pos,max-min+1);
//	std::cout<<endl;
//	printArray(newArr,length);
	for(i=0;i<length;i++)
		arr[i]=newArr[i];
//	arr = newArr;
	delete[] newArr;
	delete[] pos;
	
	

}
template<class T>
struct Node
{
	Node *left, *right;
	T value;
	Node(T data=0)
	{
		left = right = NULL;
		value = data;
	}
};


template<class T>
void inOrder(Node<T> *root, T *arr,int ind)
{
	Node<T> *curr = NULL;
	int index = 0;
	stack<Node<T>*> st;
	while(curr != NULL || !st.empty())
	{
		if(curr->left != NULL)
		{
			st.push(curr);
			curr = curr->left;
		}
		else
		{
			arr[index++] = curr->value;
			curr = curr->right;
			while(curr == NULL && !st.empty())
			{
				curr = st.top();
				
			}
		}
	}
}

int static index = 0;

template<class T>
void inOrder(Node<T> *node,T *arr)
{
	if(node == NULL)
		return;
	inOrder(node->left,arr);
	arr[index++] = node->value;
	std::cout<<node->value<<"\t";
	inOrder(node->right,arr);
}

template<class T>
void insert(Node<T> **node, T value)
{
	if(*node == NULL)
	{
		Node<T> *newNode = new Node<T>(value);
		*node = newNode;
		return;
	}
	if((*node)->value > value)
		insert(&((*node)->left),value);
	else
		insert(&((*node)->right),value);
}

//BinaryTree Sort
template<class T>
void binaryTreeSort(T *arr, int length)
{
	if(arr == NULL || length <=1)
		return;
	Node<T> *root = new Node<T>(arr[0]);
	for(int i=1;i<length;i++)
	{
		insert(&root,arr[i]);
	}
	std::cout<<"In Order:"<<endl;
	index = 0;
	inOrder(root,arr);
	std::cout<<endl;
}

void Test1()
{
	int length = 10;
	int i=0;
	std::cout<<"Please enter a number:";
	std::cin>>length;
	std::cout<<std::endl;
	int *arr = new int[length];
	if(!arr)
		cout<<"Allocate Err"<<endl;
	for(i=0;i<length;i++)
	{
		arr[i] = randomCreate(10*i+10,length*10);
	}
	printArray(arr,length);
	sort<int>(arr,length);
	printArray(arr,length);
	for(i=1;i<length;i++)
	{
		if(arr[i-1]>arr[i])
			std::cout<<"Sort Failed : "<<i<<std::endl;
	}
}

void Test2()
{
	int j=0;
	int *arr;
	for(int i=2;i<=200;i++)
	{
		arr = new int[i];
		if(!arr)
		{
			cout<<"Allocate memory error"<<endl;
			break;
		}
		for(j=0;j<i;j++)
		{
			arr[j] = randomCreate(10*j+10,(j+1)*10);
		}
		
		sort<int>(arr,i);
		printArray(arr,i);
		for(int m=1;m<i;m++)
		{
			if(arr[m-1]>arr[m])
				std::cout<<"Sort Failed: i="<<i<<", m="<<m<<std::endl;
		}
		delete[] arr;
	}
}

void Test3()
{
	int length = 10;
	int i=0;
	std::cout<<"Please enter a number:";
	std::cin>>length;
	std::cout<<std::endl;
	int *arr = new int[length];
	if(!arr)
		cout<<"Allocate Err"<<endl;
	for(i=0;i<length;i++)
	{
		arr[i] = randomCreate(length*10);
	}
	printArray(arr,length);
	sort<int>(arr,length);
	printArray(arr,length);
	for(i=1;i<length;i++)
	{
		if(arr[i-1]>arr[i])
			std::cout<<"Sort Failed : "<<i<<std::endl;
	}
}

void Test4()
{
	int j=0;
	int *arr;
	for(int i=2;i<=200;i++)
	{
		arr = new int[i];
		if(!arr)
		{
			cout<<"Allocate memory error"<<endl;
			break;
		}
		for(j=0;j<i;j++)
		{
			arr[j] = randomCreate((j+1)*10);
		}
		
		sort<int>(arr,i);
//		printArray(arr,i);
		for(int m=1;m<i;m++)
		{
			if(arr[m-1]>arr[m])
				std::cout<<"Sort Failed: i="<<i<<", m="<<m<<std::endl;
		}
		delete[] arr;
	}
}


int main()
{
	Test1();
//	Test2();
	//Test3();
//	Test4();
	return 0;
}
