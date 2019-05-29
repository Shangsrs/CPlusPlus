#include "../header.h"

template<class K, class V>
class Dictionary
{
public:
	virtual ~Dictionary(){};
	virtual bool empty() const = 0;
	virtual int size() const = 0;
	virtual pair<const K, V>* find(const K&) const = 0;
	virtual void erase(const &) = 0;
	virtual void insert(const pair<const K, E> &) = 0;
};



int main()
{
	return 0;

}