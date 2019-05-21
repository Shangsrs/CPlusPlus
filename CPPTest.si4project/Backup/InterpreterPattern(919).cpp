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

