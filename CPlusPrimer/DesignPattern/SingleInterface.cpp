#include "header.h"

class IPettyGirl
{
public:
	virtual void goodLooking() = 0;
	virtual void niceFigure() = 0;
	virtual void greatTemperament() = 0;
}

class AbstractSearcher
{
public:
	AbstractSearcher(IPettyGirl _pettyGirl);
	virtual void show()=0;
}


