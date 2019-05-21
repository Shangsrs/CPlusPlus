#include "header.h"

class Context;
class OpenningState;
class ClosingState;
class RunningState;
class StoppingState;

class LiftState
{
protected:
	Context *_context;
public:
	void setContext(Context *context){_context=context;};
	virtual void open() = 0;
	virtual void close() = 0;
	virtual void run() = 0;
	virtual void stop() = 0;
};

class Context
{
private:
	LiftState *_liftState;
public:
	static OpenningState *openningState;
	static ClosingState *closingState;
	static RunningState *runningState;
	static StoppingState *stoppingState;
	void setLiftState(LiftState* liftState)
	{
		_liftState = liftState;
	};
	LiftState* getLiftState(){return _liftState;};
	void open(){_liftState->open();};
	void close(){_liftState->close();};
	void stop(){_liftState->stop();};
	void run(){_liftState->run();};
	
};

class OpenningState : public LiftState
{
public:
	void open()
	{
		cout<<"Lift door open..."<<endl;
	};
	void close();
	void run()
	{
	};
	void stop()
	{
	};
};
class ClosingState : public LiftState
{
public:
	void open()
	{
		_context->setLiftState(Context::openningState);
		_context->getLiftState()->close();
	};
	void close()
	{
		cout<<"Lift door close..."<<endl;
	};
	void run();
	void stop();
};



class RunningState : public LiftState
{
public:
	void open()
	{
	};
	void close()
	{
	};
	void run()
	{
		cout<<"Lift run..."<<endl;
	};
	void stop();
};


class StoppingState : public LiftState
{
public:
	void open()
	{
		_context->setLiftState(Context::openningState);
		_context->getLiftState()->open();
	};
	void close()
	{
	};
	void run()
	{
		_context->setLiftState(Context::runningState);
		_context->getLiftState()->run();
	};
	void stop()
	{
		cout<<"Lift stop..."<<endl;
	};
};

OpenningState* Context::openningState = new OpenningState();
ClosingState* Context::closingState = new ClosingState();
RunningState* Context::runningState = new RunningState();
StoppingState* Context::stoppingState = new StoppingState();


void OpenningState::close()
{
	_context->setLiftState(Context::closingState);
	_context->getLiftState()->close();
};

void ClosingState::run()
{
	_context->setLiftState(Context::runningState);
	_context->getLiftState()->run();
};
void ClosingState::stop()
{
	_context->setLiftState(Context::stoppingState);
	_context->getLiftState()->stop();
};
void RunningState::stop()
{
	_context->setLiftState(Context::stoppingState);
	_context->getLiftState()->stop();
};




int main()
{
	Context *context = new Context();
	context->setLiftState(new ClosingState);
	context->open();
	cout<<"1"<<endl;
	context->close();
	cout<<"2"<<endl;
	context->run();
	cout<<"3"<<endl;
	context->stop();
	cout<<"4"<<endl;
	return 0;
}

