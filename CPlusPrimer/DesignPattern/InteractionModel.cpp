#include "header.h"

class AbstractMediator;
class AbstractColleague
{
protected:
	AbstractMediator *_mediator;
public:
	AbstractColleague(AbstractMediator *mediator)
	{
		_mediator = mediator;
	};
};

class Purchase : public AbstractColleague
{
public:
	Purchase(AbstractMediator *mediator):AbstractColleague(mediator){};
	void buyIBMComputer(int number);
	void refuseBuyIBM();

};

class Sale : public AbstractColleague
{
public:
	Sale(AbstractMediator *mediator):AbstractColleague(mediator){};
	void sellIBMComputer(int number);
	int getSaleStatus();
	void offSale();
};

class Stock : public AbstractColleague
{
private:
	static int COMPUTER_NUMBER;
public:
	Stock(AbstractMediator* mediator):AbstractColleague(mediator){};
	void increase(int number);
	void decrease(int number);
	int getStockNumber();
	void clearStock();
};

int Stock::COMPUTER_NUMBER=100;

class AbstractMediator
{
protected:
	Purchase *purchase;
	Sale *sale;
	Stock *stock;
public:
	AbstractMediator()
	{
		purchase = new Purchase(this);
		sale = new Sale(this);
		stock = new Stock(this);
	};
	virtual void execute(string str,int argc) = 0;
};

class Mediator : public AbstractMediator
{
private:
	void buyComputer(int number)
	{
		int saleStatus = sale->getSaleStatus();
		if(saleStatus>80)
		{
			cout<<"Purchase IBM Computer number: "<<number<<endl;
			stock->increase(number);
		}
		else
		{
			int buyNumber = number/2;
			cout<<"Purchase IBM Computer number: "<<buyNumber<<endl;
			stock->increase(buyNumber);
		}
	};
	void sellComputer(int number)
	{
		if(stock->getStockNumber()<number)
		{
			purchase->buyIBMComputer(number);
		}
		stock->decrease(number);
	};
	void offSell()
	{
		cout<<"Off sell IBM Computer number:"<<stock->getStockNumber()<<endl;
	};
	void clearStock()
	{
		sale->offSale();
		purchase->refuseBuyIBM();
	};

public:
	void execute(string str,int argc)
	{
		if(str == "purchase.buy")
			buyComputer(argc);
		else if(str == "sale.sell")
			sellComputer(argc);
		else if(str == "sale.offsell")
			offSell();
		else if(str == "stock.clear")
			clearStock();
	};
};

void Purchase::buyIBMComputer(int number)
{
	_mediator->execute("purchase.buy",number);
};
void Purchase::refuseBuyIBM()
{
	cout<<"Do not purchase IBM computer"<<endl;
};


void Sale::sellIBMComputer(int number)
{
	_mediator->execute("sale.sell",number);
};
int Sale::getSaleStatus()
{
	srand(time(0));
	int saleStatus = rand()%100;
	cout<<"Sell number of IBM coumuter:"<<saleStatus<<endl;
	return saleStatus;
};
void Sale::offSale()
{
	_mediator->execute("sale.offsell",0);
};

void Stock::increase(int number)
{
	COMPUTER_NUMBER += number;
	cout<<"Computer in stock number:"<<COMPUTER_NUMBER<<endl;
};
void Stock::decrease(int number)
{
	COMPUTER_NUMBER -= number;
	cout<<"Computer in stock number:"<<COMPUTER_NUMBER<<endl;
};
int Stock::getStockNumber()
{
	return COMPUTER_NUMBER;
};
void Stock::clearStock()
{
	cout<<"Clear stock number:"<<COMPUTER_NUMBER<<endl;
	_mediator->execute("stock.clear",0);
};

int main()
{
	AbstractMediator *mediator = new Mediator;
	cout<<"--------Purchaser buy computer--------"<<endl;
	Purchase *purchase = new Purchase(mediator);
	purchase->buyIBMComputer(100);
	cout<<endl<<"--------Seller sell computer--------"<<endl;
	Sale *sale = new Sale(mediator);
	sale->sellIBMComputer(1);
	cout<<endl<<"--------Stocker clear stock--------"<<endl;
	Stock *stock = new Stock(mediator);
	stock->clearStock();
	return 0;
}
