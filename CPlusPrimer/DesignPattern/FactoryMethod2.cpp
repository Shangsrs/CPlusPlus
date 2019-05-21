#include "header.h"


class Human
{
public:
	virtual void getColor() = 0;
	virtual void talk() = 0;
	virtual void getSex() = 0;
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
class FemaleBlackHuman : public BlackHuman
{
public:
	void getSex()
	{
		cout<<"Black Female Human"<<endl;
	};
};

class MaleBlackHuman : public BlackHuman
{
public:
	void getSex()
	{
		cout<<"Black Male Human"<<endl;
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

class FemaleYelloHuman : public YellowHuman
{
public:
	void getSex()
	{
		cout<<"Yello Female Human"<<endl;
	};
};

class MaleYelloHuman : public YellowHuman
{
public:
	void getSex()
	{
		cout<<"Yello Male Human"<<endl;
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

class FemaleWhiteHuman : public WhiteHuman
{
public:
	void getSex()
	{
		cout<<"White Female Human"<<endl;
	};
};

class MaleWhiteHuman : public WhiteHuman
{
public:
	void getSex()
	{
		cout<<"White Male Human"<<endl;
	};
};


class FemaleHumanFactory : public AbstractHumanFactory
{
public:
	Human* createHuman(string human)
	{
		if(human == "BlackHuman")
			return new FemaleBlackHuman();
		else if(human == "YellowHuman")
			return new FemaleYelloHuman();
		else if(human == "WhiteHuman")
			return new FemaleWhiteHuman();
		else
			return NULL;
	};

};

class MaleHumanFactory : public AbstractHumanFactory
{
public:
	Human* createHuman(string human)
	{
		if(human == "BlackHuman")
			return new MaleBlackHuman();
		else if(human == "YellowHuman")
			return new MaleYelloHuman();
		else if(human == "WhiteHuman")
			return new MaleWhiteHuman();
		else
			return NULL;
	};

};


int main()
{
	AbstractHumanFactory *flu = new FemaleHumanFactory();
	Human *fhuman = flu->createHuman("WhiteHuman");
	fhuman->getColor();
	fhuman->talk();
	fhuman->getSex();
	cout<<fhuman<<endl<<endl;
	delete fhuman;
	fhuman = flu->createHuman("YellowHuman");
	fhuman->getColor();
	fhuman->talk();
	fhuman->getSex();
	cout<<fhuman<<endl<<endl;
	delete fhuman;
	fhuman = flu->createHuman("BlackHuman");
	fhuman->getColor();
	fhuman->talk();
	fhuman->getSex();
	cout<<fhuman<<endl<<endl;
	delete fhuman;
	cout<<endl;
	
	AbstractHumanFactory *mlu = new MaleHumanFactory();
	Human *mhuman = mlu->createHuman("WhiteHuman");
	mhuman->getColor();
	mhuman->talk();
	mhuman->getSex();
	cout<<mhuman<<endl<<endl;
	delete mhuman;
	mhuman = mlu->createHuman("YellowHuman");
	mhuman->getColor();
	mhuman->talk();
	mhuman->getSex();
	cout<<mhuman<<endl<<endl;
	delete mhuman;
	mhuman = mlu->createHuman("BlackHuman");
	mhuman->getColor();
	mhuman->talk();
	mhuman->getSex();
	cout<<mhuman<<endl;
	delete mhuman;
	cout<<endl;
	return 0;
}

