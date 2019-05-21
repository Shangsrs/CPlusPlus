#include <iostream>
#include <string>
#include <exception>
using namespace std;

class IGamePlayer
{
public:
	virtual void login(string user, string passwd) = 0;
	virtual void killBoss() = 0;
	virtual void upgrade() = 0;
};

class GamePlayer : public IGamePlayer
{
private:
	string _name;
public:
	GamePlayer(string name):_name(name){};
	GamePlayer(IGamePlayer* gamePlayer, string name)
	{
		if(gamePlayer == NULL)
			throw new exception("Can not create role!");
		else
			_name = name;	
	};
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

class GamePlayerProxy : public IGamePlayer
{
private:
	IGamePlayer *_gamePlayer;
public:
	GamePlayerProxy(IGamePlayer* gamePlayer):_gamePlayer(gamePlayer){};
	GamePlayerProxy(string name)
	{
		_gamePlayer = new GamePlayer(this,name);
	};
	void killBoss(){_gamePlayer->killBoss();};
	void login(string user, string passwd)
	{
		_gamePlayer->login(user,passwd);
	};
	void upgrade()
	{
		_gamePlayer->upgrade();
	};
};

int main()
{
	IGamePlayer *player = new GamePlayer("ZhangSan");;
	
	IGamePlayer *proxy = new GamePlayerProxy(player);
	proxy->login("zs","password");
	proxy->killBoss();
	proxy->upgrade();
	IGamePlayer *pr2 = new GamePlayerProxy("LiSi");
	pr2 ->login("li","password");
	pr2 ->killBoss();
	pr2 ->upgrade();
	return 0;
}

