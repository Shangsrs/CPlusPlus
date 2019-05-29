#include "../header.h"


void towersOfHanoi(int n,string x,string y,string z)
{
	if(n>0)
	{
		towersOfHanoi(n-1,x,z,y);
		cout<<"Move top disk form tower "<<x
			<<" to top of tower "<<y;
		cout<<" disk number "<<z<<" :"<<n-1<<endl;
		towersOfHanoi(n-1,z,y,x);
	}
}


int main()
{
	int diskNumber = 3;
	towersOfHanoi(diskNumber,"x","y","z");
	return 0;
}


