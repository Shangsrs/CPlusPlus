#include <iostream>
using namespace std;

int randomCreate(int seed, int range)
{
	int flag = 1;
	srand(seed);
	srand(rand());
	srand(rand());
	if(rand()%2==0)
		flag=-1;
	srand(rand());
	return flag*rand()%range;

}

int randomCreate(int range)
{
	int flag = 1;
	srand(time());
	if(rand()%2==0)
		flag=-1;
	srand(rand());
	return flag*rand()%range;

}

void printArray(int *arr, int len)
{
	for(int i=0;i<len;i++)
		cout<<*arr++<<'\t';
	cout<<endl<<endl;
}

void printArray(int *arr, int start, int end)
{
	for(int i=start;i<=end;i++)
		cout<<arr[i]<<'\t';
	cout<<endl<<endl;
}


struct MaxInfo
{
	int leftIndex;
	int rightIndex;
	int maxSum;
	MaxInfo(int left, int right,int max)
	{
		leftIndex = left;
		rightIndex = right;
		maxSum = max;
	}
	MaxInfo()
	{
		leftIndex = 0;
		rightIndex = 0;
		maxSum = 0;
	}
};

MaxInfo findMaxCrossingSubarray(int *arr, int low, int mid, int high)
{
	int sum = 0, leftSum = 0, rightSum=0;
	int leftIndex = mid;
	int rightIndex = mid;
	int i = 0;
	leftSum = arr[mid];
	sum = arr[mid];
	for(i=mid-1;i>=0;i--)
	{
		sum+=arr[i];
		if(sum > leftSum)
		{
			leftSum = sum;
			leftIndex = i;
		}
	}
	rightSum = arr[mid];
	sum = arr[mid];
	for(i=mid+1; i<high;i++)
	{
		sum+=arr[i];
		if(sum > rightSum)
		{
			rightSum = sum;
			rightIndex = i;
		}
	}
	MaxInfo info(leftIndex, rightIndex, leftSum+rightSum-arr[mid]);
	return info;
}

MaxInfo findMaxSubarray(int *arr, int low, int high)
{
	if(low==high)
		return MaxInfo(low,high,arr[low]);
	int mid = (low + high)/2;
	MaxInfo left, right, cross;
	left = findMaxSubarray(arr, low, mid);
	right = findMaxSubarray(arr, mid+1, high);
	cross = findMaxCrossingSubarray(arr, low, mid, high);
	if(left.maxSum >= right.maxSum && left.maxSum >= cross.maxSum)
		return left;
	else if(right.maxSum >= left.maxSum && right.maxSum >= cross.maxSum)
		return right;
	else
		return cross;
}

MaxInfo findMaxSubarray(int *arr, int length)
{
	if(arr == NULL || length <= 1)
		return MaxInfo(0,0,arr[0]);
	int leftIndex=0,rightIndex=0,maxSum=0,sum=0;
//	leftIndex=i;
//	maxSum=sum=arr[i];
	for(int i=0;i<length;i++)
	{
		sum=arr[i];
		for(int j=i+1;j<length;j++)
		{
			sum+=arr[j];
			if(sum>maxSum)
			{
				leftIndex=i;
				rightIndex=j;
				maxSum=sum;
			}
		}
	}
	MaxInfo info(leftIndex, rightIndex, maxSum);
	return info;
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
		arr[i] = randomCreate(10*i+10,100);
	}
//	printArray(arr,length);
	MaxInfo info = findMaxSubarray(arr, 0, length-1);
	cout<<"Max info1: left="<<info.leftIndex<<" right="<<info.rightIndex<<" sum="<<info.maxSum<<endl;
	MaxInfo info2 = findMaxSubarray(arr, i);
	cout<<"Max info2: left="<<info2.leftIndex<<" right="<<info2.rightIndex<<" sum="<<info2.maxSum<<endl;
	delete[] arr;
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
			arr[j] = randomCreate(10*j+10,100);
		}
		
		MaxInfo info = findMaxSubarray(arr, 0, i-1);
		cout<<"Max info1: left="<<info.leftIndex<<" right="<<info.rightIndex<<" sum="<<info.maxSum<<endl;
		MaxInfo info2 = findMaxSubarray(arr, i);
		cout<<"Max info2: left="<<info2.leftIndex<<" right="<<info2.rightIndex<<" sum="<<info2.maxSum<<endl;
//		printArray(arr,i);
//		printArray(arr,info.leftIndex, info.rightIndex);
		delete[] arr;
	}
}

int main(int argc, char *argv[])
{
//	Test2();
	Test1();
	return 0;
}
