#include "../header.h"



int main(int argc, char* argv[])
{
	char outputFile[64], inputFile[64];
	if(argc >= 2)
		strcpy(inputFile,argv[1]);
	else
	{
		cout<<"Enter name of file to compress:"<<endl;
		cin>>inputFile;
		cout<<endl;
	}
	fstream readFile;
	readFile.open(inputFile,std::fstream::in );
	if(readFile.is_open())
	{
		cout<<"Open file "<<inputFile<<" Success"<<endl;
	}
	else
	{
		cout<<"Open file "<<inputFile<<" error"<<endl;
		return 1;
	}
	strcpy(outputFile,inputFile);
	strcat(outputFile,".zzz");
	fstream writeFile;
	writeFile.open(outputFile,std::fstream::out | std::fstream::binary);
	if(writeFile.is_open())
	{
		cout<<"Open file "<<outputFile<<" Success"<<endl;
	}
	else
	{
		cout<<"Open file "<<outputFile<<" error"<<endl;
		return 1;
	}
	readFile.close();
	writeFile.close();
	return 0;
}
