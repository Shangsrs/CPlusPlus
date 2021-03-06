#include <iostream>
#include <stack>
#include <queue>
#include <list>
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
void sort(T *arr, int length)cccccccccccccccccc
{
	if(arr==NULL || length <= 1)
		return;
//	selectSort(arr, length);
//	insertSort(arr, length);
//	bubbleSort(arr, length);
//	shellSort(arr, length);
//	mergeSort(arr,0,length-1);
//	mergeSort(arr,length);
//	quickSort(arr,0,length-1);
//	heapSort(arr,length);
	countSort(arr,length);
//	binarySort(arr,length);
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
void mergeSort(T *arr, int length, char* backup)
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

//QuickSort
template<class T>
void quickSort(T *arr, int left, int right)
{
	if(left>=right)
		return;
	T pivot = arr[left];
	int i=left, j=right;
	while(i<j)
	{
		while(arr[j]>=pivot && i<j) j--;
		while(arr[i]<=pivot && i<j) i++;
		T temp = arr[i];
		arr[i]=arr[j];
		arr[j]=temp;
	}
	arr[left]=arr[i];
	arr[i]=pivot;
	quickSort(arr,left,i-1);
	quickSort(arr,i+1,right);
	
}

//Heap Sort
template<class T>
void downAdjust(T *arr, int parent, int length)
{
	int child = 2*parent+1;
	while(child < length)
	{
		if(child+1<length && arr[child+1]>arr[child])
			child++;
		if(arr[child]<arr[parent])
			break;
		T temp = arr[parent];
		arr[parent]=arr[child];
		arr[child]=temp;
		parent = child;
		child = 2*parent + 1;
	}
}

template<class T>
void heapSort(T *arr, int length)
{
	if(length<=1)
		return;
	for(int i=(length-2)/2;i>=0;i--)
		downAdjust(arr,i,length);
	for(int i=1;i<length;i++)
	{
		T temp = arr[length-i];
		arr[length-i] = arr[0];
		arr[0] = temp;
		downAdjust(arr,0,length-i);
	}
}

//Count Sort
template<class T>
void countSort(T *arr, int length)
{
	T max=arr[0], min=arr[0];
	for(int i=1;i<length;i++)
	{
		if(arr[i]>max)
			max=arr[i];
		if(arr[i]<min)
			min=arr[i];
	}
	T *pos = new T[max-min+1];
	for(int i=0;i<max-min+1;i++)
		pos[i]=0;
		
	for(int j=0;j<length;j++)
		pos[arr[j]-min]++;
	for(int t=1;t<max-min+1;t++)
		pos[t]+=pos[t-1];
	T *newArr = new T[length];
	for(int i=0;i<length;i++)
	{
		newArr[pos[arr[i]-min]-1] = arr[i];
		pos[arr[i]-min]--;
	}
	for(int i=0;i<length;i++)
	{
		arr[i]=newArr[i];
	}
	
	delete[] pos;
	delete[] newArr;
		
}

//Base sort
template<class T>
void baseSort(T *arr, int length)
{

	

}

//bucket sort
template<class T>
void bucketSort(T *arr, int length)
{
	T max=arr[0], min=arr[0];
	for(int i=1;i<length;i++)
	{
		if(arr[i]>max)
			max=arr[i];
		if(arr[i]<min)
			min=arr[i];
	}
	int d = max-min;
	int bucketNum = d/5+1;
//	list<list<T*>*> *bucketList = new list<list<T*>*>();
}


//BinaryTree Sort
template<class T>
struct Node
{
	Node<T> *left, *right;
	T value;
	Node<T>(T data=0)
	{
		left = right = NULL;
		value = data;
	}
};
	
template<class T>
void preOrder(Node<T> *node)
{
	stack<Node<T>*> st;
	Node<T> *curr = node;
	int i=0;
	std::cout<<"Pre Order: "<<std::endl;
	while(curr !=NULL || !st.empty())
	{
		std::cout<<curr->value<<"\t";
		st.push(curr);
		curr = curr->left;
		while(!curr && !st.empty())
		{
			curr = st.top();
			st.pop();
			curr = curr->right;
		}
	}
	std::cout<<std::endl;
}


template<class T>
void inOrder(Node<T> *node,T *arr)cccccccc
{
	stack<Node<T>*> st;
	Node<T> *curr = node;
	int i=0;
	while(curr != NULL || !st.empty())
	{
		if(curr->left != NULL)
		{
			st.push(curr);
			curr=curr->left;
		}
		else
		{
			arr[i++]=curr->value;
			curr=curr->right;
			while(!curr && !st.empty())
			{
				curr=st.top();
				arr[i++]=curr->value;
				st.pop();
				curr=curr->right;
			}
		}
	}
	
}

template<class T>
void postOrder(Node<T> *node)
{
	stack<Node<T>*> st;
	Node<T> *curr = node;
	Node<T> *pre = NULL;
	int i=0;
	st.push(node);
	std::cout<<"Post Order: "<<std::endl;
	while(!st.empty())
	{
		curr = st.top();
		if((curr->left==NULL && curr->right==NULL)||
			pre!=NULL && (curr->left==pre || curr->right==pre))
		{
			std::cout<<curr->value<<"\t";
			st.pop();
			pre = curr;
		}
		else
		{
			if(curr->left !=NULL)
				st.push(curr->left);
			if(curr->right != NULL)
				st.push(curr->right);
		}
	}
	std::cout<<std::endl;
	std::cout<<"In Order: "<<std::endl;
}


template<class T>
void layerOrder(Node<T> *node)
{
	Node<T> *curr = NULL;
	queue<Node<T>*> que;
	que.push(node);
	std::cout<<"Layout Order"<<endl;
	while(!que.empty())
	{
		curr=que.front();
		que.pop();
		std::cout<<curr->value<<"\t";
		if(curr->left != NULL)
			que.push(curr->left);
		if(curr->right != NULL)
			que.push(curr->right);
	}
	std::cout<<std::endl;
}


template<class T>
void inOrder(Node<T> *node,T *arr, int &index)
{

	if(node->left)
		inOrder(node->left,arr,index);
	arr[index++] = node->value;
	if(node->right)
		inOrder(node->right,arr,index);			
}


template<class T>
void insertNode(Node<T> *root,T data)
{
	if(root->value > data)
	{
		if(root->left == NULL)
			root->left = new Node<T>(data);
		else
			insertNode(root->left,data);
	}
	else 
	{
		if(root->right == NULL)
			root->right = new Node<T>(data);
		else
			insertNode(root->right,data);
	}
}

template<class T>
void binarySort(T *arr, int length)
{
	Node<T> *root = new Node<T>(arr[0]);
	for(int i=1;i<length;i++)
	{	
		insertNode(root,arr[i]);
	}
//	std::cout<<"Binary Output:"<<endl;
	int index = 0;
	layerOrder(root);
	inOrder(root,arr);
	preOrder(root);
	postOrder(root);
//	inOrder(root,arr,index);
//	std::cout<<"Binary Output end:"<<endl;
}


//Base Sort

//Bucket Sort


void Test1()
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
}

void Test4()//for Binary Tree sort
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
}

void Test3()
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
		arr[i] = randomCreate(10*i+10,100);
	}
	printArray(arr,length);
	sort<int>(arr,length);
	printArray(arr,length);
	for(int i=1;i<length;i++)
	{
		if(arr[i-1]>arr[i])
			std::cout<<"Sort Failed : "<<i<<std::endl;
	}
}

void Test2()
{
	int j=0;
	int *arr;
	for(int i=2;i<=200	;i++)
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
		printArray(arr,i);
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
int main()
{
	Test1();
//	Test2();
//	Test4();
	return 0;
}
