#include <assert.h>
#include <iostream>
#include <string.h>
using namespace std;

int computeUglyLength(char* ch, int len)
{
	int argNumber = 0;
	for(int i=1;i<len;i++)
	{
		if(ch[i-1] == ch[i])
			argNumber++;
	}
	return argNumber;
}

int minUglyLength(char* ch,int len)
{
	if (len <= 1)
	{
		return 0;
	}
	assert(ch!=NULL);
	char* temp = ch;
	int markNumber = 0;
	int markPos[50] = {0};
	int j = 0;
	for(int i=0;i<len;i++)
	{
		if(temp[i] == '?')
		{
			markPos[j] = i;
			markNumber++;
		}
	}
	int count = computeUglyLength(ch,len);
	for (int t=0; t<markNumber ;t++ )
	{
		if(markPos[t]+1 < len && markPos[t] >0)
		{
			if(ch[markPos[t] - 1] != ch[markPos[t] +1])
			{
				count ++;
			}
		}
	}
	return count;
}

int main(int argc, char *argv[])
{    
    char* str = new char[50];
    while(cin>>str)
	{
		int len = strlen(str);
		cout<<minUglyLength(str, len);
	}
	return 0;
}
