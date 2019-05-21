#include <iostream>
#include <string>

using namespace std;

class IWomen
{
public:
	virtual void getType() = 0;
	virtual string getRequest() = 0;
};


class IHander
{
public:
	virtual void HandleMessage(IWomen *women) = 0;
};

int main()
{
	return 0;
}
