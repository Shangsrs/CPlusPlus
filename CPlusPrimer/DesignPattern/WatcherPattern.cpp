#include "header.h"

using namespace std;

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
	ILiSi *_liSi;
public:
	HanfeiZi():_isBreakfast(false),_isFun(false)
	{
		_liSi = new LiSi();
	};
	void haveBreakfast()
	{
		cout<<"Han Feizi : Eat"<<endl;
		_liSi->update("Han is eating");
		_isBreakfast = true;
	};
	void haveFun()
	{
		cout<<"Han Feizi : Fun"<<endl;
		_liSi->update("Han is having fun");
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



int main()
{
	HanfeiZi *hanFeiZi = new HanfeiZi();
	hanFeiZi->haveBreakfast();
	hanFeiZi->haveFun();
	
	return 0;
}


