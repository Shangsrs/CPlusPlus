#include "header.h"

using namespace std;


class Observer
{
public:
	virtual void update(string context) = 0;
};

class Observable
{
public:
	virtual void addObserver(Observer *observer) = 0;
	virtual void deleteObserver(Observer *observer) = 0;
	virtual void notifyObservers(string context) = 0;
};

class IHanFeiZi
{
public:
	virtual void haveBreakfast() = 0;
	virtual void haveFun() = 0;
};

class HanfeiZi : public Observable, IHanFeiZi
{
private:
	list<Observer*> *observerList;
public:
	HanfeiZi()
	{
		observerList = new list<Observer*>();
	};
	void addObserver(Observer *observer)
	{
		observerList->push_back(observer);
	};
	void deleteObserver(Observer *observer)
	{
		observerList->remove(observer);
	};
	void notifyObservers(string context)
	{
		for(list<Observer*>::iterator it = observerList->begin();it!=observerList->end();it++)
		{
			(*it)->update(context);
		}
	};
	void haveBreakfast()
	{
		cout<<"Han Feizi : Eat"<<endl;
		notifyObservers("Han is eating");
	};
	void haveFun()
	{
		cout<<"Han Feizi : Fun"<<endl;
		notifyObservers("Han is having fun");
	};
};


class LiSi : public Observer
{
public:
	void reportToQinShiHuang(string reportContext)
	{
		cout<<"Li Si : Qin, Han is activity --->"<<reportContext<<endl;
	};
	void update(string context)
	{
		cout<<"Li Si : Watch Han Feizi activity, and report..."<<endl;
		reportToQinShiHuang(context);
		cout<<"Li Si : Report end...\n"<<endl;
	};
};


class WangSi : public Observer
{
public:
	void cry(string reportContext)
	{
		cout<<"Wang Si : Because "<<reportContext<<" so I said"<<endl;
	};
	void update(string context)
	{
		cout<<"Wang Si : Watch Han Feizi activity, and report..."<<endl;
		cry(context);
		cout<<"Wang Si : Report end...\n"<<endl;
	};
};

class LiuSi : public Observer
{
public:
	void happy(string reportContext)
	{
		cout<<"Liu Si : Because"<<reportContext<<", so I happy"<<endl;
	};
	void update(string context)
	{
		cout<<"Liu Si : Watch Han Feizi activity, and report..."<<endl;
		happy(context);
		cout<<"Liu Si : Report end...\n"<<endl;
	};
};


int main()
{
	Observer *liSi = new LiSi();
	Observer *wangSi = new WangSi();
	Observer *liuSi = new LiuSi();
	HanfeiZi *hanFeiZi = new HanfeiZi();

	hanFeiZi->addObserver(liSi);
	hanFeiZi->addObserver(wangSi);
	hanFeiZi->addObserver(liuSi);
	
	hanFeiZi->haveBreakfast();
	hanFeiZi->haveFun();
	hanFeiZi->deleteObserver(liuSi);
	hanFeiZi->haveBreakfast();
	hanFeiZi->haveFun();
	
	return 0;
}


