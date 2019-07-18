#include <assert.h>
#include <iostream>
#include <iomanip>
using namespace std;

int computeKind(int sum, int k, int n)
{
	int kind = 0;
	int addNumber = 0;
	int number[1000] = {0}
	for(int i = 0; i<k; i++)
	{
		for(int j = 0; j<n; j++)
			number[i] = j;
	}
	return kind;
}

int sumNumber(int n, int k)
{
	int times = (n - 1) / 2;
	int kind = 0;
	for (int i =1; i < times ; i++ )
	{
		kind += computeKind(i * n, k, n);
	}
	return kind;
}

int main(int argc, char *argv[])
{

	int n = 0;
	int k = 0;
	while(cin>>n>>k)
	{
		cout<<sumNumber(n,k)<<endl;
	}
	return 0;
}
