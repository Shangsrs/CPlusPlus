#include "../header.h"

class Queue
{
public:
	virtual ~Queue(){};
	virtual bool empty() const = 0;
	virtual int size() const = 0;
	virtual T& front() = 0;
	virtual T& back() = 0;
	virtual void pop() = 0;
	vritual void push(const T& element) = 0;
};




int main()
{

	return 0;
}

