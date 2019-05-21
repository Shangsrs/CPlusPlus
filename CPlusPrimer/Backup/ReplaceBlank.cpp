#include <iostream>
using namespace std;

char* replaceBlank(const char* ch)
{
	int size = strlen(ch);
	if(size==0)
		return NULL;
	int num = 0;
	for(int i=0; i<size; i++)
	{
		if(ch[i] == ' ')
			num++;
	}
	char* newChar = new char[size+2*num+1];
	int t = size+2*num-1;
	for(i=size-1;i>=0;i--)
	{
		if(ch[i] ==' ')
		{
			newChar[t] = '0';
			newChar[t-1] = '2';
			newChar[t-2] = '%';
			t-=3;
		}
		else
		{
			newChar[t] = ch[i];
			t--;
		}
	}
	newChar[size+2*num] ='\0';
	return newChar;
}


int main()
{
	char* ch = new char[1024];
	cout<<"Enter a string :"<<'%'<<endl;
	cin.getline(ch,1024);
//	ch = "abc def  efg";
	cout<<"Before replace:"<<ch<<endl;
	cout<<"After replace:"<<replaceBlank(ch)<<endl;
	return 0;
}