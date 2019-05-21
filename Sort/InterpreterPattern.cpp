#include <iostream>
#include <string>
#include <map>
using namespace std;
class Expression
{
public:
	virtual int interpreter(map<string,int> *var) = 0;
};

class VarExpression : public Expression
{
private:
	string _key;
public:
	VarExpression(string key){_key = key;};
	int interpreter(map < string, int > * var)
	{
		return (*var)[_key];
	};
};

class SymbolExpresion : public Expression
{
protected:
	Expression *_left;
	Expression *_right;
public:
	SymbolExpresion(Expression *left, Expression *right)
	{
		_left = left;
		_right = right;
	};
};

class AddExpression : public SymbolExpresion
{
public:
	AddExpression(Expression *left, Expression *right):SymbolExpresion(left,right){};
	int interpreter(map < string, int > * var)
	{
		return _left->interpreter(var)+_right->interpreter(var);
	};
};


class SubExpression : public SymbolExpresion
{
public:
	SubExpression(Expression *left, Expression *right):SymbolExpresion(left,right){};
	int interpreter(map < string, int > * var)
	{
		return _left->interpreter(var)-_right->interpreter(var);
	};
};

class Calculator
{
private:
	Expression *_expression;
public:
	Calculator(string expStr)
	{
		stack<Expression*> *stack = new stack<Expression*>();
		Expression *left = NULL;
		Expression *right = NULL;
		for(int i=0;i<expStr.length();i++)
		{
			switch(expStr.at(i))
			{
			case '+':
				left = stack->pop();
				right = new VarExpression(expStr.substr(++i));
				stack->push(new AddExpression(left,right));
				break;
			case '-':
				left = stack->pop();
				right = new VarExpression(expStr.substr(++i));
				stack->push(new SubExpression(left,right));
				break;
			default:
				stack->push(new VarExpression(expStr.at[i]));
			}
		}
		_expression = stack->pop();
	};
	int run(<map<string,int> *var)
	{
		return _expression->interpreter(var);
	};
};

string getExpStr()
{
	cout<<"Please input expression:"<<endl;
	string expStr;
	cin>>expStr;
	return expStr;
};

map<string,int> getValue(string expStr)
{
	map<string,int> *expMap = new map<string,int>();
	for(int i=0;i<expStr.length;i++)
	{
		if(expStr.at[i] != '+' && expStr.at[i] != '-')
	}
	
};

void main()
{
	string expStr = getExpStr();
	map<string,int> *var = getValue(expStr);
	Calculator *cal = new Calculator(expStr);
	cout<<"Result: "<<expStr<<" = "<<cal->run(var)<<endl;
}

