#include <iostream>
#include <list>
#include <string>
using namespace std;

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
	void report()
	{
		char str[64];
		sprintf(str,"%d",_salary);
		string info = "Name: "+_name+"\t";
		info = info + "Sex: "+(_sex==MALE?"Male":"Female")+"\t";
		info = info + "Salary: "+str;
		cout<<info<<endl;
	};
	virtual string getOtherInfo() = 0;
};

class CommonEmployee : public Employee
{
private:
	string _job;
public:
	string getJob(){return _job;};
	void setJob(string job){_job = job;};
	string getOtherInfo()
	{
		return "Job: "+_job+"\t";
	};
};

class Manager : public Employee
{
private:
	string _performance;
public:
	string getPerformance(){return _performance;};
	void setPerformance(string performance){_performance = performance;};
	string getOtherInfo()
	{
		return "Performance: "+_performance+"\t";
	};
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
		(*it)->report();
	}
	return 0;
}
