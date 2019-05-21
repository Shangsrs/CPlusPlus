#include <iostream>
#include <string>

using namespace std;

class Memento
{
private:
	string _state;
public:
	Memento(string state){_state = state;};
	string getState(){return _state;};
	void setState(string state){_state=state;};
};

class Boy
{
private:
	string _state;
public:
	void changeState(){_state = "Emotion is bad";};
	string getState(){return _state;};
	void setState(string state){_state = state;};
	Memento* createMemento(){return new Memento(_state);};
	void restoreMemento(Memento *memento){setState(memento->getState());};
};

class Caretaker
{
private:
	Memento *_memento;
public:
	Memento* getMemento(){return _memento;};
	void setMemento(Memento* memento){_memento=memento;};
};

int main()
{
	Boy *boy = new Boy();
	Caretaker *caretaker = new Caretaker;
	
	boy->setState("Emotion is nice!");
	cout<<"---------Boy's State now---------"<<endl;
	cout<<boy->getState()<<endl;

	caretaker->setMemento(boy->createMemento())	;
	
	boy->changeState();
	cout<<"---------Boy's State After the girl---------"<<endl;
	cout<<boy->getState()<<endl;

	boy->restoreMemento(caretaker->getMemento());
	cout<<"---------Boy's State After refill---------"<<endl;
	cout<<boy->getState()<<endl;
	
	return 0;
}
