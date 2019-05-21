#include <iostream>
#include <string>

using namespace std;

class Product
{
public:
	virtual void beProducted() = 0;
	virtual void beSelled() = 0;
};
	
class House : public Product
{
public:
	void beProducted()
	{
		cout<<"House ..."<<endl;
	};
	void beSelled()
	{
		cout<<"Selled House ..."<<endl;
	};
};


class IPod : public Product
{
public:
	void beProducted()
	{
		cout<<"iPod ..."<<endl;
	};
	void beSelled()
	{
		cout<<"Selled iPod ..."<<endl;
	};
};

class Clothes : public Product
{
public:
	void beProducted()
	{
		cout<<"clothes ..."<<endl;
	};
	void beSelled()
	{
		cout<<"Selled Clothes ..."<<endl;
	};
};


class Corp
{
private:
	Product *_product;
public:
	Corp(Product *product):_product(product){};
	void makeMoney()
	{
		_product->beProducted();
		_product->beSelled();
	};
};

class HouseCorp : public Corp
{
public:
	HouseCorp(House *house):Corp(house){};
	void makeMoney()
	{
		Corp::makeMoney();
		cout<<"House Corp make a lot of money ..."<<endl;
	};
};

class ShanZhaiCorp : public Corp
{
public:
	ShanZhaiCorp(Product *product):Corp(product){};
	void makeMoney()
	{
		Corp::makeMoney();
		cout<<"Make a lot of money ..."<<endl;
	};
};


int main()
{
	cout<<"------Clothes Corp Run--------"<<endl;
	House *house = new House();
	HouseCorp *houseCorp = new HouseCorp(house);
	houseCorp->makeMoney();
	cout<<"------Shan Zhai Corp Run--------"<<endl;
	ShanZhaiCorp *shanZhaiCorp = new ShanZhaiCorp(new Clothes);
	shanZhaiCorp->makeMoney();
	
	return 0;
}
