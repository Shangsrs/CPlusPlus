#include "header.h"

int PRICE[]={1,5,8,9,10,17,17,20,24,30};

int max(int a,int b)
{
	return a>b?a:b;
}

int cutRod( int n)
{
	if(n==0)
		return 0;
	int q = 0;
	for(int i=1;i<=n;i++)
	{
		q=max(q,PRICE[(i-1)%10]+cutRod(n-i));
		cout<<q<<endl;
	}
	return q;
}

int memoizedCutRodAux(int n,int r[])
{
	if(n-1>=0 && r[n-1]>=0)
		return r[n-1];
	int q;
	if(n==0)
		q = 0;
	else
		q = -1;
	for(int i=1;i<=n;i++)
	{
		q=max(q,PRICE[(i-1)%10]+memoizedCutRodAux(n-i,r));
	}
	r[n-1]=q;
	return q;
}

int memoizedCutRod(int n)
{
	n = 64;
	int r[64];
	for(int i=0;i<n;i++)
		r[i]=0;
	return memoizedCutRodAux(n,r);
}

int bottomUpCutRod(int n)
{
	int r[64] = {0};
	
	int q = 0;
	for(int j=0;j<n;j++)
	{
		q = -99;
		for(int i=1;i<=j;i++)
			q=max(q,p[i]+r[j-i]);
		r[j]=q;
	}
	return r[n];
}

int extendedBottomUpCutRod(int n)
{
	int r[64]={0};
	int s[64] = {0};
	int q;
	for(int j=1;j<=n;j++)
	{
		q=-99;
		for(int j=1;i<=j;i++)
		{
			if(q<p[i]+r{j-i])
			{
				q = p[i] + r[j-i];
				s[j] = i;
			}
			
		}
		r[j]=q;
	}
	return r;
}

void printCutRodSolution(int n)
{
	int r[] = extendedBottomUpCutRod(n);
	while(n>0)
	{
		cout<<s[n]<<"\t";
		n = n-s[n];
	}
}

int main()
{	
	cout<<"Input length:"<<endl;
	int length;
	cin>>length;
	cout<<cutRod(length);
	cout<<memoizedCutRod(length);
	return 0;
}


