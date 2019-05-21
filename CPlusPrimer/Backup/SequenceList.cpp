#include "SequenceList.h"


int main(int argc, char *argv[])
{
	printf("Hello, world\n");
	int len = 9;
	SeqList<int> array(20);
	for(int i=0;i<len;i++)
		array.insert(i+1);
/*
	std::cout<<array<<std::endl;
	int a=0;
	array.remove(5,a);
	array.insert(0,RandomCreate(4,1000));
	std::cout<<array<<std::endl;
	array.clear();
	array.insert(6,RandomCreate(5,1000));
	std::cout<<array<<std::endl;
	array.clear();
	std::cout<<array<<std::endl;
*/
	std::cout<<"Array: " <<array<<std::endl;
	int a = 0;
	i=0 ;
	int j=0;
	while(array.length()>=3)
	{
		i+=7;
		j = i%array.length();
		std::cout<<" "<<array.get(j);
		array.remove(j,a);
	}
	return 0;
}
