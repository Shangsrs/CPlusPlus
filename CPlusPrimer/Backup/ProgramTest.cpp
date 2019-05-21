#include <iostream>
//#include <random>
//二分查找
int BinaryFind(int* arr, int item,int len)
{
	int low = 0, high = len-1;
	while(low <= high)
	{
		int mid = (low + high)/2;
		std::cout<<low <<" "  <<high <<" " <<mid <<std::endl;
		if(arr[mid] == item)
			return mid;
		else if(arr[mid] < item)
		{
			low = mid + 1;
		}
		else
		{
			high = mid - 1;
		}
	}
	return -1;
}
//打印数组
void printArray(int*arr, int len = 10)
{
	for(int i=0;i<len;i++)
	{
		std::cout<<arr[i]<<" ";
	}
	std::cout<<std::endl;
}
//产生随机数
int RandomCreate(int seed, int area)
{
	srand(seed);
	srand(rand());
	return rand()%area;
}
//快速排序
void QuickSort(int* arr, int begin, int len)
{
	if(len < 2)
		return ;
	int base = arr[begin];
//	std::cout<<"begin:"<<begin<<" len:"<<len<<" base:" <<base<<std::endl;
//	printArray(arr);
	int i = begin, j= begin + len - 1;
	while (i!=j)
	{
		while(arr[j]>base && i<j)
			j--;

		while(arr[i]<=base && i<j)
			i++;
		if(i!=j)
		{
			int temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
//		std::cout<<"i:"<<i<<" j:"<<j<<std::endl;
	}
	arr[begin] = arr[i];
	arr[i] = base;
//	printArray(arr);
///	system("pause");
	QuickSort(arr,begin,i-begin);
	QuickSort(arr,i+1,begin+len-i-1);
}

//最大相似字符串
char* maxSameCharacter(const char* ch1, const char* ch2)
{
	int len1, len2;
	len1 = strlen(ch1);
	len2 = strlen(ch2);
	std::cout<<"len1: " << len1 <<" len2: " << len2 << std::endl;
	std::cout<<"ch1: " << ch1 <<" ch2: " << ch2 << std::endl;
	if(len1==0 || len2==0)
		return NULL;
	int *cell = new int[len1*len2];
	int i=0, j=0;
	for(i = 0; i < len1; i++)
	{
		for(j = 0; j < len2; j++)
		{
			if(ch1[i] == ch2[j])
			{
				if(i >= 1 && j >= 1)
				{
					cell[i*len2+j] = cell[(i-1)*len2 + j-1] + 1;
				} 
				else
				{
					cell[ i * len2 + j] = 1;
				}
			} 
			else
			{
				cell[ i * len2 + j] = 0;
			}
//			std::cout<<" (" <<i * len2 + j<<") ";
//			std::cout<<cell[ i * len2 + j]<<" ";
//			std::cout<<"I: " << i <<" j: " << j << std::endl;
		}
//		std::cout<<std::endl;
	}

	int maxLen = 0;
	int maxIndex = 0;

	for(i=0; i<len1*len2; i++)
	{
		if(maxLen < cell[i])
		{
			maxLen = cell[i];
			maxIndex = i;
		}
		std::cout<<cell[i]<<" ";
		if( (i+1) % len2 == 0)
			std::cout<<std::endl;
	}
//	std::cout<<"maxLen:"<<maxLen<<std::endl;
	char* sameChar = new char[64];
	if(sameChar == NULL)
		return NULL;
	memset(sameChar,0,64);
	int n = maxIndex;
//	std::cout<<"maxIndex: " << maxIndex << std::endl;
//	std::cout<<"ch1: " << ch1 <<" ch2: " << ch2 << std::endl;
	for(int m = maxLen ; m > 0 ; m--)
	{
//		std::cout<<"maxIndex:"<<m<<std::endl;
		sameChar[m-1] = ch2[n%len2];
		n = n-len2-1;
//		std::cout<<"n:"<<n<<std::endl;
	}
	
	sameChar[maxLen] = '\0';
	return sameChar;
}
//最大相似字符序列
int maxSameCharacterSeq(const char* ch1, const char* ch2)
{
	int len1, len2;
	len1 = strlen(ch1);
	len2 = strlen(ch2);
	std::cout<<"len1: " << len1 <<" len2: " << len2 << std::endl;
	std::cout<<"ch1: " << ch1 <<" ch2: " << ch2 << std::endl;
	if(len1==0 || len2==0)
		return NULL;
	int *cell = new int[len1*len2];
	int i=0, j=0;
	for(i = 0; i < len1; i++)
	{
		for(j = 0; j < len2; j++)
		{
			if(ch1[i] == ch2[j])
			{
				if(i >= 1 && j >= 1)
				{
					cell[i*len2+j] = cell[(i-1)*len2 + j-1] + 1;
				} 
				else
				{
					cell[ i * len2 + j] = 1;
				}
			} 
			else
			{
				if(i==0 && j==0)
					cell[i * len2 + j] = 0;
				else if(i==0)
					cell[i * len2 + j] = cell[j-1];
				else if(j == 0)
					cell[i * len2 + j] = cell[(i-1)*len2];
				else
					cell[ i * len2 + j] = (cell[(i-1)*len2+j]>cell[i*len2+j-1])?cell[(i-1)*len2+j]:cell[i*len2+j-1];
				
			}
//			std::cout<<" (" <<i * len2 + j<<") ";
//			std::cout<<cell[ i * len2 + j]<<" ";
//			std::cout<<"I: " << i <<" j: " << j << std::endl;
		}
//		std::cout<<std::endl;
	}

	int maxLen = 0;
	int maxIndex = 0;

	for(i=0; i<len1*len2; i++)
	{
		if(maxLen < cell[i])
		{
			maxLen = cell[i];
			maxIndex = i;
		}
		std::cout<<cell[i]<<" ";
		if( (i+1) % len2 == 0)
			std::cout<<std::endl;
	}
//	std::cout<<"maxLen:"<<maxLen<<std::endl;
/*
	char* sameChar = new char[64];
	if(sameChar == NULL)
		return NULL;
	memset(sameChar,0,64);
	int n = maxIndex;
//	std::cout<<"maxIndex: " << maxIndex << std::endl;
//	std::cout<<"ch1: " << ch1 <<" ch2: " << ch2 << std::endl;
	for(int m = maxLen ; m > 0 ; m--)
	{
//		std::cout<<"maxIndex:"<<m<<std::endl;
		sameChar[m-1] = ch2[n%len2];
		n = n-len2-1;
//		std::cout<<"n:"<<n<<std::endl;
	}
	
	sameChar[maxLen] = '\0';
*/
	return maxLen;
}

int main5()
{
	char* ch1 = new char[64];
	char* ch2 = new char[64];
//	ch2 = "shangsrs";
//	ch1 = "shang";
	std::cout<<"Please enter Character 1:"<<std::endl;
	std::cin>>ch1;
	std::cout<<"Please enter Character 2:"<<std::endl;
	std::cin>>ch2;
//	std::cout<<"test:"<<std::endl;
	int sameChar = maxSameCharacterSeq(ch1,ch2);//最大相似字符序列
	std::cout<<"Max same char len is:  " << sameChar << std::endl;
	return 0;
}

int main()
{
	char* ch1 = new char[64];
	char* ch2 = new char[64];
//	ch2 = "shangsrs";
//	ch1 = "shang";
	std::cout<<"Please enter Character 1:"<<std::endl;
	std::cin>>ch1;
	std::cout<<"Please enter Character 2:"<<std::endl;
	std::cin>>ch2;
//	std::cout<<"test:"<<std::endl;
	char* sameChar = maxSameCharacter(ch1,ch2);//最大相似字符串
	if(sameChar == NULL)
		return -1;
	std::cout<<"Max same char len is:  " << strlen(sameChar) << std::endl;
	std::cout<<"Max same char is: " << sameChar << std::endl; 
	return 0;
}

int main3()
{
	int len = 0;
	std::cout<<"Please enter lenth:"<<std::endl;
	std::cin>>len;
	int *arr = new int[len];
	for (int i=0; i < len ; i++ )
	{
		arr[i] = RandomCreate(i,10*len);
	}
	std::cout<<"Before Sort:"<<std::endl;
	printArray(arr,len);

	QuickSort(arr,0,len);//快速排序
	std::cout<<"After Sort:"<<std::endl;
	printArray(arr,len);
	return 0;
}

int main2()
{
	int len = 13;
	int* arr = new int[len] ;
	for (int i = 0;i<len ;i++ )
	{
		arr[i] = i+1;
	}
	int item = 0;
	std::cout<<"Please enter a number:"<<std::endl;
	std::cin>>item;
	int result = BinaryFind(arr,item,len);//二分查找
	if(result < 0)
	{
		std::cout<<"Can not find the number: "<<item<<std::endl;
	}
	else
	{
		std::cout<<item<<" 's index is "<<result;
	}
	return 0;
}

