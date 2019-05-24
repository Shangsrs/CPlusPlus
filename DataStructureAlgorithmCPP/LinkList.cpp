#include "listAlgorithm.h"

int main1()
{
	LinearList<int> *chainList = new ChainList<int>;
	int length = 20;
	cout<<"Please enter a number:";
	cin>>length;
	cout<<endl;
	for(int i=0;i<length;i++)
		chainList->insert(i,i*3);
	cout<<*chainList<<endl;
	chainList->erase(15);
	cout<<*chainList<<endl;
	return 0;
}

const int Number = 8;

struct studentRecord
{
	int _score;
	string _name;
	studentRecord():_score(0),_name(""){};
	studentRecord(int score, string name)
		:_score(score),_name(name){};
	int operator!=(const studentRecord& x) const
	{
		return _score != x._score;
	};
	operator int() const{return _score;};
};

ostream& operator<<(ostream& out, const studentRecord& x)
{
	out<<x._name<<" "<<x._score<<"\t";
	return out;
};

void binSort(ChainList<studentRecord>& chain, int range)
{
	ChainList<studentRecord> *bin;
	bin = new ChainList<studentRecord>[range+1];
	int numberOfElements = chain.size();
	for(int i=0;i<numberOfElements;i++)
	{
		studentRecord x = chain.get(0);
		cout<<i<<" "<<x._name<<" "<<x._score<<endl;
		chain.erase(0);
		bin[x._score].insert(0,x);
	}
	for(int j=range;j>=0;j--)
	{
		while(!bin[j].empty())
		{
			studentRecord x=bin[j].get(0);
			bin[j].erase(0);
			chain.insert(0,x);
		}
	}
	delete bin;
};

ChainList<studentRecord>* listCreate(int length)
{
	ChainList<studentRecord> *bin = new ChainList<studentRecord>;
//	cout<<"List Create"<<endl;
	for(int i=0;i<length;i++)
	{
		string name = getRandString(2);
		int score = randomCreate(Number);
		studentRecord *st = new studentRecord(score,name);
		bin->insert(0,*st);
	}
//	cout<<"List Create2"<<endl;
	return bin;
};

int main()
{
	int length  = 60;
	ChainList<studentRecord>* bin = listCreate(length);
	cout<<"Main"<<endl;
	binSort(*bin,Number);
	cout<<*bin;
	return 0;
	
}
