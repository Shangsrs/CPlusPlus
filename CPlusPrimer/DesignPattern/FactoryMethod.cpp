#include "header.h"


class Human
{
public:
	virtual void getColor() = 0;
	virtual void talk() = 0;
};


class AbstractHumanFactory
{
public:
	virtual Human* createHuman(string human) = 0;
};

class BlackHuman : public Human
{
public:
	void getColor()
	{
		cout<<"Black skin!"<<endl;
	};
	void talk()
	{
		cout<<"Black speak!"<<endl;
	};
	
};

class YellowHuman : public Human
{
public:
	void getColor()
	{
		cout<<"Yellow skin!"<<endl;
	};
	void talk()
	{
		cout<<"Yellow speak!"<<endl;
	};
	
};

class WhiteHuman : public Human
{
public:
	void getColor()
	{
		cout<<"White skin!"<<endl;
	};
	void talk()
	{
		cout<<"White speak!"<<endl;
	};
	
};

class HumanFactory : public AbstractHumanFactory
{
public:
	Human* createHuman(string human)
	{
		if(human == "BlackHuman")
			return new BlackHuman();
		else if(human == "YellowHuman")
			return new YellowHuman();
		else if(human == "WhiteHuman")
			return new WhiteHuman();
		else
			return NULL;
	};

};

class ProductFactory
{
private:
	static map<string,Human*> *pMap;
public:
	Human *createHuman(string human)
	{
		map<string,Human*>::iterator it = pMap->find(human);
		if(it != pMap->end())
			return (*pMap)[human];
		else
		{
			Human* _human;
			if(human == "BlackHuman")
				_human = new BlackHuman();
			else if(human == "YellowHuman")
				_human = new YellowHuman();
			else if(human == "WhiteHuman")
				_human = new WhiteHuman();
			else
				return NULL;
			(*pMap)[human] = _human;
			return _human;
		}
	};
};

map<string,Human*> *ProductFactory::pMap = new map<string,Human*>();

int main()
{
	AbstractHumanFactory *lu = new HumanFactory();
	Human *human = lu->createHuman("WhiteHuman");
	human->getColor();
	human->talk();
	cout<<human<<endl;
	delete human;
	human = lu->createHuman("YellowHuman");
	human->getColor();
	human->talk();
	cout<<human<<endl;
	delete human;
	human = lu->createHuman("BlackHuman");
	human->getColor();
	human->talk();
	cout<<human<<endl;
	delete human;
	cout<<endl;
	ProductFactory *pf = new ProductFactory();
	human = pf->createHuman("YellowHuman");
	human->getColor();
	human->talk();
	cout<<human<<endl;
	human = pf->createHuman("BlackHuman");
	human->getColor();
	human->talk();
	cout<<human<<endl;
	human = pf->createHuman("WhiteHuman");
	human->getColor();
	human->talk();
	cout<<human<<endl;
	human = pf->createHuman("WhiteHuman");
	human->getColor();
	human->talk();
	cout<<human<<endl;
	human = pf->createHuman("WhiteHuman");
	human->getColor();
	human->talk();
	cout<<human<<endl;
	human = pf->createHuman("YellowHuman");
	human->getColor();
	human->talk();
	cout<<human<<endl;
	return 0;
}

