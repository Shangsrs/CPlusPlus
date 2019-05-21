#include "header.h"

//Dependence Inversion Principle, DIP
class ICar
{
public:
	virtual void run() = 0;
};

class IDriver
{
public:
	virtual void drive(ICar *car) = 0;
};


class Benz:public ICar
{
public:
	void run()
	{
		cout<<"Benz run ..."<<endl;
	};
};

class BMW:public ICar
{
public:
	void run()
	{
		cout<<"BMW run ..."<<endl;
	};
};
class Dirver:public IDriver
{
public:
	void drive(ICar *car)
	{
		car->run();
	};
};


int main()
{
	IDriver *zs = new Dirver();
	ICar *benz = new Benz();
	zs->drive(benz);
	ICar *bmw = new BMW();
	zs->drive(bmw);
	return 0;
}

