#include <assert.h>
#include <iostream>
#include <iomanip>
using namespace std;

float computeStep(int n)
{

	return 0.0;
}

int main(int argc, char *argv[])
{

	int n = 0;
	while(cin>>n)
	{
		float step = computeStep(n);
		cout<<fixed<<setprecision(1)<<step<<endl;;
	}
	return 0;
}
