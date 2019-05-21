#include <iostream>
#include <string>
using namespace std;


struct Node
{
	string str;
	int i;
	Node *left;
	Node *right;
};
	

int main()
{
	Node *n1 = new Node();
	cout<<"sizeof(*n1):"<<sizeof(*n1)<<endl;
	cout<<"sizeof(n1->str):"<<sizeof(n1->str)<<endl;
	n1->str = string("Hello World! Hello World! Hello World! Hello World! Hello World! Hello World! ");
	n1->i = 100;
	n1->left = n1->right = NULL;
	cout<<"sizeof(*n1):"<<sizeof(*n1)<<endl;
	Node *n2 = new Node();
	cout<<"sizeof(*n2):"<<sizeof(*n2)<<endl;
	n1->left = n1->right = n2;
	*n2 = *n1;
	n2->left=n2->right = n1;
	cout<<"sizeof(*n2):"<<sizeof(*n2)<<endl;
	cout<<"n1:"<<endl;
	cout<<"str:"<<n1->str<<" &str:"<<&(n1->str)<<endl;;
	cout<<" i:"<<n1->i<<" &i:"<<&(n1->i)<<endl;
	cout<<"Left:"<<n1->left<<" &left:"<<&(n1->left)<<endl;
	cout<<" Right:"<<n1->right<<" &right"<<&(n1->right)<<endl;
	cout<<"n2:"<<endl;
	cout<<"str:"<<n2->str<<" &str:"<<&(n2->str)<<endl;;
	cout<<" i:"<<n2->i<<" &i:"<<&(n2->i)<<endl;
	cout<<"Left:"<<n2->left<<" &left:"<<&(n2->left)<<endl;
	cout<<" Right:"<<n2->right<<" &right"<<&(n2->right)<<endl;

	return 0;
}
