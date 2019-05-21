#include <iostream>
#include <string>
#include <list>
using namespace std;

class Corp
{
private:
	string _name;
	string _position;
	int _salary;
public:
	Corp(string name, string position, int salary)
		:_name(name),_position(position),_salary(salary)
	{};
	string getInfo()
	{
/*
		char buffer[256];
		sprintf(buffer,"Name: %s\tJob: %s\tSalary: %d\n",_name,_position,_salary);
		return string(buffer);
*/
///*
		string info;
		info = "Name: " + _name;
		info = info + "\tJob: " + _position;
		info += "\n";
//		info = info + "\tSalary: " + to_string(_salary) + "\n";
		return info;
//*/
	};
	virtual void addSubordinate(Corp *corp) = 0;
	virtual list<Corp*>* getSubordinate() = 0;
};

class Leaf : public Corp
{
public:
	Leaf(string name, string position, int salary)
		:Corp(name,position,salary)
	{};
	void addSubordinate(Corp *corp)
	{
//		_subordinateList->push_back(corp);
	};
	list<Corp*>* getSubordinate()
	{
		return NULL;
	};
	
};

class Branch : public Corp
{
private:
	list<Corp*> * _subordinateList;
public:
	Branch(string name, string position, int salary)
		:Corp(name,position,salary)
	{
		_subordinateList = new list<Corp*>();
	};
	void addSubordinate(Corp *corp)
	{
		_subordinateList->push_back(corp);
	};
	list<Corp*>* getSubordinate()
	{
		return _subordinateList;
	};
	
};
	

void getAllSubordinateInfo(list<Corp*> *corpList)
{
	if(corpList == NULL)
		return ;
	for(list<Corp*>::iterator it = corpList->begin();it!=corpList->end();it++)
	{
		getAllSubordinateInfo((*it)->getSubordinate());
		cout<<(*it)->getInfo();
	}
	
};

int main()
{
	Branch *ceo = new Branch("Wang Damazi","Manager",100000);
	Branch *developDep = new Branch("Liu Daquezi", "Develop Manager", 10000);
	Branch *salesDep = new Branch("Ma Erguaizi","Sale Manager",20000);
	Branch *financeDep = new Branch("Zhao Santuozi", "Finance Manager",30000);

	Branch *firstDevGroup = new Branch("Yang San","Group Leader One",5000);
	Branch *secondDevGroup = new Branch("Wu Dabangcui", "Group Leader Two", 6000);

	Leaf *a = new Leaf("a","Developer",2000);
	Leaf *b = new Leaf("b","Developer",2000);
	Leaf *c = new Leaf("c","Developer",2000);
	Leaf *d = new Leaf("d","Developer",2000);
	Leaf *e = new Leaf("e","Developer",2000);
	Leaf *f = new Leaf("f","Developer",2000);
	Leaf *g = new Leaf("g","Developer",2000);
	Leaf *h = new Leaf("h","Sales Man",5000);
	Leaf *i = new Leaf("i","Sales Man",5000);
	Leaf *j = new Leaf("j","Finincer",5000);
	Leaf *k = new Leaf("k","CEO Helper",8000);

	Leaf *zhengLaoLiu = new Leaf("Zheng Laoliu","Assicant Developer Manager",20000);

	ceo->addSubordinate(developDep);
	ceo->addSubordinate(salesDep);
	ceo->addSubordinate(financeDep);

	ceo->addSubordinate(k);

	developDep->addSubordinate(firstDevGroup);
	developDep->addSubordinate(secondDevGroup);

	developDep->addSubordinate(zhengLaoLiu);
	firstDevGroup->addSubordinate(a);
	firstDevGroup->addSubordinate(b);
	firstDevGroup->addSubordinate(c);
	secondDevGroup->addSubordinate(d);
	secondDevGroup->addSubordinate(e);
	secondDevGroup->addSubordinate(f);
	secondDevGroup->addSubordinate(g);
	salesDep->addSubordinate(h);
	salesDep->addSubordinate(i);
	financeDep->addSubordinate(j);

	cout<<ceo->getInfo();

	getAllSubordinateInfo(ceo->getSubordinate());
	return 0;
};
