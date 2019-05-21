#include "header.h"

class IActionDispatcher
{
public:
	virtual string actionInvoke() = 0;
};

class ValueManager
{
public:
	string getViewPath();
};

class FilterDispatcher : public Filter
{
private:
	ValueStackHelper *_valueStackHelper;
	IActionDispatcher *actionDispatcher ;
public:
	vid destroy();
	void doFilter
};

