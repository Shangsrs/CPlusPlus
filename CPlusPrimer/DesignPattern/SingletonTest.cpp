#include "header.h"

class Emperor
{
private:
	Emperor(){};
	static Emperor *emperor;
public:
	static Emperor* getInstance()
	{
		if(emperor==NULL)
			emperor = new Emperor();
		return emperor;
	};
	
	void say()
	{
		cout<<"I am emperor "<<emperor<<endl;
	};
};

Emperor* Emperor::emperor = NULL;

class EmperorTwo
{
private:
	EmperorTwo(){};
	static EmperorTwo *emperor;
public:
	static EmperorTwo* getInstance()
	{
		if(emperor==NULL)
			emperor = new Emperor();
		return emperor;
	};
	
	void say()
	{
		cout<<"I am emperor "<<emperor<<endl;
	};
};

EmperorTwo* EmperorTwo::emperor = new EmperorTwo();

class MultiEmperor
{
private:
	MultiEmperor(){};
	static vector<MultiEmperor*> *emperorVector;
	static int count;
public:
	static MultiEmperor* getInstance()
	{
		if(emperorVector==NULL)
		{
			emperorVector = new vector<MultiEmperor*>();
			for(int i=0;i<5;i++)
			{
				emperorVector->push_back(new MultiEmperor());
			}
		}
		srand(time(NULL)+count*3);
		count = rand()%5;
		return (*emperorVector)[count];
	};
	void say()
	{
		cout<<"I am emperor "<<(*emperorVector)[count]<<endl;
	};
};

vector<MultiEmperor*> *MultiEmperor::emperorVector = NULL;
int MultiEmperor::count = 0;
int main()
{
	for(int day=0; day<4; day++)
	{
		Emperor *emp = Emperor::getInstance();
		emp->say();
	}
	cout<<endl;
	for(day=0; day<8; day++)
	{
		MultiEmperor *multiEmp = MultiEmperor::getInstance();
		multiEmp->say();
	}
	cout<<endl;
	for(day=0; day<4; day++)
	{
		EmperorTwo *empt = EmperorTwo::getInstance();
		empt->say();
	}
	return 0;
}

