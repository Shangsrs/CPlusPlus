#include <iostream>
#include <string>

using namespace std;

class IGamePlayer
{
public:
	virtual void login(string user, string password) = 0;
	virtual void killBoss() = 0;
	virtual void upgrade() = 0;
};

class GamePlayer : public IGamePlayer
{
private:
	string _name;
public:
	GamePlayer(string name){_name = name;};
	void killBoss()
	{
		cout<<_name<<" is killing boss ..."<<endl;
	};
	void login(string user, string passwd)
	{
		cout<<"Login name: "<<user<<" name: "<<_name<<" login successful!"<<endl;
	};
	void upgrade()
	{
		cout<<_name<<" upgrade one step!"<<endl;
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

