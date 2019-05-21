#include "header.h"

class SignInfo
{
private:
	string _id;
	string _location;
	string _subject;
	string _postAddress;
public:
	string getId(){return _id;};
	void setId(string id){_id = id;};
	string getLocation(){return _location;};
	void setLocation(string location){_location = location;};
	string getSubject(){return _subject;};;
	void setSubject(string subject){_subject=subject;};
	string getPostAddress(){return _postAddress;};
	void setPostAddress(string postaddress){_postAddress=postaddress;};
	
};

class SignInfoPool : public SignInfo
{
private:
	string _key;
public:
	SignInfoPool(string key){_key = key;};
	string getKey(){return _key;};
	void setKey(string key){_key=key;};
};

class SignInfoFactory
{
private:
	static map<string,SignInfoPool*> *_pool;
public:
	static SignInfoPool* getSignInfo(string key)
	{
		SignInfoPool *result = NULL;
		map<string,SignInfoPool*>::iterator it;
		it = _pool->find(key);
		if(it!=_pool->end())
		{
			result = it->second;
			cout<<key<<" ---Get from pool"<<endl;
		}
		else
		{
			cout<<key<<" ---Create Object and put into pool"<<endl;
			result = new SignInfoPool(key);
			_pool->insert(pair<string,SignInfoPool*>(key,result));
		}
		return result;
	};
};

map<string,SignInfoPool*>* SignInfoFactory::_pool = new map<string,SignInfoPool*>();

int main()
{
	for(int i=0;i<4;i++)
	{
		char subject[64];
		sprintf(subject,"Subject %d ",i);
		for(int j=0;j<30;j++)
		{
			char key[64];
			sprintf(key,"Course Address %d",j);
			SignInfoFactory::getSignInfo(string(subject)+string(key));
		}
	}
	SignInfoPool *signInfo = SignInfoFactory::getSignInfo("Subject 1 Course Address 1");
	return 0;
}
