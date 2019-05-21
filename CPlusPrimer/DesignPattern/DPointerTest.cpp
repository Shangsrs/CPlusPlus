#include "header.h"

class MyClassPrivate;
class MyClass
{
public:
	MyClass();
	virtual ~MyClass();
	void printMyClass();
private:
	MyClassPrivate *const d_ptr;
	Q_DECLARE_PRIVATE(MyClass)
};

class MyClassPrivate
{
public:
	MyClassPrivate(MyClass *myClass):q_ptr(myClass){};
	void foobar()
	{
		Q_Q(MyClass);
		q->printMyClass();
	};
	virtual ~MyClassPrivate()
	{
//		delete q_ptr;
	};
	void printMyClassPrivate()
	{
		cout<<"MyClassPrivate ..."<<endl;
	};
private:
	MyClass *const q_ptr;
	Q_DECLARE_PUBLIC(MyClass);

};

MyClass::MyClass():d_ptr(new MyClassPrivate(this))
{
//	d_ptr = new MyClassPrivate(this);
}
MyClass::~MyClass()
{
	delete d_ptr;
}


void MyClass::printMyClass()
{
	cout<<"MyClass ..."<<endl;
	Q_D(MyClass);
	d->printMyClassPrivate();
}


int main()
{
	MyClass *myClass = new MyClass();
	myClass->printMyClass();
	delete myClass;
	return 0;
}

