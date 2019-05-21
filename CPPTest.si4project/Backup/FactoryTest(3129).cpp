#include <iostream>
using namespace std;

class Human
{

public:
	void getColor();
	void talk();
}

class BlackHuman: public Human
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

class YelloHuman: public Human
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




