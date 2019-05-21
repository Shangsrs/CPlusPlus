#include "header.h"

const string start("start");
const string stop("stop");
const string alarm("alarm");
const string engineBoom("engineBoom");

class CarModel
{
	list<string> *sequence;
public:
	virtual void start() = 0;
	virtual void stop() = 0;
	virtual void alarm() = 0;
	virtual void engineBoom() = 0;
	void run()
	{
		for(list<string>::iterator it = sequence->begin();it!=sequence->end();++it)
		{
			if(*it == "start")
				start();
			else if(*it == "stop")
				stop();
			else if(*it == "alarm")
				alarm();
			else if(*it == "engineBoom")
				engineBoom();
		}
	};
	void setSequence(list<string> *_sequence)
	{
		sequence = _sequence;
	};
};

class CarBuilder
{
public:
	virtual void setSequence(list<string> *sequence) = 0;
	virtual CarModel* getCarModel() = 0;
};

class BenzModel :public CarModel
{
public:
	void start()
	{
		cout<<"Benz start ..."<<endl;
	};
	void stop()
	{
		cout<<"Benz stop ..."<<endl;
	};
	void alarm()
	{
		cout<<"Benz alarm ..."<<endl;
	};
	void engineBoom()
	{
		cout<<"Benz engine boom ..."<<endl;
	};
};


class BWMModel :public CarModel
{
public:
	void start()
	{
		cout<<"BWM start ..."<<endl;
	};
	void stop()
	{
		cout<<"BWM stop ..."<<endl;
	};
	void alarm()
	{
		cout<<"BWM alarm ..."<<endl;
	};
	void engineBoom()
	{
		cout<<"BWM engine boom ..."<<endl;
	};
};



class BenzBuilder : public CarBuilder
{
private:
	BenzModel *benz;
public:
	BenzBuilder(){benz = new BenzModel();};
	CarModel* getCarModel()
	{
		return benz;
	};
	void setSequence(list<string> *sequence)
	{
		benz->setSequence(sequence);
	};
};

class BWMBuilder : public CarBuilder
{
private:
	BWMModel *bwm;
public:
	BWMBuilder(){bwm = new BWMModel();};
	CarModel* getCarModel()
	{
		return bwm;
	};
	void setSequence(list<string> *sequence)
	{
		bwm->setSequence(sequence);
	};
};


int main()
{
	list<string> *sequence = new list<string>();
	sequence->push_back(start);
	sequence->push_back(alarm);
	sequence->push_back(engineBoom);
	sequence->push_back(alarm);
	sequence->push_back(engineBoom);
	sequence->push_back(stop);
	BenzBuilder *benzBuilder = new BenzBuilder();
	benzBuilder->setSequence(sequence);
	BenzModel *benz = (BenzModel*)benzBuilder->getCarModel();
	benz->run();
	BWMBuilder *bwmBuilder = new BWMBuilder();
	bwmBuilder->setSequence(sequence);
	BWMModel *bwm = (BWMModel*)bwmBuilder->getCarModel();
	bwm->run();
	return 0;
}

int main1()
{
	BenzModel *benz = new BenzModel();
	list<string> *sequence = new list<string>();
	sequence->push_back(start);
	sequence->push_back(alarm);
	sequence->push_back(engineBoom);
	sequence->push_back(alarm);
	sequence->push_back(engineBoom);
	sequence->push_back(alarm);
	sequence->push_back(engineBoom);
	sequence->push_back(alarm);
	sequence->push_back(engineBoom);
	sequence->push_back(stop);
	benz->setSequence(sequence);
	benz->run();
	return 0;
}

