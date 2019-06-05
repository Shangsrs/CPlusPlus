#include "../header.h"
#include "PriorityQueueTest.h"


struct HuffmanNode
{
	char _c;
	int _freq;
	HuffmanNode():_c(' '),_freq(0){}
	HuffmanNode(char c,int freq):_c(c),_freq(freq){}
	bool operator<(const HuffmanNode &node)
	{
		return _freq < node._freq;
	}
	bool operator>(const HuffmanNode &node)
	{
		return _freq > node._freq;
	}
};

int CharFrequency(const char* ch, int length,int* &freq, MaxHeap<HuffmanNode> &heap)
{
	for(int i=0;i<128;i++)
		freq[i] = 0;
	for(int j=0;j<length;j++)
	{
		freq[(int)ch[j]]++;
	}
	int number = 0;
	for(int i=0;i<128;i++)
	{
		if(freq[i] != 0)
		{
//			cout<<hex<<i<<"-"<<(char)i<<":"<<dec<<freq[i]<<"\t\t";
			HuffmanNode *node = new HuffmanNode((char)i,freq[i]);
			heap.push(*node);
			number++;
		}
	}
	cout<<endl<<"Kinds: "<<number<<endl;
	return number;
}

int main()
{
	char* inputFile("text.txt");
	fstream readFile;
	readFile.open(inputFile,std::fstream::in );
	if(readFile.is_open())
	{
		cout<<"Open file "<<inputFile<<" Success"<<endl;
	}
	else
	{
		cout<<"Open file "<<inputFile<<" error"<<endl;
		return 1;
	}

	readFile.seekg(0,std::ios::end);
	int length = readFile.tellg();
	readFile.seekg(0,std::ios::beg);

	char *str = new char[length];
	
	readFile.read(str,length);	

	readFile.close();
	
	cout<<"length:"<<strlen(str)<<endl;

	MaxHeap<HuffmanNode> *heap = new MaxHeap<HuffmanNode>;

	int *freq = new int[128];
	CharFrequency(str,strlen(str),freq,*heap);
	while(!heap->empty())
	{
		cout<<heap->top()._c<<":"<<heap->top()._freq<<"\t";
		heap->pop();
	}
	cout<<endl;
	
	CharFrequency(str,strlen(str),freq,*heap);
	while(!heap->empty())
	{
		cout<<hex<<(int)(heap->top()._c)<<":"<<dec<<heap->top()._freq<<"\t";
		heap->pop();
	}
	
	return 0;
}

int main1()
{

	MaxHeap<HuffmanNode> *heap = new MaxHeap<HuffmanNode>;
	char str[1024];
	cout<<"Please input some string:"<<endl;
	gets(str);
//	str = "dabc   deg~!@#$%^&*()_+`1234567890-=';,./L:\
//	\"<>?GHF   kjhaaabbbcccdddeeefff";
	cout<<endl<<str<<endl;
	int *freq = new int[128];
//	CharFrequency(str.c_str(),str.length(),freq);
	int number = CharFrequency(str,strlen(str),freq,*heap);
	while(!heap->empty())
	{
//		cout<<hex<<(int)(heap->top()._c)<<":"<<heap->top()._freq<<"\t";
		cout<<heap->top()._c<<":"<<heap->top()._freq<<"\t";
		heap->pop();
	}
	return 0;
}
