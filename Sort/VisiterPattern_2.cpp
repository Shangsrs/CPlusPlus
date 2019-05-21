#include <iostream>
#include <list>
#include <string>
using namespace std;

class CommonEmployee;
class Manager;

class IVisitor
{
public:
	virtual void visit(CommonEmployee *commonEmployee) = 0;
	virtual void visit(Manager *manager) = 0;
};

class Employee
{
private:
	string _name;
	int _salary;
	int _sex;
public:
	const static int MALE = 0;
	const static int FEMALE = 1;
	string getName(){return _name;};
	void setName(string name){_name = name;};
	int getSalary(){return _salary;};
	void setSalary(int salary){_salary = salary;};
	int getSex(){return _sex;};
	void setSex(int sex){_sex = sex;};
	virtual void accept(IVisitor *visitor);
};


class Visitor : public IVisitor
{
private:
	string getBasicInfo(Employee *employee);
	string getManagerInfo(Manager *manager);
	string getCommonEmployee(CommonEmployee *commonEmployee);
public:
	
	void visit(CommonEmployee *commonEmployee);
	void visit(Manager *manager);
	
};

class CommonEmployee : public Employee
{
private:
	string _job;
public:
	string getJob(){return _job;};
	void setJob(string job){_job = job;};
	void accept(IVisitor *visitor);
};

class Manager : public Employee
{
private:
	string _performance;
public:
	string getPerformance(){return _performance;};
	void setPerformance(string performance){_performance = performance;};
	void accept(IVisitor *visitor);
};


string Visitor::getBasicInfo(Employee *employee)
{
	char str[64];
	sprintf(str,"%d",employee->getSalary());
	string info = "Name: "+employee->getName()+"\t";
	info = info + "Sex: "+(employee->getSex()==Employee::MALE?"Male":"Female")+"\t";
	info = info + "Salary: "+str;
	return info;
};
string Visitor::getManagerInfo(Manager *manager)
{
	string info = getBasicInfo(manager);
	info = info + "\tPerformance: "+manager->getPerformance();
	return info;
};
string Visitor::getCommonEmployee(CommonEmployee *commonEmployee)
{
	string info = getBasicInfo(commonEmployee);
	info = info + "\tJob: "+commonEmployee->getJob();
	return info;
};

void Visitor::visit(CommonEmployee *commonEmployee)
{
	cout<<getCommonEmployee(commonEmployee)<<endl;
};
void Visitor::visit(Manager *manager)
{
	cout<<getManagerInfo(manager)<<endl;
};
	
void Manager::accept(IVisitor *visitor)
{
	visitor->visit(this);
};

void CommonEmployee::accept(IVisitor *visitor)
{
	visitor->visit(this);
};


int main()
{
	list<Employee*> *empList = new list<Employee*>();
	CommonEmployee *zhangSan = new CommonEmployee();
	zhangSan->setJob("Java developer");
	zhangSan->setName("Zhang San");
	zhangSan->setSalary(2800);
	zhangSan->setSex(Employee::MALE);
	empList->push_back(zhangSan);
	
	CommonEmployee *liSi = new CommonEmployee();
	liSi->setJob("Picture");
	liSi->setName("Li Si");
	liSi->setSalary(2500);
	liSi->setSex(Employee::FEMALE);
	empList->push_back(liSi);

	Manager *wangWu = new Manager();
	wangWu->setName("Wang Wu");
	wangWu->setPerformance("Common...");
	wangWu->setSalary(18500);
	wangWu->setSex(Employee::MALE);
	empList->push_back(wangWu);

	for(list<Employee*>::iterator it=empList->begin();it!=empList->end();it++)
	{
		(*it)->accept(new Visitor());
	}
	return 0;
}
