#include <iostream>
#include <string>
using namespace std;

class SchoolReport
{
public:
	virtual void report() = 0;
	virtual void sign(string name) = 0;
};


class FourthGradeSchoolReport : public SchoolReport
{
public:
	void report()
	{
		cout<<"Dear Parent:"<<endl;
		cout<<"   	 		......    "<<endl;
		cout<<"Chinese : 62; Math : 65; Sports : 98; Nature : 63 "<<endl;
		cout<<"    			......    "<<endl;
		cout<<"				Signature:		"<<endl;
		
	};
	void sign(string name)
	{
		cout<<"		Signature:	"<<name<<endl;
	};
};

class Decorator : public SchoolReport
{
private:
	SchoolReport *_sr;
public:
	Decorator(SchoolReport *sr)
	{
		_sr = sr;
	};
	void report()
	{
		_sr->report();
	};
	void sign(string name)
	{
		_sr->sign(name);
	};
};

class HighScoreDecorator : public Decorator
{
private:
	void reportHighScore()
	{
		cout<<"------------Top score------------"<<endl;
		cout<<"Chinese : 75; Math : 78; Sports : 89; Nature : 80 "<<endl;
	};
public:
	HighScoreDecorator(SchoolReport *sr):Decorator(sr){};
	void report()
	{
		reportHighScore();
		Decorator::report();
	};
};

class SortDecorator : public Decorator
{
private:
	void reportSort()
	{
		cout<<"My sort is 38  ........"<<endl;
	};
public:
	SortDecorator(SchoolReport *sr):Decorator(sr){};
	void report()
	{
		Decorator::report();
		reportSort();
	};
	
};
/*	
class SugarFouthGradeSchoolReport : public FourthGradeSchoolReport
{
private:
	void reportHighScore()
	{
		cout<<"------------Top score------------"<<endl;
		cout<<"Chinese : 75; Math : 78; Sports : 89; Nature : 80 "<<endl;
	};
	void reportSort()
	{
		cout<<"My sort is 38  ........"<<endl;
	};
public:
	void report()
	{
		reportHighScore();
		FourthGradeSchoolReport::report();
		reportSort();
	};
};
*/
void main()
{
	SchoolReport *sr;
	sr = new FourthGradeSchoolReport();
//	sr = new HighScoreDecorator(sr);
	sr = new SortDecorator(sr);
	sr->report();
	sr->sign("ZhangSan");
};

