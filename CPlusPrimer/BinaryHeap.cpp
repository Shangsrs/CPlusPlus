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
//二叉堆 父节点：(n-1)/2 子节点：2*n+1  2*n+2

template<class T>
class BinaryHeap
{
private:
	int *data;
	int size;
	int length;
public:
	BinaryHeap(int *arr,int len);
	~BinaryHeap();
	void upAdjust(int len);
	void insert(T value);
	void downAdjust(int len);
	int getLength();
	T getData(int i);
	void sortDown();//Down adjust sort
	void sortUp();//Up adjust sort
	friend ostream& operator<<(ostream &out,BinaryHeap<T> bh);
};

template<class T>
T BinaryHeap<T>::getData(int i)
{
	return data[i];
}

template<class T>
int BinaryHeap<T>::getLength()
{
	return length;
}

template<class T>
BinaryHeap<T>::BinaryHeap(int *arr,int len)
{
	int size = 2*len>64?2*len:60;
	data = new T[size];
	length=0;
	if(arr!=NULL && len>0)
	{
		for(int i=0;i<len;i++)
			insert(arr[i]);
	}
}

template<class T>
BinaryHeap<T>::~BinaryHeap()
{
}

template<class T>
void BinaryHeap<T>::insert(T value)
{
	data[length]=value;
	int child = length;
	int parent = length;
	while((parent-1)>=0)
	{
		parent = (parent - 1)/2;
		if(data[child]>data[parent])
		{
			T temp = data[parent];
			data[parent] = data[child];
			data[child] = temp;
		}
		child = parent;
	}
	length++;
}

template<class T>
void BinaryHeap<T>::upAdjust()
{

}

template<class T>
void BinaryHeap<T>::sortUp()
{
}

template<class T>
void BinaryHeap<T>::downAdjust(int len)
{
	int parent = 0;
	int child = 2*parent+1;
	T temp = data[parent];
	while(child < len)
	{
		if(child+1<len && data[child] < data[child+1])
		{
			child = child + 1;
		}
		if(temp > data[child])
			break;
		data[parent] = data[child];
		parent = child;
		child = 2*parent + 1;
	}
	data[parent] = temp;
}


template<class T>
void BinaryHeap<T>::sortDown()
{
	T temp;
	for(int i=1;i<length;i++)
	{
		temp = data[length-i];
		data[length-i] = data[0];
		data[0] = temp;
		downAdjust(length-i-1);
	}
	temp = data[0];
	for(i=0;i<length;i++)
	{
		std::cout<<data[i]<<'\t';
		if(data[i]<temp)
			std::cout<<"Sort Failed";
		temp = i;
	}
}


template<class T>
ostream& operator<<(ostream &out,BinaryHeap<T> &bh)
{
	int len = bh.getLength();
	int row = 0;
	int parent = len;
	while(parent>0)
	{
		row++;
		parent = (parent-1)/2;
	}
	row ++;
	if(len<=0)
	{
		out<<"Empty heap";
		return out;
	}
	out<<"( ";

	for(int n=0;n<len;n++)
		out<<bh.getData(n)<<'\t';
	out<<")"<<std::endl;
	int begin = 1;
	for (int i=0;i<row ;i++ )
	{
		for(int m=(row-i);m>0;m--)
			cout<<'\t';
		for(int j=begin-1;j<begin*2-1 && j<len;j++)
		{
			out<<bh.getData(j)<<'\t';
		}
		begin = begin*2;
		out<<std::endl<<std::endl;
	}
	return out;
}


int main(int argc, char *argv[])
{
	int len = 35;
//	std::cout<<"Please enter length::"<<std::endl;
//	std::cin>>len;
	if(len>10000)
		len=10000;
	int *arr = new int[len];
	for(int i=0;i<len;i++)
		arr[i] = RandomCreate(10*i+10,len*2);
	printArray(arr,len);
	BinaryHeap<int> *bh = new BinaryHeap<int>(arr,len);
	std::cout<<*bh;
	bh->sortDown();
	return 0;
}


