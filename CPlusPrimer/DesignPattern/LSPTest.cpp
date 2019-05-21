#include "header.h"

//Liskov Substitution Principle LSP
class AbstractGun
{
public:
	virtual void shoot() = 0;
};

class HandGun : public AbstractGun
{
public:
	void shoot()
	{
		std::cout<<"Hand gun shoot"<<endl;
	};

};
class Rifle : public AbstractGun
{
public:
	void shoot()
	{
		std::cout<<"Rifle gun shoot"<<endl;
	};

};

class MachineGun : public AbstractGun
{
public:
	void shoot()
	{
		std::cout<<"Machine gun shoot"<<endl;
	};

};

class Soldier
{
private:
	AbstractGun* gun;

public:
	void setGun(AbstractGun *g)
	{
		gun = g;
	};
	void killEnemy()
	{
		cout<<"Soldier kill enemy: "<<endl;
		gun->shoot();
	};
};


class AUG : public Rifle
{
public:
	void zoomOut()
	{
		cout<<"Look enemy by far mirror"<<endl;
	};
	void shoot()
	{
		zoomOut();
		cout<<"AUG shoot"<<endl;
	};
};
int main()
{
	Soldier *zs = new Soldier();
	zs->setGun(new Rifle());
	zs->killEnemy();
	zs->setGun(new HandGun());
	zs->killEnemy();
	zs->setGun(new MachineGun());
	zs->killEnemy();
	zs->setGun(new AUG());
	zs->killEnemy();
	return 0;
}

