#include <iostream>
#include <string>
#include <list>
using namespace std;
const string START("start");
const string STOP("stop");
const string ALARM("alarm");
const string ENGINE_BOOM("engineBoom");
class CarModel
{
private:
	list<string> *_sequence;
public:
	virtual void start() = 0;
	virtual void stop() = 0;
	virtual void alarm() = 0;
	virtual void engineBoom() = 0;
	void setSequence(list<string> *sequence)
	{ 
		_sequence = sequence;
	};
	void run()
	{
		for(list<string>::iterator it = _sequence->begin();it != _sequence->end();it++)
		{
			if(*it==START)
				start();
			else if(*it==STOP)
				stop();
			else if(*it==ALARM)
				alarm();
			else if(*it==ENGINE_BOOM)
				engineBoom();
		};
		cout<<endl;
	};
};

class HummerModel : public CarModel
{
public:
	void start()
	{
		cout<<"Hummer start"<<endl;
	};
	void stop()
	{
		cout<<"Hummer stop"<<endl;
	};
	void alarm()
	{
		cout<<"Hummer alarm"<<endl;
	};
	void engineBoom()
	{
		cout<<"Hummer engine Boom"<<endl;
	};
};

class BenzModel : public CarModel
{
public:
	void start()
	{
		cout<<"Benz start"<<endl;
	};
	void stop()
	{
		cout<<"Benz stop"<<endl;
	};
	void alarm()
	{
		cout<<"Benz alarm"<<endl;
	};
	void engineBoom()
	{
		cout<<"Benz engine Boom"<<endl;
	};
};

class CarBuilder
{
public:
	virtual void setSequence(list<string> *sequence)= 0;
	virtual CarModel* getCarModel() = 0;
};

class HummerBuilder : public CarBuilder
{
private:
	HummerModel *hummer;
public:
	HummerBuilder(){hummer=new HummerModel();};
	CarModel* getCarModel(){return hummer;};
	void setSequence(list < string > * sequence){hummer->setSequence(sequence);};
};

class BenzBuilder : public CarBuilder
{
private:
	BenzModel *benz;
public:
	BenzBuilder(){benz=new BenzModel();};
	CarModel* getCarModel(){return benz;};
	void setSequence(list < string > * sequence){benz->setSequence(sequence);};
};

class Director
{
private:
	list<string> *_sequence;
	BenzBuilder *_benzBuilder;
	HummerBuilder *_hummerBuilder;
public:
	Director()
	{
		_sequence = new list<string>();
		_benzBuilder = new BenzBuilder();
		_hummerBuilder = new HummerBuilder();
	};
	BenzModel* getBenzModel()
	{
		_sequence->clear();
		_sequence->push_back(START);
		_sequence->push_back(ALARM);
		_sequence->push_back(ENGINE_BOOM);
		_sequence->push_back(STOP);
		_benzBuilder->setSequence(_sequence);
		return (BenzModel*)_benzBuilder->getCarModel();
	};
	HummerModel* getHummerModel()
	{
		_sequence->clear();
		_sequence->push_back(START);
		_sequence->push_back(ENGINE_BOOM);
		_sequence->push_back(STOP);
		_hummerBuilder->setSequence(_sequence);
		return (HummerModel*)_hummerBuilder->getCarModel();
	};
};

int main()
{
	Director *di = new Director();
	di->getBenzModel()->run();
	di->getHummerModel()->run();
	di->getBenzModel()->run();
	di->getHummerModel()->run();
	di->getBenzModel()->run();
	di->getHummerModel()->run();
	return 0;
}
