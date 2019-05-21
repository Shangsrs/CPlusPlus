#include <iostream>
using namespace std;

class Human
{

public:
	virtual void getColor() = 0;
	virtual void talk() = 0;
}

class BlackHuman : public Human
{
public:
	void getColor()
	{
		std::cout<<"Black skin"<<endl;
	}
	void talk()
	{
		std::cout<<"Black human talk";
	}
}

class YelloHuman : public Human
{
public:
	void getColor()
	{
		std::cout<<"Yello skin"<<endl;
	}
	void talk()
	{
		std::cout<<"Yello human talk";
	}
}

class WhiteHuman: public Human
{
public:
	void getColor()
	{
		std::cout<<"White skin"<<endl;
	}
	void talk()
	{
		std::cout<<"White human talk";
	}
}

class AbstractHumanFactory
{
public:
	virtual Human createHuman(Human man) = 0;
}

class HumanFactory : public AbstractHumanFactory
{
public:
	Human createHuman(Human man)
	{
		Human human = NULL;
		try
		{
			human = 
		}
	}
}

