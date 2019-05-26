#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <string>
#include <queue>
#include <sstream>
#include <algorithm>
#include <time.h>
//#include <windows.h>

#include <afxwin.h>         // MFC core and standard components
#include <afxext.h>         // MFC extensions
#include <afxdtctl.h>		// MFC support for Internet Explorer 4 Common Controls
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>			// MFC support for Windows Common Controls
#endif // _AFX_NO_AFXCMN_SUPPORT

using namespace std;

string getRandString(int length)
{
	string source="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char *ch = new char[length+1];
	ch[length] ='\0';
	int strLength = source.size();
	Sleep(300);
	Sleep(10);
	srand(time(NULL));
	for(int i=0; i<length; i++)
	{
		ch[i] = source.at(rand()%strLength);
	}
	return string(ch);
}

int randomCreate(int range)
{
	Sleep(313);
	srand(time(0));
	srand(rand());
	return rand()%range;
}

#endif
