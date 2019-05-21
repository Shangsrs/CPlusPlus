#include <iostream>
#include <string>

using namespace std;

class Corp
{
protected:
	virtual void produce() = 0;
	virtual void sell() = 0;
public:
	void makeMoney()
	{
		produce();
		sell();
	};
};
	
class HouseCorp : public Corp
{

protected:
	void produce()
	{
		cout<<"Make House ..."<<endl;
	};
	void sell()
	{
		cout<<"Sell House ..."<<endl;
	};
public:
	void makeMoney()
	{
		Corp::makeMoney();
		cout<<"House Corp Make a lot of money..."<<endl;
	};
};

class ClothesCorp : public Corp
{

protected:
	void produce()
	{
		cout<<"Make Clothes ..."<<endl;
	};
	void sell()
	{
		cout<<"Sell Clothes  ..."<<endl;
	};
public:
	void makeMoney()
	{
		Corp::makeMoney();
		cout<<"CLothes Corp Make a lot of money..."<<endl;
	};
};



int main()
{
	cout<<"------Clothes Corp Run--------"<<endl;
	HouseCorp *houseCorp = new HouseCorp();
	houseCorp->makeMoney();
	cout<<"------House Corp Run--------"<<endl;
	ClothesCorp *clothesCorp = new ClothesCorp();
	clothesCorp->makeMoney();
	
	return 0;
}
