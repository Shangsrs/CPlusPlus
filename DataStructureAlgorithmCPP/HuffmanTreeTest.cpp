#include "../header.h"

void CharFrequency(const char* ch, int length,int* &freq)
{
	for(int i=0;i<128;i++)
		freq[i] = 0;
	for(int j=0;j<length;j++)
	{
		freq[(int)ch[j]]++;
	}
	for(int i=0;i<128;i++)
		cout<<hex<<i<<": "<<freq[i]<<"\t";
	
}

int main()
{
	string str;
	cout<<"Please input some string:"<<endl;
	cin>>str;
	cout<<endl;
	int *freq = new int[128];
	CharFrequency(str.c_str(),str.length(),freq);
	return 0;
}
