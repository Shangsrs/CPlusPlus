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
	Women(int type,string request):_type(type),_request(request)
	{
		switch(_type)
		{
		case 1:
			_request = string("Daughter's request: ") + _request;
			break;
		case 2:
			_request = string("Wife's request: ") + _request;
			break;
		case 3:
			_request = string("Mother's request: ") + _request;
			break;
		}
	};
	int getType(){return _type;};
	string getRequest(){return _request;};
};

static const int FATHER_LEVEL_REQUEST = 1;
static const int HUSPAND_LEVEL_REQUEST = 2;
static const int SON_LEVEL_REQUEST = 3;

class IHandler
{
private:
	int _level;
	IHandler *_nextHandler;
public: 
	IHandler(int level = 0)
	{
		_level = level;
	};
	virtual void response(IWomen *women) = 0;
	void setNext(IHandler *handler)
	{
		_nextHandler = handler;
	};
	void handleMessage(IWomen *women) 
	{
		if(women->getType() == _level)
		{
			response(women);
		}
		else
		{
			if(_nextHandler != NULL)
			{
				_nextHandler->handleMessage(women);
			}
			else
			{
				cout<<"\n-----------No place to handle : Not Agree------------"<<endl;
			}
		}
	};
};

class Father : public IHandler
{
public:
	Father():IHandler(FATHER_LEVEL_REQUEST){};
	void response(IWomen * women)
	{
		cout<<"\nDaughter's requirement: "<<women->getRequest()<<endl;
		cout<<"Father's replay: agree"<<endl;
	};
};

class Husband : public IHandler
{
	public:
		Husband():IHandler(HUSPAND_LEVEL_REQUEST){};
		void response(IWomen * women)
		{
			cout<<"\nWife's requirement: "<<women->getRequest()<<endl;
			cout<<"Husband's replay: agree"<<endl;
		};
};

class Son : public IHandler
{
	public:
		Son():IHandler(SON_LEVEL_REQUEST){};
		void response(IWomen * women)
		{
			cout<<"\nMother's requirement: "<<women->getRequest()<<endl;
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
	father->setNext(husband);
	husband->setNext(son);
	for(list<IWomen*>::iterator it = arrList->begin();it != arrList->end();it++)
	{
		father->handleMessage(*it);
	}
	return 0;
}

