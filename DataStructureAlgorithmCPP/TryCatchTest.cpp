#include "../header.h"

int abc(int a,int b, float c)
{
	if(a<=0 || b<=0 || c<=0)
		throw "All parameters should be > 0";
	return a + b * c;
}

int& abc(int &a,int &b, int &c)
{

	if(a<=0 || b<=0 || c<=0)
		throw "Reference All parameters should be > 0";
	static int x = a + b * c;
	return x;
}

int main1()
{
	try{cout<<abc(2,0,4.0)<<endl;}
	catch(const char *e)
	{
		cout<<"The parameter to abc is 2,0,4"<<endl;
		cout<<"An exception has been thrown"<<endl;
		cout<<e<<endl;
		return 1;
	}
	return 0;
}

int main2()
{
	int x=2,y=4,z=4;
	try{cout<<abc(x,y,z)<<endl;}
	catch(const char *e)
	{
		cout<<"The parameter to abc is 2,0,4"<<endl;
		cout<<"An exception has been thrown"<<endl;
		cout<<e<<endl;
		return 1;
	}
	return 0;
	
}

int main()
{
	char (*c)[5];
	int n;
	cout<<"Please enter a number:"<<endl;
	cin>>n;
	cout<<endl;
	try{c = new char[n][5];}
	catch(bad_alloc)
	{
		cout<<"out of memory"<<endl;
		exit(1);
	}
	delete[] c;
	return 0;
}

