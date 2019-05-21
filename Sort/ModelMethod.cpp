#include <iostream>
using namespace std;

class HummerModel
{
public:
	virtual void start() = 0;
	virtual void stop() = 0;
	virtual void alarm() = 0;
	virtual void engineBoom() = 0;
	void run()
	{
		start();
		if(isAlarm())
		{
			alarm();
		}
		engineBoom();
		stop();
		cout<<endl;
	};
protected:
	virtual bool isAlarm() = 0;
};

class HummerH1Model : public HummerModel
{
private:
	bool alarmFlag;
public:
	HummerH1Model():alarmFlag(false){};
	void start()
	{
		cout<<"Hummer H1 start"<<endl;
	};
	void stop()
	{
		cout<<"Hummer H1 stop"<<endl;
	};
	void alarm()
	{
		cout<<"Hummer H1 alarm"<<endl;
	};
	void engineBoom()
	{
		cout<<"Hummer H1 engine Boom"<<endl;
	};
protected:
	bool isAlarm()
	{
		return alarmFlag;
	};
};

class HummerH2Model : public HummerModel
{
private:
	bool alarmFlag;
public:
	HummerH2Model():alarmFlag(true){};
	void start()
	{
		cout<<"Hummer H2 start"<<endl;
	};
	void stop()
	{
		cout<<"Hummer H2 stop"<<endl;
	};
	void alarm()
	{
		cout<<"Hummer H2 alarm"<<endl;
	};
	void engineBoom()
	{
		cout<<"Hummer H2 engine Boom"<<endl;
	};
protected:
	bool isAlarm()
	{
		return alarmFlag;
	};
};


int main()
{
	HummerH1Model *h1 = new HummerH1Model();
	h1->run();
	HummerH2Model *h2 = new HummerH2Model();
	h2->run();
}
