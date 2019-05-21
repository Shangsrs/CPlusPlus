#include <iostream>
#include <string>

using namespace std;

class IGamePlayer
{
public:
	virtual void login(string user, string password) = 0;
	virtual void killBoss() = 0;
	virtual void upgrade() = 0;
	virtual IGamePlayer* getProxy() = 0;
};

class IProxy
{
public:
	virtual void count() = 0;
	
};
class GamePlayerProxy : public IGamePlayer, IProxy
{
private:
	IGamePlayer *_gamePlayer;
public:
	GamePlayerProxy(IGamePlayer* gamePlayer){_gamePlayer = gamePlayer;};
	void killBoss(){_gamePlayer->killBoss();};
	void login(string user, string passwd){_gamePlayer->login(user, passwd);};
	void upgrade(){_gamePlayer->upgrade();count();};
	IGamePlayer* getProxy(){return this;};
	void count()
	{
		cout<<"The total postage for this upgrade is $1.50"<<endl;
	};
};

class GamePlayer : public IGamePlayer
{
private:
	string _name;
	IGamePlayer *_proxy;
public:
	GamePlayer(string name){_name = name;};
	IGamePlayer* getProxy()
	{
		_proxy = new GamePlayerProxy(this);
		return _proxy;
	};
	void killBoss()
	{
		if(_proxy)
			cout<<_name<<" is killing boss ..."<<endl;
		else
			cout<<"Please use the assigned proxy!"<<endl;
	};
	void login(string user, string passwd)
	{
		if(_proxy)
			cout<<"Login name: "<<user<<" name: "<<_name<<" login successful!"<<endl;
		else
			cout<<"Please use the assigned proxy!"<<endl;
	};
	void upgrade()
	{
		if(_proxy)
			cout<<_name<<" upgrade one step!"<<endl;
		else
			cout<<"Please use the assigned proxy!"<<endl;
	};
	
};


void main()
{
	IGamePlayer *player = new GamePlayer("ZhangSan");
	player->login("zs","passwd");
	player->killBoss();
	player->upgrade();
	IGamePlayer *proxy = new GamePlayerProxy(player);
	proxy->login("zs","passwd");
	proxy->killBoss();
	proxy->upgrade();

	IGamePlayer *proxy2 = player->getProxy();
	proxy2->login("zs","passwd");
	proxy2->killBoss();
	proxy2->upgrade();
	
}

