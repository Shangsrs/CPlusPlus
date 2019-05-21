#include <iostream>
#include <string>
//#include <thread>
#include <Windows.h>

using namespace std;

class IHanFeiZi
{
public:
	virtual void haveBreakfast() = 0;
	virtual void haveFun() = 0;
};


class HanfeiZi : public IHanFeiZi
{
private:
	bool _isBreakfast;
	bool _isFun;
public:
	HanfeiZi():_isBreakfast(false),_isFun(false){};
	void haveBreakfast()
	{
		cout<<"Han Feizi : Eat"<<endl;
		_isBreakfast = true;
	};
	void haveFun()
	{
		cout<<"Han Feizi : Fun"<<endl;
		_isFun = true;
	};
	bool isBreakfast()
	{
		return _isBreakfast;
	};
	bool isFun()
	{
		return _isFun;
	};
	void setBreakfast(bool bBreakfast)
	{
		_isBreakfast = bBreakfast;
	};
	void setFun(bool bFun)
	{
		_isFun = bFun;
	};
};

class ILiSi
{

public:
	virtual void update(string context) = 0;
};

class LiSi : public ILiSi
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

class Spy
{
private:
	HanfeiZi *_hanFeizi;
	LiSi *_liSi;
	string _type;
public:
	Spy(HanfeiZi *hanFeizi, LiSi *liSi, string type)
		:_hanFeizi(hanFeizi),_liSi(liSi),_type(type)
	{
	};

	void runThread()
	{
		while(true)
		{
			if(_type == "breakfast")
			{
				if(_hanFeizi->isBreakfast())
				{
					_liSi->update("Han Feizi is eating");
					_hanFeizi->setBreakfast(false);
				}
			}
			else
			{
				if(_hanFeizi->isFun())
				{
					_liSi->update("Han Feizi is having fun");
					_hanFeizi->setFun(false);
				}
			}
		};
	};
};

int main()
{
	LiSi *liSi = new LiSi();
	HanfeiZi *hanFeiZi = new HanfeiZi();
	Spy *watchBreakfast = new Spy(hanFeiZi,liSi,"breakfast");
	Spy *watchFun = new Spy(hanFeiZi,liSi,"fun");

	thread *th1 = new thread(Spy::runThread,watchBreakfast);
	thread *th2 = new thread(Spy::runThread,watchFun);
	th1->join();
	th2->join();
	
	return 0;
}

