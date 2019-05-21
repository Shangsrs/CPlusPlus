#include "ListLink.h"
#include "Stack.h"
#include "ListSequence.h"

template<class T>
void postOrder(ListLink<T> *list,int i)
{
	if(list->hasNext())
	{
		postOrder(list,i++);
		std::cout<<list->next()<<" ";		
	}
	return;
}

int main()
{
	ListLink<int> *list = new ListLink<int>();

	for(int i=0;i<=10;i++)
	{
		list->insert(i+1);
	}
	std::cout<<*list;
	postOrder(list,0);


/*	Stack<int> *stack = new Stack<int>;
	int len = list->length();
	for(i=0;i<len;i++)
	{
		stack->push(list->get(i));
	}
	std::cout<<*stack;
	ListSequence<int> *arr = new ListSequence<int>(len);
	while(!stack->isEmpty())
	{
		arr->insert(stack->pop());
	}
	std::cout<<*arr;
*/
	return 0;
}