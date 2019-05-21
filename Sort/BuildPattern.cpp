#include <iostream>
#include <string>

using namespace std;

class SuperMan
{
private:
	string _body;
	string _specialTalent;
	string _specialSymbol;
public:
	string getBody(){return _body;};
	void setBody(string body){_body=body;};
	string getSpecialTalent(){return _specialTalent;};
	void setSpecialTalent(string specialTalent){_specialTalent=specialTalent;};
	string getSpecialSymbol(){return _specialSymbol;};
	void setSpecialSymbol(string specialSymbol){_specialSymbol=specialSymbol;};
	
};

class Builder
{
protected:
	SuperMan *_superMan;
public:
	Builder():_superMan(new SuperMan){};
	void setBody(string body){_superMan->setBody(body);};
	void setSpecialTalent(string specialTalent){_superMan->setSpecialTalent(specialTalent);};
	void setSpecialSymbol(string specialSymbol){_superMan->setSpecialSymbol(specialSymbol);};
	virtual SuperMan* getSuperMan() = 0;
};

class AdultSuperManBuilder : public Builder
{
public:
	SuperMan* getSuperMan()
	{
		Builder::setBody("Strong Body");
		Builder::setSpecialSymbol("S symbol");
		Builder::setSpecialTalent("Can Fly");
		return _superMan;
	};
};


class ChildSuperManBuilder : public Builder
{
public:
	SuperMan* getSuperMan()
	{
		Builder::setBody("Strong Body");
		Builder::setSpecialSymbol("s symbol");
		Builder::setSpecialTalent("Invulnerabiliey");
		return _superMan;
	};
};

class Director
{
private:
	static Builder *_adultBuilder;
	static Builder *_childBuilder;
public:
	static SuperMan *getAudltSuperMan(){return _adultBuilder->getSuperMan();};
	static SuperMan *getChildSuperMan(){return _childBuilder->getSuperMan();};
};
Builder* Director::_adultBuilder = new AdultSuperManBuilder;
Builder* Director::_childBuilder = new ChildSuperManBuilder;

int main()
{
	SuperMan *audltSuperMan = Director::getAudltSuperMan();
	cout<<audltSuperMan->getSpecialTalent();
	return 0;
}
