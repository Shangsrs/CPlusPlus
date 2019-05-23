#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <string>
#include <queue>
#include <sstream>

using namespace std;



class illegalParameterValue
{
public:
	illegalParameterValue():
		message("Illegal parameter value"){};
	illegalParameterValue(char* theMessage)
	{
		message = theMessage;
	};
	void outputMessage(){cout<<message<<endl;};

private:
	string message;
};

#endif
