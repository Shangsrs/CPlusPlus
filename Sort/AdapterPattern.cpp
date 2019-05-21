#include <iostream>
#include <string>
#include <map>

using namespace std;

class IUserInfo
{
public:
	virtual string getUserName() = 0;
	virtual string getHomeAddress() = 0;
	virtual string getMobileNumber() = 0;
	virtual string getOfficeTelNumber() = 0;
	virtual string getJobPosition() = 0;
	virtual string getHomeTelNumber() = 0;	
};

class UserInfo : public IUserInfo
{
public:
	string getUserName()
	{
		cout<<"--------User Name--------"<<endl;
		return "Name";
	};
	string getHomeAddress()
	{
		cout<<"--------Home Address--------"<<endl;
		return "Address";
	};
	string getMobileNumber()
	{
		cout<<"--------Mobile Number--------"<<endl;
		return "Mobile";
	};
	string getOfficeTelNumber()
	{
		cout<<"--------Office Tellephone Number--------"<<endl;
		return "Office";
	};
	string getJobPosition()
	{
		cout<<"--------Job Position--------"<<endl;
		return "JobPosition";
	};
	string getHomeTelNumber()
	{
		cout<<"--------Home Tellephone Numbeer--------"<<endl;
		return "HomeTelNumber";
	};
};


class IOuterUser
{
public:
	virtual map<string,string>* getUserBaseInfo() = 0;
	virtual map<string,string>* getUserOfficeInfo() = 0;
	virtual map<string,string>* getUserHomeInfo() = 0;
};

class OuterUser : public IOuterUser
{
public:
	map<string,string>* getUserBaseInfo()
	{
		map<string,string> * baseInfoMap = new map<string,string>();
		(*baseInfoMap)["userName"] = "Name";
		(*baseInfoMap)["mobileNumber"] = "Mobile";
		return baseInfoMap;
	};

	map<string,string>* getUserOfficeInfo()
	{
		map<string,string> * officeInfo = new map<string,string>();
		(*officeInfo)["jobPosition"] = "JobPosition";
		(*officeInfo)["officeTelNumber"] = "OfficeNumber";
		return officeInfo;
	};
	map<string,string>* getUserHomeInfo()
	{
		map<string,string> * homeInfo = new map<string,string>();
		(*homeInfo)["homeTelNumber"] = "HomeTelNumber";
		(*homeInfo)["homeAddress"] = "HomeAddess";
		return homeInfo;
	};
};

class OuterUserInfo : public OuterUser, IUserInfo
{
private:
	map<string,string> *_baseInfo;
	map<string,string> *_officeInfo;
	map<string,string> *_homeInfo;
public:
	OuterUserInfo()
	{
		_baseInfo = getUserBaseInfo();
		_officeInfo = getUserOfficeInfo();
		_homeInfo = getUserHomeInfo();
	};
	string getHomeAddress()
	{
		string homeAddress = (*_homeInfo)["homeAddress"];
		cout<<homeAddress<<endl;
		return homeAddress;
	};
	string getHomeTelNumber()
	{
		string homeTelNumber = (*_homeInfo)["homeTelNumber"];
		cout<<homeTelNumber<<endl;
		return homeTelNumber;
	};
	string getJobPosition()
	{
		string jobPosition = (*_officeInfo)["jobPosition"];
		cout<<jobPosition<<endl;
		return jobPosition;
	};
	string getOfficeTelNumber()
	{
		string officeTelNumber = (*_officeInfo)["officeTelNumber"];
		cout<<officeTelNumber<<endl;
		return officeTelNumber;
	};
	string getMobileNumber()
	{
		string mobileNumber = (*_baseInfo)["mobileNumber"];
		cout<<mobileNumber<<endl;
		return mobileNumber;
	};
	string getUserName()
	{
		string userName = (*_baseInfo)["userName"];
		cout<<userName<<endl;
		return userName;
	};
};

int main()
{
	IUserInfo *ui = new UserInfo();
	cout<<ui->getUserName()<<endl;
	return 0;
}
