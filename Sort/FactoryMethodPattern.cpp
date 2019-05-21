#include <iostream>
#include <string>

using namespace std;

class ISuperMan
{
public:
	virtual void specialTalent() = 0;
};

class AdultSuperMan : public ISuperMan
{
	void specialTalent()
	{
		cout<<"Super man has super strength"<<endl;
	};
};

class ChildSuperMan : public ISuperMan
{
	void specialTalent()
	{
		cout<<"Child Super man in invulnerabiliey"<<endl;
	};
};

class SuperManFactory
{
public:
	static ISuperMan *createSuperMan(string type)
	{
		if(type == "adult")
			return new AdultSuperMan;
		else if(type == "child")
			return new ChildSuperMan;
		else 
			return NULL;
	};
};

int main()
{
	ISuperMan *adultSuperMan = SuperManFactory::createSuperMan("child");
	adultSuperMan->specialTalent();
	return 0;
}
