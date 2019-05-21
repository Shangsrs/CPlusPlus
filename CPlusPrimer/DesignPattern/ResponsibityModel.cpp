#include "header.h"

class IWomen
{
public:
	virtual int getType() = 0;
	virtual string getRequest() = 0;
};

class Women : public IWomen
{
private:
	int _type;
	string _request;
public:
	Women(int type,string request):_type(type),_request(request){};
	int getType(){return _type;};
	string getRequest(){return _request;};
};

class IHandler
{
public: 
	virtual void HandleMessage(IWomen *women) = 0;
};

class Father : public IHandler
{
public:
	void HandleMessage(IWomen * women)
	{
		cout<<"Daughter's requirement: "<<women->getRequest()<<endl;
		cout<<"Father's replay: agree"<<endl;
	};
};

class Husband : public IHandler
{
	public:
		void HandleMessage(IWomen * women)
		{
			cout<<"Wife's requirement: "<<women->getRequest()<<endl;
			cout<<"Husband's replay: agree"<<endl;
		};
};

class Son : public IHandler
{
	public:
		void HandleMessage(IWomen * women)
		{
			cout<<"Mother's requirement: "<<women->getRequest()<<endl;
			cout<<"Son's replay: agree"<<endl;
		};
};

int main()
{
	srand(time(0));
	list<IWomen*> *arrList = new list<IWomen*>();
	for(int i=0;i<5;i++)
	{
		arrList->push_back(new Women(rand()%4,"I want to go shopping"));
	}
	IHandler *father = new Father();
	IHandler *husband = new Husband();
	IHandler *son = new Son();
	for(list<IWomen*>::iterator it = arrList->begin();it != arrList->end();it++)
	{
		if((*it)->getType() == 1)
		{
			cout<<"\n--------Daughter and Father--------"<<endl;
			father->HandleMessage(*it);
		}
		else if((*it)->getType() == 2)
		{
			cout<<"\n--------Wife and Husband--------"<<endl;
			husband->HandleMessage(*it);
		}
		else if((*it)->getType() == 3)
		{
			cout<<"\n--------Mother and Son--------"<<endl;
			son->HandleMessage(*it);
		}
	}
	return 0;
}

