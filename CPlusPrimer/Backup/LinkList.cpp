#include "LinkList.h"

int main()
{
	int *arr = new int[10];
	for(int i=0;i<10;i++)
	{
		arr[i] = i;
	}
	int temp;
	LinkList<int> list1;
	std::cout<<list1;
	LinkList<int> list2(arr[0]);
	std::cout<<list2;
	LinkList<int> list3(arr,10);
	std::cout<<list3;
	std::cout<<list3.get(2)<<std::endl;
	list3.insert(0,4);
	std::cout<<list3;
	list3.insert(4,5);
	std::cout<<list3;
	list3.remove(0,temp);
	std::cout<<list3;
	list3.remove(4,temp);
	std::cout<<list3;
	LinkList<char> ch1;
	std::cout<<ch1;
	char chTemp ;
	char *ch = new char[1024];
	ch = "Hello World!";
	LinkList<char> ch2(ch,14);
	std::cout<<ch2;
	ch2.remove(0,chTemp);
	std::cout<<ch2;

	return 0;
}