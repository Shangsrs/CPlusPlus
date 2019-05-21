#include <iostream>
using namespace std;

class Group
{
public:
	virtual void find() = 0;
	virtual void add() = 0;
	virtual void remove() = 0;
	virtual void change() = 0;
	virtual void plan() = 0;
	
};

class CodeGroup : public Group
{
public:
	void find()
	{
		cout<<"Find Code Group"<<endl;
	};
	void add() 
	{
		cout<<"Client command add a function"<<endl;
	};
	void remove()
	{
		cout<<"Client command remove a function"<<endl;
	};
	void change() 
	{
		cout<<"Client command change a function"<<endl;
	};
	void plan()
	{
		cout<<"Client command change the function plan"<<endl;
	};
};

class PageGroup : public Group
{
public:
	void find()
	{
		cout<<"Find Page Group"<<endl;
	};
	void add() 
	{
		cout<<"Client command add a page"<<endl;
	};
	void remove()
	{
		cout<<"Client command remove a page"<<endl;
	};
	void change() 
	{
		cout<<"Client command change a page"<<endl;
	};
	void plan()
	{
		cout<<"Client command change the page plan"<<endl;
	};
};

class RequirementGroup : public Group
{
public:
	void find()
	{
		cout<<"Find Requirement Group"<<endl;
	};
	void add() 
	{
		cout<<"Client command add a requirement"<<endl;
	};
	void remove()
	{
		cout<<"Client command remove a requirement"<<endl;
	};
	void change() 
	{
		cout<<"Client command change a requirement"<<endl;
	};
	void plan()
	{
		cout<<"Client command change the plan"<<endl;
	};
};

class Command
{
protected:
	RequirementGroup *_rg;
	PageGroup *_pg;
	CodeGroup *_cd;
public:
	Command()
	{
		_rg = new RequirementGroup();
		_pg = new PageGroup();
		_cd = new CodeGroup();
	};
	virtual void execute() = 0;
};

class DeletePageCommand : public Command
{
public:
	void execute()
	{
		_pg->find();
		_pg->remove();
		_pg->plan();
	};
};

class AddRequirementCommand : public Command
{
public:
	void execute()
	{
		_rg->find();
		_rg->add();
		_rg->plan();
	};
};

class Invoker
{
private:
	Command * _command;
public:
	void setCommand(Command *command){_command = command;};
	void Action(){_command->execute();};
};

int main()
{
	cout<<"--------Client add a requirement--------"<<endl;
	Group *rg = new RequirementGroup();
	rg->find();
	rg->add();
	rg->plan();


	Invoker *xs = new Invoker();
	cout<<endl<<"--------Clent add a requirement--------"<<endl;
	Command *command = new AddRequirementCommand();
	xs->setCommand(command);
	xs->Action();
	delete command;
	cout<<endl<<"--------Clent remove a requirement--------"<<endl;
	command = new DeletePageCommand();
	xs->setCommand(command);
	xs->Action();
	return 0;
}
