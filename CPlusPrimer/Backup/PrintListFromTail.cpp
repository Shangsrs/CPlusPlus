#include <iostream>
using namespace std;

template<class T>
struct listNode
{
	T value;
	listNode *next;
};

template<class T>
class LinkList
{
	private:
		ListNode *head, *tail;
	public:
		LinkList();
		LinkList(T arr[],int);
		~LinkList();
		bool isEmpty();
		int length();
		T get(int i);
		bool set(int i, T x);
		friend ostream&operator<<(ostream &out,SeqList<T> &list);
		void insert(int i,T x);
		void insert(T x);
		bool remove(int i, T &old);
		void clear();

};


template<class T>
LinkList<T>::LinkList()
{
}


template<class T>
LinkList<T>::LinkList(T arr[],int)
{
}


template<class T>
LinkList<T>::~linkList()
{
}


template<class T>
LinkList<T>::bool isEmpty()
{
}


template<class T>
LinkList<T>::int length()
{
}


template<class T>
LinkList<T>:T get(int i)
{
}


template<class T>
LinkList<T>::bool set(int i, T x)
{
}


template<class T>
friend ostream&operator<<(ostream &out,SeqList<T> &list)
{
}


template<class T>
LinkList<T>::void insert(int i,T x)
{
}


template<class T>
LinkList<T>::void insert(T x)
{
}


template<class T>
LinkList<T>::bool remove(int i, T &old)
{
}


template<class T>
LinkList<T>::void clear()
{
}

int main()
{
	return 0;
}