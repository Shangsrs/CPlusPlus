#include <iostream>
using namespace std;

/*
#ifndef Q_DECLARE_PRIVATE
#define Q_DECLARE_PRIVATE(Class) inline Class##Private *d_func() \
{return reinterpret_cast<Class##Private*>(qGetPtrHelper(d_ptr));} \
inline const Class##Private *d_func() \
{return reinterpret_cast<const Class##Private*>(qGetPtrHelper(d_ptr));} \
friend class Class##Private;
#endif

#ifndef Q_DECLARE_PUBLIC
#define Q_DECLARE_PUBLIC(Class) inline Class* q_func() \
{return static_cast<Class*>(q_ptr);} \
inline const Class* q_func()\
{return static_cast<const Class*>(q_ptr);}\
friend class Class;
#endif
*/


template <typename T> static inline T *qGetPtrHelper(T *ptr) { return ptr; }


#define Q_DECLARE_PRIVATE(Class) \
    inline Class##Private* d_func() { return reinterpret_cast<Class##Private *>(qGetPtrHelper(d_ptr)); } \
    inline const Class##Private* d_func() const { return reinterpret_cast<const Class##Private *>(qGetPtrHelper(d_ptr)); } \
    friend class Class##Private;


#define Q_DECLARE_PUBLIC(Class)                                    \
    inline Class* q_func() { return static_cast<Class *>(q_ptr); } \
    inline const Class* q_func() const { return static_cast<const Class *>(q_ptr); } \
    friend class Class;


#define Q_D(Class) Class##Private * const d = d_func()
#define Q_Q(Class) Class * const q = q_func()


class MyClassPrivate;
class MyClass
{
public:
	MyClass();
	virtual ~MyClass();
	void dummyFunc();
private:
	MyClassPrivate* const d_ptr;
	Q_DECLARE_PRIVATE(MyClass);
		
};

class MyClassPrivate
{
public:
	MyClassPrivate(MyClass *parent):q_ptr(parent){};
	void foobar()
	{
		Q_Q(MyClass);
		
	};

private:
	MyClass *const q_ptr;
	Q_DECLARE_PUBLIC(MyClass);
};

MyClass：：MyClass()
{
	d_ptr = new MyClassPrivate(this);
}

MyClass::~MyClass()
{
	Q_D(MyClass);
	delete d;
}

void MyClass::dummyFunc()
{
	Q_D(MyClass);
	d->foobar();
}



int main()
{
	return 0;
}


