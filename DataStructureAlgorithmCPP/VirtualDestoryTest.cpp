#include "../header.h"


class Base
{
public:
	virtual void fun1(){cout<<"Base Virtual fun"<<endl;};
	void fun2(){cout<<"Base fun"<<endl;}
	Base()
	{
		cout<<"Base Constructor"<<endl;
		fun1();
		fun2();
	};
	virtual ~Base()
	{
		cout<<"Base Destructor"<<endl;
		fun1();
		fun2();
	};
};

class Derived : public Base
{
public:
	virtual void fun1(){cout<<"Derived Virtual fun"<<endl;};
	void fun2(){cout<<"Derived fun"<<endl;}
	Derived()
	{
		cout<<"Derived Constructor"<<endl;
		fun1();
		fun2();
	};
	~Derived()
	{
		cout<<"Derived Destructor"<<endl;
		fun1();
		fun2();
	};
};


int main()
{
	Base *pb1 = new Derived;
	auto_ptr<Base> pb(pb1);
//	std::auto_ptr<Base> pb (new Derived);
	cout<<"Test"<<endl<<endl;
	pb->fun1();
	pb->fun2();
	cout<<"Test"<<endl<<endl;
//	delete pb;
	return 0;
}


