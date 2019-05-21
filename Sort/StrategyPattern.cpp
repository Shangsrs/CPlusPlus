#include <iostream>

using namespace std;

class IStrategy
{
public:
	virtual void operate() = 0;
};

class BackDoor : public IStrategy
{
public:
	void operate()
	{
		cout<<"Ask for Qiao help"<<endl;
	};
};

class GivenGreenLight : public IStrategy
{
public:
	void operate()
	{
		cout<<"Ask green light from Wu "<<endl;
	};
};

class BlockEnemy : public IStrategy
{
public:
	void operate()
	{
		cout<<"Ask Sun for block enemy"<<endl;
	};
};

class Context
{
private:
	IStrategy *_strategy;
public:
	Context(IStrategy *strategy)
	{
		_strategy = strategy;
	};
	void operate()
	{
		_strategy->operate();
	};
};

void main()
{	
	Context *context;
	cout<<"--------Open The First --------"<<endl;
	context = new Context(new BackDoor);
	context->operate();
	cout<<"\n\n\n"<<endl;
	cout<<"--------Open The Secone --------"<<endl;
	context = new Context(new GivenGreenLight);
	context->operate();
	cout<<"\n\n\n"<<endl;
	cout<<"--------Open The Third --------"<<endl;
	context = new Context(new BlockEnemy);
	context->operate();
}

