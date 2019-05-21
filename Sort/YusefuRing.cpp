#include "header.h"

const int number = 78;
const int m = 9;

int main()
{
	int ring[number] = {0};
	int count = 0;
	for(int i=1;i<=number;i++)
	{
		for(int j=0;j<m;)
		{
			count = (count+1)%number;
			if(ring[count]==0)
				j++;
		}
		ring[count]=i;
	}
	for(int i=0;i<number;i++)
		cout<<i<<"-"<<ring[i]<<"\t";
	cout<<endl<<endl;
	for(int i=1;i<=number;i++)
	{
		for(int j=0;j<number;j++)
		{
			if(ring[j]==i)
			{
				cout<<j<<"-"<<ring[j]<<"\t";
				break;
			}
		}
	}
	return 0;	
}
