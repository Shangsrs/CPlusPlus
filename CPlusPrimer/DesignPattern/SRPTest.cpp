#include "header.h"

//Software entities like classes,modules and functions should 
//be open for extension but closed for modifications

class IBook
{
public:
	virtual string& getName() = 0;
	virtual int getPrice() = 0;
	virtual string& getAuthor() = 0;
};

class NovelBook : public IBook
{
	string name;
	int price;
	string author;
public:
	NovelBook(string _name, int _price, string _author)
	{
		name = _name;
		price = _price;
		author = _author;
	};
	
	string& getName()
	{
		return name;
	};
	int getPrice()
	{
		return price;
	};
	string& getAuthor()
	{
		return author;
	};
};

class OffNovelBook : public NovelBook
{
public:
	OffNovelBook(string _name, int _price, string _author)
		: NovelBook(_name,_price,_author)
	{
	};
	int getPrice()
	{
		int offPrice = NovelBook::getPrice();
		if(offPrice>4000)
			offPrice = offPrice*90/100;
		return offPrice;
	};
};

class IComputerBook : public IBook
{
public:
	string getScope();
};
	

class ComputerBook : public IComputerBook
{
		string name;
		int price;
		string author;
		string scope;
	public:
		ComputerBook(string _name, int _price, string _author, string _scope)
		{
			name = _name;
			price = _price;
			author = _author;
			scope = _scope;
		};
		
		string& getName()
		{
			return name;
		};
		int getPrice()
		{
			return price;
		};
		string& getAuthor()
		{
			return author;
		};
		string& getScope()
		{
			return scope;
		};

};

class BookStore
{
private:
	list<IBook*> *bookList;
public:
	BookStore()
	{
		bookList = new list<IBook*>();
		bookList->push_back(new NovelBook("Book One",3200,"Author One"));
		bookList->push_back(new NovelBook("Book Two",5600,"Author Two"));
		bookList->push_back(new NovelBook("Book Three",4000,"Author Three"));
		bookList->push_back(new OffNovelBook("Book Four",6214,"Author Four"));
		bookList->push_back(new OffNovelBook("Book Five",5846,"Author Five"));
		bookList->push_back(new OffNovelBook("Book Six",584876,"Author Six"));
		bookList->push_back(new ComputerBook("Book Eight",5874,"Author Eight","Java"));
	};
	list<IBook*>* getList()
	{
		return bookList;
	};
};


int main()
{
	BookStore *bs = new BookStore();
	list<IBook*>::const_iterator it=bs->getList()->begin();

	for(it=bs->getList()->begin();it!=bs->getList()->end();it++)
	{
		cout<<(*it)->getName()<<"\t";
//		cout<<setiosflags(ios::fixed)<<float((*it)->getPrice()/100.0)<<"\t";
//		cout<<setprecision(5)<<float((*it)->getPrice()/100.0)<<"\t";
//		cout<<setw(5)<<right<<float((*it)->getPrice()/100.0)<<"\t";
//		cout<<setw(5)<<left<<setfill(0)<<float((*it)->getPrice()/100.0)<<"\t";
//		cout<<showpos<<fixed<<setw(5)<<setfill('0')<<float((*it)->getPrice()/100.0)<<"\t";
		cout<<showpoint<<fixed<<setprecision(2)<<right<<float((*it)->getPrice()/100.0)<<"\t";
		cout<<(*it)->getAuthor()<<endl;
	}	
	return 0;
}

