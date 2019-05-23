#include "../header.h"


int abc(int a,int b, int c)
{
	if(a<=0 || b<=0 || c<=0)
		throw illegalParameterValue("All parameters should be > 0");
	return a + b * c;
}

int main()
{
	try{cout<<abc(2,0,4)<<endl;}
	catch(illegalParameterValue e)
	{
		cout<<"The parameter to abc is 2,0 and 4"<<endl;
		cout<<"illegalParameterValue exception thrown"<<endl;
		e.outputMessage();
		return 1;
	}
	return 0;
}
