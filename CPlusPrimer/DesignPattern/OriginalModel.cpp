#include "header.h"

class AdvTemplate
{
private:
	string _advSubject;
	string _advContent;
public:
	AdvTemplate():_advSubject("Activity Subject"),_advContent("Activity content"){};
	string& getAdvSubject(){return _advSubject;};
	string& getAdvContent(){return _advContent;};
};

class Mail
{
private:
	string _receiver;
	string _subject;
	string _appellation;
	string _contxt;
	string _tail;
public:
	Mail(AdvTemplate *advTemplate)
	{
		_contxt = advTemplate->getAdvContent();
		_subject = advTemplate->getAdvSubject();
	};
	string& getReceiver(){return _receiver;};
	string& getSubject(){return _subject;};
	string& getAppellation(){return _appellation;};
	string& getContxt(){return _contxt;};
	string& getTail(){return _tail;};
	void setReceiver(string receiver){_receiver = receiver;};
	void setSubject(string subject){ _subject = subject;};
	void setAppellation(string appellation){ _appellation = appellation;};
	void setContxt(string contxt){ _contxt = contxt;};
	void setTail(string tail){ _tail = tail;};
	
};

const static int MAX_COUNT = 6;

void sendMail(Mail *mail)
{
	cout<<"Title:"<<mail->getSubject()<<"\t Receiver:"<<mail->getReceiver()<<"\t Send Successful"<<endl;
}

string getRandString(int length)
{
	string source="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char *ch = new char[length+1];
	ch[length] ='\0';
	int strLength = source.size();
	Sleep(300);
	srand(time(NULL));
	for(int i=0; i<length; i++)
	{
		ch[i] = source.at(rand()%strLength);
	}
	return string(ch);
}

int main()
{
	int i = 0;
	Mail *mail = new Mail(new AdvTemplate());
	mail->setTail("Bank Owner ");
	while(i<MAX_COUNT)
	{
		mail->setAppellation(getRandString(5).append(" Lady/Gentlemen "));
		mail->setReceiver(getRandString(5).append("@").append(getRandString(8)));
		sendMail(mail);
		i++;
	}
	return 0;
};
