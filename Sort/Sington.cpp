#include <iostream>
#include <list>
#include <string>
#include <vector>
#include <time.h>
using namespace std;

class Emperor
{
private:
	Emperor(){};
	static Emperor *emperor;
public:
	static Emperor* getInstance()
	{
		if( emperor==NULL)
			emperor = new Emperor();
		return emperor;
	};
	void say()
	{
		std::cout<<"I am Emperor "<<emperor<<endl;
	};
};

class MultiEmperor
{
private:
	static int number;
	static int count;
//	static list<string> name;
	static vector<MultiEmperor*> emp;
	MultiEmperor(){};
public:
	static MultiEmperor* getInstance()
	{
		vector<MultiEmperor*>::iterator it;
		it=emp.begin();
		if(emp.empty())
		{
			for(int i=0;i<number;i++)
			{
				emp.push_back(new MultiEmperor());
			}
		}
		srand(time(0)+count*10);
		count = rand()%number;
		std::cout<<count<<" \t";
		return emp.at(count);
	};
	void say()
	{
		std::cout<<"I am Emperor "<<emp.at(count)<<endl;
	}
	
};
	
int MultiEmperor::number = 5;
int MultiEmperor::count = 0;
vector<MultiEmperor*> MultiEmperor::emp = vector<MultiEmperor*>();


Emperor* Emperor::emperor = NULL;
int main()
{
	for(int day=0; day<9; day++)
	{
		Emperor *emp = Emperor::getInstance();
//		Emperor *emp2 = new Emperor();
		emp->say();
	}
	for(int day=0; day<9; day++)
	{
		MultiEmperor *emp = MultiEmperor::getInstance();
		emp->say();
	}
	return 0;
}

