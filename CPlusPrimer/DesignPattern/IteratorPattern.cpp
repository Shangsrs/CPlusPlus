#include "header.h"

class IProject
{
public:
	virtual string getProjectInfo() = 0;
};

class Project : public IProject
{
private:
	string _name;
	int _num;
	int _cost;
	
public:
	Project(string name, int num, int cost)	
	{
		_name = name;
		_num = num;
		_cost = cost;
	};
	string getProjectInfo()
	{
		char buffer[256];
		int pos = sprintf(buffer, "Project Name: %s \nProject Number : %d\n Project Cost : %d\n\n", _name.data(),_num,_cost);
//		buffer[pos] = '\0';
		return string(buffer);
	};
};


int main()
{
	list<IProject*> *projectList = new list<IProject*>();
	projectList->push_back(new Project("Plant War",10,10000));
	projectList->push_back(new Project("Time Space Torch",20,15420));
	projectList->push_back(new Project("Super Man Make",15,45210));
	for(int i=4;i<100;i++)
	{
		char buffer[256];
		int pos = sprintf(buffer,"Project %d",i);
//		buffer[pos] = '\0';
		projectList->push_back(new Project(string(buffer),i*5,i*100));
	}
	for(list<IProject*>::iterator it = projectList->begin();it != projectList->end(); it++)
		cout<<(*it)->getProjectInfo();
	return 0;
	
}

