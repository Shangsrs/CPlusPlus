#include <iostream>
#include <time.h>

using namespace std;

class Sale
{
public:
	void sellIBMComputer(int number);
	int getSaleStatus();
	void offSale();
};

class Stock
{
private:
	static int COMPUTER_NUMBER;
public:
	void increase(int number);
	void decrease(int number);
	int getStockNumber();
	void clearStock();
};

int Stock::COMPUTER_NUMBER = 100;

class Purchase
{
public:
	void buyIBMComputer(int number)
	{
		Stock *stock = new Stock();
		Sale *sale = new Sale();
		int saleStatus = sale->getSaleStatus();
		if(saleStatus>80)
		{
			cout<<"Purchase IBM Computer number:"<<number<<endl;
			stock->increase(number);
		}
		else
		{
			int buyNumber = number/2;
			cout<<"Purchase IBM Computer number:"<<buyNumber<<endl;
		}
	};
	void refuseBuyIBM()
	{
		cout<<"Do Not Purse IBM Computer"<<endl;
	};
};



void Sale::sellIBMComputer(int number)
{
	Stock *stock = new Stock;
	Purchase *purchase = new Purchase;
	if(stock->getStockNumber()<number)
		purchase->buyIBMComputer(number);
	cout<<"Saled IBM Computer Number:"<<number<<endl;
	stock->decrease(number);
}
int Sale::getSaleStatus()
{
	srand(time(0));
	int saleStatus = rand()%100;
	cout<<"The saling status of IBM computer is:"<<saleStatus<<endl;
	return saleStatus;
}
void Sale::offSale()
{
	Stock *stock = new Stock;
	cout<<"Offsale IBM Computer Number:"<<stock->getStockNumber()<<endl;
}

void Stock::increase(int number)
{
	COMPUTER_NUMBER += number;
	cout<<"The Stock Number:"<<COMPUTER_NUMBER<<endl;
}
void Stock::decrease(int number)
{
	COMPUTER_NUMBER -= number;
	cout<<"The Stock Number:"<<COMPUTER_NUMBER<<endl;
}
int Stock::getStockNumber()
{
	return COMPUTER_NUMBER;
}
void Stock::clearStock()
{
	Purchase *purchase = new Purchase;
	Sale *sale = new Sale;
	cout<<"Clear Stock Number: "<<COMPUTER_NUMBER<<endl;
	sale->offSale();
	purchase->refuseBuyIBM();
};

class AbstractMediator
{
protected:
	Purchase *purchase;
	Sale *sale;
	Stock *stock;
public:
	AbstractMediator()
	{
		purchase = new Purchase;
		sale = new Sale;
		stock = new Stock;
	};
	void execute(string str);
};

class Mediator : public AbstractMediator
{
public:
	void execute(string str)
	{
		if(str == )
	};
};

int main()
{
	cout<<"--------Saler buy Computer--------"<<endl;
	Purchase *purchase = new Purchase;
	purchase->buyIBMComputer(100);
	cout<<endl<<"--------Saler sale Computer--------"<<endl;
	Sale *sale = new Sale;
	sale->sellIBMComputer(1);
	cout<<endl<<"--------Puchaser Clean Stock--------"<<endl;
	Stock *stock = new Stock;
	stock->clearStock();
	return 0;
}
