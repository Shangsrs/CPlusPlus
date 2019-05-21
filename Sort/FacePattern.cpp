#include <iostream>
#include <string>

using namespace std;

class ILetterProcess
{
public:
	virtual void writeContext(string context) = 0;
	virtual void fillEnvelope(string address) = 0;
	virtual void letterIntoEnvelope() = 0;
	virtual void sendLetter() = 0;
};

class LetterProcessImpl : public ILetterProcess
{
public:
	void writeContext(string context)
	{
		cout<<"Letter Context ..."<<context<<endl;
	};
	void fillEnvelope(string address)
	{
		cout<<"Fill Receiver address and name ..."<<address<<endl;
	};
	void letterIntoEnvelope()
	{
		cout<<"Put letter into envelop..."<<endl;
	};
	void sendLetter()
	{
		cout<<"Send letter ..."<<endl;
	};
	
};

class Police
{
public:
	void checkLetter(ILetterProcess *letterProcess)
	{
		cout<<letterProcess<<" have checked!..."<<endl;
	};
};

class ModenPostOffice
{
private:
	ILetterProcess *_letterProcess;
	Police *_letterPolice;
public:
	ModenPostOffice():_letterProcess(new LetterProcessImpl),_letterPolice(new Police){};
	void sendLetter(string context, string address)
	{
		_letterProcess->writeContext(context);
		_letterProcess->fillEnvelope(address);
		_letterPolice->checkLetter(_letterProcess);
		_letterProcess->letterIntoEnvelope();
		_letterProcess->sendLetter();
	};
};

int main()
{
	ILetterProcess *letterProcess = new LetterProcessImpl();
	letterProcess->writeContext("Hello, It's me, do you know who I am? ...");
	letterProcess->fillEnvelope("Happy Rode NO. 666, God Province, Heaven");
	letterProcess->letterIntoEnvelope();
	letterProcess->sendLetter();

	ModenPostOffice *hellRoadPostOffice = new ModenPostOffice;
	string address = "Happy Rode NO. 666, God Province, Heaven";
	string context = "Hello, It's me, do you know who I am? ...";
	hellRoadPostOffice->sendLetter(context, address);
	return 0;
}